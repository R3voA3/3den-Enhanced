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
_value params ["_center","_text","_alt","_r","_angle","_dir"];

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText str _center;
(_ctrlGroup controlsGroupCtrl 101) ctrlSetText _text;

[_ctrlGroup controlsGroupCtrl 102,_ctrlGroup controlsGroupCtrl 103,"m"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 102,_ctrlGroup controlsGroupCtrl 103,"m",_alt] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 104,_ctrlGroup controlsGroupCtrl 105,"m"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 104,_ctrlGroup controlsGroupCtrl 105,"m",_r] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 106,_ctrlGroup controlsGroupCtrl 107,"°"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 106,_ctrlGroup controlsGroupCtrl 107,"°",_angle] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 108) lbSetCurSel _dir;

true