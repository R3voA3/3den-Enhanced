#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by simple slider attributes. Call when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    NUMBER: Attribute value
*/

params ["_ctrlGroup"];

sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00)
