#include "\x\enh\addons\main\script_component.hpp"
#include "\x\enh\addons\main\functions\GUI\3DENCommandPalette\defines.inc"

/*
    Author: R3vo

    Date: 2025-07-13

    Description:
    Adds a command to the command palette.

    Parameter(s):
    0: STRING - Command action
    0: STRING - Command picture
    0: STRING - Command shortcuts (only two are supported, comma separated)
    0: STRING - Command text
    0: STRING - Command description, optional, default is auto generated

    Return Value:
    NOTHING
*/

params ["_action", "_picture", "_shortcuts", "_text", ["_description", ""]];

private _rootDisplay = findDisplay IDD_DISPLAY3DEN getVariable ["ENH_3DENCommandPalette_Display", displayNull];

private _rowIndex = _rootDisplay getVariable ["ENH_3DENCommandPalette_RowIndex", 0];
private _commandButtons = _rootDisplay getVariable ["ENH_3DENCommandPalette_CommandButtons", []];

private _ctrlGroupCommands = _rootDisplay getVariable ["ENH_3DENCommandPalette_ControlGroupCommands", controlNull];
private _ctrlBackground = _rootDisplay ctrlCreate ["ctrlStaticFooter", -1, _ctrlGroupCommands];
private _ctrlPicture = _rootDisplay ctrlCreate ["ctrlStaticPictureKeepAspect", -1, _ctrlGroupCommands];
private _ctrlTitle = _rootDisplay ctrlCreate ["ctrlStatic", -1, _ctrlGroupCommands];
private _ctrlDescription = _rootDisplay ctrlCreate ["ctrlStatic", -1, _ctrlGroupCommands];
private _ctrlShortcut1 = _rootDisplay ctrlCreate ["ctrlStatic", -1, _ctrlGroupCommands];
private _ctrlShortcut2 = _rootDisplay ctrlCreate ["ctrlStatic", -1, _ctrlGroupCommands];
private _ctrlFakeButton = _rootDisplay ctrlCreate ["ctrlButton", -1, _ctrlGroupCommands];

_ctrlBackground ctrlSetPosition
[
    GRID_W,
    _rowIndex * 8 * GRID_H,
    (UI_W - 1 - 1) * GRID_W,
    7 * GRID_H
];

_ctrlPicture ctrlSetPosition
[
    2.5 * GRID_W,
    _rowIndex * 8 * GRID_H + 1 * GRID_H,
    5 * GRID_W, 5 * GRID_H
];

_ctrlTitle ctrlSetPosition
[
    8 * GRID_W, _rowIndex * 8 * GRID_H,
    (UI_W - 8 - 1 - 1) * GRID_W,
    4 * GRID_H
];

_ctrlDescription ctrlSetPosition
[
    8 * GRID_W,
    _rowIndex * 8 * GRID_H + 4 * GRID_H,
    (UI_W - 8 - 1 - 1) * GRID_W,
    3 * GRID_H
];

_ctrlShortcut1 ctrlSetPosition
[
    (UI_W - 30 - 1) * GRID_W,
    _rowIndex * 8 * GRID_H,
    30 * GRID_W,
    3 * GRID_H
];
_ctrlShortcut2 ctrlSetPosition
[
    (UI_W - 30 - 1) * GRID_W,
    _rowIndex * 8 * GRID_H + 3 * GRID_H,
    30 * GRID_W,
    3 * GRID_H
];

_ctrlFakeButton ctrlSetPosition
[
    GRID_W,
    _rowIndex * 8 * GRID_H,
    (UI_W - 1 - 1) * GRID_W,
    7 * GRID_H
];

_ctrlFakeButton ctrlSetFade 1;

_ctrlTitle ctrlSetFontHeight (4 * GRID_H);
_ctrlDescription ctrlSetFontHeight (3 * GRID_H);
_ctrlShortcut1 ctrlSetFontHeight (3 * GRID_H);
_ctrlShortcut2 ctrlSetFontHeight (3 * GRID_H);

_ctrlDescription ctrlSetTextColor [0.5, 0.5, 0.5, 1];

_ctrlPicture ctrlSetText _picture;

_ctrlTitle ctrlSetText _text;
_ctrlTitle ctrlSetTooltip _text;

_ctrlDescription ctrlSetText _description;
_ctrlDescription ctrlSetTooltip _description;

_shortcuts splitString "," params [["_shortcut1", ""], ["_shortcut2", ""]];

_ctrlShortcut1 ctrlSetText trim _shortcut1 ;
_ctrlShortcut1 ctrlSetTooltip  _shortcut1;

_ctrlShortcut2 ctrlSetText trim _shortcut2;
_ctrlShortcut2 ctrlSetTooltip trim _shortcut2;

_ctrlFakeButton ctrlSetTooltip (_text + endl + _description + endl + _shortcuts); // TODO: Make the font smaller 2025-07-10 R3vo

_ctrlFakeButton setVariable ["Background", _ctrlBackground];
_ctrlFakeButton setVariable ["Action", _action];

_ctrlFakeButton ctrlAddEventHandler ["MouseEnter",
{
    params ["_ctrlButton"];
    (_ctrlButton getVariable "Background") ctrlSetBackgroundColor
    [
        profileNamespace getVariable ["GUI_BCG_RGB_R", 0.77],
        profileNamespace getVariable ["GUI_BCG_RGB_G", 0.51],
        profileNamespace getVariable ["GUI_BCG_RGB_B", 0.08],
        1
    ];
}];

_ctrlFakeButton ctrlAddEventHandler ["MouseExit",
{
    params ["_ctrlButton"];
    (_ctrlButton getVariable "Background") ctrlSetBackgroundColor [0, 0, 0, 0.3];
}];

_ctrlFakeButton ctrlAddEventHandler ["MouseButtonDown",
{
    params ["_ctrlFakeButton", "_key"];

    if (_key == 0) then
    {
        _ctrlFakeButton call ENH_fnc_3DENCommandPalette_execCommand;
    };
}];

_ctrlFakeButton ctrlAddEventHandler ["KeyDown",
{
    params ["_ctrlFakeButton", "_key"];

    if (_key in [DIK_RETURN, DIK_NUMPADENTER]) then
    {
        _ctrlFakeButton call ENH_fnc_3DENCommandPalette_execCommand;
    };
}];

private _controls = [_ctrlBackground, _ctrlPicture, _ctrlTitle, _ctrlDescription, _ctrlShortcut1, _ctrlShortcut2, _ctrlFakeButton];

_controls apply {_x ctrlCommit 0};

_commandButtons pushBack _ctrlFakeButton;
_rootDisplay setVariable ["ENH_3DENCommandPalette_CommandButtons", _commandButtons];
_rootDisplay setVariable ["ENH_3DENCommandPalette_RowIndex", _rowIndex + 1];

nil
