#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Used by the marker shape attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    STRING: Attribute value
*/

params ["_ctrlGroup"];

CUSTOM_MARKER_SHAPES select lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00);
