/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the time multiplier attribute. Called when controls are created.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup"];

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"x"] call BIS_fnc_initSliderValue;

true