class Enh_SetMass
{
	displayName = $STR_ENH_setMass_displayName;
	tooltip = $STR_ENH_setMass_tooltip;
	property = "Enh_setMass";
	control = "Slider";
	expression = "if (!is3DEN) then {_this setMass ((getMass _this) * _value)}";
	condition = "objectVehicle";
	defaultValue = "1";
};
