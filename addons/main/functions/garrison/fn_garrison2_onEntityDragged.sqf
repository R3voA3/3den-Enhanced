#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    Handles dragging of entities when garrison mode is enabled

    Parameter(s):
    -

    Return Value:
    BOOLEAN - True on success, false if failed
*/

if (get3DENActionState "toggleMap" > 0) exitWith
{
    ["ENH_Garrison2_2D_Not_Supported"] call ENH_fnc_3DENNotificationQueue;
    call ENH_fnc_garrison2_exit;
    false
};

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

private _cursorPos =
[
    parseNumber ctrlText (_display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR_X),
    parseNumber ctrlText (_display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR_Y),
    parseNumber ctrlText (_display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR_Z)
];

// Conver to ATL for water areas
if (surfaceIsWater [_cursorPos#0, _cursorPos#1]) then
{
    _cursorPos = ASLToATL _cursorPos;
};

private _building = nearestBuilding _cursorPos;

if (_building buildingPos -1 isEqualTo []) then
{
    _building = objNull;
};

if !(isNull _building) then
{
    private _cursorInBoundingBox = [_building, _cursorPos] call ENH_fnc_garrison2_positionInBoundingBox;

    _display3DEN setVariable ["ENH_CurrentBuilding", _building];
    _display3DEN setVariable ["ENH_CursorInBuilding", _cursorInBoundingBox];
};
