class ENH_WaterLeakiness
{
    displayName = "$STR_ENH_MAIN_WATERLEAKINESS_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_WATERLEAKINESS_TOOLTIP";
    property = "ENH_WaterLeakiness";
    control = "EditShort";
    expression = "if (!is3DEN && {_value != getWaterLeakiness _this}) then {[_this, _value] remoteExec ['setWaterLeakiness', _this]}";
    condition = "objectVehicle";
    typeName = "NUMBER";
    defaultValue = "getWaterLeakiness _this";
};
