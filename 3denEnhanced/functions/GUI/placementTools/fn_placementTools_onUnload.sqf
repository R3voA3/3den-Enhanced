/*
  Author: R3vo

  Description:
  Called when ENH_PlacementTools GUI is closed. Used for clean up.

  Parameter(s):
  -

  Returns:
  -
*/

delete3DENEntities [ENH_PlacementTools_AreaTrigger, ENH_PlacementTools_GarrisonTrigger];

removeMissionEventHandler ["draw3D", ENH_PlacementTools_CenterIcon_EH];

ENH_PlacementTools_CenterIcon_EH = nil;
ENH_PlacementTools_AreaTrigger = nil;
ENH_PlacementTools_GarrisonTrigger = nil;

["ShowPanelLeft", true] call BIS_fnc_3DENInterface;