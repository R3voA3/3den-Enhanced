#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    Handles placing of entities in building if all conditions are met.

    Parameter(s):
    0: DISPLAY - Eden Editor display
    1: NUMBER - Mouse button ID

    Return Value:
    ARRAY - True on success, false if failed
*/

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

        // Placement needs to happen next frame
        // otherwise onEntityDragged will happen after it
        // and place units incorrectly
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
                        if (profileNamespace getVariable ["AutoSelectRemainingEntities", false]) then
                        {
                            set3DENSelected (_selectedEntities - _movedEntities);
                        };

                        ["ENH_Garrison2_All_Positions_Taken"] call BIS_fnc_3DENNotification;
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

call ENH_fnc_garrison2_exit;

true
