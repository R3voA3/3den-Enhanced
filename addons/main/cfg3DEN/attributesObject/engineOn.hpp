class ENH_EngineOn
{
    displayName = "$STR_ENH_MAIN_ENGINEON_DISPLAYNAME";
    tooltip = "";
    control = "Checkbox";
    property = "ENH_engineOn";
    expression = "[_this, _value] remoteExec ['engineOn', _this]";
    condition = "objectVehicle";
    defaultValue = "false";
};
