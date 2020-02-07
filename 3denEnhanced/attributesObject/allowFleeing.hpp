class ENH_AllowFleeing
{
	displayName = $STR_ENH_allowFleeing_displayName;
	tooltip = $STR_ENH_allowFleeing_tooltip;
	property = "ENH_allowFleeing";
	control = "Slider";
	condition = "objectBrain";
	expression = "_this allowFleeing _value";
	defaultValue = "0.5";
};