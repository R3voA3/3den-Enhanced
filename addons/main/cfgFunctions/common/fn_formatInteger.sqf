#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-01-01
    File: addons\main\functions\misc\fn_formatInteger.sqf

    Description:
    Formats an integer to given number of digits for display purpose.

    Parameter(s):
    0: NUMBER - Any number, will be rounded
    2: NUMBER - Number of digits (1000 = 4, 100 = 3, ...)

    Return Value:
    STRING - Integer string representation

    Examples(s):
    [125, 4] call ENH_fnc_formatInteger; // "0125"
*/

params ["_integer", ["_digitCount", 3]];

private _strInteger = str round _integer;

while {count _strInteger < _digitCount} do
{
    _strInteger = "0" + _strInteger;
};

_strInteger
