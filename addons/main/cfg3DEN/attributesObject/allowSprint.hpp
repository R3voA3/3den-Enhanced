class ENH_AllowSprint
{
    displayName = "$STR_ENH_MAIN_ALLOWSPRINTING_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_ALLOWSPRINTING_TOOLTIP";
    control = "Checkbox";
    property = "ENH_allowSprint";
    expression = "[_this, _value] remoteExec ['allowSprint', _this]";
    defaultValue = "true";
    condition = "objectBrain";
};
