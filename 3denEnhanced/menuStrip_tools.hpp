class Tools
{
  items[] +=
  {
    "ENH_Folder_Utilities",
    "ENH_Folder_Placement",
    "ENH_Folder_Loadout",
    "ENH_Folder_Miscellaneous",
    "ENH_Folder_Debug",
    "ENH_Folder_GUI"
  };
};
class ENH_Folder_Placement
{
  text = "$STR_ENH_FOLDER_PLACEMENTTOOLS";
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
  text = "$STR_ENH_FOLDER_DEBUGTOOLS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_VariableViewer",
    "Separator",
    "ENH_ProductInfo",
    "ENH_RecompileFunctions",
    "ENH_ToggleMapIDs",
    "ENH_ClearChat"
  };
};
class ENH_Folder_Loadout
{
  text = "$STR_ENH_FOLDER_LOADOUTTOOLS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_InventoryManager",
    "ENH_CopyLoadout",
    "ENH_ApplyLoadout",
    "ENH_ExportLoadoutConfig",
    "ENH_ExportLoadoutCfgRespawnInventory",
    "Separator",
    "ENH_RemoveNVGs",
    "ENH_RemoveVests",
    "ENH_RemoveGoggles",
    "ENH_RemoveHeadgear",
    "ENH_RemoveWeapons"
  };
};
class ENH_Folder_GUI
{
  text = "$STR_ENH_FOLDER_GUI";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_ExportGUIBaseClasses",
    "Separator",
    "ENH_GUITestGrids",
    "ENH_ControlStyles",
    "ENH_ControlTypes"
  };
};
class ENH_Folder_Utilities
{
  text = "$STR_ENH_FOLDER_UTILITIES";
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
    "ENH_3DENCamPositions",
    "ENH_ScenarioAttributesManager",
    "ENH_CfgSentencesBrowser",
    "ENH_TextureFinder",
    "Separator",
    "ENH_BriefingEditor",
    "ENH_ActionCreator",
    "ENH_BatchReplace",
    "ENH_NameObjects"
  };
};
class ENH_Folder_Miscellaneous
{
  text = "$STR_ENH_FOLDER_MISCELLANEOUS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_DeleteEmptyLayers",
    "ENH_ExportMissionParameters",
    "ENH_GenerateSteamMissionDescription",
    "ENH_SwitchTime",
    "Separator",
    "ENH_ToggleGrass",
    "ENH_ToggleSimpleObject",
    "ENH_ToggleSimulation",
    "ENH_ToggleDynamicSimulation",
    "ENH_ToggleDrawBuildingPositions",
    "ENH_ToggleDrawDLCIcons",
    "ENH_ToggleAIFeatures",
    "Separator",
    "ENH_CreateTrigger"
  };
};
//Utilities
class ENH_MoonPhases
{
  text = "$STR_ENH_TOOLS_MOONPHASES";
  action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_moonPhases.sqf'";
  opensNewWindow = 1;
};
class ENH_Jukebox
{
  text = "$STR_ENH_TOOLS_JUKEBOX";
  action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_jukebox.sqf'";
  opensNewWindow = 1;
};
class ENH_PrintConfig
{
  text = "$STR_ENH_TOOLS_PRINTCONFIG";
  action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_printConfig.sqf'";
  opensNewWindow = 1;
};
class ENH_CfgDisabledCommands
{
  text = "$STR_ENH_TOOLS_CFGDISABLEDCOMMANDS";
  action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_cfgDisabledCommands.sqf'";
  opensNewWindow = 1;
};
class ENH_ScriptCommands
{
  text = "$STR_ENH_TOOLS_SCRIPTCOMMANDS";
  action = "[] execVM 'A3\Functions_F\Debug\Utilities\utility_scriptCommands.sqf'";
  opensNewWindow = 1;
};
class ENH_BriefingEditor
{
  text = "$STR_ENH_TOOLS_BRIEFINGEDITOR";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\whiteboard_ca.paa";
  action = "findDisplay 313 createDisplay 'ENH_briefingEditor'";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_B};
  opensNewWindow = 1;
};
class ENH_3DENRadio
{
  text = "$STR_ENH_TOOLS_3DENRADIO";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\radio_ca.paa";
  action = "findDisplay 313 createDisplay 'ENH_3DENRadio'";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_M};
  opensNewWindow = 1;
};
class ENH_ActionCreator
{
  text = "$STR_ENH_TOOLS_ACTIONCREATOR";
  action = "findDisplay 313 createDisplay 'ENH_ActionCreator'";
  opensNewWindow = 1;
};
class ENH_ScenarioAttributesManager
{
  text = "$STR_ENH_TOOLS_SCENARIOATTRIBUTESMANAGER";
  action = "findDisplay 313 createDisplay 'ENH_ScenarioAttributesManager'";
  opensNewWindow = 1;
};
class ENH_BatchReplace
{
  text = "$STR_ENH_TOOLS_BATCHREPLACE";
  action = "call ENH_fnc_batchReplace_createDisplay";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_R};
  opensNewWindow = 1;
};
class ENH_NameObjects
{
  text = "$STR_ENH_TOOLS_BATCHNAMING";
  action = "findDisplay 313 createDisplay 'ENH_NameObjects'";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_N};
  opensNewWindow = 1;
};
class ENH_TextureFinder
{
  text = "$STR_ENH_TOOLS_TEXTUREFINDER";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa";
  action = "findDisplay 313 createDisplay 'ENH_TextureFinder'";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_T};
  opensNewWindow = 1;
};
class ENH_3DENCamPositions
{
  text = "$STR_ENH_TOOLS_3DENCAM";
  picture = "A3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\free.paa";
  action = "findDisplay 313 createDisplay 'ENH_3DENCamPositions'";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_U};
  opensNewWindow = 1;
};
class ENH_VariableViewer
{
  text = "$STR_ENH_TOOLS_VARIABLEVIEWER";
  action = "findDisplay 313 createDisplay 'ENH_VariableViewer'";
  opensNewWindow = 1;
};
class ENH_CfgSentencesBrowser
{
  text = "$STR_ENH_TOOLS_CFGSENTENCESBROWSER";
  action = "findDisplay 313 createDisplay 'ENH_CfgSentencesBrowser'";
  opensNewWindow = 1;
};
//Miscellaneous
class ENH_DeleteEmptyLayers
{
  text = "$STR_ENH_TOOLS_DELETEEMPTYLAYERS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
  action = "call ENH_fnc_deleteEmptyLayers";
};
class ENH_SwitchTime
{
  text = "$STR_ENH_TOOLS_SWITCHTIME";
  picture = "\A3\ui_f\data\igui\cfg\actions\settimer_ca.paa";
  action = "call ENH_fnc_switchTime";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_UP};
};
class ENH_ToggleGrass
{
  text = "$STR_ENH_TOOLS_TOGGLEGRASS";
  action = "[] spawn ENH_fnc_toggleGrass";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_DOWN};
};
class ENH_ToggleSimpleObject
{
  text = "$STR_ENH_TOOLS_TOGGLESIMPLEOBJECT";
  picture = "";
  action = "[['Object'],'objectIsSimple'] call ENH_fnc_toggleAttribute";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_S};
};
class ENH_ToggleSimulation
{
  text = "$STR_ENH_TOOLS_TOGGLESIMULATION";
  picture = "";
  action = "[['Object'],'enableSimulation'] call ENH_fnc_toggleAttribute";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_E};
};
class ENH_ToggleDynamicSimulation
{
  text = "$STR_ENH_TOOLS_TOGGLEDYNAMICSIMULATION";
  picture = "";
  action = "[['Object','Group'],'dynamicSimulation'] call ENH_fnc_toggleAttribute";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_D};
};
class ENH_ToggleDrawBuildingPositions
{
  text = "$STR_ENH_TOOLS_DRAWBUILDINGPOSITIONS";
  action = "call ENH_fnc_toggleDrawBuildingPositions";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_P};
};
class ENH_ToggleDrawDLCIcons
{
  text = "$STR_ENH_TOOLS_DRAWDLCICONS";
  action = "call ENH_fnc_toggleDrawDLCIcons";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_I};
};
class ENH_ToggleAIFeatures
{
  text = "$STR_ENH_TOOLS_TOGGLEAIFEATURES";
  action = "call ENH_fnc_toggleAIFeatures";
};
class ENH_GenerateSteamMissionDescription
{
  text = "$STR_ENH_TOOLS_GENERATESTEAMMISSIONDESCRIPTION";
  action = "[] spawn ENH_fnc_generateSteamMissionDescription";
  opensNewWindow = 1;
};
class ENH_ExportMissionParameters
{
  text = "$STR_ENH_TOOLS_EXPORTMISSIONPARAMETERS";
  action = "copyToClipboard loadFile '3denEnhanced\missionParameters.hpp'; ['ENH_DataCopied'] call BIS_fnc_3DENNotification";
};
class ENH_CreateTrigger
{
  text = "$STR_ENH_TOOLS_CREATETRIGGER";
  picture = "\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
  action = "private _trigger = create3DENEntity ['Trigger','EmptyDetectorArea10x10',[worldSize / 2, worldSize / 2,0]]; _trigger set3DENAttribute ['size3',[worldSize / 2,worldSize / 2,0]]; ['ENH_ActionPerformed'] call BIS_fnc_3DENNotification";
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
  text = "$STR_ENH_TOOLS_PLACEMENTTOOL";
  action = "call ENH_fnc_placementTools_createDisplay";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_L};
  opensNewWindow = 1;
};
class ENH_SetRandomDir
{
  Text = "$STR_ENH_TOOLS_RANDOMDIR";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
  action = "-1 call ENH_fnc_setOrientation";
  conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD3};
};
class ENH_ReverseDirection
{
  text = "$STR_ENH_TOOLS_REVERSEDIRECTION";
  picture = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
  action = "-2 call ENH_fnc_setOrientation";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD7};
};
class ENH_OrientateNorth
{
  text = "$STR_ENH_TOOLS_ORIENTATENORTH";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\N_ca.paa";
  action = "0 call ENH_fnc_setOrientation";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD8};
};
class ENH_OrientateEast: ENH_OrientateNorth
{
  text = "$STR_ENH_TOOLS_ORIENTATEEAST";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\E_ca.paa";
  action = "90 call ENH_fnc_setOrientation";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD6};
};
class ENH_OrientateSouth: ENH_OrientateNorth
{
  text = "$STR_ENH_TOOLS_ORIENTATESOUTH";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\S_ca.paa";
  action = "180 call ENH_fnc_setOrientation";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD2};
};
class ENH_OrientateWest: ENH_OrientateNorth
{
  text = "$STR_ENH_TOOLS_ORIENTATEWEST";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\W_ca.paa";
  action = "270 call ENH_fnc_setOrientation";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD4};
};
//Loadout Tools
class ENH_CopyLoadout
{
  text = "$STR_ENH_TOOLS_COPYLOADOUTS";
  action = "'copy' call ENH_fnc_loadoutTool";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_C};
};
class ENH_ApplyLoadout
{
  text = "$STR_ENH_TOOLS_APPLYLOADOUTS";
  action = "'apply' call ENH_fnc_loadoutTool";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_A};
};
class ENH_ExportLoadoutCfgRespawnInventory
{
  text = "$STR_ENH_TOOLS_EXPORTLOADOUT_CFGRESPAWNINVENTORY";
  action = "false call ENH_fnc_exportLoadout";
};
class ENH_ExportLoadoutConfig
{
  text = "$STR_ENH_TOOLS_EXPORTLOADOUT_CONFIG";
  action = "true call ENH_fnc_exportLoadout";
};
class ENH_RemoveNVGs
{
  text = "$STR_ENH_TOOLS_REMOVENVGS";
  action = "2 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_N};
};
class ENH_RemoveVests
{
  text = "$STR_ENH_TOOLS_REMOVEVESTS";
  action = "3 call ENH_fnc_removeGear";
};
class ENH_RemoveGoggles
{
  text = "$STR_ENH_TOOLS_REMOVEGOGGLES";
  action = "0 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_G};
};
class ENH_RemoveHeadgear
{
  text = "$STR_ENH_TOOLS_REMOVEHEADGEAR";
  action = "1 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_H};
};
class ENH_RemoveWeapons
{
  text = "$STR_ENH_TOOLS_REMOVEWEAPONS";
  action = "4 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_W};
};
class ENH_InventoryManager
{
  text = "$STR_ENH_TOOLS_INVENTORYMANAGER";
  action = "call ENH_fnc_IM_open";
  opensNewWindow = 1;
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_I};
};
//GUI
class ENH_ExportGUIBaseClasses
{
  text = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES";
  action = "findDisplay 313 createDisplay 'ENH_ExportGUIDefines'";
};
class ENH_GUITestGrids
{
  text = "$STR_ENH_TOOLS_GUITESTGRIDS";
  action = "findDisplay 313 createDisplay 'RscTestGrids'";
  opensNewWindow = 1;
};
class ENH_ControlStyles
{
  text = "$STR_ENH_TOOLS_CONTROLSTYLES";
  action = "findDisplay 313 createDisplay 'RscTestControlStyles'";
  opensNewWindow = 1;
};
class ENH_ControlTypes
{
  text = "$STR_ENH_TOOLS_CONTROLTYPES";
  action = "findDisplay 313 createDisplay 'RscTestControlTypes'";
  opensNewWindow = 1;
};
//Debug Tools
class ENH_ToggleMapIDs
{
  text = "$STR_ENH_TOOLS_SHOWMAPIDS";
  picture = "\3DENEnhanced\data\icon_id.paa";
  action = "call ENH_fnc_toggleMapIDs";
};
class ENH_ProductInfo
{
  text = "$STR_ENH_TOOLS_PRODUCTINFO";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\intel_ca.paa";
  action = "call ENH_fnc_productInfo";
};
class ENH_RecompileFunctions
{
  text = "$STR_ENH_TOOLS_RECOMPILEFUNCTIONS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\functions_ca.paa";
  action = "1 call BIS_fnc_recompile; ['ENH_actionPerformed'] call BIS_fnc_3DENNotification";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_R};
};
class ENH_ClearChat
{
  text = "$STR_ENH_TOOLS_CLEARCHAT";
  action = "clearRadio";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_C};
};