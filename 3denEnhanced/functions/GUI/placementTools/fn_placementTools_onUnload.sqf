/*
   Author: Revo

   Description:
   Called when ENH_PlacementTools GUI is closed. Used for clean up.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

delete3DENEntities [ENH_PlacementTools_AreaTrigger,ENH_PlacementTools_GarrisonTrigger];
ENH_PlacementTools_AreaTrigger = nil; 
ENH_PlacementTools_GarrisonTrigger = nil;

["ENH_PlacementTools_CenterIcon", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;

["ShowPanelLeft",true] call BIS_fnc_3DENInterface;

true