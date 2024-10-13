class ENH_RemoveFromRemainsCollector
{
    displayName = "$STR_ENH_MAIN_REMOVEFROMREMAINSCOLLECTOR_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_REMOVEFROMREMAINSCOLLECTOR_TOOLTIP";
    control = "Checkbox";
    property = "ENH_removeFromRemainsCollector";
    expression = "if (!is3DEN && _value) then {removeFromRemainsCollector [_this]}";
    defaultValue = "false";
    condition = "objectSimulated";
};
