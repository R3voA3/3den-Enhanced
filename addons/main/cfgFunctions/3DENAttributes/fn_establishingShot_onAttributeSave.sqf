#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the establishingShot attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
    [
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02)
    ],
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06),
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07),
    lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09)
]
