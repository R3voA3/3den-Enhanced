class ENH_EnableHeadlights
{
    displayName = "$STR_ENH_MAIN_ENABLEHEADLIGHTS_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_ENABLEHEADLIGHTS_TOOLTIP";
    control = "Checkbox";
    property = "ENH_enableHeadlights";
    expression = "[_this, _value] remoteExec ['setPilotLight', _this]";
    condition = "objectVehicle";
    defaultValue = "false";
};
