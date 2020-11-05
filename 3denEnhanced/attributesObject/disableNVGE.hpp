class ENH_DisableNVGE
{
    displayName = $STR_ENH_DISABLENVGEQUIPMENT_DISPLAYNAME;
    tooltip = $STR_ENH_DISABLENVGEQUIPMENT_TOOLTIP;
    control = "Checkbox";
    property = "ENH_disableNVGEquipment";
    expression = "_this disableNVGEquipment _value";
    condition = "objectVehicle";
    defaultValue = "false";
};