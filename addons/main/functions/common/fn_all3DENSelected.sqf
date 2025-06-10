#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-12-03

    Description:
    Puts all selected Eden entities into one array for easy access.

    Parameter(s):
    0: ARRAY - Array of strings. Entity types to return. For possible values see https:// community.bistudio.com/wiki/get3DENSelected
        Default: ["Object", "Group", "Trigger", "Logic", "Waypoint", "Marker"]

    Returns:
    ARRAY - List of selected entities

    Example(s):
    [] call ENH_fnc_all3DENSelected; // Returns all selected entities no matter what type

*/

params [["_whiteList", ["Object", "Group", "Trigger", "Logic", "Waypoint", "Marker"]]];

private _return = [];

{
    _return append (get3DENSelected _x);
} forEach _whiteList;

_return
