#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-07-15

    Description:
    Spaces all selected entities equally.

    Parameter(s):
    0: NUMBER - Position index, 0 = x, 1 = y, >=2 = z.

    Returns:
    -
*/

params [["_index", 0]];

["ENH_AlignEntities_WrongIndexValue"] call BIS_fnc_3DENNotification;

private _entities = [["Object", "Marker", "Logic", "Waypoint", "Trigger"]] call ENH_fnc_all3DENSelected;
if (count _entities < 3) exitWith {}; // Makes no sense to space less than three entities

private _positions = [];

// Get max and min position
_entities apply
{
    _positions pushBack ((_x get3DENAttribute "Position") # 0 # _index);
};

private _max = selectMax _positions;
private _min = selectMin _positions;

// Sort entities by position
_entities = [_entities, [], {(_x get3DENAttribute "Position") # 0 # _index}] call BIS_fnc_sortBy;

// Get step count and size
private _stepCount = count _entities - 1;
private _stepSize = abs ((_max - _min) / _stepCount);

// Update positions
[localize "STR_ENH_MAIN_FOLDER_SPACE", nil, "a3\3den\data\cfg3den\history\moveitems_ca.paa"] collect3DENHistory
{
    {
        private _pos = (_x get3DENAttribute "Position") # 0;
        if (_forEachIndex < _stepCount) then
        {
            _pos set [_index, _min + _stepSize * _forEachIndex];
            _x set3DENAttribute ["Position", _pos];
        };
    } forEach _entities;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

nil
