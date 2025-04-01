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

private _ctrlClassesTree = _ctrlGroup controlsGroupCtrl 500;
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
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 101),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 102),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 103)
    ],
    [ // End pos
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 105),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 106),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 107)
    ],
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 109), // Altitude
    ["limited", "normal", "full"] # lbCurSel (_ctrlGroup controlsGroupCtrl 110), // Speed
    [west, east, independent, civilian] # lbCurSel (_ctrlGroup controlsGroupCtrl 111), // Side
    [ // Delay
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 112),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 113),
        parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 114)
    ],
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 104),
    parseNumber ctrlText (_ctrlGroup controlsGroupCtrl 108)
]
