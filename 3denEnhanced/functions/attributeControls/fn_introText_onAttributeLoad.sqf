/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the intro text attribute. Call when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value	

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_delay","_line1","_line2","_line3","_introType"];

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"s"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"s",_delay] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 102) ctrlSetText _line1;
(_ctrlGroup controlsGroupCtrl 103) ctrlSetText _line2;
(_ctrlGroup controlsGroupCtrl 104) ctrlSetText _line3;

(_ctrlGroup controlsGroupCtrl 105) lbSetCurSel _introType;

true