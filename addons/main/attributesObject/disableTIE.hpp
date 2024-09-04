class ENH_DisableTIE
{
    displayName = "$STR_ENH_MAIN_DISABLETIEQUIPMENT_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_DISABLETIEQUIPMENT_TOOLTIP";
    control = "Checkbox";
    property = "ENH_disableTIEquipment";
    expression = "if (isServer) then {_this disableTIEquipment _value}";
    condition = "objectVehicle";
    defaultValue = "false";
};
