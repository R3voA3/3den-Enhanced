/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the dynamic skill attribute. Call when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params 
[
   "_enable",
   "_skillMinBLUFOR",
   "_skillAimMinBLUFOR",
   "_skillMaxBLUFOR",
   "_skillAimMaxBlUFOR",
   "_skillMinOPFOR",
   "_skillAimMinOPFOR",
   "_skillMaxOPFOR",
   "_skillAimMaxOPFOR",
   "_skillMinINDFOR",
   "_skillAimMinINDFOR",
   "_skillMaxINDFOR",
   "_skillAimMaxINDFOR"
];

(_ctrlGroup controlsGroupCtrl 100) cbSetChecked _enable;

[_ctrlGroup controlsGroupCtrl 101,_ctrlGroup controlsGroupCtrl 102,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 101,_ctrlGroup controlsGroupCtrl 102,"%",_skillMinBLUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 103,_ctrlGroup controlsGroupCtrl 104,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 103,_ctrlGroup controlsGroupCtrl 104,"%",_skillAimMinBLUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 105,_ctrlGroup controlsGroupCtrl 106,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 105,_ctrlGroup controlsGroupCtrl 106,"%",_skillMaxBLUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 107,_ctrlGroup controlsGroupCtrl 108,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 107,_ctrlGroup controlsGroupCtrl 108,"%",_skillAimMaxBlUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 109,_ctrlGroup controlsGroupCtrl 110,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 109,_ctrlGroup controlsGroupCtrl 110,"%",_skillMinOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 111,_ctrlGroup controlsGroupCtrl 112,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 111,_ctrlGroup controlsGroupCtrl 112,"%",_skillAimMinOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 113,_ctrlGroup controlsGroupCtrl 114,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 113,_ctrlGroup controlsGroupCtrl 114,"%",_skillMaxOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 115,_ctrlGroup controlsGroupCtrl 116,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 115,_ctrlGroup controlsGroupCtrl 116,"%",_skillAimMaxOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 117,_ctrlGroup controlsGroupCtrl 118,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 117,_ctrlGroup controlsGroupCtrl 118,"%",_skillMinINDFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 119,_ctrlGroup controlsGroupCtrl 120,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 119,_ctrlGroup controlsGroupCtrl 120,"%",_skillAimMinINDFOR] call BIS_fnc_initSliderValue;


[_ctrlGroup controlsGroupCtrl 121,_ctrlGroup controlsGroupCtrl 122,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 121,_ctrlGroup controlsGroupCtrl 122,"%",_skillMaxINDFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 123,_ctrlGroup controlsGroupCtrl 124,"%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 123,_ctrlGroup controlsGroupCtrl 124,"%",_skillAimMaxINDFOR] call BIS_fnc_initSliderValue;

true