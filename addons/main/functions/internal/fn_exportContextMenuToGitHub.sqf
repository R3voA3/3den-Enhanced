#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-05-09

    Description:
    Exports all ENH context menu actions in markdown format for the Github 3den Enhanced wiki to the clipboard.

    Parameter(s):
    -

    Return Value:
    -
*/

private _contextMenuEntries = "configName _x select [0, 3] == 'ENH' && (getArray (_x >> 'items')) isEqualTo []" configClasses (configFile >> "Display3DEN" >> "ContextMenu" >> "Items");
private _items = [];

_contextMenuEntries apply
{
    _items pushBack
    [
        getText (_x >> "text"),
        getText (_x >> "action"),
        getText (_x >> "wikiDescription")
    ];
};

_items = [_items, [], {_x select 0}] call BIS_fnc_sortBy;

private _export = format ["_**Number of added entries: %1**_", count _contextMenuEntries] + endl + "___" + endl + endl;

{
    _x params ["_text", "_action", "_wikiDescription"];
    _export = _export + "# " + _text + endl + endl;
    _export = _export + "Description: " + _wikiDescription + endl + endl;
    _export = _export + "Action: " + "```" + _action + "```" + endl;
} forEach _items;

uiNamespace setVariable ["display3DENCopy_data", ["Context Menu Documentation", trim _export]];
findDisplay IDD_DISPLAY3DEN createDisplay "display3denCopy";
