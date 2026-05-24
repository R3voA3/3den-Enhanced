#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-01-01
    File: addons\main\functions\internal\fn_log.sqf

    Description:
    Saves message in UI namespace variable ENH_Log_Data. Each message is in format [diag_ticktime, message]

    Parameter(s):
    0: STRING - Message

    Return Value:
    BOOLEAN - true
*/

params ["_message"];

private _data = uiNamespace getVariable ["ENH_Log_Data", []];

if !(_message isEqualType "") then
{
    _message = str _message;
};

_data append [[diag_tickTime, _message]];

uiNamespace setVariable ["ENH_Log_Data", _data];

true
