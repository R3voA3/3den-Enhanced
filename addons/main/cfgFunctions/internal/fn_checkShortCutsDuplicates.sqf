#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-08-31

    Description:
    Check for duplicated shortcuts in the context menu and menu strip.

    Parameter(s):
    -

    Returns:
    ARRAY:
        0: BOOLEAN - True if no duplicates in context menu
        1: BOOLEAN - True if no duplicates in menu strip

*/

private _contextMenuEntries = "true" configClasses (configFile >> "Display3DEN" >> "ContextMenu" >> "Items");
private _contextMenuShortCuts = [];
private _contextMenuShortCutsUnique = [];

private _menuStripEntries = "true" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items");
private _menuStripShortCuts = [];
private _menuStripShortCutsUnique = [];

{
    private _shortCut = getArray (_x >> "shortcuts");
    _shortCut = _shortCut # 0;
    if ((_shortCut isNotEqualTo []) && !(_shortCut isEqualType 0)) then
    {
        _shortCut = _shortCut splitString " ";
        _shortCut = _shortCut joinString "";
        _contextMenuShortCuts pushBack _shortCut;
        _contextMenuShortCutsUnique pushBackUnique _shortCut;
    };
} forEach _contextMenuEntries;

{
    _shortCut = getArray (_x >> "shortcuts");
    _shortCut = _shortCut # 0;
    if ((_shortCut isNotEqualTo []) && (_shortCut isEqualType 0)) then
    {
        _shortCut = _shortCut splitString " ";
        _shortCut = _shortCut joinString "";
        _menuStripShortCuts pushBack _shortCut;
        _menuStripShortCutsUnique pushBackUnique _shortCut;
    };
} forEach _menuStripEntries;

[_contextMenuShortCuts isEqualTo _contextMenuShortCutsUnique, _menuStripShortCuts isEqualTo _menuStripShortCutsUnique]
