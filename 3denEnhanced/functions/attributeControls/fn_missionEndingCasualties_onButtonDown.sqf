/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the mission ending casualties attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"",5] call BIS_fnc_initSliderValue;
(_ctrlGroup controlsGroupCtrl 102) lbSetCurSel 0;

(_ctrlGroup controlsGroupCtrl 103) cbSetChecked false;
(_ctrlGroup controlsGroupCtrl 104) lbSetCurSel ([west,east,independent,civilian] find civilian);

true