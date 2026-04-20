#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-09-15

    Description:
    Convert float to time format "Minutes:Seconds". Rounds initial value up to full seconds.

    Parameter(s):
    0: NUMBER: Time in seconds

    Returns:
    STRING: Time in format "Minutes:Seconds"
*/

params ["_toConvert"];

_toConvert = round _toConvert;
private _minutes = floor (_toConvert / 60);
private _mod = _toConvert mod 60;
private _seconds = _mod / 1;

format
[
    "%1:%2",
    if (_minutes < 10) then {format ["0%1", _minutes]} else {format ["%1", _minutes]},
    if (_seconds < 10) then {format ["0%1", _seconds]} else {format ["%1", _seconds]}
]
