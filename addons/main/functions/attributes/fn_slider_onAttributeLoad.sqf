#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by simple slider attributes. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: NUMBER - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), "x"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), "x", _value] call BIS_fnc_initSliderValue;
