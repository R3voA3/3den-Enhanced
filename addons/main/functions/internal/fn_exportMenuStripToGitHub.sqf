#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-10-15

    Description:
    Exports all ENH menustrip actions in markdown format for the Github 3den Enhanced wiki to the clipboard.

    Parameter(s):
    -

    Returns:
    -
*/

private _menuStipEntries = "configName _x select [0, 3] == 'ENH' && (getArray (_x >> 'items')) isEqualTo []" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items");
private _items = [];

_menuStipEntries apply
{
    _items pushBack
    [
        getText (_x >> "text"),
        getText (_x >> "action"),
        getText (_x >> "weblink"),
        getText (_x >> "wikiDescription")
    ];
};

_items = [_items, [], {_x select 0}] call BIS_fnc_sortBy;

private _export = format ["_**Number of added entries: %1**_", count _menuStipEntries] + endl + "___" + endl + endl;

{
    _x params ["_text", "_action", "_weblink", "_wikiDescription"];
    _export = _export + "# " + _text + endl + endl;

    _export = _export + "Description: " + _wikiDescription + endl + endl;

    if (_action != "") then
    {
        _export = _export + "Action: " + "```" + _action + "```" + endl;
    }
    else
    {
        _export = _export + "Weblink: " + _weblink + endl;
    };
} forEach _items;

uiNamespace setVariable ["display3DENCopy_data", ["Menu Strip Documentation", trim _export]];
findDisplay IDD_DISPLAY3DEN createDisplay "display3denCopy";
