class Enh_SetCaptive
{
	displayName = $STR_ENH_captive_displayName;
	tooltip = $STR_ENH_captive_tooltip;
	property = "Enh_setCaptive";
	control = "Checkbox";
	expression = "_this setCaptive _value";
	condition = "objectBrain";
	defaultValue = "false";
};