class ENH_SetCaptive
{
    displayName = "$STR_ENH_MAIN_CAPTIVE_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_CAPTIVE_TOOLTIP";
    property = "ENH_setCaptive";
    control = "Checkbox";
    expression = "[_this, _value] remoteExec ['setCaptive', _this]";
    condition = "objectBrain";
    defaultValue = "false";
};
