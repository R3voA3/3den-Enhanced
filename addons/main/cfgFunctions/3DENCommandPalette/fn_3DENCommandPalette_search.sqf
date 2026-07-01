#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-07-13

    Description:
    Filters the command palette.

    Parameter(s):
    0: CONTROL: Edit control
    1: STRING: Search string

    Return Value:
    NOTHING
*/

params ["_ctrlEdit", "_searchText"];

private _rootDisplay = findDisplay IDD_DISPLAY3DEN getVariable ["ENH_3DENCommandPalette_Display", displayNull];
private _ctrlGroupCommands = _rootDisplay getVariable ["ENH_3DENCommandPalette_ControlGroupCommands", controlNull];
private _commands = _rootDisplay getVariable ["ENH_3DENCommandPalette_Commands", []];

allControls _ctrlGroupCommands apply {ctrlDelete _x};

_rootDisplay setVariable ["ENH_3DENCommandPalette_ButtonIndex", -1];
_rootDisplay setVariable ["ENH_3DENCommandPalette_RowIndex", 0];
_rootDisplay setVariable ["ENH_3DENCommandPalette_CommandButtons", []];

_commands apply
{
    _x params ["", "", "", "_text"];

    if (_searchText == "" || {toLower _searchText in toLower _text}) then
    {
        _x call ENH_fnc_3DENCommandPalette_addCommand;
    };
};

nil
