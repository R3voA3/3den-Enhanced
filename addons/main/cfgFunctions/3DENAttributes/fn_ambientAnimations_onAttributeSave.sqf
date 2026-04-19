#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the ambient animations attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value
*/

params ["_ctrlGroup"];

// Selection animations to pass to the attribute
private _animSet = (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) lbData lbCurSel (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00);
private _anims = switch _animSet do
{
    case "SHIELD_FROM_SUN":
    {
        ["Acts_ShieldFromSun_loop"];
    };
    case "STAND_IDLE_2":
    {
        ["acts_millerIdle"];
    };
    case "WORKING_AT_DESK":
    {
        ["acts_millerDisarming_deskLoop"];
    };
    case "HANDS_HELD_HIGH":
    {
        ["Acts_JetsMarshallingStop_loop"];
    };
    case "WARMUP":
    {
        ["Acts_AidlPercMstpSloWWpstDnon_warmup_6_loop"];
    };
    case "WARMUP_KNEELING":
    {
        ["Acts_AidlPercMstpSloWWrflDnon_warmup_6_loop"];
    };
    case "SIT_HANDCUFFED":
    {
        ["Acts_AidlPsitMstpSsurWnonDnon01", "Acts_AidlPsitMstpSsurWnonDnon02", "Acts_AidlPsitMstpSsurWnonDnon03", "Acts_AidlPsitMstpSsurWnonDnon04", "Acts_AidlPsitMstpSsurWnonDnon05"];
    };
    case "STAND_TALKING":
    {
        ["Acts_CivilTalking_1", "Acts_CivilTalking_2"];
    };
    case "STAND_IDLE":
    {
        ["Acts_CivilIdle_1", "Acts_CivilIdle_2"];
    };
    case "STAND_PISTOL":
    {
        ["Acts_Executioner_StandingLoop"];
    };
    case "ACCESSING_COMPUTER":
    {
        ["Acts_Accessing_Computer_Loop"]
    };
    case "WARMUP_1":
    {
        ["Acts_AidlPercMstpSloWWpstDnon_warmup_1_loop"]
    };
    case "WARMUP_2":
    {
        ["Acts_AidlPercMstpSnonWnonDnon_warmup_3_loop"]
    };
    case "RELAX_1":
    {
        ["Acts_Ambient_Relax_1"]
    };
    case "RELAX_2":
    {
        ["Acts_Ambient_Relax_2"]
    };
    case "RELAX_3":
    {
        ["Acts_Ambient_Relax_3"]
    };
    case "RELAX_4":
    {
        ["Acts_Ambient_Relax_4"]
    };
    case "BRIEFING_START":
    {
        ["Acts_Briefing_SA_StartLoop"]
    };
    case "HIDING_1":
    {
        ["Acts_CivilHiding_1"]
    };
    case "HIDING_2":
    {
        ["Acts_CivilHiding_2"]
    };
    case "IDLE_1":
    {
        ["Acts_CivilIdle_1"]
    };
    case "IDLE_2":
    {
        ["Acts_CivilIdle_2"]
    };
    case "INJURED_ARMS":
    {
        ["Acts_CivilInjuredArms_1"]
    };
    case "INJURED_CHEST":
    {
        ["Acts_CivilInjuredChest_1"]
    };
    case "INJURED_GENERAL":
    {
        ["Acts_CivilInjuredGeneral_1"]
    };
    case "INJURED_HEAD":
    {
        ["Acts_CivilInjuredHead_1"]
    };
    case "INJURED_LEGS":
    {
        ["Acts_CivilInjuredLegs_1"]
    };
    case "LISTENING_1":
    {
        ["Acts_CivilListening_1"]
    };
    case "LISTENING_2":
    {
        ["Acts_CivilListening_2"]
    };
    case "SHOCKED_1":
    {
        ["Acts_CivilShocked_1"]
    };
    case "SHOCKED_2":
    {
        ["Acts_CivilShocked_2"]
    };
    case "DANCE_1":
    {
        ["Acts_Dance_01"]
    };
    case "DANCE_2":
    {
        ["Acts_Dance_02"]
    };
    case "VICTIM":
    {
        ["Acts_ExecutionVictim_Loop"]
    };
    case "PHOTO":
    {
        ["Acts_StaticPose_Photo"]
    };
    case "KNEEL":
    {
        ["Acts_SupportTeam_Front_KneelLoop"]
    };
    case "UAV_JAMMING":
    {
        ["Acts_UGV_Jamming_Loop"]
    };
    case "WAKING":
    {
        ["Acts_Waking_Up_Player"]
    };
    case "WALKING":
    {
        ["Acts_WalkingChecking"]
    };
    case "WATCHING":
    {
        ["Acts_Watching_Fire_Loop"]
    };
    default
    {
        (_animSet call BIS_fnc_ambientAnimGetParams) param [0, []];
    };
};

// Make sure to exit with exact default value if nothing was set, so attribute data is not written to mission.sqf (Workaround)
if (_animSet isEqualTo "") exitWith {['', [], false, false]};

[
    _animSet, // Needs to be saved to restore the value when attribute is loaded
    _anims,
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01),
    cbChecked (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02)
]
