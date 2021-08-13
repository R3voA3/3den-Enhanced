class ENH_AI
{
  displayName = "$STR_ENH_AI_CATEGORY";
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
      displayName = "$STR_ENH_AIMINGSHAKE_DISPLAYNAME";
      tooltip = "$STR_ENH_AIMINGSHAKE_TOOLTIP";
      property = "ENH_aimingShake";
      expression = "_this setSkill ['aimingShake', _value]";
      control = "Slider";
      defaultValue = "0.5";
      condition = "objectBrain";
    };
    class ENH_AimingSpeed: ENH_AimingShake
    {
      displayName = "$STR_ENH_AIMINGSPEED_DISPLAYNAME";
      tooltip = "$STR_ENH_AIMINGSPEED_TOOLTIP";
      property = "ENH_aimingSpeed";
      expression = "_this setSkill ['aimingSpeed', _value]";
    };
    class ENH_AimingAccuracy: ENH_AimingShake
    {
      displayName = "$STR_ENH_AIMINGACCURACY_DISPLAYNAME";
      tooltip = "$STR_ENH_AIMINGACCURACY_TOOLTIP";
      property = "ENH_aimingAccuracy";
      expression = "_this setSkill ['aimingAccuracy', _value]";
    };
    class ENH_Commanding: ENH_AimingShake
    {
      displayName = "$STR_ENH_COMMANDING_DISPLAYNAME";
      tooltip = "$STR_ENH_COMMANDING_TOOLTIP";
      property = "ENH_commanding";
      expression = "_this setSkill ['commanding', _value]";
    };
    class ENH_Courage: ENH_AimingShake
    {
      displayName = "$STR_ENH_COURAGE_DISPLAYNAME";
      tooltip = "$STR_ENH_COURAGE_TOOLTIP";
      property = "ENH_courage";
      expression = "_this setSkill ['courage', _value]";
    };
    class ENH_General: ENH_AimingShake
    {
      displayName = "$STR_ENH_GENERAL_DISPLAYNAME";
      tooltip = "$STR_ENH_GENERAL_TOOLTIP";
      property = "enh_general";
      expression = "_this setSkill ['general', _value]";
    };
    class ENH_ReloadSpeed: ENH_AimingShake
    {
      displayName = "$STR_ENH_RELOADSPEED_DISPLAYNAME";
      tooltip = "$STR_ENH_RELOADSPEED_TOOLTIP";
      property = "ENH_reloadingSpeed";
      expression = "_this setSkill ['reloadSpeed', _value]";
    };
    class ENH_SpotDistance: ENH_AimingShake
    {
      displayName = "$STR_ENH_SPOTDISTANCE_DISPLAYNAME";
      tooltip = "$STR_ENH_SPOTDISTANCE_TOOLTIP";
      property = "ENH_spotDistance";
      expression = "_this setSkill ['spotDistance', _value]";
    };
    class ENH_SpotTime: ENH_AimingShake
    {
      displayName = "$STR_ENH_SPOTTIME_DISPLAYNAME";
      tooltip = "$STR_ENH_SPOTTIME_TOOLTIP";
      property = "ENH_spotTime";
      expression = "_this setSkill ['spotTime', _value]";
    };
    //----------------Not really skill, but still related to behaviour of AI
    class ENH_AllowFleeing: ENH_AimingShake
    {
      displayName = "$STR_ENH_ALLOWFLEEING_DISPLAYNAME";
      tooltip = "$STR_ENH_ALLOWFLEEING_TOOLTIP";
      property = "ENH_allowFleeing";
      expression = "_this allowFleeing _value";
    };
    //----------------AI Features
    class ENH_AI_Features_Subcategory: ENH_AI_Skill_SubCategory
    {
      description = "$STR_ENH_DISABLEAI_SUBCATEGORY";
      data = "AttributeSystemSubcategory";
    };
    class ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_ALL_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_ALL_TOOLTIP";
      property = "ENH_disableAI_all";
      control = "Checkbox";
      expression = "if (_value) then {_this disableAI 'all'}";
      defaultValue = "false";
      condition = "objectBrain";
    };
    class ENH_Move: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_MOVE_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_MOVE_TOOLTIP";
      property = "ENH_disableAI_move";
      expression = "if (_value) then {_this disableAI 'MOVE'}";
    };
    class ENH_Target: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_TARGET_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_TARGET_TOOLTIP";
      property = "ENH_disableAI_target";
      expression = "if (_value) then {_this disableAI 'TARGET'}";
    };
    class ENH_Cover: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_COVER_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_COVER_TOOLTIP";
      property = "ENH_disableAI_cover";
      expression = "if (_value) then {_this disableAI 'COVER'}";
    };
    class ENH_Autotarget: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_AUTOTARGET_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_AUTOTARGET_TOOLTIP";
      property = "ENH_disableAI_autotarget";
      expression = "if (_value) then {_this disableAI 'AUTOTARGET'}";
    };
    class ENH_Animation: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_ANIM_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_ANIM_TOOLTIP";
      property = "ENH_disableAI_anim";
      expression = "if (_value) then {_this disableAI 'ANIM'}";
    };
    class ENH_FSM: ENH_All
    {
      displayName = "FSM";
      tooltip = "$STR_ENH_DISABLEAI_FSM_TOOLTIP";
      property = "ENH_disableAI_FSM";
      expression = "if (_value) then {_this disableAI 'FSM'}";
    };
    class ENH_AimingError: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_AIMINGERROR_DISPLAYNAME";
      tooltip =  "$STR_ENH_DISABLEAI_AIMINGERROR_TOOLTIP";
      property = "ENH_disableAI_aimingError";
      expression = "if (_value) then {_this disableAI 'AIMINGERROR'}";
    };
    class ENH_TeamSwitch: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_TEAMSWITCH_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_TEAMSWITCH_TOOLTIP";
      property = "ENH_disableAI_teamswitch";
      expression = "if (_value) then {_this disableAI 'TEAMSWITCH'}";
    };
    class ENH_Suppression: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_SUPPRESSION_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_SUPPRESSION_TOOLTIP";
      property = "ENH_disableAI_suppression";
      expression = "if (_value) then {_this disableAI 'SUPPRESSION'}";
    };
    class ENH_CheckVisible: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_RAYCASTS_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_RAYCASTS_TOOLTIP";
      property = "ENH_disableAI_checkVisible";
      expression = "if (_value) then {_this disableAI 'CHECKVISIBLE'}";
    };
    class ENH_Autocombat: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_AUTOCOMBAT_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_AUTOCOMBAT_TOOLTIP";
      property = "ENH_disableAI_autocombat";
      expression = "if (_value) then {_this disableAI 'AUTOCOMBAT'}";
    };
    class ENH_Path: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_PATH_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_PATH_TOOLTIP";
      property = "ENH_disableAI_path";
      expression = "if (_value) then {_this disableAI 'PATH'}";
    };
    class ENH_MineDetection: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_MINEDETECTION_DISPLAYNAME";
      tooltip = "";
      property = "ENH_disableAI_mineDetection";
      expression = "if (_value) then {_this disableAI 'MINEDETECTION'}";
    };
    class ENH_WeaponAim: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_WEAPONAIM_DISPLAYNAME";
      tooltip = "";
      property = "ENH_disableAI_weaponAim";
      expression = "if (_value) then {_this disableAI 'WEAPONAIM'}";
    };
    class ENH_NVG: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_NVG_DISPLAYNAME";
      tooltip = "";
      property = "ENH_disableAI_NVG";
      expression = "if (_value) then {_this disableAI 'NVG'}";
    };
    class ENH_Lights: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_LIGHTS_DISPLAYNAME";
      tooltip = "";
      property = "ENH_disableAI_lights";
      expression = "if (_value) then {_this disableAI 'LIGHTS'}";
    };
    class ENH_RadioProtocol: ENH_All
    {
      displayName = "$STR_ENH_DISABLEAI_RADIOPROTOCOL_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_RADIOPROTOCOL_TOOLTIP";
      property = "ENH_disableAI_radioProtocol";
      expression = "if (_value) then {_this disableAI 'RADIOPROTOCOL'}";
    };
  };
};