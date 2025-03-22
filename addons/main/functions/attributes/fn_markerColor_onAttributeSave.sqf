#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Used by the marker color attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

private _history = profileNamespace getVariable ["ENH_Attributes_MarkerColor_History", createHashMap];

private _colorRGB =
[
    round (sliderPosition (_ctrlGroup controlsGroupCtrl 101) * 100) / 100,
    round (sliderPosition (_ctrlGroup controlsGroupCtrl 103) * 100) / 100,
    round (sliderPosition (_ctrlGroup controlsGroupCtrl 105) * 100) / 100
];

private _hash = hashValue _colorRGB;
private _notNew = _history set [_hash, _colorRGB, true];

if (!_notNew) then
{
    profileNamespace setVariable ["ENH_Attributes_MarkerColor_History", _history];
    // saveProfileNamespace;
};

[
    cbChecked (_ctrlGroup controlsGroupCtrl 100),
    format
    [
        "#(%1,%2,%3)",
        _colorRGB#0,
        _colorRGB#1,
        _colorRGB#2
    ]
]
