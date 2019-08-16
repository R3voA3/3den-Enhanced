/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the ambient animations attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

(_ctrlGroup controlsGroupCtrl 100) lbSetCurSel 0;
(_ctrlGroup controlsGroupCtrl 101) cbSetChecked false;
(_ctrlGroup controlsGroupCtrl 102) cbSetChecked false;

true