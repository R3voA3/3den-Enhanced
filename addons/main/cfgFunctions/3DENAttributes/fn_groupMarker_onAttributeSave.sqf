#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the group marker attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

private _ctrlComboType =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;
private _ctrlComboColor =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01;
private _ctrlEdit =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02;
private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03;
private _ctrlCheckbox2 = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04;

[
    _ctrlComboType lbData lbCurSel _ctrlComboType,
    _ctrlComboColor lbData lbCurSel _ctrlComboColor,
    ctrlText _ctrlEdit,
    cbChecked _ctrlCheckbox,
    cbChecked _ctrlCheckbox2
]
