class Enh_SetCaptive
{
	displayName = $STR_ENH_setCaptive_displayName;
	tooltip = $STR_ENH_setCaptive_tooltip;
	property = "Enh_setCaptive";
	control = "Checkbox";
	expression = "_this setCaptive _value";
	condition = "objectBrain";
	defaultValue = "false";
};