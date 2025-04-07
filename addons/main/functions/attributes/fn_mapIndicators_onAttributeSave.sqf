#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the mapindicators attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Array with booleans, attribute value
*/

params ["_ctrlGroup"];

[
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03)
]
