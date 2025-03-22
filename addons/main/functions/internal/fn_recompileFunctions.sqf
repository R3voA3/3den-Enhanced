#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-07
    File: addons\main\functions\internal\fn_recompileFunctions.sqf

    Description:
    Recompiles all 3den Enhanced functions.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - True on success, false if failed

    Examples(s):
    [] call ENH_fnc_recompileFunctions;
*/

if !is3DEN exitWith {false};

allVariables missionNamespace apply
{
    if (_x select [0, 4] == "enh_") then
    {
        [_x] call BIS_fnc_recompile;
        [format ["Function %1 was recompiled.", _x]] call ENH_fnc_log;
    };
};

true
