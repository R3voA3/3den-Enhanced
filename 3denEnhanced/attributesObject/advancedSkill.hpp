class Enh_AdvancedSkill
{
	displayName = $STR_ENH_attributeCategory_advancedSkill;
	collapsed = 1;
	class Attributes
	{
		class Enh_AimingShake
		{
			displayName = $STR_ENH_aimingShake_displayName;
			tooltip = $STR_ENH_aimingShake_tooltip;
			property = "Enh_aimingShake";
			expression = "_this setSkill ['aimingShake',_value]";
			control = "Skill";
			defaultValue = "0.5";
			condition = "objectBrain";
		};
		class Enh_AimingSpeed: Enh_AimingShake
		{
			displayName = $STR_ENH_aimingSpeed_displayName;
			tooltip = $STR_ENH_aimingSpeed_tooltip;
			property = "Enh_aimingSpeed";
			expression = "_this setSkill ['aimingSpeed',_value]";
		};
		class Enh_AimingAccuracy: Enh_AimingShake
		{
			displayName = $STR_ENH_aimingAccuracy_displayName;
			tooltip = $STR_ENH_aimingAccuracy_tooltip;
			property = "Enh_aimingAccuracy";
			expression = "_this setSkill ['aimingAccuracy',_value]";
		};
		class Enh_Commanding: Enh_AimingShake
		{
			displayName = $STR_ENH_commanding_displayName;
			tooltip = $STR_ENH_commanding_tooltip;
			property = "Enh_commanding";
			expression = "_this setSkill ['commanding',_value]";
		};
		class Enh_Courage: Enh_AimingShake
		{
			displayName = $STR_ENH_courage_displayName;
			tooltip = $STR_ENH_courage_tooltip;
			property = "Enh_courage";
			expression = "_this setSkill ['courage',_value]";
		};
		class Enh_General: Enh_AimingShake
		{
			displayName = $STR_ENH_general_displayName;
			tooltip = $STR_ENH_general_tooltip;
			property = "Enh_general";
			expression = "_this setSkill ['general',_value]";
		};
		class Enh_ReloadSpeed: Enh_AimingShake
		{
			displayName = $STR_ENH_reloadSpeed_displayName;
			tooltip = $STR_ENH_reloadSpeed_tooltip;
			property = "Enh_reloadingSpeed";
			expression = "_this setSkill ['reloadSpeed',_value]";
		};
		class Enh_SpotDistance: Enh_AimingShake
		{
			displayName = $STR_ENH_spotDistance_displayName;
			tooltip = $STR_ENH_spotDistance_tooltip;
			property = "Enh_spotDistance";
			expression = "_this setSkill ['spotDistance',_value]";
		};
		class Enh_SpotTime: Enh_AimingShake
		{
			displayName = $STR_ENH_spotTime_displayName;
			tooltip = $STR_ENH_spotTime_tooltip;
			property = "Enh_spotTime";
			expression = "_this setSkill ['spotTime',_value]";
		};
	};
};