class ENH_AI
{
    displayName = "$STR_ENH_MAIN_AI_CATEGORY";
    collapsed = 1;
    class Attributes
    {
        //----------------SKILL
        class ENH_AI_Skill_Subcategory
        {
            description = "$STR_A3_RSCDISPLAYGAMEOPTIONS_TEXTAISKILL";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        class ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_AIMINGSHAKE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AIMINGSHAKE_TOOLTIP";
            property = "ENH_aimingShake";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['aimingShake', _value]] remoteExec ['setSkill', _this]";
            control = "Slider";
            defaultValue = "0.5";
            condition = "objectBrain";
        };
        class ENH_AimingSpeed: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_AIMINGSPEED_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AIMINGSPEED_TOOLTIP";
            property = "ENH_aimingSpeed";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['aimingSpeed', _value]] remoteExec ['setSkill', _this]";
        };
        class ENH_AimingAccuracy: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_AIMINGACCURACY_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AIMINGACCURACY_TOOLTIP";
            property = "ENH_aimingAccuracy";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['aimingAccuracy', _value]] remoteExec ['setSkill', _this]";
        };
        class ENH_Commanding: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_COMMANDING_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_COMMANDING_TOOLTIP";
            property = "ENH_commanding";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['commanding', _value]] remoteExec ['setSkill', _this]";
        };
        class ENH_Courage: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_COURAGE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_COURAGE_TOOLTIP";
            property = "ENH_courage";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['courage', _value]] remoteExec ['setSkill', _this]";
        };
        class ENH_General: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_GENERAL_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_GENERAL_TOOLTIP";
            property = "enh_general";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['general', _value]] remoteExec ['setSkill', _this]";
        };
        class ENH_ReloadSpeed: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_RELOADSPEED_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_RELOADSPEED_TOOLTIP";
            property = "ENH_reloadingSpeed";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['reloadSpeed', _value]] remoteExec ['setSkill', _this]";
        };
        class ENH_SpotDistance: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_SPOTDISTANCE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_SPOTDISTANCE_TOOLTIP";
            property = "ENH_spotDistance";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['spotDistance', _value]] remoteExec ['setSkill', _this]";
        };
        class ENH_SpotTime: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_SPOTTIME_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_SPOTTIME_TOOLTIP";
            property = "ENH_spotTime";
            expression = "if (_value == 0.5) exitWith {}; [_this, ['spotTime', _value]] remoteExec ['setSkill', _this]";
        };
        //----------------Not really skill, but still related to behaviour of AI
        class ENH_AllowFleeing: ENH_AimingShake
        {
            displayName = "$STR_ENH_MAIN_ALLOWFLEEING_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_ALLOWFLEEING_TOOLTIP";
            property = "ENH_allowFleeing";
            expression = "if (_value == 0.5) exitWith {}; [_this, _value] remoteExec ['allowFleeing', _this]";
        };
        //----------------AI Features
        class ENH_AI_Features_Subcategory: ENH_AI_Skill_Subcategory
        {
            description = "$STR_ENH_MAIN_DISABLEAI_SUBCATEGORY";
            data = "AttributeSystemSubcategory";
        };
        class ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_ALL_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_ALL_TOOLTIP";
            property = "ENH_disableAI_all";
            control = "Checkbox";
            expression = "if (_value) then {[_this, 'all'] remoteExec ['disableAI', _this]}";
            defaultValue = "false";
            condition = "objectBrain";
        };
        class ENH_Move: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_MOVE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_MOVE_TOOLTIP";
            property = "ENH_disableAI_move";
            expression = "if (_value) then {[_this, 'MOVE'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Target: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_TARGET_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_TARGET_TOOLTIP";
            property = "ENH_disableAI_target";
            expression = "if (_value) then {[_this, 'TARGET'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Cover: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_COVER_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_COVER_TOOLTIP";
            property = "ENH_disableAI_cover";
            expression = "if (_value) then {[_this, 'COVER'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Autotarget: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_AUTOTARGET_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_AUTOTARGET_TOOLTIP";
            property = "ENH_disableAI_autotarget";
            expression = "if (_value) then {[_this, 'AUTOTARGET'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Animation: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_ANIM_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_ANIM_TOOLTIP";
            property = "ENH_disableAI_anim";
            expression = "if (_value) then {[_this, 'ANIM'] remoteExec ['disableAI', _this]}";
        };
        class ENH_FSM: ENH_All
        {
            displayName = "FSM";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_FSM_TOOLTIP";
            property = "ENH_disableAI_FSM";
            expression = "if (_value) then {[_this, 'FSM'] remoteExec ['disableAI', _this]}";
        };
        class ENH_AimingError: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_AIMINGERROR_DISPLAYNAME";
            tooltip =  "$STR_ENH_MAIN_DISABLEAI_AIMINGERROR_TOOLTIP";
            property = "ENH_disableAI_aimingError";
            expression = "if (_value) then {[_this, 'AIMINGERROR'] remoteExec ['disableAI', _this]}";
        };
        class ENH_TeamSwitch: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_TEAMSWITCH_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_TEAMSWITCH_TOOLTIP";
            property = "ENH_disableAI_teamswitch";
            expression = "if (_value) then {[_this, 'TEAMSWITCH'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Suppression: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_SUPPRESSION_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_SUPPRESSION_TOOLTIP";
            property = "ENH_disableAI_suppression";
            expression = "if (_value) then {[_this, 'SUPPRESSION'] remoteExec ['disableAI', _this]}";
        };
        class ENH_CheckVisible: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_RAYCASTS_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_RAYCASTS_TOOLTIP";
            property = "ENH_disableAI_checkVisible";
            expression = "if (_value) then {[_this, 'CHECKVISIBLE'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Autocombat: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_AUTOCOMBAT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_AUTOCOMBAT_TOOLTIP";
            property = "ENH_disableAI_autocombat";
            expression = "if (_value) then {[_this, 'AUTOCOMBAT'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Path: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_PATH_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_PATH_TOOLTIP";
            property = "ENH_disableAI_path";
            expression = "if (_value) then {[_this, 'PATH'] remoteExec ['disableAI', _this]}";
        };
        class ENH_MineDetection: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_MINEDETECTION_DISPLAYNAME";
            tooltip = "";
            property = "ENH_disableAI_mineDetection";
            expression = "if (_value) then {[_this, 'MINEDETECTION'] remoteExec ['disableAI', _this]}";
        };
        class ENH_WeaponAim: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_WEAPONAIM_DISPLAYNAME";
            tooltip = "";
            property = "ENH_disableAI_weaponAim";
            expression = "if (_value) then {[_this, 'WEAPONAIM'] remoteExec ['disableAI', _this]}";
        };
        class ENH_NVG: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_NVG_DISPLAYNAME";
            tooltip = "";
            property = "ENH_disableAI_NVG";
            expression = "if (_value) then {[_this, 'NVG'] remoteExec ['disableAI', _this]}";
        };
        class ENH_Lights: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_LIGHTS_DISPLAYNAME";
            tooltip = "";
            property = "ENH_disableAI_lights";
            expression = "if (_value) then {[_this, 'LIGHTS'] remoteExec ['disableAI', _this]}";
        };
        class ENH_RadioProtocol: ENH_All
        {
            displayName = "$STR_ENH_MAIN_DISABLEAI_RADIOPROTOCOL_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DISABLEAI_RADIOPROTOCOL_TOOLTIP";
            property = "ENH_disableAI_radioProtocol";
            expression = "if (_value) then {[_this, 'RADIOPROTOCOL'] remoteExec ['disableAI', _this]}";
        };
    };
};