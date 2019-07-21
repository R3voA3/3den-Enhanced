/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the dynamic skill attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

(_ctrlGroup controlsGroupCtrl 100) cbSetChecked false;
[_ctrlGroup controlsGroupCtrl 101,_ctrlGroup controlsGroupCtrl 102,"%",0.5] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 103,_ctrlGroup controlsGroupCtrl 104,"%",0.3] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 105,_ctrlGroup controlsGroupCtrl 106,"%",0.8] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 107,_ctrlGroup controlsGroupCtrl 108,"%",0.5] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 109,_ctrlGroup controlsGroupCtrl 110,"%",0.5] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 111,_ctrlGroup controlsGroupCtrl 112,"%",0.3] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 113,_ctrlGroup controlsGroupCtrl 114,"%",0.8] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 115,_ctrlGroup controlsGroupCtrl 116,"%",0.5] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 117,_ctrlGroup controlsGroupCtrl 118,"%",0.5] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 119,_ctrlGroup controlsGroupCtrl 120,"%",0.3] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 121,_ctrlGroup controlsGroupCtrl 122,"%",0.8] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 123,_ctrlGroup controlsGroupCtrl 124,"%",0.5] call BIS_fnc_initSliderValue;

true