#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    Fills the targeted building's positions with the selected entities.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - True
*/

params [["_building", objNull]];

private _selectedEntities = get3DENSelected "Object" - [_building];
private _movedEntities = [];

[
    localize "$STR_ENH_MAIN_GARRISON2_HISTORY_TITLE",
    localize "$STR_ENH_MAIN_GARRISON2_HISTORY_TOOLTIP",
    TEXTURE_BUILDING_POS
] collect3DENHistory
{
    private _buildingPositions = _building buildingPos -1;
    private _noneEmptyPositionFound = false;

    // Settings
    private _groupTogether = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_GroupTogether", false];
    private _randomRotation = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_RandomRotation", false];
    private _disablePathfinding = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_DisablePathfinding", false];
    private _autoSelect = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities", false];
    private _checkForEmptyPositions = profileNamespace getVariable ["ENH_Garrison2_CheckForTakenPositions", true];
    private _stance = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_Stance", 3];
    private _createLayer = profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_CreateLayer', false];

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

        if (_checkForEmptyPositions) then
        {
            if !([_closestPosition] call ENH_fnc_garrison2_isBuildingPositionEmpty) then
            {
                continue;
            };
        };

        _entity set3DENAttribute
        [
            "Position",
            if (surfaceIsWater _closestPosition) then {ASLToATL _closestPosition} else {_closestPosition}
        ];

        if (_randomRotation) then
        {
            private _rotation = _entity get3DENAttribute "Rotation";
            _rotation set [2, random 359];
            _entity set3DENAttribute ["Rotation", _rotation];
        };

        if (_disablePathfinding) then
        {
            _entity set3DENAttribute ["ENH_disableAI_path", true];
        };

        switch (_stance) do
        {
            case STANCE_RANDOM:
            {
                _entity set3DENAttribute
                [
                    STANCE_ATT_NAME,
                    selectRandom
                    [
                        STANCE_STAND,
                        STANCE_KNEEL,
                        STANCE_PRONE,
                        STANCE_DEFAULT
                    ]
                ];
            };
            case STANCE_NO_PRONE:
            {
                _entity set3DENAttribute
                [
                    STANCE_ATT_NAME,
                    selectRandom
                    [
                        STANCE_STAND,
                        STANCE_KNEEL,
                        STANCE_DEFAULT
                    ]
                ];
            };
            default
            {
                _entity set3DENAttribute [STANCE_ATT_NAME, _stance];
            };
        };

        _movedEntities pushBack _entity;

        if (_buildingPositions isEqualTo []) exitWith
        {
            if (_autoSelect) then
            {
                set3DENSelected (_selectedEntities - _movedEntities);
            };

            ["ENH_Garrison2_All_Positions_Taken"] call BIS_fnc_3DENNotification;
        };
    } forEach (get3DENSelected "Object" - [_building]);
    // TODO: enable if it ever gets fixed 2025-05-03 R3vo
    // Grouping is broken (https:// feedback.bistudio.com/T191578)
    // if (_groupTogether) then
    // {
    //     add3DENConnection ["Group", _movedEntities, _movedEntities#0];
    // };

    if (_createLayer) then
    {
        private _newLayer = -1 add3DENLayer (call ENH_fnc_createHashValue);
        _movedEntities apply {_x set3DENLayer _newLayer};
    };
};
