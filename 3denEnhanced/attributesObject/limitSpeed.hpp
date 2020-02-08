class ENH_LimitSpeed: ENH_SetCaptive
{
	displayName = $STR_ENH_LIMITSPEED_DISPLAYNAME;
	tooltip = $STR_ENH_LIMITSPEED_TOOLTIP;
	property = "ENH_limitSpeed";
	control = "EditShort";
	expression = "_this limitSpeed _value";
	condition = "objectVehicle";
	typeName = "NUMBER";
	defaultValue = "-1";
};