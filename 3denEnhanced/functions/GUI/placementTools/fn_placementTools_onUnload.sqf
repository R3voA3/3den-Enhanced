/*
   Author: Revo

   Description:
   Called when Enh_PlacementTools GUI is closed. Used for clean up.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

delete3DENEntities [Enh_PlacementTools_AreaTrigger,Enh_PlacementTools_GarrisonTrigger];
Enh_PlacementTools_AreaTrigger = nil; 
Enh_PlacementTools_GarrisonTrigger = nil;

["Enh_PlacementTools_CenterIcon", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;

["ShowPanelLeft",true] call BIS_fnc_3DENInterface;

true