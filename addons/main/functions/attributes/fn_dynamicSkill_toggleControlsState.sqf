#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-04-06

    Description:
    Toggles enabled state of slider and edit controls.

    Parameter(s):
    0: CONTROL - Checkbox

    Return Value:
    -
*/

params ["_ctrlCheckbox"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlCheckbox;
private _state = cbChecked _ctrlCheckbox;

allControls _ctrlGroup apply
{
    if (ctrlType _x in [CT_EDIT, CT_XSLIDER]) then
    {
        _x ctrlEnable _state;
    };
};
