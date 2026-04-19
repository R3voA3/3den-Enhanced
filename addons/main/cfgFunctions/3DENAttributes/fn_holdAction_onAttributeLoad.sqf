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

#define DEFAULT_ICONS\
[\
    "\a3\data_f_destroyer\data\UI\IGUI\Cfg\holdactions\holdAction_loadVehicle_ca.paa",\
    "\a3\data_f_destroyer\data\UI\IGUI\Cfg\holdactions\holdAction_unloadVehicle_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_box_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_follow_start_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_follow_stop_ca.paa",\
    "\a3\missions_f_oldman\data\img\holdactions\holdAction_talk_ca.paa",\
    "\a3\ui_f_aow\data\igui\cfg\holdactions\holdaction_charity_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\attack_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\destroy_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\holdAction_market_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\holdAction_sleep_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\holdAction_sleep2_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\map_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\meet_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\refuel_ca.paa",\
    "\a3\ui_f_oldman\data\IGUI\Cfg\holdactions\repair_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_forceRespawn_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_hack_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_loaddevice_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_passleadership_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_requestleadership_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_reviveMedic_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_secure_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_takeOff1_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_takeOff2_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_thumbsdown_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_thumbsup_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unbind_ca.paa",\
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unloaddevice_ca.paa",\
    "\a3\Missions_F_Orange\Data\Img\Showcase_LawsOfWar\action_access_fm_CA.paa",\
    "\a3\Missions_F_Orange\Data\Img\Showcase_LawsOfWar\action_end_sim_CA.paa",\
    "\a3\Missions_F_Orange\Data\Img\Showcase_LawsOfWar\action_exit_CA.paa",\
    "\a3\Missions_F_Orange\Data\Img\Showcase_LawsOfWar\action_start_sim_CA.paa",\
    "\a3\Missions_F_Orange\Data\Img\Showcase_LawsOfWar\action_view_article_CA.paa",\
    "\a3\props_f_enoch\items\tools\data\tinfoil_action_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_aaf_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_csat_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_escape_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_fia_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_fragment_back_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_fragment_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_idap_ca.paa",\
    "\a3\ui_f_orange\Data\CfgOrange\Missions\action_nato_ca.paa",\
    "\a3\ui_f_jets\data\igui\cfg\actions\action_attachtocatapult_ca.paa",\
    "\a3\ui_f_jets\data\igui\cfg\actions\action_detachtocatapult_ca.paa",\
    "\a3\ui_f_jets\data\igui\cfg\actions\action_launchfromcatapult_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\arrow_down_gs.paa",\
    "\a3\ui_f\data\igui\cfg\actions\arrow_up_gs.paa",\
    "\a3\ui_f\data\igui\cfg\actions\autohover_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\bandage_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\beacons_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\beacons_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\cancelhover_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\close_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\eject_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\engine_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\engine_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\flapsextend_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\flapsretract_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\gear_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\getincargo_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\getincommander_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\getindriver_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\getingunner_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\getout_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\heal_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_batt_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_batt_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_brk_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_col_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_col_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_land_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_land_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_start_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_start_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_thtl_idl_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_thtl_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_cpt_thtl_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ico_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ladderdown_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ladderoff_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\ladderup_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\landingautopilot_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\landingautopilot_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\loadvehicle_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_arrow_up_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_cancel_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_cancel_manualfire_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_deactivate_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_enter_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_exit_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_fire_in_flame_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_fire_put_down_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_gear_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_getin_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_getincargo.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_ladderondown_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_ladderonup_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_manualfire_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_open_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_takemagazine_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_takemine_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_takeweapon_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_teamswitch_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_turnin_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\obsolete\ui_action_turnout_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\open_door_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\periscopedepth_off_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\periscopedepth_on_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\radaroff_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\radaron_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\reammo_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\refuel_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\reload_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\repair_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\returnflag_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\settimer_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\take_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\takeflag_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\talk_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\unloadallvehicles_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\unloadincapacitated_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\unloadvehicle_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\vtolvectoring_ca.paa",\
    "\a3\ui_f\data\igui\cfg\actions\vtolvectoringcancel_ca.paa"\
]

private _additionalIcons = profileNamespace getVariable ["ENH_EditorPreferences_HoldActionIcons", []];

// Prevent issues if user entered custom icons with quotes
{
    if (_x select [0, 1] == """") then
    {
        _additionalIcons set [_forEachIndex, call compile _x];
    };
} forEach _additionalIcons;


uiNamespace setVariable ["ENH_HoldAction_Icons", DEFAULT_ICONS + _additionalIcons];

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
    "_removeAfterUse",
    "_radius"
];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText _name;

private _clickCode =
{
    params ["_ctrl"];
    [
        ctrlParent _ctrl,
        _ctrl,
        uiNamespace getVariable ["ENH_HoldAction_Icons", [DEFAULT_ICONS]],
        ctrlText _ctrl
    ] call ENH_fnc_iconPicker;
};

_ctrlIconIdle = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01;
_ctrlIconIdle ctrlAddEventHandler ["ButtonClick", _clickCode];

_ctrlIconIdle ctrlSetText _iconIdle;

_ctrlIconProgress = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02;
_ctrlIconProgress ctrlAddEventHandler ["ButtonClick", _clickCode];

_ctrlIconProgress ctrlSetText _iconProgress;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText localize "$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_DISPLAYNAME";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetTooltip localize "$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_TOOLTIP";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText _conditionShow;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText localize "$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_DISPLAYNAME";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetTooltip localize "$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_TOOLTIP";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText _conditionProgress;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText localize "$STR_ENH_MAIN_HOLDACTION_CODESTART_DISPLAYNAME";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetTooltip localize "$STR_ENH_MAIN_HOLDACTION_CODESTART_TOOLTIP";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText _codeStart;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText localize "$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_DISPLAYNAME";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetTooltip localize "$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_TOOLTIP";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText _codeProgress;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText localize "$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_DISPLAYNAME";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetTooltip localize "$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_TOOLTIP";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText _codeCompletion;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText localize "$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_DISPLAYNAME";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetTooltip localize "$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_TOOLTIP";
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText _codeInterrupt;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "s"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "s", _duration] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), ""] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), "", _priority] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_16), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17), ""] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_16), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17), "", _radius] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13) cbSetChecked _showUnconscious;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14) cbSetChecked _showWindow;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15) cbSetChecked _removeAfterUse;

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "true";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "true";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08 controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "";
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10), "s", 10] call BIS_fnc_initSliderValue;
    [(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12), "", 1000] call BIS_fnc_initSliderValue;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13) cbSetChecked false;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14) cbSetChecked true;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15) cbSetChecked true;
}];
