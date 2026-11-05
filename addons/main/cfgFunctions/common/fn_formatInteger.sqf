#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-01-01
    Description:
    Formats an integer to given number of digits for display purpose.

    Parameter(s):
    0: NUMBER - Any number, will be rounded
    1: NUMBER - Number of digits (1000 = 4, 100 = 3, ...)

    Returns:
    STRING - Integer string representation

    Examples:
    [125, 4] call ENH_fnc_formatInteger; // "0125"
*/

params ["_integer", ["_digitCount", 3]];

private _strInteger = str round _integer;

while {count _strInteger < _digitCount} do
{
    _strInteger = "0" + _strInteger;
};

_strInteger
