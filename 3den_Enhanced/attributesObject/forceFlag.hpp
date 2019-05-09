class Enh_ForceFlag
{
	displayName = $STR_ENH_forceFlag_displayName;
	tooltip = $STR_ENH_forceFlag_tooltip;
	property = "Enh_forceFlag";
	control = "Edit";
	expression = "if (_value != '') then {_this forceFlagTexture _value}";
	condition = "objectVehicle + objectBrain";
	defaultValue = "''";
};