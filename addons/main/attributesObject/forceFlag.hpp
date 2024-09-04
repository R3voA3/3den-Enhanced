class ENH_ForceFlag
{
    displayName = "$STR_ENH_MAIN_FORCEFLAG_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_FORCEFLAG_TOOLTIP";
    property = "ENH_forceFlag";
    control = "Edit";
    expression = "if (_value != '') then {_this forceFlagTexture _value}";
    condition = "objectBrain + objectVehicle";
    defaultValue = "''";
};
