class ENH_AdvancedSkill
{
	displayName = $STR_ENH_attributeCategory_advancedSkill;
	collapsed = 1;
	class Attributes
	{
		class ENH_AimingShake
		{
			displayName = $STR_ENH_aimingShake_displayName;
			tooltip = $STR_ENH_aimingShake_tooltip;
			property = "ENH_aimingShake";
			expression = "_this setSkill ['aimingShake',_value]";
			control = "Skill";
			defaultValue = "0.5";
			condition = "objectBrain";
		};
		class ENH_AimingSpeed: ENH_AimingShake
		{
			displayName = $STR_ENH_aimingSpeed_displayName;
			tooltip = $STR_ENH_aimingSpeed_tooltip;
			property = "ENH_aimingSpeed";
			expression = "_this setSkill ['aimingSpeed',_value]";
		};
		class ENH_AimingAccuracy: ENH_AimingShake
		{
			displayName = $STR_ENH_aimingAccuracy_displayName;
			tooltip = $STR_ENH_aimingAccuracy_tooltip;
			property = "ENH_aimingAccuracy";
			expression = "_this setSkill ['aimingAccuracy',_value]";
		};
		class ENH_Commanding: ENH_AimingShake
		{
			displayName = $STR_ENH_commanding_displayName;
			tooltip = $STR_ENH_commanding_tooltip;
			property = "ENH_commanding";
			expression = "_this setSkill ['commanding',_value]";
		};
		class ENH_Courage: ENH_AimingShake
		{
			displayName = $STR_ENH_courage_displayName;
			tooltip = $STR_ENH_courage_tooltip;
			property = "ENH_courage";
			expression = "_this setSkill ['courage',_value]";
		};
		class ENH_General: ENH_AimingShake
		{
			displayName = $STR_ENH_general_displayName;
			tooltip = $STR_ENH_general_tooltip;
			property = "ENH_general";
			expression = "_this setSkill ['general',_value]";
		};
		class ENH_ReloadSpeed: ENH_AimingShake
		{
			displayName = $STR_ENH_reloadSpeed_displayName;
			tooltip = $STR_ENH_reloadSpeed_tooltip;
			property = "ENH_reloadingSpeed";
			expression = "_this setSkill ['reloadSpeed',_value]";
		};
		class ENH_SpotDistance: ENH_AimingShake
		{
			displayName = $STR_ENH_spotDistance_displayName;
			tooltip = $STR_ENH_spotDistance_tooltip;
			property = "ENH_spotDistance";
			expression = "_this setSkill ['spotDistance',_value]";
		};
		class ENH_SpotTime: ENH_AimingShake
		{
			displayName = $STR_ENH_spotTime_displayName;
			tooltip = $STR_ENH_spotTime_tooltip;
			property = "ENH_spotTime";
			expression = "_this setSkill ['spotTime',_value]";
		};
	};
};