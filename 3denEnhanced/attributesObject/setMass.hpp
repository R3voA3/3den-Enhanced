class ENH_SetMass
{
	displayName = $STR_ENH_SETMASS_DISPLAYNAME;
	tooltip = $STR_ENH_SETMASS_TOOLTIP;
	property = "ENH_setMass";
	control = "Slider";
	expression = "if (!is3DEN) then {_this setMass ((getMass _this) * _value)}";
	condition = "objectVehicle";
	defaultValue = "1";
};
