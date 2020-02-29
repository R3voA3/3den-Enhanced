class ENH_EnableSPR: ENH_SetCaptive
{
	displayName = $STR_ENH_SPR_ENABLESPR;
	tooltip = "";
	property = "ENH_EnableSPR";
	expression = "_this setVariable ['%s',_value]";
	condition = "objectBrain";
	defaultValue = "false";
};