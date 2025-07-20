#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-21

    Description:
    Parses shortcuts.

    Parameter(s):
    0: ARRAY - Shortcuts in format ["shortcut1", "shortcut2", "shortcutn"] where shortcut can be number or string

    Return Value:
    STRING - Formatted shortcut, empty string if no shortcut was provided
*/

params [["_rawShortCuts", [], [[]]]];

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

private _fnc_shortcutToString =
{
    params [["_shortcut", 0, [0]]];

    private _shortcutTranslatedArray = [];
    private _bitflags = _shortcut call BIS_fnc_bitflagsToArray;

    if (512 in _bitflags) then {_shortcutTranslatedArray pushBack localize "STR_DIK_CONTROL"; _bitflags = _bitflags - [512]};
    if (1024 in _bitflags) then {_shortcutTranslatedArray pushBack localize "STR_DIK_SHIFT"; _bitflags = _bitflags - [1024]};
    if (2048 in _bitflags) then {_shortcutTranslatedArray pushBack localize "STR_DIK_ALT"; _bitflags = _bitflags - [2048]};

    // Sum up remaining bitflags to get the key
    private _keyNumber = 0;

    _bitflags apply
    {
        _keyNumber = _keyNumber + _x;
    };

    private _index = _DIKKeyCodes find _keyNumber;
    if (_index < 1) then {continue};

    _shortcutTranslatedArray pushBack localize format ["STR_DIK_%1", _DIKKeyCodes select (_index - 1)];

    _shortcutTranslatedArray joinString "+"
};

private _fnc_translateShortcutConfig =
{
    params [["_shortcutsArray", ["", []]]];

    private _shortcutsTranslated = [];

    {
        private _shortcut = _x;
        if (_x isEqualType 0) then
        {
            _shortcutsTranslated pushBack (_x call _fnc_shortcutToString);
        };
        if (_x isEqualType "") then
        {
            _shortcutsTranslated pushBack ((_x call BIS_fnc_parseNumber) call _fnc_shortcutToString);
        };
    } forEach _shortcutsArray;

    // Returns "SHORTCUT" if only one entry
    // Returns "SHORTCUT, SHORTCUT2" if multiple entries
    // Returns "" for empty array
    toUpper (_shortcutsTranslated joinString ", ");
};

_rawShortCuts call _fnc_translateShortcutConfig;
