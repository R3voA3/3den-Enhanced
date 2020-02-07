class ENH_DisableNVGE: ENH_SetCaptive
{
	displayName = $STR_ENH_disableNVGEquipment_displayName;
	tooltip = $STR_ENH_disableNVGEquipment_tooltip;
	property = "ENH_disableNVGEquipment";
	expression = "_this disableNVGEquipment _value";
	condition = "objectVehicle";
};