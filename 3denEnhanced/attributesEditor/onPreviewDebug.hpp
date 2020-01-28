class Enh_OnPreviewDebug
{
	displayName = "On Preview Debug";
	class Attributes
	{
		class Enh_OnPreviewDebug_Description
		{
			displayName = $STR_ENH_description;
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
			defaultValue = "profileNamespace getVariable ['%s',false]";
		};
		class Enh_BulletTracing: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_bulletTracking_displayName;
			tooltip = $STR_ENH_onPreviewDebug_bulletTracking_tooltip;
			property = "Enh_BulletTracing";
		};
		class Enh_Zeus: Enh_ShowUnits
		{
			displayName = $STR_ENH_onMissionDebug_zeus_displayName;
			tooltip = "";
			property = "Enh_Zeus";
		};
		class Enh_Arsenal: Enh_Zeus
		{
			displayName = $STR_ENH_onMissionDebug_arsenal_displayName;
			property = "Enh_Arsenal";
		};
		class Enh_Garage: Enh_Zeus
		{
			displayName = $STR_ENH_onMissionDebug_garage_displayName;
			property = "Enh_Garage";
		};
		class Enh_Invulnerability: Enh_Zeus
		{
			displayName = $STR_ENH_onPreviewDebug_invulnerability_displayName;
			property = "Enh_Invulnerability";
		};
		class Enh_CaptiveMode: Enh_ShowUnits
		{
			displayName = $STR_ENH_onMissionDebug_captive_displayName;
			tooltip = $STR_ENH_onMissionDebug_captive_tooltip;
			property = "Enh_CaptiveMode";
		};
		class Enh_DisableStamina: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_stamina_displayName;
			tooltip = "";
			property = "Enh_DisableStamina";
		};
		class Enh_Awareness: Enh_ShowUnits
		{
			displayName = $STR_ENH_onMissionDebug_awareness_displayName;
			tooltip = $STR_ENH_onMissionDebug_awareness_tooltip;
			property = "Enh_Awareness";
		};
		class Enh_FPS: Enh_Zeus
		{
			displayName = $STR_ENH_onPreviewDebug_FPS_displayName;
			property = "Enh_FPS";
		};
		class Enh_KillWEST: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killWest_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillWest";
		};
		class Enh_KillEAST: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killEast_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillEast";
		};
		class Enh_KillINDEP: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killIndep_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillIndep";
		};
		class Enh_KillCIV: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killCiv_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killUnits_tooltip;
			property = "Enh_KillCiv";
		};
		class Enh_KillCursor: Enh_ShowUnits
		{
			displayName = $STR_ENH_onPreviewDebug_killCursor_displayName;
			tooltip = $STR_ENH_onPreviewDebug_killCursor_tooltip;
			property = "Enh_KillCursor";
		};
	};
};