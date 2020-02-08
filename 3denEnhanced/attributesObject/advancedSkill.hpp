class ENH_AdvancedSkill
{
	displayName = $STR_ENH_ATTRIBUTECATEGORY_ADVANCEDSKILL;
	collapsed = 1;
	class Attributes
	{
		class ENH_AimingShake
		{
			displayName = $STR_ENH_AIMINGSHAKE_DISPLAYNAME;
			tooltip = $STR_ENH_AIMINGSHAKE_TOOLTIP;
			property = "ENH_aimingShake";
			expression = "_this setSkill ['aimingShake',_value]";
			control = "Skill";
			defaultValue = "0.5";
			condition = "objectBrain";
		};
		class ENH_AimingSpeed: ENH_AimingShake
		{
			displayName = $STR_ENH_AIMINGSPEED_DISPLAYNAME;
			tooltip = $STR_ENH_AIMINGSPEED_TOOLTIP;
			property = "ENH_aimingSpeed";
			expression = "_this setSkill ['aimingSpeed',_value]";
		};
		class ENH_AimingAccuracy: ENH_AimingShake
		{
			displayName = $STR_ENH_AIMINGACCURACY_DISPLAYNAME;
			tooltip = $STR_ENH_AIMINGACCURACY_TOOLTIP;
			property = "ENH_aimingAccuracy";
			expression = "_this setSkill ['aimingAccuracy',_value]";
		};
		class ENH_Commanding: ENH_AimingShake
		{
			displayName = $STR_ENH_COMMANDING_DISPLAYNAME;
			tooltip = $STR_ENH_COMMANDING_TOOLTIP;
			property = "ENH_commanding";
			expression = "_this setSkill ['commanding',_value]";
		};
		class ENH_Courage: ENH_AimingShake
		{
			displayName = $STR_ENH_COURAGE_DISPLAYNAME;
			tooltip = $STR_ENH_COURAGE_TOOLTIP;
			property = "ENH_courage";
			expression = "_this setSkill ['courage',_value]";
		};
		class ENH_General: ENH_AimingShake
		{
			displayName = $STR_ENH_GENERAL_DISPLAYNAME;
			tooltip = $STR_ENH_GENERAL_TOOLTIP;
			property = "enh_general";
			expression = "_this setSkill ['general',_value]";
		};
		class ENH_ReloadSpeed: ENH_AimingShake
		{
			displayName = $STR_ENH_RELOADSPEED_DISPLAYNAME;
			tooltip = $STR_ENH_RELOADSPEED_TOOLTIP;
			property = "ENH_reloadingSpeed";
			expression = "_this setSkill ['reloadSpeed',_value]";
		};
		class ENH_SpotDistance: ENH_AimingShake
		{
			displayName = $STR_ENH_SPOTDISTANCE_DISPLAYNAME;
			tooltip = $STR_ENH_SPOTDISTANCE_TOOLTIP;
			property = "ENH_spotDistance";
			expression = "_this setSkill ['spotDistance',_value]";
		};
		class ENH_SpotTime: ENH_AimingShake
		{
			displayName = $STR_ENH_SPOTTIME_DISPLAYNAME;
			tooltip = $STR_ENH_SPOTTIME_TOOLTIP;
			property = "ENH_spotTime";
			expression = "_this setSkill ['spotTime',_value]";
		};
	};
};