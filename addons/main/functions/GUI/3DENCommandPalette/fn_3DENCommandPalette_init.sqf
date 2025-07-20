#include "\x\enh\addons\main\script_component.hpp"
#include "\x\enh\addons\main\functions\GUI\3DENCommandPalette\defines.inc"

/*
    Author: R3vo

    Date: 2025-06-21

    Description:
    Opens the 3DEN Command Palette.

    Parameter(s):
    -

    Return Value:
    BOOLEAN: True
*/

disableSerialization;

private _display3DEN = findDisplay IDD_DISPLAY3DEN;
private _rootDisplay = _display3DEN createDisplay "ENH_DisplayEmpty";

private _ctrlGroup = _rootDisplay ctrlCreate ["ctrlControlsGroupNoScrollbars", -1];
private _ctrlBackground = _rootDisplay ctrlCreate ["ctrlStaticBackground", -1, _ctrlGroup];
private _ctrlEdit = _rootDisplay ctrlCreate ["ctrlEdit", -1, _ctrlGroup];
private _ctrlButtonSearch = _rootDisplay ctrlCreate ["ctrlButtonSearch", -1, _ctrlGroup];
private _ctrlButtonExit = _rootDisplay ctrlCreate [configFile >> "Display3DEN" >> "Controls" >> "ButtonExit", -1, _ctrlGroup];
private _ctrlButtonHelp = _rootDisplay ctrlCreate ["ctrlButtonPictureKeepAspect", -1, _ctrlGroup];
private _ctrlFooter = _rootDisplay ctrlCreate ["ctrlStaticFooter", -1, _ctrlGroup];
private _ctrlGroupCommands = _rootDisplay ctrlCreate ["ctrlControlsGroup", -1, _ctrlGroup];

[_ctrlEdit, _ctrlButtonSearch] call ENH_fnc_initSearchControls;

_rootDisplay setVariable ["ENH_3DENCommandPalette_ControlGroupCommands", _ctrlGroupCommands];
_rootDisplay setVariable ["ENH_3DENCommandPalette_RowIndex", 0];
_rootDisplay setVariable ["ENH_3DENCommandPalette_CommandButtons", []];
_display3DEN setVariable ["ENH_3DENCommandPalette_Display", _rootDisplay];

_ctrlGroup ctrlSetPosition
[
    0.5 - UI_W * 0.5 * GRID_W - 4 * GRID_W,
    UI_Y,
    UI_W * GRID_W,
    GROUP_H * GRID_H
];

_ctrlBackground ctrlSetPosition
[
    0,
    0,
    UI_W * GRID_W,
    (GROUP_H - 1) * GRID_H
];

_ctrlEdit ctrlSetPosition
[
    GRID_W,
    GRID_H,
    (UI_W - 2 - 5 - 6 - 6) * GRID_W,
    5 * GRID_H
];

_ctrlButtonSearch ctrlSetPosition
[
    (UI_W - 1 - 5 - 6- 6) * GRID_W,
    GRID_H,
    5 * GRID_W,
    5 * GRID_H
];

_ctrlButtonHelp ctrlSetPosition
[
    (UI_W - 1 - 5 - 6) * GRID_W,
    GRID_H,
    5 * GRID_W,
    5 * GRID_H
];

_ctrlButtonExit ctrlSetPosition
[
    (UI_W - 1 - 5) * GRID_W,
    GRID_H,
    5 * GRID_W,
    5 * GRID_H
];

_ctrlButtonHelp ctrlSetURL "https://github.com/R3voA3/3den-Enhanced/wiki/3DEN-Command-Palette";
_ctrlButtonHelp ctrlSetText "a3\3den\data\displays\display3den\toolbar\help_tutorial_ca.paa";

_ctrlFooter ctrlSetPosition
[
    1 * GRID_W,
    GROUP_H * GRID_H - CTRL_DEFAULT_H,
    (UI_W - 2) * GRID_W,
    3 * GRID_H
];

_ctrlGroupCommands ctrlSetPosition
[
    0,
    7 * GRID_H,
    UI_W * GRID_W,
    38 * GRID_H
];

if ((_rootDisplay getVariable ["ENH_3DENCommandPalette_Commands", []]) isEqualTo []) then
{
    _rootDisplay setVariable ["ENH_3DENCommandPalette_Commands", call ENH_fnc_3DENCommandPalette_collectCommands];
};

[_ctrlEdit, ""] call ENH_fnc_3DENCommandPalette_search;

_ctrlEdit ctrlAddEventHandler ["EditChanged", ENH_fnc_3DENCommandPalette_search];

_ctrlButtonExit ctrlAddEventHandler ["ButtonClick",
{
    findDisplay IDD_DISPLAY3DEN getVariable "ENH_3DENCommandPalette_Display" closeDisplay 1;
}];

_rootDisplay displayAddEventHandler ["KeyDown",
{
    params ["_rootDisplay", "_key"];

    if !(_key in [DIK_UP, DIK_DOWN]) exitWith {true};

    private _ctrlGroupCommands = _rootDisplay getVariable ["ENH_3DENCommandPalette_ControlGroupCommands", controlNull];
    private _buttonIndex = _rootDisplay getVariable ["ENH_3DENCommandPalette_ButtonIndex", -1];
    private _allButtons = _rootDisplay getVariable ["ENH_3DENCommandPalette_CommandButtons", []];

    // Search didn't find anything, so no buttons
    if (_allButtons isEqualTo []) exitWith {};

    if (_key == DIK_DOWN) then
    {
        _buttonIndex = _buttonIndex + 1 min (count _allButtons - 1);
    }
    else
    {
        _buttonIndex = _buttonIndex - 1 max 0;
    };

    private _targetButton = _allButtons select _buttonIndex;

    // We need to delay the focusing by a frame, otherwise engine focusing will overwrite our focus
    addMissionEventHandler ["EachFrame",
    {
        _thisArgs params ["_targetButton", "_frameNo"];

        if (diag_frameNo >= (_frameNo + 1)) then
        {
            ctrlSetFocus _targetButton;
            removeMissionEventHandler [_thisEvent, _thisEventHandler];
        };
    }, [_targetButton, diag_frameNo]];

    // Reset previous background color if it was set
    ((_rootDisplay getVariable ["ENH_3DENCommandPalette_TargetButton", controlNull]) getVariable ["Background", controlNull]) ctrlSetBackgroundColor [0, 0, 0, 0.3];

    (_targetButton getVariable "Background") ctrlSetBackgroundColor
    [
        profileNamespace getVariable ["GUI_BCG_RGB_R", 0.77],
        profileNamespace getVariable ["GUI_BCG_RGB_G", 0.51],
        profileNamespace getVariable ["GUI_BCG_RGB_B", 0.08],
        1
    ];

    _ctrlGroupCommands ctrlSetScrollValues [1 / (count _allButtons) * _buttonIndex, -1];

    _rootDisplay setVariable ["ENH_3DENCommandPalette_ButtonIndex", _buttonIndex];
    _rootDisplay setVariable ["ENH_3DENCommandPalette_TargetButton", _targetButton];
}];

_ctrlGroup ctrlCommit 0;
allControls _ctrlGroup apply {_x ctrlCommit 0};

ctrlSetFocus _ctrlEdit;

true
