#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the airdrop attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) splitString ";, [] " + endl, // Convert string to array with strings
    [
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03)
    ],
    ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07),
    [west, east, independent, civilian] # lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08)
]
