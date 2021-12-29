/*
  Author: R3vo

  Date: 2019-08-30

  Description:
  Draws all building positions on the map. Function always covers the whole map. If drawing has already already been enabled, calling it again will destroy the icons.

  Parameter(s):
  -

  Returns:
  -
*/

#define CENTER (getPosWorld get3DENCamera)
#define RADIUS 100

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

//Remove icons if EH already exists and exit
if (["ENH_EH_DrawBuildingPositions_ID", "onEachFrame"] call BIS_fnc_removeStackedEventHandler) exitWith {};

//Get all building positions from nearby buildings
["ENH_EH_DrawBuildingPositions_ID", "onEachFrame",
  {
    {
      for "_i" from 0 to (count (_x buildingPos -1) - 1) do
      {
        drawIcon3D
        [
          "\A3\modules_f\data\iconStrategicMapMission_ca.paa",
          [1, 0.1, 1, 1],
          _x buildingPos _i,
          0.5,
          0.5,
          0,
          str _i
        ];
      };
      false;
    } count (CENTER nearObjects ["House", RADIUS]);
  }
] call BIS_fnc_addStackedEventHandler;