class Enh_Statusbar_EntityCounter
{
	displayName = "Show Entity Counter";
	tooltip = "Show Entity Counter in status bar.";
	property = "Enh_Statusbar_EntityCounter";
	control = "Checkbox";
	expression = "profileNamespace setVariable ['%s',_value]; 'INIT' call Enh_fnc_statusbar_entityCounter";
	defaultValue = "profileNamespace getVariable ['Enh_Statusbar_EntityCounter',true]";
};