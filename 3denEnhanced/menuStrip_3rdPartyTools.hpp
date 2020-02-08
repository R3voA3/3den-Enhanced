class ENH_3rdPartyTools
{
	text = $STR_ENH_FOLDER_3RDPARTYTOOLS;
	items[] =
	{
		"ENH_3rdPartyTools_Folder_NoDependencies",
		"ENH_3rdPartyTools_Folder_Dependencies"
	};
};
class ENH_3rdPartyTools_Folder_NoDependencies
{
	text =  $STR_ENH_FOLDER_3RDPARTYTOOLS_NODEPENDENCIES;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] =
	{
		"ENH_3rdPartyTools_ColorPicker",
		"ENH_3rdPartyTools_ExtendedFunctionViewer",
		"ENH_3rdPartyTools_DebugConsole",
		"ENH_3rdPartyTools_EditingExtensions",
		"ENH_3rdPartyTools_ZEI",
		"ENH_3rdPartyTools_ZEC",
		"ENH_3rdPartyTools_Emitter3Ditor",
		"ENH_3rdPartyTools_CompoT",
		"ENH_3rdPartyTools_DisableMissionPreviewShortcut"
	};
};
class ENH_3rdPartyTools_Folder_Dependencies: ENH_3rdPartyTools_Folder_NoDependencies
{
	text = $STR_ENH_FOLDER_3RDPARTYTOOLS_DEPENDENCIES;
	items[] =
	{
		"ENH_3rdPartyTools_Arma3MissionFramework",
		"ENH_3rdPartyTools_MissionMakerFramework",
		"ENH_3rdPartyTools_EdenExtendedObjects"
	};
};
class ENH_3rdPartyTools_ColorPicker
{
	text = "Color Picker by Connor";
	picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1668729705";
	opensNewWindow = 1;
};
class ENH_3rdPartyTools_ExtendedFunctionViewer: ENH_3rdPartyTools_ColorPicker
{
	text = "Extended Function Viewer by Connor";
	picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1678581937";
	opensNewWindow = 1;
};
class ENH_3rdPartyTools_DebugConsole: ENH_3rdPartyTools_ColorPicker
{
	text = "Debug Console by R3vo";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1231625987";
};
class ENH_3rdPartyTools_EditingExtensions: ENH_3rdPartyTools_ColorPicker
{
	text = "Editing Extensions by 7erra";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1387934106";
};
class ENH_3rdPartyTools_ZEI: ENH_3rdPartyTools_ColorPicker
{
	text = "ZEI - Zeus and Eden Interiors by LSD";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1251859358";
};
class ENH_3rdPartyTools_ZEC: ENH_3rdPartyTools_ColorPicker
{
	text = "ZEC - Zeus and Eden Compositions by LSD";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=642912021&searchtext=ZEC";
};
class ENH_3rdPartyTools_EdenExtendedObjects: ENH_3rdPartyTools_ColorPicker
{
	text = "Eden Extended Objects by _SCAR";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=882231372";
};
class ENH_3rdPartyTools_Emitter3Ditor: ENH_3rdPartyTools_ColorPicker
{
	text = "Emitter 3Ditor by h-";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1613905318";
};
class ENH_3rdPartyTools_CompoT: ENH_3rdPartyTools_ColorPicker
{
	text = "CompoT by mind";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=557183401";
};
class ENH_3rdPartyTools_DisableMissionPreviewShortcut: ENH_3rdPartyTools_ColorPicker
{
	text = "Disable 3den Mission Preview Shortcut by 7erra";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1420348567";
};
class ENH_3rdPartyTools_Arma3MissionFramework: ENH_3rdPartyTools_ColorPicker
{
	text = "Arma 3 Mission Framework by EightySix";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1378195701";
};
class ENH_3rdPartyTools_MissionMakerFramework: ENH_3rdPartyTools_ColorPicker
{
	text = "Mission Maker Framework by PiZZADOX";
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1378195701";
};