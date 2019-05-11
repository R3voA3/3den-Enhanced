class Enh_KbTellName
{
	displayName = $STR_ENH_kbTell_displayName;
	tooltip = $STR_ENH_kbTell_tooltip;
	property = "KbTellName";
	control = "Edit";
	expression = "if !(_value isEqualTo '') then {_this setVariable ['bis_fnc_kbTellLocal_name',_value,true]}";
	condition = "objectBrain";
	defaultValue = "''";
};