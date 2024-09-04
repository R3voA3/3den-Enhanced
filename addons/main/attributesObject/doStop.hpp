class ENH_DoStop
{
    displayName = "$STR_ENH_MAIN_DOSTOP_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_DOSTOP_TOOLTIP";
    control = "Checkbox";
    property = "ENH_doStop";
    expression = "if (!is3DEN && _value) then {doStop _this}";
    condition = "objectBrain + objectVehicle";
    defaultValue = "false";
};
