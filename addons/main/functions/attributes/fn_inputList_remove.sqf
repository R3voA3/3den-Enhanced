/*
    Author: R3vo

    Date: 2024-09-09

    Description:
    Removes an entry from the listbox

    Parameter(s):
    0: CONTROL - Button control

    Returns:
    BOOLEAN
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlListbox = _ctrlGroup controlsGroupCtrl 100;
private _value = ctrlText (_ctrlGroup controlsGroupCtrl 101);

private _index = lbCurSel _ctrlListbox;

if (_index == -1) exitWith {false};

_ctrlListbox lbDelete _index;
// _ctrlListbox lbSetCurSel 0;

true
