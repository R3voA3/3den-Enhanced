/*
   Author: R3vo

   Date: 2019-08-30

   Description:
   Draws the mod icon next to the Eden entity.
   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

//Remove icons if EH already exists and exit
if (["ENH_EH_DrawDLCIcons_ID", "onEachFrame"] call BIS_fnc_removeStackedEventHandler) exitWith {false};

//Define path here to save performance inside the loop
ENH_DrawDLCIcons_Path = configFile >> "CfgVehicles";

//Loop though all object
private ["_icon"];
["ENH_EH_DrawDLCIcons_ID", "onEachFrame",
	{
		{
			//Use param to filter nil value when no icon is define
			_icon = modParams [configSourceMod (ENH_DrawDLCIcons_Path >> typeOf _x),["logo"]] param [0,"",[""]];
			drawIcon3D
			[
				_icon,
				[1,1,1,1],
				_x modelToWorldVisual [0,0,0.5],
				0.5,
				0.5,
				0
			];
			false;
		} count (vehicles + allUnits);//vehicles is alot faster than all3DENEntities # 0;
	}
] call BIS_fnc_addStackedEventHandler;

true