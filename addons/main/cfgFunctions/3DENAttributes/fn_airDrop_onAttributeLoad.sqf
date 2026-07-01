#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the airdrop attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_classes", "_center", "_condition", "_alt", "_r", "_side"];

if (_classes isEqualType "") then
{
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText _classes;
}
else
{
    // Change classes from type array to type string
    private _valueClasses = "";

    {
        private _add = if (_forEachIndex == 0) then {_x} else {format [", %1", _x]};
        _valueClasses = _valueClasses + _add;
    } forEach _classes;

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText _valueClasses;
};

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText str (_center#0);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText str (_center#1);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText str (_center#2);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText _condition;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText str _alt;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText str _r;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08) lbSetCurSel ([west, east, independent, civilian] find _side);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlAddEventHandler ["ButtonClick",
{
    private _array = call ENH_fnc_array3FromClipboard;

    if (_array isNotEqualTo []) then
    {
        private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText str (_array#0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText str (_array#1);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText str (_array#2);
    };
}];

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText "";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText "0";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText "false";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText "500";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText "200";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08) lbSetCurSel 0;
}];
