/*
   Author: Revo

   Description:
   Initializes the Enh_Pattern GUI.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true / false
*/

params ["_display"];

Enh_PlacementTools_Selected = get3DENSelected "Object";
uiNamespace setVariable ["Enh_PlacementTools_Display",_display];

if (Enh_PlacementTools_Selected isEqualTo []) exitWith {["No Entities selected!",1] call BIS_fnc_3DENNotification; _display closeDisplay 1; false};

Enh_PlacementTools_Center = screenToWorld [0.5,0.5];
Enh_PlacementTools_CentralAngle = 360;
Enh_PlacementTools_Radius = 50;
Enh_PlacementTools_Selected = get3DENSelected "Object";
Enh_PlacementTools_Rotation = 0;
Enh_PlacementTools_NumRows = 2;
Enh_PlacementTools_NumColums = 2;
Enh_PlacementTools_SpaceX = 2;
Enh_PlacementTools_SpaceY = 2;
Enh_PlacementTools_A = 1;
Enh_PlacementTools_B = 2;
Enh_PlacementTools_AreaDia = 200;
Enh_PlacementTools_Coverage = 2;//2 = 50%, 10=10%, 1=100%...

["ShowPanelLeft",false] call BIS_fnc_3DENInterface;
["ShowPanelRight",false] call BIS_fnc_3DENInterface;

true