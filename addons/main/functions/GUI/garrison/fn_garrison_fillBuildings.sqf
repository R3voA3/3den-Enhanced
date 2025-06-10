#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-08-03

    Description:
    Garrison one or multiple buildings in the area. Radius and coverage are taken from the custom UI ENH_Garrison.

    Parameter(s):
    -

    Returns:
    -
*/

disableSerialization;

private _display = findDisplay IDD_DISPLAY3DEN;
private _mode = lbCurSel CTRL(IDC_GARRISON_MODE);
private _unitPos = lbCurSel CTRL(IDC_GARRISON_STANCE);
private _enablePath = [true, false] select (lbCurSel CTRL(IDC_GARRISON_PATH));

// Set entity attributes
private _fnc_setAttributes =
{
params ["_entity", "_pos", "_unitPos"];

    _entity set3DENAttribute ["position", _pos];
    _entity set3DENAttribute ["unitPos", if (_unitPos == 4) then {selectRandom [0, 1, 2, 3]} else {_unitPos}];
    _entity set3DENAttribute ["rotation", [0, 0, random 360]];
    _entity set3DENAttribute ["ENH_disableAI_path", _enablePath];
};

// Get building positions from given buildings. Respecting coverage value
private _fnc_getBuildingsPositions =
{
    params [["_firstOnly", false]];

    private _coverage = [10, 4, 2, 1] select (lbCurSel CTRL(IDC_GARRISON_COVERAGE)); // Convert selected index to divisor

    ENH_Garrison_ValidBuildings = [ENH_Garrison_ValidBuildings, [], {ENH_Garrison_AreaHelper distance _x}, "ASCEND"] call BIS_fnc_sortBy;

    if _firstOnly exitWith
    {
        ENH_Garrison_ValidBuildings select 0 buildingPos -1;
    };

    private _buildingPositions = ENH_Garrison_ValidBuildings apply {_x buildingPos -1};
    private _buildingsPositionsFlattened = [];

    _buildingPositions apply {_x apply {_buildingsPositionsFlattened pushBack _x}};

    // Resize array to reduce amount of positions randomly according to coverage value
    _buildingsPositionsFlattened = _buildingsPositionsFlattened call BIS_fnc_arrayShuffle;
    _buildingsPositionsFlattened resize (round (count _buildingsPositionsFlattened / _coverage));
    _buildingsPositionsFlattened;
};

[localize "STR_ENH_MAIN_GARRISON_HEADER"] collect3DENHistory
{
    switch _mode do
    {
        case 0:// CLOSEST BUILDING
        {
            private _positions = true call _fnc_getBuildingsPositions;
            {
                if (_positions isEqualTo []) exitWith {["ENH_NotEnoughBuildingPositions"] call BIS_fnc_3DENNotification};

                private _pos = selectRandom _positions;
                _positions = _positions - [_pos];
                [_x, _pos, _unitPos] call _fnc_setAttributes;
            } forEach ENH_Garrison_SelectedEntities;
        };
        case 1:// FROM CENTER
        {
            private _positions = false call _fnc_getBuildingsPositions;
            {
                if (_positions isEqualTo []) exitWith {["ENH_NotEnoughBuildingPositions"] call BIS_fnc_3DENNotification};

                private _pos = _positions select 0;
                _positions deleteAt 0;
                [_x, _pos, _unitPos] call _fnc_setAttributes;
            } forEach ENH_Garrison_SelectedEntities;
        };
        case 2:// RANDOM
        {
            private _positions = false call _fnc_getBuildingsPositions;
            {
                if (_positions isEqualTo []) exitWith {["ENH_NotEnoughBuildingPositions"] call BIS_fnc_3DENNotification};

                private _pos = selectRandom _positions;
                _positions = _positions - [_pos];
                [_x, _pos, _unitPos] call _fnc_setAttributes;
            } forEach ENH_Garrison_SelectedEntities;
        };
    };
};
