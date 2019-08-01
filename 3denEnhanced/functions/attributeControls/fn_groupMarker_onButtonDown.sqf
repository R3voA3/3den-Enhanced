/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the group marker attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

private _ctrlComboType = _ctrlGroup controlsGroupCtrl 100;
private _ctrlComboColor =_ctrlGroup controlsGroupCtrl 101;
private _ctrlEdit =_ctrlGroup controlsGroupCtrl 102;
private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl 103;

//Setting default values, colour and group ID cannot be retrieved from here so they are ignored
(_ctrlGroup controlsGroupCtrl 100) ctSetCurSel 0;
(_ctrlGroup controlsGroupCtrl 103) cbSetChecked 1;

true