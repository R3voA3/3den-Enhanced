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
    ctrlText (_ctrlGroup controlsGroupCtrl 100) splitString ";, [] " + endl, // Convert string to array with strings
    [
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 101),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 102),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 103)
    ],
    ctrlText (_ctrlGroup controlsGroupCtrl 105),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 106),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 107),
    [west, east, independent, civilian] # lbCurSel (_ctrlGroup controlsGroupCtrl 108)
]
