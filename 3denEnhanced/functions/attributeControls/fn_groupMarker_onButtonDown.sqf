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

//Setting default values, colour and group ID cannot be retrieved from here so they are ignored
(_ctrlGroup controlsGroupCtrl 100) lbSetCurSel 0;
(_ctrlGroup controlsGroupCtrl 103) cbSetChecked true;

true