/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the hold action attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText "";
(_ctrlGroup controlsGroupCtrl 101) lbSetCurSel 0;
(_ctrlGroup controlsGroupCtrl 102) lbSetCurSel 0;
(_ctrlGroup controlsGroupCtrl 103) ctrlSetText "true";
(_ctrlGroup controlsGroupCtrl 104) ctrlSetText "true";
(_ctrlGroup controlsGroupCtrl 105) ctrlSetText "";
(_ctrlGroup controlsGroupCtrl 106) ctrlSetText "";
(_ctrlGroup controlsGroupCtrl 107) ctrlSetText "";
(_ctrlGroup controlsGroupCtrl 108) ctrlSetText "";
[_ctrlGroup controlsGroupCtrl 109,_ctrlGroup controlsGroupCtrl 110,"s",10] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 111,_ctrlGroup controlsGroupCtrl 112,"",1000] call BIS_fnc_initSliderValue;
(_ctrlGroup controlsGroupCtrl 113) cbSetChecked false;
(_ctrlGroup controlsGroupCtrl 114) cbSetChecked true;
(_ctrlGroup controlsGroupCtrl 115) lbSetCurSel 0;

true