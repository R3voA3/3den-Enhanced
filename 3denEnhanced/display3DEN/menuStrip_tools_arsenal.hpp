class ENH_Folder_Arsenal {
	text = "$STR_ENH_FOLDER_ARSENAL";
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_Init_Arsenal",
		"ENH_ARSENAL",
		"ENH_Remove_Arsenal"
	};
};
class ENH_Init_Arsenal {
	text = "$STR_ENH_TOOLS_INIT_ARSENAL";
}
class ENH_ARSENAL {
	text = "$STR_ENH_TOOLS_LIMIT_ARSENAL";
	action = "call ENH_fnc_arsenal_open";
	opensNewWindow = 1;
}
class ENH_Remove_Arsenal {
	text = "$STR_ENH_TOOLS_REMOVE_ARSENAL";
}