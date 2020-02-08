class ENH_EnableHeadlights: ENH_SetCaptive
{
	displayName = $STR_ENH_ENABLEHEADLIGHTS_DISPLAYNAME;
	tooltip = $STR_ENH_ENABLEHEADLIGHTS_TOOLTIP;
	property = "ENH_enableHeadlights";
	expression = "_this setPilotLight _value";
	condition = "objectVehicle";
};