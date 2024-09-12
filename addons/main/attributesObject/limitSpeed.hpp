class ENH_LimitSpeed
{
    displayName = "$STR_ENH_MAIN_LIMITSPEED_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_LIMITSPEED_TOOLTIP";
    property = "ENH_limitSpeed";
    control = "EditShort";
    expression = "[_this, _value] remoteExec ['limitSpeed', _this]";
    condition = "objectVehicle";
    typeName = "NUMBER";
    defaultValue = -1;
};
