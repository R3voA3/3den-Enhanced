class ENH_SetMass
{
    displayName = "$STR_ENH_MAIN_SETMASS_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_SETMASS_TOOLTIP";
    property = "ENH_setMass";
    control = "Slider";
    expression = "if (!is3DEN) then {[_this, (getMass _this * _value)] remoteExec ['setMass', _this]}";
    condition = "objectVehicle";
    defaultValue = "1";
};
