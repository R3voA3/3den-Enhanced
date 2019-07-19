/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the ambient flyby attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText "";

(_ctrlGroup controlsGroupCtrl 101) ctrlSetText "[0,0,0]";
(_ctrlGroup controlsGroupCtrl 102) ctrlSetText "[0,0,0]";

[_ctrlGroup controlsGroupCtrl 103,_ctrlGroup controlsGroupCtrl 104,"m",500] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 105) lbSetCurSel 1;
(_ctrlGroup controlsGroupCtrl 106) lbSetCurSel 0;

[_ctrlGroup controlsGroupCtrl 107,_ctrlGroup controlsGroupCtrl 108,"s",300] call BIS_fnc_initSliderValue;

true