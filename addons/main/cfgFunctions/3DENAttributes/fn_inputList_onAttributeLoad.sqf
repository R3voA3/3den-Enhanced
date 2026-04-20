#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Fill attributes listbox from string or array value.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY, STRING - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];

if (_value isEqualType []) exitWith
{
    private _ctrlListbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;

    _value apply
    {
        _ctrlListbox lbAdd _x;
    };

    lbSort _ctrlListbox;
};

// If value is string, convert it to array and call function again
if (_value isEqualType "") exitWith
{
    _value = _value splitString " ,;";
    [_ctrlGroup, _value] call ENH_fnc_inputList_onAttributeLoad;
};
