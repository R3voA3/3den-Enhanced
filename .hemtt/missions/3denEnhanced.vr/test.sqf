#include "\x\enh\addons\main\script_component.hpp"

profileNamespace setVariable ["ENH_EditorPreferences_Garrison_GroupTogether", true];
profileNamespace setVariable ["ENH_EditorPreferences_Garrison_RandomRotation", true];
profileNamespace setVariable ["ENH_EditorPreferences_Garrison_DisablePath", true];
profileNamespace setVariable ["ENH_EditorPreferences_Garrison_UnitPos", 4];
// 4: Random
// 3: Default Stance
// 2: Prone
// 1: Kneel
// 0: Stand
profileNamespace setVariable ["ENH_EditorPreferences_Garrison_AutoSelectType", 1];
// 0: Keep original selection
// 1: Select remaining units
// 2: Deselect everything
// 3: Select garrisoned units

ENH_fnc_garrison_cleanUp =
{
    private _display3DEN = findDisplay IDD_DISPLAY3DEN;

    _display3DEN displayRemoveEventHandler
    [
        "MouseButtonUp",
        _display3DEN getVariable ["ENH_MouseButtonUpID", -1]
    ];

    remove3DENEventHandler
    [
        "OnEntityDragged",
        _display3DEN getVariable ["ENH_OnEntityDraggedID", -1]
    ];

    remove3DENEventHandler
    [
        "OnBeforeMissionPreview",
        _display3DEN getVariable ["ENH_OnBeforeMissionPreviewID", -1]
    ];

    _display3DEN setVariable ["ENH_MouseButtonUpID", nil];
    _display3DEN setVariable ["ENH_OnEntityDraggedID", nil];
    _display3DEN setVariable ["ENH_EachFrameID", nil];
    _display3DEN setVariable ["ENH_Draw3DID", nil];
    _display3DEN setVariable ["ENH_OnBeforeMissionPreviewID", nil];

    _display3DEN setVariable ["ENH_CurrentBuilding", nil];
    _display3DEN setVariable ["ENH_CursorInBuilding", nil];

    // [[], [], false] call BIS_fnc_drawBoundingBox;

    ["Quick garrison disabled!"] call BIS_fnc_3DENNotification;
};

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

