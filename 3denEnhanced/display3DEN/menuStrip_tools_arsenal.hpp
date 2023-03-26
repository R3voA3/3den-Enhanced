class ENH_Folder_Arsenal {
	text = "$STR_ENH_FOLDER_ARSENAL";
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_Init_Arsenal",
		"ENH_Limit_Arsenal",
		"ENH_Remove_Arsenal"
	};
};
class ENH_Init_Arsenal {
	text = "$STR_ENH_TOOLS_INIT_ARSENAL";
	action = "'init' call ENH_fnc_arsenalTool"
}
class ENH_Limit_Arsenal {
	text = "$STR_ENH_TOOLS_LIMIT_ARSENAL";
}
class ENH_Remove_Arsenal {
	text = "$STR_ENH_TOOLS_REMOVE_ARSENAL";
	action = "'remove' call ENH_fnc_arsenalTool"
}