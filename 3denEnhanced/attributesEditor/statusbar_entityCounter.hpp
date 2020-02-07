class ENH_Statusbar_EntityCounter
{
	displayName = $STR_ENH_statusbar_EntityCounter_displayName;
	property = "ENH_Statusbar_EntityCounter";
	control = "Checkbox";
	expression = "profileNamespace setVariable ['%s',_value]; 'init' call ENH_fnc_statusbar_entityCounter";
	defaultValue = "profileNamespace getVariable ['ENH_Statusbar_EntityCounter',true]";
};