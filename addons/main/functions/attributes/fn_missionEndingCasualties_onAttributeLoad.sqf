#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the mission ending attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Array with booleans, attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_threshold", "_debriefing", "_isWin", "_side"];

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), ""] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), "", _threshold] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02), _debriefing] call ENH_fnc_missionEndingCasualties_initDebriefingCombo;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) cbSetChecked _isWin;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) lbSetCurSel ([west, east, independent, civilian] find _side);

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), "", 5] call BIS_fnc_initSliderValue;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) lbSetCurSel 0;

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) cbSetChecked false;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) lbSetCurSel ([west, east, independent, civilian] find civilian);
}];
