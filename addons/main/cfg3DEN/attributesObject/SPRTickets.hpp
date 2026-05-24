class ENH_SPR_Tickets
{
    displayName = "$STR_ENH_MAIN_SPR_RESPAWNTICKETS_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_RESPAWNTICKETS_TOOLTIP";
    property = "ENH_SPR_Tickets";
    control = "EditShort";
    expression = "if (!is3DEN && !isMultiplayer) then {_this setVariable ['ENH_SPR_Tickets', _value]}";
    condition = "objectBrain";
    typeName = "NUMBER";
    defaultValue = 0;
};
