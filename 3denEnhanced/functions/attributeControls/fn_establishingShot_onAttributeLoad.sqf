/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the establishingShot attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_center","_text","_alt","_r","_angle"];

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText str _center;
(_ctrlGroup controlsGroupCtrl 101) ctrlSetText _text;
(_ctrlGroup controlsGroupCtrl 102) ctrlSetText str _alt;
(_ctrlGroup controlsGroupCtrl 103) ctrlSetText str _r;
(_ctrlGroup controlsGroupCtrl 104) ctrlSetText str _angle;

true