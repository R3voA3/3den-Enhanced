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
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 100),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 101),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 102)
    ],
    ctrlText (_ctrlGroup controlsGroupCtrl 104),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 105),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 106),
    sliderPosition (_ctrlGroup controlsGroupCtrl 107),
    lbCurSel (_ctrlGroup controlsGroupCtrl 109)
]
