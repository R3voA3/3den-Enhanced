class ENH_DisableTIE: ENH_SetCaptive
{
	displayName = $STR_ENH_DISABLETIEQUIPMENT_DISPLAYNAME;
	tooltip = $STR_ENH_DISABLETIEQUIPMENT_TOOLTIP;
	property = "ENH_disableTIEquipment";
	expression = "_this disableTIEquipment _value";
	condition = "objectVehicle";
};