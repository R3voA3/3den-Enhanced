class ENH_LimitSpeed: ENH_SetCaptive
{
	displayName = $STR_ENH_limitSpeed_displayName;
	tooltip = $STR_ENH_limitSpeed_tooltip;
	property = "ENH_limitSpeed";
	control = "EditShort";
	expression = "_this limitSpeed _value";
	condition = "objectVehicle";
	typeName = "NUMBER";
	defaultValue = "-1";
};