if (findDisplay IDD_DISPLAY3DEN getVariable ["ENH_OnEntityDraggedID", -1] == -1) then
{
    if (get3DENActionState "toggleMap" > 0) exitWith
    {
        // TODO: enable it in 2D 2025-05-01 R3vo
        ["Quick garrison does not support 2D view.", 1] call BIS_fnc_3DENNotification;
    };

    ["Quick garrison enabled!"] call BIS_fnc_3DENNotification;

    private _mouseButtonUpID = _display3DEN displayAddEventHandler ["MouseButtonUp",
    {
        params ["_display3DEN", "_button"];

        // Only left mouse button counts
        if (_button != 0) exitWith {};

        private _display3DEN = findDisplay IDD_DISPLAY3DEN;
        private _cursorInBuilding = _display3DEN getVariable ["ENH_CursorInBuilding", false];
        private _building = _display3DEN getVariable ["ENH_CurrentBuilding", objNull];

        if (_cursorInBuilding) then
        {
            private _ID = addMissionEventHandler ["EachFrame",
            {
                _thisArgs params ["_frame", "_building"];

                if (diag_frameNo >= _frame + 1) then
                {
                    removeMissionEventHandler [_thisEvent, _thisEventHandler];

                    private _selectedEntities = get3DENSelected "Object" - [_building];
                    private _movedEntities = [];

                    [
                        "Garrison", "Entities were moved into a building.",
                        TEXTURE_BUILDING_POS
                    ] collect3DENHistory
                    {
                        private _buildingPositions = _building buildingPos -1;

                        {
                            private _entity = _x;
                            private _sortedBuildingPositions =
                            [
                                _buildingPositions,
                                [_entity],
                                {_input0 distance _x}
                            ] call BIS_fnc_sortBy;

                            private _closestPosition = _sortedBuildingPositions#0;
                            _buildingPositions = _buildingPositions - [_closestPosition];

                            _entity set3DENAttribute ["Position", _closestPosition];

                            if ((profileNamespace getVariable ["ENH_EditorPreferences_Garrison_RandomRotation", false])) then
                            {
                                private _rotation = _entity get3DENAttribute "Rotation";
                                _rotation set [2, random 359];
                                _entity set3DENAttribute ["Rotation", _rotation];
                            };

                            if ((profileNamespace getVariable ["ENH_EditorPreferences_Garrison_DisablePath", false])) then
                            {
                                _entity set3DENAttribute ["ENH_disableAI_path", true];
                            };

                            private _unitPos = profileNamespace getVariable ["ENH_EditorPreferences_Garrison_UnitPos", 3];
                            if (_unitPos == 4) then
                            {
                                _entity set3DENAttribute ["unitPos", selectRandom [0, 1, 2, 3]];
                            }
                            else
                            {
                                _entity set3DENAttribute ["unitPos", _unitPos];
                            };

                            _movedEntities pushBack _entity;

                            if (_buildingPositions isEqualTo []) exitWith
                            {
                                set3DENSelected (_selectedEntities - _movedEntities);

                                ["No more empty positions! Remaining entities were auto selected.", 1, nil, nil, 0.1] call BIS_fnc_3DENNotification;
                            };
                        } forEach (get3DENSelected "Object" - [_building]);

                        // Grouping is broken (https://feedback.bistudio.com/T191578)
                        // if (profileNamespace getVariable ["ENH_EditorPreferences_Garrison_GroupTogether", false]) then
                        // {
                        //     add3DENConnection ["Group", _movedEntities, _movedEntities#0];
                        // };
                    };
                };
            },
                [diag_frameNo, _building]
            ];

            findDisplay IDD_DISPLAY3DEN setVariable ["ENH_EachFrameID", _ID];
        };
        call ENH_fnc_garrison_cleanUp;
    }];

    private _onEntityDraggedID = add3DENEventHandler ["OnEntityDragged",
    {
        if (get3DENActionState "toggleMap" > 0) exitWith {};

        private _display3DEN = findDisplay IDD_DISPLAY3DEN;

        private _cursorPos =
        [
            parseNumber ctrlText (_display3DEN displayctrl IDC_DISPLAY3DEN_STATUSBAR_X),
            parseNumber ctrlText (_display3DEN displayctrl IDC_DISPLAY3DEN_STATUSBAR_Y),
            parseNumber ctrlText (_display3DEN displayctrl IDC_DISPLAY3DEN_STATUSBAR_Z)
        ];

        // Conver to ATL for water areas
        if (surfaceIsWater [_cursorPos#0, _cursorPos#1]) then
        {
            _cursorPos = ASLToATL _cursorPos;
        };

        private _building = nearestBuilding _cursorPos;

        if (_building buildingPos -1 isEqualTo []) then
        {
            _building = objNull;
        };

        if !(isNull _building) then
        {
            private _bb = 0 boundingBoxReal _building;
            private _p1 = _bb select 0;
            private _p2 = _bb select 1;
            private _maxWidth = abs ((_p2 select 0) - (_p1 select 0));
            private _maxLength = abs ((_p2 select 1) - (_p1 select 1));
            private _maxHeight = abs ((_p2 select 2) - (_p1 select 2));

            private _cursorInBoundingBox = _cursorPos inArea
            [
                _building,
                _maxWidth * 0.5,
                _maxLength  * 0.5,
                getDir _building,
                true,
                _maxHeight
            ];

            _display3DEN setVariable ["ENH_CurrentBuilding", _building];
            _display3DEN setVariable ["ENH_CursorInBuilding", _cursorInBoundingBox];
        };
    }];

    private _draw3DID = addMissionEventHandler ["Draw3D",
    {
        private _display3DEN = findDisplay IDD_DISPLAY3DEN;
        private _building = _display3DEN getVariable ["ENH_CurrentBuilding", objNull];
        private _cursorInBuilding = _display3DEN getVariable ["ENH_CursorInBuilding", false];

        if (_cursorInBuilding) then
        {
            private _selectedEntities = get3DENSelected "Object";
            private _buildingPositions = _building buildingPos -1;

            // If only one unit is selected we highlight closest position
            if (count _selectedEntities == 1) then
            {
                private _closestPosition =
                ([
                    _buildingPositions,
                    [_selectedEntities#0],
                    {_input0 distance _x}
                ] call BIS_fnc_sortBy) # 0;

                _buildingPositions apply
                {
                    drawIcon3D
                    [
                        TEXTURE_BUILDING_POS,
                        [[COLOR_BUILDING_POS], [COLOR_BUILDING_POS_HIGHLIGHT]] select (_x isEqualTo _closestPosition),
                        _x,
                        0.5,
                        0.5,
                        0
                    ];
                };
            }
            else
            {
                _buildingPositions apply
                {
                    drawIcon3D
                    [
                        TEXTURE_BUILDING_POS,
                        [COLOR_BUILDING_POS],
                        _x,
                        0.5,
                        0.5,
                        0
                    ];
                };
            };
        };
    }];

    private _onBeforeMissionPreviewID = add3DENEventHandler ["OnBeforeMissionPreview",
    {
        call ENH_fnc_garrison_cleanUp;
    }];

    _display3DEN setVariable ["ENH_MouseButtonUpID", _mouseButtonUpID];
    _display3DEN setVariable ["ENH_OnEntityDraggedID", _onEntityDraggedID];
    _display3DEN setVariable ["ENH_Draw3DID", _draw3DID];
    _display3DEN setVariable ["ENH_OnBeforeMissionPreviewID", _onBeforeMissionPreviewID];
}
else
{
    call ENH_fnc_garrison_cleanUp;
};
