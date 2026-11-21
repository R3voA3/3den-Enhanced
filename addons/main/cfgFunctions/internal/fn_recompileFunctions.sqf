#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-07
    Description:
    Recompiles all 3den Enhanced functions.

    Parameter(s):
    -

    Returns:
    BOOLEAN - True on success, false if failed
*/

if !is3DEN exitWith {false};

allVariables missionNamespace apply
{
    if (_x select [0, 4] == "enh_") then
    {
        [_x] call BIS_fnc_recompile;
        diag_log [format ["Function %1 was recompiled.", _x]];
    };
};

true
