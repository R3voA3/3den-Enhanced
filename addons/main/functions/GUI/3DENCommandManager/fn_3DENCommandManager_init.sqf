#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-21

    Description:
    This is an awesome description.

    Parameter(s):
    0: ARRAY - Some description, optional, default false

    Return Value:
    ARRAY - True on success, false if failed

    Examples(s):
    [] call ENH_fnc_missionDisplay;
*/

disableSerialization;

#define GROUP_H 51
#define UI_W 120
#define UI_Y (WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H)

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

_display3DEN getVariable ["ENH_CommandPallet_Controls", []] apply {ctrlDelete _x}; // TODO: remove later 2025-06-22 R3vo

private _ctrlGroup = _display3DEN ctrlCreate ["ctrlControlsGroupNoScrollbars", 1001];
private _ctrlImgLeft = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 1002, _ctrlGroup];
private _ctrlImgRight = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 1003, _ctrlGroup];
private _ctrlBackground = _display3DEN ctrlCreate ["ctrlStaticBackground", 1004, _ctrlGroup];
private _ctrlEdit = _display3DEN ctrlCreate ["ctrlEdit", 645, _ctrlGroup];
private _ctrlListNBox = _display3DEN ctrlCreate ["ctrlListNBox", 1006, _ctrlGroup];
private _ctrlFooter = _display3DEN ctrlCreate ["ctrlStaticFooter", 1007, _ctrlGroup];

_ctrlGroup ctrlSetPosition
[
    0.5 - UI_W * 0.5 * GRID_W - 4 * GRID_W,
    UI_Y,
    UI_W * GRID_W,
    GROUP_H * GRID_H
];

_ctrlImgLeft ctrlSetText "\x\enh\addons\main\data\left_ca.paa";

_ctrlImgLeft ctrlSetPosition
[
    0,
    0,
    5 * GRID_W,
    7 * GRID_H
];

_ctrlImgRight ctrlSetText "\x\enh\addons\main\data\right_ca.paa";

_ctrlImgRight ctrlSetPosition
[
    UI_W * GRID_W - 5 * GRID_W,
    0,
    5 * GRID_W,
    7 * GRID_H
];

_ctrlBackground ctrlSetPosition
[
    4 * GRID_W,
    0,
    (UI_W - 8) * GRID_W,
    GROUP_H * GRID_H
];

_ctrlEdit ctrlSetPosition
[
    4 * GRID_W,
    GRID_H,
    (UI_W - 8) * GRID_W,
    5 * GRID_H
];

_ctrlFooter ctrlSetPosition
[
    4 * GRID_W,
    GROUP_H * GRID_H,
    (UI_W - 8) * GRID_W,
    CTRL_DEFAULT_H
];

_ctrlFooter ctrlSetText "HOLD CTRL TO PREVENT THE BACKGROUND FROM SCROLLING";

_ctrlListNBox lnbAddColumn 8 * GRID_W;
_ctrlListNBox lnbAddColumn 110 * GRID_W;

_ctrlListNBox ctrlSetPosition
[
    4 * GRID_W,
    7 * GRID_H,
    (UI_W - 8) * GRID_W,
    39 * GRID_H
];

private _fnc_addCommand =
{
    params ["_action", "_picture", "_shortcuts", "_text"];

    private _row = _ctrlListNBox lnbAddRow ["", _text, _shortcuts];

    _ctrlListNBox lnbSetPicture [[_row, 0], _picture];
    _ctrlListNBox lnbSetData [[_row, 0], _action];
};

private _commands = [];
private _menuStripItems = "getText (_x >> 'action') != ''" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items");
private _cfg3DENCommands = "getText (_x >> 'action') != ''" configClasses (configFile >> "Cfg3DEN" >> "ENH_Command_Pallet_Commands");

{
    private _action = getText (_x >> "action");
    private _picture = getText (_x >> "picture");
    private _shortcuts = getArray (_x >> "shortcuts");
    private _text = getText (_x >> "text");

    private _shortcuts = [_shortcuts] call ENH_fnc_3DENShortcuts_parseShortcut;

    _commands pushBack
    [
        _action,
        _picture,
        _shortcuts,
        _text
    ];

    // diag_log _text;

    [_action, _picture, _shortcuts, _text] call _fnc_addCommand;
} forEach (_menuStripItems + _cfg3DENCommands);

_ctrlListNBox lnbSort [1, false];

private _fnc_search =
{
    params ["_ctrlEdit", "_searchText"];

    private _ctrlListNBox = findDisplay IDD_DISPLAY3DEN getVariable ["ENH_CommandPallet_ListNBox", controlNull];
    private _commands = findDisplay IDD_DISPLAY3DEN getVariable ["ENH_CommandPallet_Commands", []];

    lnbClear _ctrlListNBox;

    _commands apply
    {
        _x params ["_action", "_picture", "_shortcuts", "_text"];

        if (_searchText == "" || {toLower _searchText in toLower _text}) then
        {
            private _row = _ctrlListNBox lnbAddRow ["", _text, _shortcuts];

            _ctrlListNBox lnbSetPicture [[_row, 0], _picture];
            _ctrlListNBox lnbSetData [[_row, 0], _action];
        };
    };
};

private _fnc_mouseHandler =
{
    params ["_ctrlGroup", "", "", "_mouseOver"];

    _ctrlGroup ctrlSetPositionH ([7 * GRID_H, GROUP_H * GRID_H] select _mouseOver);
    _ctrlGroup ctrlCommit 0;

    if (ctrlPosition _ctrlGroup select 3 < GROUP_H * GRID_H) then
    {
        findDisplay IDD_DISPLAY3DEN getVariable "ENH_CommandPallet_Edit" ctrlSetText "";
    };
};

private _fnc_execCommand =
{
    params ["_ctrlListNBox", "_row"];

    private _code = _ctrlListNBox lnbData [_row, 0];

    if (_code != "") then
    {
        call compile _code;
    };
};

_ctrlGroup ctrlAddEventHandler ["MouseMoving", _fnc_mouseHandler];
_ctrlEdit ctrlAddEventHandler ["EditChanged", _fnc_search];
_ctrlListNBox ctrlAddEventHandler ["LBDblClick", _fnc_execCommand];

private _controls = [_ctrlListNBox, _ctrlEdit, _ctrlBackground, _ctrlImgLeft, _ctrlImgRight, _ctrlGroup];

_controls apply {_x ctrlCommit 0};

_display3DEN setVariable ["ENH_CommandPallet_Controls", _controls]; // TODO: remove later 2025-06-22 R3vo
_display3DEN setVariable ["ENH_CommandPallet_Commands", _commands];
_display3DEN setVariable ["ENH_CommandPallet_ListNBox", _ctrlListNBox];
_display3DEN setVariable ["ENH_CommandPallet_Edit", _ctrlEdit];
