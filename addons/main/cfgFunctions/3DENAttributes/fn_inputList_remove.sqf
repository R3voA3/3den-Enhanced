#include "\x\enh\addons\main\script_component.hpp"

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
private _ctrlListbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;
private _value = ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01);

private _index = lbCurSel _ctrlListbox;

if (_index == -1) exitWith {false};

_ctrlListbox lbDelete _index;
// _ctrlListbox lbSetCurSel 0;

true
