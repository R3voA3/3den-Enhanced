class Enh_DisableNVGE: Enh_SetCaptive
{
	displayName = $STR_ENH_disableNVGEquipment_displayName;
	tooltip = $STR_ENH_disableNVGEquipment_tooltip;
	property = "Enh_disableNVGEquipment";
	expression = "_this disableNVGEquipment _value";
	condition = "objectVehicle";
};