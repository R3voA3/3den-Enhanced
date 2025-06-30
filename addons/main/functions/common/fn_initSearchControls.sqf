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
    [_ctrlEdit, _ctrlButton, ENH_fnc_3DENRadio_searchList] call ENH_fnc_initSearchControls;
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

// Handle search button
_ctrlEdit ctrlAddEventHandler ["EditChanged",
{
    params ["_ctrlEdit", "_newText"];

    private _image = [TEXTURE_SEARCH_END, TEXTURE_SEARCH_START] select (_newText == "");

    _ctrlEdit getVariable "SearchButton" ctrlSetText _image;
    _ctrlEdit call (_ctrlEdit getVariable "OnSearchCode");
}];

// Handle search button
_ctrlButton ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    // Change search button icon and clear edit control to reset tree view filter
    _ctrlButton getVariable "SearchEdit" ctrlSetText "";
    _ctrlButton ctrlSetText TEXTURE_SEARCH_START;
}];

true
