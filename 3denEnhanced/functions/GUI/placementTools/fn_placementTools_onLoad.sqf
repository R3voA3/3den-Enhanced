/*
   Author: Revo

   Description:
   Initializes the Enh_Pattern GUI.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

params ["_display"];

uiNamespace setVariable ["Enh_PlacementTools_Display",_display];

["ShowPanelLeft",false] call BIS_fnc_3DENInterface;
["ShowPanelRight",false] call BIS_fnc_3DENInterface;

Enh_PlacementTools_Center = if (get3DENActionState "ToggleMap" == 1) then 
{
   (findDisplay 313 displayCtrl 51 ctrlMapScreenToWorld [0.5,0.5]) + [0];//ctrlMapScreenToWorld only returns [x,y], add another 0 to have [x,y,z]
}
else
{
   screenToWorld [0.5,0.5];
};

//Define variables if undefined
if (isNil "Enh_PlacementTools_Radius") then {Enh_PlacementTools_Radius = 50};
if (isNil "Enh_PlacementTools_InitialAngle") then {Enh_PlacementTools_InitialAngle = 0};
if (isNil "Enh_PlacementTools_CentralAngle") then {Enh_PlacementTools_CentralAngle = 360};
if (isNil "Enh_PlacementTools_Spacing") then {Enh_PlacementTools_Spacing = 2};
if (isNil "Enh_PlacementTools_NumColums") then {Enh_PlacementTools_NumColums = 2};
if (isNil "Enh_PlacementTools_SpaceX") then {Enh_PlacementTools_SpaceX = 2};
if (isNil "Enh_PlacementTools_SpaceY") then {Enh_PlacementTools_SpaceY = 2};
if (isNil "Enh_PlacementTools_A") then {Enh_PlacementTools_A = 50};
if (isNil "Enh_PlacementTools_B") then {Enh_PlacementTools_B = 50};
if (isNil "Enh_PlacementTools_AreaDia") then {Enh_PlacementTools_AreaDia = 200};
if (isNil "Enh_PlacementTools_Coverage") then {Enh_PlacementTools_Coverage = 2};//2 = 50%, 10=10%, 1=100%...
if (isNil "Enh_PlacementTools_RectangleA") then {Enh_PlacementTools_RectangleA = 5};
if (isNil "Enh_PlacementTools_RectangleB") then {Enh_PlacementTools_RectangleB = 5};
if (isNil "Enh_PlacementTools_RectangleSpacing") then {Enh_PlacementTools_RectangleSpacing = 5};

//Set up sliders
_display displayCtrl 10 sliderSetPosition Enh_PlacementTools_Radius;
_display displayCtrl 20 sliderSetPosition Enh_PlacementTools_InitialAngle;
_display displayCtrl 30 sliderSetPosition Enh_PlacementTools_CentralAngle;
_display displayCtrl 40 sliderSetPosition Enh_PlacementTools_Spacing;
_display displayCtrl 50 sliderSetPosition Enh_PlacementTools_NumColums;
_display displayCtrl 60 sliderSetPosition Enh_PlacementTools_SpaceX;
_display displayCtrl 70 sliderSetPosition Enh_PlacementTools_SpaceY;
_display displayCtrl 80 sliderSetPosition Enh_PlacementTools_A;
_display displayCtrl 90 sliderSetPosition Enh_PlacementTools_B;
_display displayCtrl 100 sliderSetPosition Enh_PlacementTools_AreaDia;
_display displayCtrl 110 sliderSetPosition Enh_PlacementTools_Coverage;

_display displayCtrl 130 sliderSetPosition Enh_PlacementTools_RectangleA;
_display displayCtrl 140 sliderSetPosition Enh_PlacementTools_RectangleB;
_display displayCtrl 150 sliderSetPosition Enh_PlacementTools_RectangleSpacing;

true