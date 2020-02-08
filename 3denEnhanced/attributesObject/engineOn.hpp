class ENH_EngineOn: ENH_SetCaptive
{
	displayName = $STR_ENH_ENGINEON_DISPLAYNAME;
	tooltip = "";
	property = "ENH_engineOn";
	expression = "_this engineOn _value";
	condition = "objectVehicle";
};