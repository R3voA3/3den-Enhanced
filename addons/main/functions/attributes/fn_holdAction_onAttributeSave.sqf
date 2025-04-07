#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the hold action attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00),
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) lbText lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01),
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) lbText lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08),
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09),
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15)
];
