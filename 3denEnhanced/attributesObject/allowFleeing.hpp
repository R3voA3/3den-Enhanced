class Enh_AllowFleeing
{
	displayName = $STR_ENH_allowFleeing_displayName;
	tooltip = $STR_ENH_allowFleeing_tooltip;
	property = "Enh_allowFleeing";
	control = "Slider";
	condition = "objectBrain";
	expression = "_this allowFleeing _value";
	defaultValue = "0.5";
};