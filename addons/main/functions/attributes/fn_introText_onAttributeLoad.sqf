#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the intro text attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_delay", "_line1", "_line2", "_line3", "_introType"];

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), "s"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), "s", _delay] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText _line1;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText _line2;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText _line3;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) lbSetCurSel _introType;

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), "s", 0] call BIS_fnc_initSliderValue;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText briefingName;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText ('by ' + profileName);
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText ([dayTime, 'HH:MM'] call BIS_fnc_TimeToString);
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) lbSetCurSel 0;
}];
