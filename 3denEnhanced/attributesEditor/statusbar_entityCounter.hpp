class Enh_Statusbar_EntityCounter
{
	displayName = $STR_ENH_statusbar_EntityCounter_displayName;
	property = "Enh_Statusbar_EntityCounter";
	control = "Checkbox";
	expression = "profileNamespace setVariable ['%s',_value]; 'init' call Enh_fnc_statusbar_entityCounter";
	defaultValue = "profileNamespace getVariable ['Enh_Statusbar_EntityCounter',true]";
};