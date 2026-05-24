class ENH_FuelConsumptionCoef
{
    displayName = "$STR_ENH_MAIN_FUELCONSUMPTIONCOEF_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_FUELCONSUMPTIONCOEF_TOOLTIP";
    property = "ENH_FuelConsumptionCoef";
    control = "EditShort";
    expression = "[_this, _value] remoteExec ['setFuelConsumptionCoef', _this]";
    condition = "objectVehicle";
    typeName = "NUMBER";
    defaultValue = 1;
};
