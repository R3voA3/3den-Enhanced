#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the establishingShot attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_center", "_text", "_alt", "_r", "_angle", "_dir"];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText str (_center#0);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText str (_center#1);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText str (_center#2);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText _text;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText str _alt;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText str _r;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText str _angle;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08), "°"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08), "°", _angle] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09) lbSetCurSel _dir;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlAddEventHandler ["ButtonClick",
{
    private _array = call ENH_fnc_array3FromClipboard;

    if (_array isNotEqualTo []) then
    {
        private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText str (_array#0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText str (_array#1);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText str (_array#2);
    };
}];

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText "0";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText (getText (configFile >> "CfgWorlds" >> worldName >> "description"));
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText "500";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText "200";

    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08), "°", 60] call BIS_fnc_initSliderValue;

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09) lbSetCurSel 0;
}];
