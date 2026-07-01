#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the ambient flyby attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

private _ctrlClassesTree = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17;
private _classes = [];

for "_i" from 0 to (_ctrlClassesTree tvCount []) - 1 do
{
    if (_ctrlClassesTree tvValue [_i] > 0) then
    {
        _classes pushBack (_ctrlClassesTree tvData [_i]);
    };
};

[
    _classes,
    [ // Start pos
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03)
    ],
    [ // End pos
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07)
    ],
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), // Altitude
    ["limited", "normal", "full"] # lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), // Speed
    [west, east, independent, civilian] # lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), // Side
    [ // Delay
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14)
    ],
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08)
]
