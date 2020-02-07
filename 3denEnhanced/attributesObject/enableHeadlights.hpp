class ENH_EnableHeadlights: ENH_SetCaptive
{
	displayName = $STR_ENH_enableHeadlights_displayName;
	tooltip = $STR_ENH_enableHeadlights_tooltip;
	property = "ENH_enableHeadlights";
	expression = "_this setPilotLight _value";
	condition = "objectVehicle";
};