#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Toggles given attribute of selected entities of given types. Only attribute which use boolean values can be toggled.

    Parameter(s):
    0: ARRAY - Array of types to select. See ENH_fnc_all3DENSelected for values
    1: ARRAY - Attribute names. Only attributes which have boolean values are supported

    Returns:
    -
*/

if !(is3DEN) exitWith {};

private _types = param [0, ["Object"], [[]]];
private _attributes = param [1, []];
private _selected = [_types] call ENH_fnc_all3DENSelected;

if (_selected isEqualTo []) exitWith
{
    ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
};

collect3DENHistory
{
    {
        private _entity = _x;
        {
            _entity set3DENAttribute [_x, !((_entity get3DENAttribute _x) select 0)]; // Negate attribute value
        } forEach _attributes;
    } forEach _selected;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
