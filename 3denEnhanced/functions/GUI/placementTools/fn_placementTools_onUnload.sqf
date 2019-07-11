/*
   Author: Revo

   Description:
   Called when Enh_PlacementTools GUI is closed.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

delete3DENEntities [Enh_PlacementTools_AreaTrigger,Enh_PlacementTools_GarrisonTrigger]; 
Enh_PlacementTools_AreaTrigger = nil; 
Enh_PlacementTools_GarrisonTrigger = nil;

["ShowPanelLeft",true] call BIS_fnc_3DENInterface;
["ShowPanelRight",true] call BIS_fnc_3DENInterface;

true