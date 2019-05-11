class Enh_VirtualArsenal
{
	displayName = $STR_ENH_arsenal_displayName;
	tooltip = $STR_ENH_arsenal_tooltip;
	property = "Enh_virtualArsenal";
	control = "Checkbox";
	expression = "if (!is3DEN && _value) then {['AmmoboxInit',[_this,true]] spawn BIS_fnc_arsenal}";
	condition = "1";
	defaultValue = "false";
};