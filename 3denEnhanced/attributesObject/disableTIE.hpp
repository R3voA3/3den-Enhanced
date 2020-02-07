class ENH_DisableTIE: ENH_SetCaptive
{
	displayName = $STR_ENH_disableTIEquipment_displayName;
	tooltip = $STR_ENH_disableTIEquipment_tooltip;
	property = "ENH_disableTIEquipment";
	expression = "_this disableTIEquipment _value";
	condition = "objectVehicle";
};