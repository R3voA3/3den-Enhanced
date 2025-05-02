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

private _selectedEntities = get3DENSelected "Object" - [_building];
private _movedEntities = [];

[
    "Garrison", "Entities were moved into a building.",// TODO: translate 2025-05-02 R3vo
    TEXTURE_BUILDING_POS
] collect3DENHistory
{
    private _buildingPositions = _building buildingPos -1;
    private _noneEmptyPositionFound = false;

    // Settings
    private _groupTogether = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_GroupTogether", false];
    private _randomRotation = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_RandomRotation", false];
    private _disablePath = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_DisablePath", false];
    private _autoSelect = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities", false];
    private _checkForEmptyPositions = profileNamespace getVariable ["ENH_Garrison2_CheckForTakenPositions", true];
    private _unitPos = profileNamespace getVariable ["ENH_EditorPreferences_Garrison2_UnitPos", 3];

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
                _noneEmptyPositionFound = true;
                continue;
            };
        };

        _entity set3DENAttribute ["Position", _closestPosition];

        if (_randomRotation) then
        {
            private _rotation = _entity get3DENAttribute "Rotation";
            _rotation set [2, random 359];
            _entity set3DENAttribute ["Rotation", _rotation];
        };

        if (_disablePath) then
        {
            _entity set3DENAttribute ["ENH_disableAI_path", true];
        };

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
            if (_autoSelect) then
            {
                set3DENSelected (_selectedEntities - _movedEntities);
                ["ENH_Garrison2_All_Positions_Taken_Auto_Select"] call ENH_fnc_3DENNotificationQueue;
            }
            else
            {
                ["ENH_Garrison2_All_Positions_Taken"] call ENH_fnc_3DENNotificationQueue;
            };
        };
    } forEach (get3DENSelected "Object" - [_building]);

    // Grouping is broken (https://feedback.bistudio.com/T191578)
    if (_groupTogether) then
    {
        add3DENConnection ["Group", _movedEntities, _movedEntities#0];
    };

    if (_noneEmptyPositionFound) then
    {
        ["One or more positions were already full!", 1] call ENH_fnc_3DENNotificationQueue;
    };
};
