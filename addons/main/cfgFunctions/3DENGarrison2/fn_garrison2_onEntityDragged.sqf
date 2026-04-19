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
    ["ENH_Garrison2_2D_Not_Supported"] call BIS_fnc_3DENNotification;
    [1] call ENH_fnc_garrison2_exit;
    false
};

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

private _cursorPosASL =
[
    parseNumber ctrlText (_display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR_X),
    parseNumber ctrlText (_display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR_Y),
    parseNumber ctrlText (_display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR_Z)
];

_cursorPosASLtemp = _cursorPosASL;

private _building = nearestBuilding _cursorPosASL;

if (_building buildingPos -1 isEqualTo []) then
{
    _building = objNull;
};

if !(isNull _building) then
{
    // As we don't have a Z height for the cursor
    // we assume that it's at the height of the building
    // that way it works when the building is ATL, ASL or floating (floating looks weird though)
    _cursorPosASL set [2, getPosASL _building select 2];

    private _cursorInBoundingBox = [_building, _cursorPosASL] call ENH_fnc_garrison2_positionInBoundingBox;

    _display3DEN setVariable ["ENH_CurrentBuilding", _building];
    _display3DEN setVariable ["ENH_CursorInBuilding", _cursorInBoundingBox];
};
