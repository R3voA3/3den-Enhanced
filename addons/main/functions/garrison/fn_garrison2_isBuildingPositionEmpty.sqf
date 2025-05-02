#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    Checks if provided building position is already taken by any 3DEN entity of type object

    Parameter(s):
    0: ARRAY - Building position

    Return Value:
    ARRAY - True when empty, false if not
*/

params [["_buildingPosition", [0, 0, 0]]];

private _all3DENEntities = all3DENEntities;

all3DENEntities params ["_all3DENObjects"];

_all3DENObjects = _all3DENObjects - [findDisplay IDD_DISPLAY3DEN getVariable ["ENH_CurrentBuilding", objNull]];

_all3DENObjects inAreaArrayIndexes
[
    _buildingPosition,
    0.5,
    0.5,
    0,
    false,
    2,
    false
] isEqualTo []
