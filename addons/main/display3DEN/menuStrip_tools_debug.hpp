class ENH_Folder_Debug
{
  text = "$STR_ENH_MAIN_FOLDER_DEBUGTOOLS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_VariableViewer",
    "ENH_RPTViewer",
    "Separator",
    "ENH_ProductInfo",
    "ENH_ClearChat",
    "Separator",
    "ENH_ExportGUIBaseClasses",
    "ENH_GUITestGrids",
    "Separator",
    "ENH_ToggleDrawBuildingPositions",
    "ENH_ToggleDrawDLCIcons",
    "ENH_ToggleDrawHitpoints"
  };
};
class ENH_VariableViewer
{
  text = "$STR_ENH_MAIN_TOOLS_VARIABLEVIEWER";
  action = "findDisplay 313 createDisplay 'ENH_VariableViewer'";
  opensNewWindow = 1;
};
class ENH_RPTViewer
{
  text = "$STR_ENH_MAIN_TOOLS_RPTVIEWER";
  action = "'open' call ENH_fnc_RPTViewer";
  opensNewWindow = 1;
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_V};
};
class ENH_ProductInfo
{
  text = "$STR_ENH_MAIN_TOOLS_PRODUCTINFO";
  action = "call ENH_fnc_productInfo";
};
class ENH_ClearChat
{
  text = "$STR_ENH_MAIN_TOOLS_CLEARCHAT";
  action = "clearRadio";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_C};
};
class ENH_ExportGUIBaseClasses
{
  text = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES";
  action = "findDisplay 313 createDisplay 'ENH_ExportGUIDefines'";
};
class ENH_GUITestGrids
{
  text = "$STR_ENH_MAIN_TOOLS_GUITESTGRIDS";
  action = "findDisplay 313 createDisplay 'RscTestGrids'";
  opensNewWindow = 1;
};
class ENH_ToggleDrawBuildingPositions
{
  text = "$STR_ENH_MAIN_TOOLS_DRAWBUILDINGPOSITIONS";
  action = "call ENH_fnc_toggleDrawBuildingPositions";
};
class ENH_ToggleDrawDLCIcons
{
  text = "$STR_ENH_MAIN_TOOLS_DRAWDLCICONS";
  action = "call ENH_fnc_toggleDrawDLCIcons";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_I};
};
class ENH_ToggleDrawHitpoints
{
  text = "$STR_ENH_MAIN_TOOLS_DRAWHITPOINTS";
  action = "call ENH_fnc_toggleDrawHitpoints";
};