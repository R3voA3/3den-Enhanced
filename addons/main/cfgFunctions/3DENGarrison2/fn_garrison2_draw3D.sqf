#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    Draws building positions when cursor is in building bounding box.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - True
*/

private _display3DEN = findDisplay IDD_DISPLAY3DEN;
private _building = _display3DEN getVariable ["ENH_CurrentBuilding", objNull];
private _cursorInBuilding = _display3DEN getVariable ["ENH_CursorInBuilding", false];

if (_cursorInBuilding) then
{
    private _selectedEntities = get3DENSelected "Object";
    private _buildingPositions = _building buildingPos -1;

    // If only one unit is selected we highlight closest position
    if (count _selectedEntities == 1) then
    {
        private _closestPosition =
        ([
            _buildingPositions,
            [_selectedEntities#0],
            {_input0 distance _x}
        ] call BIS_fnc_sortBy) # 0;

        _buildingPositions apply
        {
            drawIcon3D
            [
                TEXTURE_BUILDING_POS,
                [[COLOR_BUILDING_POS], [COLOR_BUILDING_POS_HIGHLIGHT]] select (_x isEqualTo _closestPosition),
                _x,
                0.5,
                0.5,
                0
            ];
        };
    }
    else
    {
        _buildingPositions apply
        {
            drawIcon3D
            [
                TEXTURE_BUILDING_POS,
                [COLOR_BUILDING_POS],
                _x,
                0.5,
                0.5,
                0
            ];
        };
    };
};

true
