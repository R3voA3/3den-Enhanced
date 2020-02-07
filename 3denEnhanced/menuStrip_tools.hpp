class Tools
{
	items[] +=
	{
		"ENH_Folder_Utilities",
		"ENH_Folder_Placement",
		"ENH_Folder_Debug",
		"ENH_Folder_Loadout",
		"ENH_Folder_GUI",
		"ENH_Folder_Miscellaneous"
	};
};
class ENH_Folder_Placement
{
	text = $STR_ENH_folder_placementTools;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_PlacementTools",
		"Separator",
		"ENH_SetRandomDir",
		"ENH_ReverseDirection",
		"Separator",
		"ENH_OrientateNorth",
		"ENH_OrientateEast",
		"ENH_OrientateSouth",
		"ENH_OrientateWest"
	};
};
class ENH_Folder_Debug
{
	text = $STR_ENH_folder_debugTools;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_ProductInfo",
		"ENH_RecompileFunctions",
		"ENH_ToggleMapIDs",
		"ENH_ClearChat"
	};
};
class ENH_Folder_Loadout
{
	text = $STR_ENH_folder_loadoutTools;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_CopyLoadout",
		"ENH_ApplyLoadout",
		"ENH_ExportLoadoutConfig",
		"ENH_RemoveNVGs",
		"ENH_RemoveVests",
		"ENH_RemoveGoggles",
		"ENH_RemoveHeadgear",
		"ENH_RemoveWeapons"
	};
};
class ENH_Folder_GUI
{
	text = $STR_ENH_folder_GUI;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_ExportGUIBaseClassesAll",
		"ENH_ExportGUIBaseClassesDefault",
		"ENH_ExportGUIBaseClasses3DEN",
		"ENH_GUITestGrids",
		"ENH_ControlStyles",
		"ENH_ControlTypes"
	};
};
class ENH_Folder_Utilities
{
	text = $STR_ENH_folder_utilities;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_CfgDisabledCommands",
		"ENH_Jukebox",
		"ENH_MoonPhases",
		"ENH_PrintConfig",
		"ENH_ScriptCommands",
		"Separator",
		"ENH_3DENRadio",
		"ENH_ActionCreator",
		"ENH_BatchReplace",
		"ENH_BriefingEditor",
		"ENH_NameObjects",
		"ENH_ScenarioAttributesManager",
		"ENH_TextureFinder",
		"ENH_3DENCamPositions"
	};
};
class ENH_Folder_Miscellaneous
{
	text = $STR_ENH_folder_miscellaneous;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_DeleteEmptyLayers",
		"ENH_GenerateSteamMissionDescription",
		"ENH_SwitchTime",
		"ENH_ToggleGrass",
		"ENH_ToggleSimpleObject",
		"ENH_ToggleSimulation",
		"ENH_ToggleDynamicSimulation",
		"ENH_ToggleDrawBuildingPositions",
		"ENH_ToggleDrawDLCIcons",
		"ENH_ToggleAIFeatures"
	};
};
//Utilities
class ENH_MoonPhases
{
	text = $STR_ENH_tools_moonPhases;
	action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_moonPhases.sqf'";
	opensNewWindow = 1;
};
class ENH_Jukebox
{
	text = $STR_ENH_tools_jukebox;
	action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_jukebox.sqf'";
	opensNewWindow = 1;
};
class ENH_PrintConfig
{
	text = $STR_ENH_tools_printConfig;
	action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_printConfig.sqf'";
	opensNewWindow = 1;
};
class ENH_CfgDisabledCommands
{
	text = $STR_ENH_tools_CfgDisabledCommands;
	action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_cfgDisabledCommands.sqf'";
	opensNewWindow = 1;
};
class ENH_ScriptCommands
{
	text = $STR_ENH_tools_ScriptCommands;
	action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_scriptCommands.sqf'";
	opensNewWindow = 1;
};
class ENH_BriefingEditor
{
	text = $STR_ENH_tools_briefingEditor;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\whiteboard_ca.paa";
	action = "findDisplay 313 createDisplay 'ENH_briefingEditor'";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_B};
	opensNewWindow = 1;
};
class ENH_3DENRadio
{
	text = $STR_ENH_tools_3DENRadio;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\radio_ca.paa";
	action = "findDisplay 313 createDisplay 'ENH_3DENRadio'";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_M};
	opensNewWindow = 1;
};
class ENH_ActionCreator
{
	text = $STR_ENH_tools_actionCreator;
	action = "findDisplay 313 createDisplay 'ENH_ActionCreator'";
	opensNewWindow = 1;
};
class ENH_ScenarioAttributesManager
{
	text = $STR_ENH_tools_scenarioAttributesManager;
	action = "findDisplay 313 createDisplay 'ENH_ScenarioAttributesManager'";
	opensNewWindow = 1;
};
class ENH_BatchReplace
{
	text = $STR_ENH_tools_batchReplace;
	action = "call ENH_fnc_batchReplace_createDisplay";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_R};
	opensNewWindow = 1;
};
class ENH_NameObjects
{
	text = $STR_ENH_tools_batchNaming;
	action = "findDisplay 313 createDisplay 'ENH_NameObjects'";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_N};
	opensNewWindow = 1;
};
class ENH_TextureFinder
{
	text = $STR_ENH_textureFinder;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa";
	action = "findDisplay 313 createDisplay 'ENH_TextureFinder'";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_T};
	opensNewWindow = 1;
};
class ENH_3DENCamPositions
{
	text = $STR_ENH_tools_3DENCam;
	picture = "A3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\free.paa";
	action = "findDisplay 313 createDisplay 'ENH_3DENCamPositions'";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_U};
	opensNewWindow = 1;
};
//Miscellaneous
class ENH_DeleteEmptyLayers
{
	text = $STR_ENH_tools_deleteEmptyLayers;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
	action = "call ENH_fnc_deleteEmptyLayers";
};
class ENH_SwitchTime
{
	text = $STR_ENH_tools_switchTime;
	picture = "\A3\ui_f\data\igui\cfg\actions\settimer_ca.paa";
	action = "call ENH_fnc_switchTime";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_UP};
};
class ENH_ToggleGrass
{
	text = $STR_ENH_tools_toggleGrass;
	action = "[] spawn ENH_fnc_toggleGrass";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_DOWN};
};
class ENH_ToggleSimpleObject
{
	text = $STR_ENH_tools_toggleSimpleObject;
	picture = "";
	action = "[['Object'],'objectIsSimple'] call ENH_fnc_toggleAttribute";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_S};
};
class ENH_ToggleSimulation
{
	text = $STR_ENH_tools_toggleSimulation;
	picture = "";
	action = "[['Object'],'enableSimulation'] call ENH_fnc_toggleAttribute";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_E};
};
class ENH_ToggleDynamicSimulation
{
	text = $STR_ENH_tools_toggleDynamicSimulation;
	picture = "";
	action = "[['Object','Group'],'dynamicSimulation'] call ENH_fnc_toggleAttribute";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_D};
};
class ENH_ToggleDrawBuildingPositions
{
	text = $STR_ENH_tools_drawBuildingPositions;
	action = "call ENH_fnc_toggleDrawBuildingPositions";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_P};
};
class ENH_ToggleDrawDLCIcons
{
	text = $STR_ENH_tools_drawDLCIcons;
	action = "call ENH_fnc_toggleDrawDLCIcons";
	shortcuts[] = {INPUT_ALT_OFFSET + DIK_I};
};
class ENH_ToggleAIFeatures
{
	text = $STR_ENH_tools_toggleAIFeatures;
	action = "call ENH_fnc_toggleAIFeatures";
};
class ENH_GenerateSteamMissionDescription
{
	text = $STR_ENH_tools_generateSteamMissionDescription;
	action = "[] spawn ENH_fnc_generateSteamMissionDescription";
	opensNewWindow = 1;
};
//Vanilla
class FunctionsViewer//Overwrites the default function viewer
{
	action = "findDisplay 313 createDisplay 'ENH_FunctionsViewer'";
	data = "";
	opensNewWindow = 1;
	shortCuts[] = {INPUT_ALT_OFFSET + DIK_F};
};
class ConfigViewer//Overwrites the default config viewer to change shortcut
{
	shortCuts[] = {INPUT_ALT_OFFSET + DIK_C};
};
class DebugConsole//Overwrites the default debug console to change shortcut
{
	shortCuts[] = {INPUT_CTRL_OFFSET + DIK_D};
};
//Placement Tools
class ENH_PlacementTools
{
	text = $STR_ENH_tools_placementTools;
	action = "call ENH_fnc_placementTools_createDisplay";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_L};
	opensNewWindow = 1;
};
class ENH_SetRandomDir
{
	Text = $STR_ENH_tools_randomDir;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
	action = "call ENH_fnc_setRandomOrientation";
	conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD3};
};
class ENH_ReverseDirection
{
	text = $STR_ENH_tools_reverseDirection;
	picture = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
	action = "call ENH_fnc_reverseOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD7};
};
class ENH_OrientateNorth
{
	text = $STR_ENH_tools_orientateNorth;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\N_ca.paa";
	action = "0 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD8};
};
class ENH_OrientateEast: ENH_OrientateNorth
{
	text = $STR_ENH_tools_orientateEast;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\E_ca.paa";
	action = "90 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD6};
};
class ENH_OrientateSouth: ENH_OrientateNorth
{
	text = $STR_ENH_tools_orientateSouth;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\S_ca.paa";
	action = "180 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD2};
};
class ENH_OrientateWest: ENH_OrientateNorth
{
	text = $STR_ENH_tools_orientateWest;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\W_ca.paa";
	action = "270 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD4};
};
//Loadout Tools
class ENH_CopyLoadout
{
	text = $STR_ENH_tools_copyLoadouts;
	action = "'copy' call ENH_fnc_loadoutTool";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_C};
};
class ENH_ApplyLoadout: ENH_copyLoadout
{
	text = $STR_ENH_tools_applyLoadouts;
	action = "'apply' call ENH_fnc_loadoutTool";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_A};
};
class ENH_ExportLoadoutConfig
{
	text = $STR_ENH_tools_exportLoadoutConfig;
	action = "call ENH_fnc_exportInventoryConfig";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_E};
};
class ENH_RemoveNVGs
{
	text = $STR_ENH_tools_removeNVGs;
	action = "2 call ENH_fnc_removeGear";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_N};
};
class ENH_RemoveVests
{
	text = $STR_ENH_tools_removeVests;
	action = "3 call ENH_fnc_removeGear";
};
class ENH_RemoveGoggles
{
	text = $STR_ENH_tools_removeGoggles;
	action = "0 call ENH_fnc_removeGear";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_G};
};
class ENH_RemoveHeadgear
{
	text = $STR_ENH_tools_removeHeadgear;
	action = "1 call ENH_fnc_removeGear";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_H};
};
class ENH_RemoveWeapons
{
	text = $STR_ENH_tools_removeWeapons;
	action = "4 call ENH_fnc_removeGear";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_W};
};
//GUI
class ENH_ExportGUIBaseClassesAll
{
	text = $STR_ENH_tools_exportGUIBaseClasses;
	action = "'' call BIS_fnc_exportGUIBaseClasses; ['ENH_DataCopied'] call BIS_fnc_3DENNotification";
};
class ENH_ExportGUIBaseClassesDefault
{
	text = $STR_ENH_tools_exportGUIBaseClasses_default;
	action = "'Default' call BIS_fnc_exportGUIBaseClasses; ['ENH_DataCopied'] call BIS_fnc_3DENNotification";
};
class ENH_ExportGUIBaseClasses3DEN
{
	text = $STR_ENH_tools_exportGUIBaseClasses_3DEN;
	action = "'3DEN' call BIS_fnc_exportGUIBaseClasses; ['ENH_DataCopied'] call BIS_fnc_3DENNotification";
};
class ENH_GUITestGrids
{
	text = $STR_ENH_tools_GUITestGrids;
	action = "findDisplay 313 createDisplay 'RscTestGrids'";
	opensNewWindow = 1;
};
class ENH_ControlStyles
{
	text = $STR_ENH_tools_controlStyles;
	action = "findDisplay 313 createDisplay 'RscTestControlStyles'";
	opensNewWindow = 1;
};
class ENH_ControlTypes
{
	text = $STR_ENH_tools_controlTypes;
	action = "findDisplay 313 createDisplay 'RscTestControlTypes'";
	opensNewWindow = 1;
};
//Debug Tools
class ENH_ToggleMapIDs
{
	text = $STR_ENH_tools_showMapIDs;
	picture = "\3DENEnhanced\data\icon_id.paa";
	action = "call ENH_fnc_toggleMapIDs";
};
class ENH_ProductInfo
{
	text = $STR_ENH_tools_productInfo;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\intel_ca.paa";
	action = "call ENH_fnc_productInfo";
};
class ENH_RecompileFunctions
{
	text = $STR_ENH_tools_recompileFunctions;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\functions_ca.paa";
	action = "1 call BIS_fnc_recompile; ['ENH_actionPerformed'] call BIS_fnc_3DENNotification";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_R};
};
class ENH_ClearChat
{
	text = $STR_ENH_tools_clearChat;
	action = "clearRadio";
	shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_C};
};