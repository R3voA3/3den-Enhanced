class ENH_Folder_Debug
{
  text = "$STR_ENH_FOLDER_DEBUGTOOLS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_VariableViewer",
    "ENH_RPTViewer",
    "ENH_CreateObject",
    "Separator",
    "ENH_ProductInfo",
    "ENH_RecompileFunctions",
    "ENH_ToggleMapIDs",
    "ENH_ClearChat"
  };
};
class ENH_VariableViewer
{
  text = "$STR_ENH_TOOLS_VARIABLEVIEWER";
  action = "findDisplay 313 createDisplay 'ENH_VariableViewer'";
  opensNewWindow = 1;
};
class ENH_RPTViewer
{
  text = "$STR_ENH_TOOLS_RPTVIEWER";
  action = "'open' call ENH_fnc_RPTViewer";
  opensNewWindow = 1;
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_V};
};
class ENH_CreateObject
{
  text = "$STR_3DEN_HISTORY_CREATEOBJECT_DISPLAYNAME";
  action = "findDisplay 313 createDisplay 'ENH_CreateObject'";
  opensNewWindow = 1;
};
class ENH_ToggleMapIDs
{
  text = "$STR_ENH_TOOLS_SHOWMAPIDS";
  picture = "\3DENEnhanced\data\icon_id_ca.paa";
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
};
class ENH_ClearChat
{
  text = "$STR_ENH_TOOLS_CLEARCHAT";
  action = "clearRadio";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_C};
};