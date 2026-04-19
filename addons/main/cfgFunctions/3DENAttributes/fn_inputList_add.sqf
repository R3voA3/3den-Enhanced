#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-09-09

    Description:
    Adds an entry to the listbox

    Parameter(s):
    0: CONTROL - Button control

    Returns:
    BOOLEAN
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlListbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;
private _ctrlEdit = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01;
private _value = ctrlText _ctrlEdit;

if (_value == "") exitWith {false};

_value splitString " ,;" apply
{
    _ctrlListbox lbAdd _x;
};

_ctrlEdit ctrlSetText "";

true
