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

private _uiWidth = 120;
private _uiTop = safeZoneY + 17 * GRID_H;

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

private _ctrlImgLeft = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 999999];

_ctrlImgLeft ctrlSetText "\x\enh\addons\main\data\left_ca.paa";

_ctrlImgLeft ctrlSetPosition
[
    0.5 - (_uiWidth) * 0.5 * GRID_W - 4 * GRID_W,
    _uiTop,
    5 * GRID_W,
    7 * GRID_H
];

private _ctrlImgRight = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 999999];

_ctrlImgRight ctrlSetText "\x\enh\addons\main\data\right_ca.paa";

_ctrlImgRight ctrlSetPosition
[
    0.5 + _uiWidth * 0.5 * GRID_W - GRID_W,
    _uiTop,
    5 * GRID_W,
    7 * GRID_H
];

private _ctrlBackground = _display3DEN ctrlCreate ["ctrlStaticBackground", 999999];

_ctrlBackground ctrlSetPosition
[
    0.5 - 0.5 * _uiWidth * GRID_W,
    _uiTop,
    _uiWidth * GRID_W,
    7 * GRID_H
];

private _ctrlEdit = _display3DEN ctrlCreate ["ctrlEdit", 645];

_ctrlEdit ctrlSetPosition
[
    0.5 - 0.5 * _uiWidth * GRID_W,
    _uiTop + GRID_H,
    _uiWidth * GRID_W,
    5 * GRID_H
];

private _ctrlBackgroundList = _display3DEN ctrlCreate ["ctrlStaticBackground", 999999];

private _ctrlListNBox = _display3DEN ctrlCreate ["ctrlListNBox", 999999];

_ctrlEdit setVariable ["ListNBox", _ctrlListNBox];
_ctrlListNBox setVariable ["Edit", _ctrlEdit];

_ctrlListNBox lnbAddColumn 8 * GRID_W;
_ctrlListNBox lnbAddColumn 120 * GRID_W;

_ctrlListNBox ctrlSetPosition
[
    0.5 - 0.5 * _uiWidth * GRID_W,
    _uiTop + 7 * GRID_H,
    _uiWidth * GRID_W,
    40 * GRID_H
];

_ctrlListNBox ctrlCommit 0;
_ctrlBackgroundList ctrlSetPosition ctrlPosition _ctrlListNBox;

_ctrlListNBox setVariable ["Background", _ctrlBackgroundList];

allControls _display3DEN apply {_x ctrlCommit 0};

private _commands = [];
private _items = "getText (_x >> 'action') != ''" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items");

{
    private _action = getText (_x >> "action");

    if (_action != "") then
    {
        private _display3DENName = getText (_x >> "text");
        private _shortcuts = getArray (_x >> "shortcuts");
        private _picture = getText (_x >> "picture");

        _commands pushBack
        [
            _display3DENName,
            _action,
            format ["%1,%2",configName _x , _display3DENName],
            [_shortcuts] call ENH_fnc_3DENShortcuts_parseShortcut,
            _picture
        ];
    };
} forEach _items;

_commands apply
{
    _x params ["_display3DENName", "_code", "_matchCodes", "_shortcuts", "_picture"];

    private _row = _ctrlListNBox lnbAddRow ["", _display3DENName, _shortcuts];

    _ctrlListNBox lnbSetPicture [[_row, 0], _picture];

    _ctrlListNBox lnbSetData [[_row, 0], _code];
    _ctrlListNBox lnbSetData [[_row, 1], _matchCodes];
};

_ctrlEdit setVariable ["Commands", _commands];
_ctrlListNBox lnbSort [1, false];

_ctrlEdit ctrlAddEventHandler ["EditChanged",
{
    params ["_ctrlEdit", "_text"];

    private _ctrlListNBox = _ctrlEdit getVariable ["ListNBox", controlNull];
    private _commands = _ctrlEdit getVariable ["Commands", []];

    lnbClear _ctrlListNBox;

    _commands apply
    {
        _x params ["_display3DENName", "_code", "_matchCodes", "_shortcuts", "_picture"];

        if (_text == "" || {toLower _text in toLower _display3DENName || {toLower _text in toLower _matchCodes}}) then
        {
            private _row = _ctrlListNBox lnbAddRow ["", _display3DENName, _shortcuts];

            _ctrlListNBox lnbSetPicture [[_row, 0], _picture];

            _ctrlListNBox lnbSetData [[_row, 0], _code];
            _ctrlListNBox lnbSetData [[_row, 1], _matchCodes];
        };
    };
}];

_ctrlListNBox ctrlAddEventHandler ["LBSelChanged",
{
    params ["_ctrlListNBox", "_row"];

    private _code = _ctrlListNBox lnbData [_row, 0];

    if (_code != "") then
    {
        call compile _code;
    };
}];


_ctrlEdit ctrlAddEventHandler ["SetFocus",
{
    params ["_ctrlEdit"];

    private _ctrlListNBox = _ctrlEdit getVariable ["ListNBox", controlNull];
    private _ctrlBackgroundList = _ctrlListNBox getVariable ["Background", controlNull];

    _ctrlBackgroundList ctrlSetPositionH 40 * GRID_H;
    _ctrlBackgroundList ctrlCommit 0.2;

    _ctrlListNBox ctrlSetPositionH 40 * GRID_H;
    _ctrlListNBox ctrlCommit 0.2;
}];

_ctrlEdit ctrlAddEventHandler ["KillFocus",
{
    params ["_ctrlEdit"];

    private _ctrlListNBox = _ctrlEdit getVariable ["ListNBox", controlNull];

    private _ctrlBackgroundList = _ctrlListNBox getVariable ["Background", controlNull];

    if (focusedCtrl ctrlParent _ctrlEdit != _ctrlListNBox) then
    {
        _ctrlBackgroundList ctrlSetPositionH 0;
        _ctrlBackgroundList ctrlCommit 0.2;

        _ctrlListNBox ctrlSetPositionH 0;
        _ctrlListNBox ctrlCommit 0.2;
    };
}];

_ctrlListNBox ctrlAddEventHandler ["KillFocus",
{
    params ["_ctrlListNBox"];

    private _ctrlEdit = _ctrlListNBox getVariable ["Edit", controlNull];
    private _ctrlBackgroundList = _ctrlListNBox getVariable ["Background", controlNull];

    if (focusedCtrl ctrlParent _ctrlListNBox != _ctrlEdit) then
    {
        _ctrlBackgroundList ctrlSetPositionH 0;
        _ctrlBackgroundList ctrlCommit 0.2;

        _ctrlListNBox ctrlSetPositionH 0;
        _ctrlListNBox ctrlCommit 0.2;
    };
}];
