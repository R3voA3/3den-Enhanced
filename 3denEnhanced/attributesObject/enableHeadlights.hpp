class ENH_EnableHeadlights
{
	displayName = $STR_ENH_ENABLEHEADLIGHTS_DISPLAYNAME;
	tooltip = $STR_ENH_ENABLEHEADLIGHTS_TOOLTIP;
  control = "Checkbox";
	property = "ENH_enableHeadlights";
	expression = "_this setPilotLight _value";
	condition = "objectVehicle";
  defaultValue = "false";
};