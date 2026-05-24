#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    A function to quickly disable grass while editing.

    Parameter(s):
    -

    Returns:
    BOOLEAN: true / false
*/

if !(is3DEN) exitWith {false};

disableSerialization;

if (isNil "ENH_eden_terrainGrid") then
{
    ENH_eden_terrainGrid = getTerrainGrid;
    setTerrainGrid 50;
}
else
{
    setTerrainGrid 3.125;
    ENH_eden_terrainGrid = nil;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true
