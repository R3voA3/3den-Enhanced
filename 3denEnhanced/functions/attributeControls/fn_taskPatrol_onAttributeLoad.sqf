/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the task patrol attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute lnbValue

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"m"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"m",_value] call BIS_fnc_initSliderValue;

true