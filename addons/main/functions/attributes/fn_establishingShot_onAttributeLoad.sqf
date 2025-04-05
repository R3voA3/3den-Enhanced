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

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText str (_center#0);
(_ctrlGroup controlsGroupCtrl 101) ctrlSetText str (_center#1);
(_ctrlGroup controlsGroupCtrl 102) ctrlSetText str (_center#2);

(_ctrlGroup controlsGroupCtrl 104) ctrlSetText _text;
(_ctrlGroup controlsGroupCtrl 105) ctrlSetText str _alt;
(_ctrlGroup controlsGroupCtrl 106) ctrlSetText str _r;
(_ctrlGroup controlsGroupCtrl 107) ctrlSetText str _angle;

[_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "°"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "°", _angle] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 109) lbSetCurSel _dir;

(_ctrlGroup controlsGroupCtrl 103) ctrlAddEventHandler ["ButtonClick",
{
    private _array = call ENH_fnc_array3FromClipboard;

    if (_array isNotEqualTo []) then
    {
        private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
        (_ctrlGroup controlsGroupCtrl 100) ctrlSetText str (_array#0);
        (_ctrlGroup controlsGroupCtrl 101) ctrlSetText str (_array#1);
        (_ctrlGroup controlsGroupCtrl 102) ctrlSetText str (_array#2);
    };
}];

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl 100) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl 101) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl 102) ctrlSetText "0";

    (_ctrlGroup controlsGroupCtrl 104) ctrlSetText (getText (configFile >> "CfgWorlds" >> worldName >> "description"));
    (_ctrlGroup controlsGroupCtrl 105) ctrlSetText "500";
    (_ctrlGroup controlsGroupCtrl 106) ctrlSetText "200";

    [_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "°", 60] call BIS_fnc_initSliderValue;

    (_ctrlGroup controlsGroupCtrl 109) lbSetCurSel 0;
}];
