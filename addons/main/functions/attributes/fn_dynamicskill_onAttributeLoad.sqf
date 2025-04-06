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

(_ctrlGroup controlsGroupCtrl 100) ctrlAddEventHandler ["CheckedChanged",
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

private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl 100;

_ctrlCheckbox cbSetChecked _enable;

// Handle state of controls
[_ctrlCheckbox] call ENH_fnc_dynamicSkill_toggleControlsState;
(_ctrlGroup controlsGroupCtrl 100) ctrlAddEventHandler ["CheckedChanged", ENH_fnc_dynamicSkill_toggleControlsState];

[_ctrlGroup controlsGroupCtrl 101, _ctrlGroup controlsGroupCtrl 102, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 101, _ctrlGroup controlsGroupCtrl 102, "%", _skillMinBLUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "%", _skillAimMinBLUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 105, _ctrlGroup controlsGroupCtrl 106, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 105, _ctrlGroup controlsGroupCtrl 106, "%", _skillMaxBLUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "%", _skillAimMaxBlUFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 109, _ctrlGroup controlsGroupCtrl 110, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 109, _ctrlGroup controlsGroupCtrl 110, "%", _skillMinOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 111, _ctrlGroup controlsGroupCtrl 112, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 111, _ctrlGroup controlsGroupCtrl 112, "%", _skillAimMinOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 113, _ctrlGroup controlsGroupCtrl 114, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 113, _ctrlGroup controlsGroupCtrl 114, "%", _skillMaxOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 115, _ctrlGroup controlsGroupCtrl 116, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 115, _ctrlGroup controlsGroupCtrl 116, "%", _skillAimMaxOPFOR] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 117, _ctrlGroup controlsGroupCtrl 118, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 117, _ctrlGroup controlsGroupCtrl 118, "%", _skillMinIndependent] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 119, _ctrlGroup controlsGroupCtrl 120, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 119, _ctrlGroup controlsGroupCtrl 120, "%", _skillAimMinIndependent] call BIS_fnc_initSliderValue;


[_ctrlGroup controlsGroupCtrl 121, _ctrlGroup controlsGroupCtrl 122, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 121, _ctrlGroup controlsGroupCtrl 122, "%", _skillMaxIndependent] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 123, _ctrlGroup controlsGroupCtrl 124, "%"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 123, _ctrlGroup controlsGroupCtrl 124, "%", _skillAimMaxIndependent] call BIS_fnc_initSliderValue;

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl 100) cbSetChecked false;
    //BLUFOR
    [_ctrlGroup controlsGroupCtrl 101, _ctrlGroup controlsGroupCtrl 102, "%", 0.5] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "%", 0.3] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 105, _ctrlGroup controlsGroupCtrl 106, "%", 0.8] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "%", 0.5] call BIS_fnc_initSliderValue;
    //OPFOR
    [_ctrlGroup controlsGroupCtrl 109, _ctrlGroup controlsGroupCtrl 110, "%", 0.5] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 111, _ctrlGroup controlsGroupCtrl 112, "%", 0.3] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 113, _ctrlGroup controlsGroupCtrl 114, "%", 0.8] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 115, _ctrlGroup controlsGroupCtrl 116, "%", 0.5] call BIS_fnc_initSliderValue;
    //Independent
    [_ctrlGroup controlsGroupCtrl 117, _ctrlGroup controlsGroupCtrl 118, "%", 0.5] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 119, _ctrlGroup controlsGroupCtrl 120, "%", 0.3] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 121, _ctrlGroup controlsGroupCtrl 122, "%", 0.8] call BIS_fnc_initSliderValue;
    [_ctrlGroup controlsGroupCtrl 123, _ctrlGroup controlsGroupCtrl 124, "%", 0.5] call BIS_fnc_initSliderValue;
}];
