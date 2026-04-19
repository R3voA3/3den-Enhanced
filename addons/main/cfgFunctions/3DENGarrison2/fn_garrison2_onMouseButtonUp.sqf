#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    Handles placing of entities in building if all conditions are met.

    Parameter(s):
    0: DISPLAY - Eden Editor display
    1: NUMBER - Mouse button ID

    Return Value:
    ARRAY - True on success, false if failed
*/

params ["_display3DEN", "_button"];

// Only left mouse button counts
if (_button != 0) exitWith {};

private _display3DEN = findDisplay IDD_DISPLAY3DEN;
private _cursorInBuilding = _display3DEN getVariable ["ENH_CursorInBuilding", false];
private _building = _display3DEN getVariable ["ENH_CurrentBuilding", objNull];

if (_cursorInBuilding) then
{
    private _ID = addMissionEventHandler ["EachFrame",
    {
        _thisArgs params ["_frame", "_building"];

        // Placement needs to happen next frame
        // otherwise onEntityDragged will happen after it
        // and place units incorrectly
        if (diag_frameNo >= _frame + 1) then
        {
            removeMissionEventHandler [_thisEvent, _thisEventHandler];

           [_building] call ENH_fnc_garrison2_fillBuildingPositions;
        };
    },
        [diag_frameNo, _building]
    ];

    findDisplay IDD_DISPLAY3DEN setVariable ["ENH_EachFrameID", _ID];
};

[0] call ENH_fnc_garrison2_exit;

true
