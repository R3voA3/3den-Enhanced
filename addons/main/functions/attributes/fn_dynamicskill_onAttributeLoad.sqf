#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the dynamic skill attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    BOOLEAN: true
*/

params ["_ctrlGroup", "_value"];
_value params
[
    "_enable",
    "_skillMinBLUFOR",
    "_skillAimMinBLUFOR",
    "_skillMaxBLUFOR",
    "_skillAimMaxBlUFOR",
    "_skillMinOPFOR",
    "_skillAimMinOPFOR",
    "_skillMaxOPFOR",
    "_skillAimMaxOPFOR",
    "_skillMinIndependent",
    "_skillAimMinIndependent",
    "_skillMaxIndependent",
    "_skillAimMaxIndependent"
];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlAddEventHandler ["CheckedChanged",
{
    params ["_ctrlCheckbox", "_checked"];

    private _ctrlGroup = ctrlParentControlsGroup _ctrlCheckbox;
    private _boolChecked = _checked > 0;

    allControls _ctrlGroup apply
    {
        if (ctrlType _x in [CT_EDIT, CT_XSLIDER]) then
        {
            _x ctrlEnable _boolChecked;
        };
    };
}];

private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;

_ctrlCheckbox cbSetChecked _enable;

// Handle state of controls
[_ctrlCheckbox] call ENH_fnc_dynamicSkill_toggleControlsState;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlAddEventHandler ["CheckedChanged", ENH_fnc_dynamicSkill_toggleControlsState];

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02), "%", _skillMinBLUFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04), "%", _skillAimMinBLUFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06), "%", _skillMaxBLUFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08), "%", _skillAimMaxBlUFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "%", _skillMinOPFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), "%", _skillAimMinOPFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14), "%", _skillMaxOPFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_16), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_16), "%", _skillAimMaxOPFOR] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_18), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_18), "%", _skillMinIndependent] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_19), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_20), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_19), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_20), "%", _skillAimMinIndependent] call BIS_fnc_initSliderValue;


[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_21), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_22), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_21), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_22), "%", _skillMaxIndependent] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_23), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_24), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_23), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_24), "%", _skillAimMaxIndependent] call BIS_fnc_initSliderValue;

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
    private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;

    _ctrlCheckbox cbSetChecked false;
    [_ctrlCheckbox] call ENH_fnc_dynamicSkill_toggleControlsState;

    // BLUFOR
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02), "%", 0.5] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04), "%", 0.3] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06), "%", 0.8] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08), "%", 0.5] call BIS_fnc_initSliderValue;
    // OPFOR
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "%", 0.5] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), "%", 0.3] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14), "%", 0.8] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_16), "%", 0.5] call BIS_fnc_initSliderValue;
    // Independent
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_18), "%", 0.5] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_19), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_20), "%", 0.3] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_21), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_22), "%", 0.8] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_23), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_24), "%", 0.5] call BIS_fnc_initSliderValue;
}];
