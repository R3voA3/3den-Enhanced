#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Refills the history combo box for the marker color attribute.

    Parameter(s):
    0: CONTROL - Listbox

    Returns:
    true
*/

params ["_ctrlEdit", "_newText"];

systemChat str _this;

// Trim all whitespaces
_newText = trim _newText regexReplace [" ", ""];

// Only update controls if the pattern matches e.g. valid color format
if (_newText regexMatch "#\([0-9.]+,[0-9.]+,[0-9.]+,[0-9.]+\)") then
{
    // Turn the string into an array
    _newText splitString "#(,)" apply {parseNumber _x} params ["_red", "_green", "_blue", "_alpha"];

    // Clamp the value
    _red = _red min 1 max 0;
    _green = _green min 1 max 0;
    _blue = _blue min 1 max 0;
    _alpha = _alpha min 1 max 0;

    systemChat str [_red, _green, _blue, _alpha];
};

true
