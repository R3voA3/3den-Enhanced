#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-07-12

    Description:
    Aligns all selected objects according to arguments.

    Parameter(s):
    0: NUMBER - Position index, 0 = x, 1 = y, >=2 = z.
    1: BOOLEAN - Maximum or minimum. True for maximum, false for minimum. Default true

    Returns:
    -
*/

params [["_index", 0], ["_max", true]];

["ENH_AlignEntities_WrongIndexValue"] call BIS_fnc_3DENNotification;

private _entities = [] call ENH_fnc_all3DENSelected;
if (count _entities < 2) exitWith {}; // Makes no sense to align less then two entities

private _positions = [];

_entities apply
{
    _positions pushBack ((_x get3DENAttribute "Position") # 0 # _index);
};

// Either select maximum or minimum. Using _max var in both cases because I am lazy
if _max then
{
    _max = selectMax _positions;
}
else
{
    _max = selectMin _positions;
};

[localize "STR_ENH_MAIN_FOLDER_ALIGN", nil, "a3\3den\data\cfg3den\history\moveitems_ca.paa"] collect3DENHistory
{
    _entities apply
    {
        private _pos = (_x get3DENAttribute "Position") # 0;

        _pos set [_index, _max];
        _x set3DENAttribute ["Position", _pos];
    };
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

nil
