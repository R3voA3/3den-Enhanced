/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the terrain detail attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute lnbValue

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];

(_ctrlGroup controlsGroupCtrl 100) lbSetCurSel ([-1,50,25,12.5,6.25,3.125] find _value);

true