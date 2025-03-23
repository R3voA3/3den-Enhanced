#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-03-23

    Description:
    Inits search controls (button with icon and edit box).

    Parameter(s):
    0: CONTROL - Edit Control
    1: CONTROL - Button Control
    2: CODE - Code executed after the content of the edit control was changed. The edit control is passed to the code in _this

    Return Value:
    BOOLEAN - true

    Examples(s):
    [_ctrlEdit, _ctrlButton, "ENH_fnc_3DENRadio_searchList"] call ENH_fnc_initSearchControls;
*/

params
[
    ["_ctrlEdit", controlNull],
    ["_ctrlButton", controlNull],
    ["_onSearchCode", {}]
];

// Save controls for later
_ctrlEdit setVariable ["SearchButton", _ctrlButton];
_ctrlEdit setVariable ["OnSearchCode", _onSearchCode];
_ctrlButton setVariable ["SearchEdit", _ctrlEdit];

[_ctrlEdit, _ctrlButton, "ENH_fnc_3DENRadio_searchList"] call ENH_fnc_initSearchControls;

true
