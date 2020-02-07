class ENH_SetCaptive
{
	displayName = $STR_ENH_captive_displayName;
	tooltip = $STR_ENH_captive_tooltip;
	property = "ENH_setCaptive";
	control = "Checkbox";
	expression = "_this setCaptive _value";
	condition = "objectBrain";
	defaultValue = "false";
};