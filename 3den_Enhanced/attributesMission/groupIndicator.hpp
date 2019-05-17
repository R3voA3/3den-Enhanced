class Enh_GroupIndicator
{
	displayName = $STR_ENH_groupIndicator_displayName;
	tooltip = $STR_ENH_groupIndicator_tooltip;
	property = "Enh_GroupIndicator";
	control = "Checkbox";
	expression = "if (!is3DEN && _value && hasInterface) then {call BIS_fnc_groupIndicator}";
	defaultValue = "false";
};