#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-09-09

    Description:
    Saves attribute value from listbox into an array.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

private _ctrlListbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;

private _value = [];

for "_i" from 0 to (lbSize _ctrlListbox - 1) do
{
    _value append [(_ctrlListbox lbText _i)];
};

_value
