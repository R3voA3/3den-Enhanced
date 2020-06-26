class ENH_SPR_Tickets: ENH_SetCaptive
{
	displayName = $STR_ENH_RESPAWNTICKETS_DISPLAYNAME;
	tooltip = $STR_ENH_RESPAWNTICKETS_TOOLTIP;
	property = "ENH_SPR_Tickets";
	control = "EditShort";
	expression = "if (!is3DEN && {!isMultiplayer}) then {_this setVariable ['%s',_value]}";
	typeName = "NUMBER";
	defaultValue = "0";
};
