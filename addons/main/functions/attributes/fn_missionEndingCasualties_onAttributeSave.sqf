#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the mission ending casualties attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00),
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) lbText lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03),
    [west, east, independent, civilian] select lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04)
]
