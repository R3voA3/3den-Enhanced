#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-04-01

    Description:
    Parses the clipboard content and tries to convert it to a three dimensional array of numbers.
    Does not work in multiplayer.

    Parameter(s):
    -

    Return Value:
    ARRAY - In format [<NUMBER>, <NUMBER>, <NUMBER>] on success, else []

    Examples(s):
    -
*/

if isMultiplayer exitWith {[]};

private _clipboardContent = trim copyFromClipboard;

// Checks to reduce risk of running into an error
if (_clipboardContent == "") exitWith {[]};
if (_clipboardContent select [0, 1] != "[") exitWith {[]};
if (reverse _clipboardContent select [0, 1] != "]") exitWith {[]};
if (count (_clipboardContent regexFind [",", 0]) != 2) exitWith {[]};

_clipboardContent = parseSimpleArray _clipboardContent;

if !(_clipboardContent isEqualTypeParams [0, 0, 0]) exitWith {[]};

_clipboardContent;
