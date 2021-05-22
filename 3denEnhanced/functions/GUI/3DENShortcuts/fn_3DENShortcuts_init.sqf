/*
  Author: R3vo

  Date: 2021-04-12

  Description:
  Creates a GUI which shows all Eden editor shortcuts.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"
#define COL_POS [0, 0.04, 0.5]
#define COL_POS_FILTER [0, 0.07, 0.53]

#define DIALOG_W 100
#define DIALOG_H 22
#define DIALOG_LEFT 0.5 - DIALOG_W / 2 * GRID_W
#define DIALOG_RIGHT 0.5 + DIALOG_W / 2 * GRID_W

disableSerialization;

private _display = findDisplay IDD_3DEN createDisplay "RscDisplayEmpty";

_display ctrlCreate ["ctrlStaticBackgroundDisable", IDC_SHORTCUTS_DISABLEDBG];
_display ctrlCreate ["ctrlStaticBackgroundDisableTiles", IDC_SHORTCUTS_DISABLEDTILESBG];

private _ctrlTitle = _display ctrlCreate ["ctrlStaticTitle", IDC_SHORTCUTS_TITLE];
_ctrlTitle ctrlSetPosition [DIALOG_LEFT, safeZoneY + 17 * GRID_H, DIALOG_W * GRID_W, 5 * GRID_H];
_ctrlTitle ctrlSetText localize "STR_ENH_3DENSHORTCUTS_DISPLAYNAME";
_ctrlTitle ctrlCommit 0;

private _ctrlContentBackground = _display ctrlCreate ["ctrlStatic", IDC_SHORTCUTS_CONTENTBG];
_ctrlContentBackground ctrlSetPosition [DIALOG_LEFT, safeZoneY + 22 * GRID_H + 5 * GRID_H, DIALOG_W * GRID_W, (DIALOG_H + 7) * GRID_H];
_ctrlContentBackground ctrlSetBackgroundColor [COLOR_BACKGROUND_RGBA];
_ctrlContentBackground ctrlCommit 0;

private _ctrlButtonClose = _display ctrlCreate ["ctrlButtonClose", IDC_SHORTCUTS_CLOSE];
_ctrlButtonClose ctrlSetPosition [DIALOG_RIGHT - 26 * GRID_W, safeZoneY + 22 * GRID_H + DIALOG_H * GRID_H + 6 * GRID_H, 25 * GRID_W, 5 * GRID_H];
_ctrlButtonClose ctrlCommit 0;

private _ctrlSearch = _display ctrlCreate ["ctrlEdit", IDC_SHORTCUTS_SEARCH];
_ctrlSearch ctrlSetPosition [DIALOG_LEFT + GRID_W, safeZoneY + 22 * GRID_H + DIALOG_H * GRID_H + 6 * GRID_H, 25 * GRID_W, 5 * GRID_H];
_ctrlSearch ctrlCommit 0;

private _ctrlSearchIcon = _display ctrlCreate ["ctrlStaticPictureKeepAspect", IDC_SHORTCUTS_SEARCHICON];
_ctrlSearchIcon ctrlSetPosition [DIALOG_LEFT + 26 * GRID_W, safeZoneY + 22 * GRID_H + DIALOG_H * GRID_H + 6 * GRID_H, 5 * GRID_W, 5 * GRID_H];
_ctrlSearchIcon ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
_ctrlSearchIcon ctrlCommit 0;

private _ctrlContent = _display ctrlCreate ["ctrlListNBox", IDC_SHORTCUTS_CONTENT];
_ctrlContent ctrlSetPosition [DIALOG_LEFT, safeZoneY + 28 * GRID_H, DIALOG_W * GRID_W, DIALOG_H * GRID_H];
_ctrlContent ctrlCommit 0;

private _ctrlFilterBackground = _display ctrlCreate ["ctrlStatic", IDC_SHORTCUTS_FILTERBG];
_ctrlFilterBackground ctrlSetPosition [DIALOG_LEFT, safeZoneY + 22 * GRID_H, DIALOG_W * GRID_W,  5 * GRID_H];
_ctrlFilterBackground ctrlCommit 0;
_ctrlFilterBackground ctrlSetBackgroundColor [0, 0, 0, 1];

private _ctrlFilter = _display ctrlCreate ["ctrlListNBox", IDC_SHORTCUTS_FILTER];
_ctrlFilter ctrlSetPosition [DIALOG_LEFT, safeZoneY + 22 * GRID_H, DIALOG_W * GRID_W, 5 * GRID_H];
_ctrlFilter ctrlCommit 0;

_ctrlContent lnbSetColumnsPos COL_POS;
_ctrlFilter lnbSetColumnsPos COL_POS_FILTER;

_ctrlFilter lnbAddRow ["", "Action", "Shortcuts"];

[_ctrlFilter, _ctrlContent, [0, 1, 2]] call BIS_fnc_initListNBoxSorting;

//Add search EH
_ctrlSearch ctrlAddEventHandler ["keyDown",
{
  params ["_ctrlSearch"];
  [ctrlparent _ctrlSearch displayCtrl IDC_SHORTCUTS_CONTENT, ctrlText _ctrlSearch] call ENH_fnc_3DENShortcuts_fillList;
}];

//Focus search so user can search right away
ctrlSetFocus _ctrlSearch;

private _DIKKeyCodes =
[
  "0", 0x0B,
  "1", 0x02,
  "2", 0x03,
  "3", 0x04,
  "4", 0x05,
  "5", 0x06,
  "6", 0x07,
  "7", 0x08,
  "8", 0x09,
  "9", 0x0A,
  "A", 0x1E,
  "B", 0x30,
  "C", 0x2E,
  "D", 0x20,
  "E", 0x12,
  "F", 0x21,
  "G", 0x22,
  "H", 0x23,
  "I", 0x17,
  "J", 0x24,
  "K", 0x25,
  "L", 0x26,
  "M", 0x32,
  "N", 0x31,
  "O", 0x18,
  "P", 0x19,
  "Q", 0x10,
  "R", 0x13,
  "S", 0x1F,
  "T", 0x14,
  "U", 0x16,
  "V", 0x2F,
  "W", 0x11,
  "X", 0x2D,
  "Y", 0x15,
  "Z", 0x2C,
  "AT", 0x91,
  "F1", 0x3B,
  "F2", 0x3C,
  "F3", 0x3D,
  "F4", 0x3E,
  "F5", 0x3F,
  "F6", 0x40,
  "F7", 0x41,
  "F8", 0x42,
  "F9", 0x43,
  "UP", 0xC8,
  "ADD", 0x4E,
  "END", 0xCF,
  "F10", 0x44,
  "F11", 0x57,
  "F12", 0x58,
  "F13", 0x64,
  "F14", 0x65,
  "F15", 0x66,
  "TAB", 0x0F,
  "APPS", 0xDD,
  "BACK", 0x0E,
  "DOWN", 0xD0,
  "HOME", 0xC7,
  "LEFT", 0xCB,
  "LWIN", 0xDB,
  "PGDN", 0xD1,
  "PGUP", 0xC9,
  "RWIN", 0xDC,
  "LALT", 0x38,
  "RALT", 0xB8,
  "COLON", 0x92,
  "COMMA", 0x33,
  "GRAVE", 0x29,
  "LMENU", 0x38,
  "MINUS", 0x0C,
  "PAUSE", 0xC5,
  "PRIOR", 0xC9,
  "RIGHT", 0xCD,
  "RMENU", 0xB8,
  "SLASH", 0x35,
  "SPACE", 0x39,
  "DELETE", 0xD3,
  "DIVIDE", 0xB5,
  "EQUALS", 0x0D,
  "ESCAPE", 0x01,
  "INSERT", 0xD2,
  "LSHIFT", 0x2A,
  "PERIOD", 0x34,
  "RETURN", 0x1C,
  "RSHIFT", 0x36,
  "SCROLL", 0x46,
  "CAPITAL", 0x3A,
  "DECIMAL", 0x53,
  "NUMLOCK", 0x45,
  "NUMPAD0", 0x52,
  "NUMPAD1", 0x4F,
  "NUMPAD2", 0x50,
  "NUMPAD3", 0x51,
  "NUMPAD4", 0x4B,
  "NUMPAD5", 0x4C,
  "NUMPAD6", 0x4D,
  "NUMPAD7", 0x47,
  "NUMPAD8", 0x48,
  "NUMPAD9", 0x49,
  "UPARROW", 0xC8,
  "LBRACKET", 0x1A,
  "LCONTROL", 0x1D,
  "MULTIPLY", 0x37,
  "RBRACKET", 0x1B,
  "RCONTROL", 0x9D,
  "SUBTRACT", 0x4A,
  "CAPSLOCK", 0x3A,
  "BACKSLASH", 0x2B,
  "BACKSPACE", 0x0E,
  "DOWNARROW", 0xD0,
  "LEFTARROW", 0xCB,
  "PREVTRACK", 0x90,
  "SEMICOLON", 0x27,
  "UNDERLINE", 0x93,
  "CIRCUMFLEX", 0x90,
  "APOSTROPHE", 0x28,
  "NUMPADPLUS", 0x4E,
  "NUMPADSTAR", 0x37,
  "RIGHTARROW", 0xCD,
  "NUMPADCOMMA", 0xB3,
  "NUMPADENTER", 0x9C,
  "NUMPADMINUS", 0x4A,
  "NUMPADSLASH", 0xB5,
  "NUMPADPERIOD", 0x53,
  "NUMPADEQUALS", 0x8D
];

private _fnc_ArrayToShortcut =
{
  params ["_scArray"];
  if (_scArray isEqualTo []) exitWith {""};

  private _sc = _scArray # 0; //Ignore alternative shortcuts
  if (_sc isEqualType 0) then {_sc = str _sc};
  if (_sc isEqualType "") then {_sc = _sc splitString "+, "};

  {
    private _key = trim _x;
    if ("2048" == _key) then {_sc set [_forEachIndex, toUpper localize "STR_DIK_ALT"]};
    if ("1024" == _key) then {_sc set [_forEachIndex, toUpper localize "STR_DIK_SHIFT"]};
    if ("512" == _key) then {_sc set [_forEachIndex, toUpper localize "STR_DIK_CONTROL"]};

    if !(_key in ["512", "1024", "2048"]) then
    {
      //Actual key, not a modifier
      private _index = _DIKKeyCodes find call compile _key;
      if (_index < 1) then {continue};
      _sc set [_forEachIndex, _DIKKeyCodes select (_index - 1)];
    };
  } forEach _sc;
  _sc joinString "+";
};

private _fnc_cacheData =
{
  if !((uiNamespace getVariable ["ENH_3DENShortcuts_Cache", []]) isEqualTo []) exitWith {};
  private _temp = [];
  private _classes = ("true" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items")) +
           ("true" configClasses (configFile >> "Display3DEN" >> "ContextMenu" >> "Items"));

  {
    private _sc = [getArray (_x >> "shortcuts")] call _fnc_ArrayToShortcut;
    private _text = getText (_x >> "text");
    private _picture = getText (_x >> "picture");

    if (_sc isEqualTo "" || _text isEqualTo "") then {continue};

    _temp append [[_text, _sc, _picture]];
  } forEach _classes;
  uiNamespace setVariable ["ENH_3DENShortcuts_Cache", _temp];
};

call _fnc_cacheData;
[_ctrlContent, ""] call ENH_fnc_3DENShortcuts_fillList;