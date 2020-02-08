class ENH_AllowFleeing
{
	displayName = $STR_ENH_ALLOWFLEEING_DISPLAYNAME;
	tooltip = $STR_ENH_ALLOWFLEEING_TOOLTIP;
	property = "ENH_allowFleeing";
	control = "Slider";
	condition = "objectBrain";
	expression = "_this allowFleeing _value";
	defaultValue = "0.5";
};