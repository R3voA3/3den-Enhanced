#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the intro text attribute. Call when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03),
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04),
    lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05)
]
