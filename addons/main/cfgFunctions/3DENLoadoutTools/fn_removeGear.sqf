#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Removes item from player depending on mode parameter.

    Parameter(s):
    NUMBER: Mode, can be
    0 - goggles
    1 - headgear
    2 - NVG
    3 - vest
    4 - weapons
    5 - backpack
    6 - uniform
    7 - remove everything

    Returns:
    BOOLEAN: true / false
*/

if (!is3DEN) exitWith {false};

params ["_mode"];
private _units = get3DENSelected "Object";

if (_units isEqualTo []) exitWith
{
    ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
    false
};

private _code =
[
    {removeGoggles _x},
    {removeHeadgear _x},
    {_x unlinkItem hmd _x},
    {removeVest _x},
    {removeAllWeapons _x},
    {removeBackpack _x},
    {removeUniform _x},
    {_x setUnitLoadout (configFile >> "EmptyLoadout")}
] select _mode;

{
    call _code;
} forEach _units;

save3DENInventory _units;
["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true
