class Enh_DisableTIE: Enh_SetCaptive
{
	displayName = $STR_ENH_disableTIEquipment_displayName;
	tooltip = $STR_ENH_disableTIEquipment_tooltip;
	property = "Enh_disableTIEquipment";
	expression = "_this disableTIEquipment _value";
	condition = "objectVehicle";
};