#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the map indicators attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Array with booleans, attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_hideFriendly", "_hideEnemy", "_hideMines", "_hidePing"];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) cbSetChecked _hideFriendly;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) cbSetChecked _hideEnemy;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) cbSetChecked _hideMines;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) cbSetChecked _hidePing;
