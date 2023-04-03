class ENH_Folder_Arsenal {
	text = "$STR_ENH_FOLDER_ARSENAL";
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_ARSENAL"
	};
};
class ENH_ARSENAL {
	text = "$STR_ENH_TOOLS_LIMIT_ARSENAL";
	action = "call ENH_fnc_VAM_arsenalPrototype";
	opensNewWindow = 1;
}