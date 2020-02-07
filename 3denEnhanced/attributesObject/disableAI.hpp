class ENH_DisableAI
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_disableAI;
	class Attributes
	{
		class ENH_Move
		{
			displayName = $STR_ENH_disableAI_move_displayName;
			tooltip = $STR_ENH_disableAI_move_tooltip;
			property = "ENH_disableAI_move";
			control = "Checkbox";
			expression = "if(_value) then {_this disableAI 'MOVE'}";
			defaultValue = "false";
			condition = "objectBrain";
		};
		class ENH_Target: ENH_Move
		{
			displayName = $STR_ENH_disableAI_target_displayName;
			tooltip = $STR_ENH_disableAI_target_tooltip;
			property = "ENH_disableAI_target";
			expression = "if(_value) then {_this disableAI 'TARGET'}";
		};
		class ENH_Cover: ENH_Move
		{
			displayName = $STR_ENH_disableAI_cover_displayName;
			tooltip = $STR_ENH_disableAI_cover_tooltip;
			property = "ENH_disableAI_cover";
			expression = "if(_value) then {_this disableAI 'COVER'}";
		};
		class ENH_Autotarget: ENH_Move
		{
			displayName = $STR_ENH_disableAI_autotarget_displayName;
			tooltip = $STR_ENH_disableAI_autotarget_tooltip;
			property = "ENH_disableAI_autotarget";
			expression = "if(_value) then {_this disableAI 'AUTOTARGET'}";
		};
		class ENH_Animation: ENH_Move
		{
			displayName = $STR_ENH_disableAI_anim_displayName;
			tooltip = $STR_ENH_disableAI_anim_tooltip;
			property = "ENH_disableAI_anim";
			expression = "if(_value) then {_this disableAI 'ANIM'}";
		};
		class ENH_FSM: ENH_Move
		{
			displayName = "FSM";
			tooltip = $STR_ENH_disableAI_FSM_tooltip;
			property = "ENH_disableAI_FSM";
			expression = "if(_value) then {_this disableAI 'FSM'}";
		};
		class ENH_AimingError: ENH_Move
		{
			displayName = $STR_ENH_disableAI_aimingError_displayName;
			tooltip =  $STR_ENH_disableAI_aimingError_tooltip;
			property = "ENH_disableAI_aimingError";
			expression = "if(_value) then {_this disableAI 'AIMINGERROR'}";
		};
		class ENH_TeamSwitch: ENH_Move
		{
			displayName = $STR_ENH_disableAI_teamSwitch_displayName;
			tooltip = $STR_ENH_disableAI_teamSwitch_tooltip;
			property = "ENH_disableAI_teamswitch";
			expression = "if(_value) then {_this disableAI 'TEAMSWITCH'}";
		};
		class ENH_Suppression: ENH_Move
		{
			displayName = $STR_ENH_disableAI_suppression_displayName;
			tooltip = $STR_ENH_disableAI_suppression_tooltip;
			property = "ENH_disableAI_suppression";
			expression = "if(_value) then {_this disableAI 'SUPPRESSION'}";
		};
		class ENH_CheckVisible: ENH_Move
		{
			displayName = $STR_ENH_disableAI_raycasts_displayName;
			tooltip = $STR_ENH_disableAI_raycasts_tooltip;
			property = "ENH_disableAI_checkVisible";
			expression = "if(_value) then {_this disableAI 'CHECKVISIBLE'}";
		};
		class ENH_Autocombat: ENH_Move
		{
			displayName = $STR_ENH_disableAI_autocombat_displayName;
			tooltip = $STR_ENH_disableAI_autocombat_tooltip;
			property = "ENH_disableAI_autocombat";
			expression = "if(_value) then {_this disableAI 'AUTOCOMBAT'}";
		};
		class ENH_Path: ENH_Move
		{
			displayName = $STR_ENH_disableAI_path_displayName;
			tooltip = $STR_ENH_disableAI_path_tooltip;
			property = "ENH_disableAI_path";
			expression = "if(_value) then {_this disableAI 'PATH'}";
		};
		class ENH_MineDetection: ENH_Move
		{
			displayName = $STR_ENH_disableAI_mineDetection_displayName;
			tooltip = "";
			property = "ENH_disableAI_mineDetection";
			expression = "if(_value) then {_this disableAI 'MINEDETECTION'}";
		};
		class ENH_WeaponAim: ENH_Move
		{
			displayName = $STR_ENH_disableAI_weaponAim_displayName;
			tooltip = "";
			property = "ENH_disableAI_weaponAim";
			expression = "if(_value) then {_this disableAI 'WEAPONAIM'}";
		};
		class ENH_NVG: ENH_Move
		{
			displayName = $STR_ENH_disableAI_NVG_displayName;
			tooltip = "";
			property = "ENH_disableAI_NVG";
			expression = "if(_value) then {_this disableAI 'NVG'}";
		};
		class ENH_Lights: ENH_Move
		{
			displayName = $STR_ENH_disableAI_lights_displayName;
			tooltip = "";
			property = "ENH_disableAI_lights";
			expression = "if(_value) then {_this disableAI 'LIGHTS'}";
		};
 		class ENH_RadioProtocol: ENH_Move
		{
			displayName = $STR_ENH_disableAI_radioProtocol_displayName;
			tooltip = $STR_ENH_disableAI_radioProtocol_tooltip;
			property = "ENH_disableAI_radioProtocol";
			expression = "if(_value) then {_this disableAI 'RADIOPROTOCOL'}";
		};
	};
};