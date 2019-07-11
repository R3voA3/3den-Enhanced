/*
   Author: R3vo

   Date: 2019-06-11

   Description:
   Checks if Enh_PlacementTools GUI should be opened and if yes, creates the display.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

Enh_PlacementTools_Selected = call Enh_fnc_all3DENSelected;

if (Enh_PlacementTools_Selected isEqualTo []) exitWith {["Enh_NoEntitiesSelected"] call BIS_fnc_3DENNotification; false};

findDisplay 313 createDisplay "Enh_PlacementTools";

true