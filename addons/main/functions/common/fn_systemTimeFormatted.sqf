#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-06-27

    Description:
    Returns systemTime or systemTimeUTC into a formatted string.

    Parameter(s):
    0: ARRAY - systemTime or systemTimeUTC, default systemTime

    Returns:
    STRING: Formatted time
*/

params [["_tArr", systemTime]];

_tArr apply {if (_x < 10) then {"0" + str _x} else {str _x}} params ["_y", "_m", "_d", "_h", "_min", "_s"];

format ["%1/%2/%3 %4:%5:%6", _y, _m, _d, _h, _min, _s];
