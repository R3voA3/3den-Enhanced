class Enh_OnPreviewDebug
{
	displayName = "On Preview Debug";
	class Attributes
	{
		class Enh_OnPreviewDebug_Description
		{
			displayName = $STR_ENH_onMissionDebug_description_displayName;
			description = $STR_ENH_onMissionDebug_description_description;
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
		};
		class Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_showUnits_displayName;
			tooltip = $STR_ENH_onPreviewDebug_showUnits_tooltip;
			property = "Enh_ShowUnits";
			control = "Checkbox";
			expression = "profileNamespace setVariable ['%s',_value]";
			defaultValue = "profileNamespace getVariable ['Enh_ShowUnits',false]";
		};
		class Enh_BulletTracing: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_bulletTracking_displayName;
			tooltip = $STR_ENH_onPreviewDebug_bulletTracking_tooltip;
			property = "Enh_BulletTracing";
			defaultValue = "profileNamespace getVariable ['Enh_BulletTracing',false]";

		};
		class Enh_Zeus: Enh_ShowUnits
		{
			displayName = $STR_ENH_onMissionDebug_zeus_displayName;
			tooltip = "";
			defaultValue = "profileNamespace getVariable ['Enh_Zeus',false]";
			property = "Enh_Zeus";

		};
		class Enh_Arsenal: Enh_Zeus
		{
			displayName = $STR_ENH_onMissionDebug_arsenal_displayName;
			property = "Enh_Arsenal";
			defaultValue = "profileNamespace getVariable ['Enh_Arsenal',false]";
		};
		class Enh_Garage: Enh_Zeus
		{
			displayName = $STR_ENH_onMissionDebug_garage_displayName;
			property = "Enh_Garage";
			defaultValue = "profileNamespace getVariable ['Enh_Garage',false]";
		};
		class Enh_Invulnerability: Enh_Zeus
		{
			displayName = $STR_ENH_onPreviewDebug_invulnerability_displayName;
			property = "Enh_Invulnerability";
			defaultValue = "profileNamespace getVariable ['Enh_Invulnerability',false]";
		};
		class Enh_CaptiveMode: Enh_ShowUnits
		{
			displayName = $STR_ENH_onMissionDebug_captive_displayName;
			tooltip = $STR_ENH_onMissionDebug_captive_tooltip;
			property = "Enh_CaptiveMode";
			defaultValue = "profileNamespace getVariable ['Enh_CaptiveMode',false]";
		};
		class Enh_DisableStamina: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_stamina_displayName;
			tooltip = "";
			property = "Enh_DisableStamina";
			defaultValue = "profileNamespace getVariable ['Enh_DisableStamina',false]";
		};
		class Enh_Awareness: Enh_ShowUnits
		{
			displayName = $STR_ENH_onMissionDebug_awareness_displayName;
			tooltip = $STR_ENH_onMissionDebug_awareness_tooltip;
			property = "Enh_Awareness";
			defaultValue = "profileNamespace getVariable ['Enh_Awareness',false]";
		};
		class Enh_FPS: Enh_Zeus
		{
			defaultValue = "profileNamespace getVariable ['Enh_FPS',false]";
			displayName = $STR_ENH_onPreviewDebug_FPS_displayName;
			property = "Enh_FPS";
		};
		class Enh_KillWEST: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killWest_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillWest";
			defaultValue = "profileNamespace getVariable ['Enh_KillWEST',false]";
		};
		class Enh_KillEAST: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killEast_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillEast";
			defaultValue = "profileNamespace getVariable ['Enh_KillEAST',false]";
		};
		class Enh_KillINDEP: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killIndep_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillIndep";
			defaultValue = "profileNamespace getVariable ['Enh_KillINDEP',false]";
		};
		class Enh_KillCIV: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killCiv_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillCiv";
			defaultValue = "profileNamespace getVariable ['Enh_KillCIV',false]";
		};
		class Enh_KillCursor: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killCursor_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killCursor_tooltip;
			property = "Enh_KillCursor";
			defaultValue = "profileNamespace getVariable ['Enh_KillCursor',false]";
		};
	};
};