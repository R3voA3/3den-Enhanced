class ENH_ForceFlag
{
	displayName = $STR_ENH_forceFlag_displayName;
	tooltip = $STR_ENH_forceFlag_tooltip;
	property = "ENH_forceFlag";
	control = "Edit";
	expression = "if (_value != '') then {_this forceFlagTexture _value}";
	condition = "objectVehicle + objectBrain";
	defaultValue = "''";
};