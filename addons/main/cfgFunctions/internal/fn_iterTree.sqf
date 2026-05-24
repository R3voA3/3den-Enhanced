#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-07-23

    Description:
    Logs all menu strip entries to the RPT.

    Parameter(s):
    0: CONTROL - A menu strip control

    Return Value:
    NOTHING
*/

params [["_menuStrip", controlNull]];

private _fnc_iterTree =
{
    params ["_menuStrip", "_path"];

    private _indent = "";

    {
        _indent = _indent + "    ";
    } forEach _path;

    diag_log format ["%1Menu item %2: %3", _indent, _path, _menuStrip menuText _path];

    if ((_menuStrip menuText _path) == "Open Command Palette") then
    {
        _menuStrip menuSetShortcut [_path, (2048 + 0x16)];
    };

    private _size = _menuStrip menuSize _path;

    if (_size > 0) then
    {
        for "_i" from 0 to _size do
        {
            [_menuStrip, _path + [_i]] call _fnc_iterTree;
        };
    };
};

[_menuStrip, []] call _fnc_iterTree;

nil
