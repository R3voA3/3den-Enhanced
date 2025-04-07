#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the hold action attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

#define DEFAULT_ICONS [\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa",\
    "\a3\data_f_destroyer\data\UI\IGUI\Cfg\holdactions\holdAction_loadVehicle_ca.paa",\
    "\a3\data_f_destroyer\data\UI\IGUI\Cfg\holdactions\holdAction_unloadVehicle_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_box_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_follow_start_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_follow_stop_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_talk_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_forceRespawn_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_hack_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_loaddevice_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_passleadership_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_requestleadership_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_reviveMedic_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_secure_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_takeOff1_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_takeOff2_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_thumbsdown_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_thumbsup_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unbind_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unloaddevice_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\attack_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\destroy_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\holdAction_market_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\holdAction_sleep2_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\holdAction_sleep_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\map_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\meet_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\refuel_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\repair_ca.paa"\
]

params ["_ctrlGroup", "_value"];

_value params
[
    "_name",
    "_iconIdle",
    "_iconProgress",
    "_conditionShow",
    "_conditionProgress",
    "_codeStart",
    "_codeProgress",
    "_codeCompletion",
    "_codeInterrupt",
    "_duration",
    "_priority",
    "_showUnconscious",
    "_showWindow",
    "_removeAfterUse"
];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText _name;

//Fill icon combos
_ctrlIconIdle = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01;
{
    _ctrlIconIdle lbAdd _x;
    _ctrlIconIdle lbSetPicture [_forEachIndex, _x];
    if (_x isEqualTo _iconIdle) then
    {
        _ctrlIconIdle lbSetCurSel _forEachIndex;
    };
} forEach DEFAULT_ICONS;

_ctrlIconProgress = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02;
{
    _ctrlIconProgress lbAdd _x;
    _ctrlIconProgress lbSetPicture [_forEachIndex, _x];
    if (_x isEqualTo _iconProgress) then
    {
        _ctrlIconProgress lbSetCurSel _forEachIndex;
    };
} forEach DEFAULT_ICONS;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText _conditionShow;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText _conditionProgress;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText _codeStart;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText _codeProgress;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText _codeCompletion;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08) ctrlSetText _codeInterrupt;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "s"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "s", _duration] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), ""] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), "", _priority] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13) cbSetChecked _showUnconscious;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14) cbSetChecked _showWindow;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15) cbSetChecked _removeAfterUse;

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) lbSetCurSel 0;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) lbSetCurSel 0;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText "true";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText "true";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08) ctrlSetText "";
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "s", 10] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), "", 1000] call BIS_fnc_initSliderValue;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13) cbSetChecked false;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14) cbSetChecked true;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15) cbSetChecked true;
}];
