/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the SPR attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"s",20] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 102,_ctrlGroup controlsGroupCtrl 103,"",0] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 104) lbSetCurSel 0;

(_ctrlGroup controlsGroupCtrl 105) cbSetChecked false;

true