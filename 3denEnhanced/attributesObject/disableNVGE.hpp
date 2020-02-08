class ENH_DisableNVGE: ENH_SetCaptive
{
	displayName = $STR_ENH_DISABLENVGEQUIPMENT_DISPLAYNAME;
	tooltip = $STR_ENH_DISABLENVGEQUIPMENT_TOOLTIP;
	property = "ENH_disableNVGEquipment";
	expression = "_this disableNVGEquipment _value";
	condition = "objectVehicle";
};