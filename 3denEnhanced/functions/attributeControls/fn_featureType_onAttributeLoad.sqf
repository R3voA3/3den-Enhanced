/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the feature type attribute. Call when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: NUMBER - Value, selected index	

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];

(_ctrlGroup controlsGroupCtrl 100) lbSetCursel _value;

true