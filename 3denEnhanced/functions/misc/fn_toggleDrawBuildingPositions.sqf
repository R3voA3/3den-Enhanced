/*
   Author: R3vo

   Date: 2019-08-30

   Description:
   Draws all building positions on the map. Function always covers the whole map. If drawing is already enabled, calling it again will destroy the icons.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

#define MAP_DIAGONAL sqrt (2 * worldSize) //TO-DO: POSITIONS ARE NOT PROPERLY DRAWN OVER WATER, SEE GARRISON FUNCTION FOR A WORKAROUND
#define GET_BUILDINGS (position get3DENCamera nearObjects ["House",MAP_DIAGONAL])

//Remove icons if EH already exists and exit
if (["Enh_EH_DrawBuildingPositions_ID", "onEachFrame"] call BIS_fnc_removeStackedEventHandler) exitWith {false};

//Get all building positions from nearby buildings
["Enh_EH_DrawBuildingPositions_ID", "onEachFrame",
	{
		{
			for "_i" from 0 to (count (_x buildingPos -1) - 1) do
			{
				drawIcon3D
				[
					"\A3\modules_f\data\iconStrategicMapMission_ca.paa",
					[1,0.1,1,1],
					_x buildingPos _i,
					0.5,
					0.5,
					0,
					str _i
				];
			};
			false;
		} count GET_BUILDINGS;
	}
] call BIS_fnc_addStackedEventHandler;

true