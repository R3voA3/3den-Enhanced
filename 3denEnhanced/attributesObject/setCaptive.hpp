class ENH_SetCaptive
{
	displayName = $STR_ENH_CAPTIVE_DISPLAYNAME;
	tooltip = $STR_ENH_CAPTIVE_TOOLTIP;
	property = "ENH_setCaptive";
	control = "Checkbox";
	expression = "_this setCaptive _value";
	condition = "objectBrain";
	defaultValue = "false";
};