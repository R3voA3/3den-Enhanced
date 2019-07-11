class Enh_EnableHeadlights: Enh_SetCaptive
{
	displayName = $STR_ENH_enableHeadlights_displayName;
	tooltip = $STR_ENH_enableHeadlights_tooltip;
	property = "Enh_enableHeadlights";
	expression = "_this setPilotLight _value";
	condition = "objectVehicle";
};