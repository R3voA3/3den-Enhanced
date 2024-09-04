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
        "ENH_GUITestGrids"
    };
};
class ENH_VariableViewer
{
    text = "$STR_ENH_MAIN_TOOLS_VARIABLEVIEWER";
    action = "findDisplay 313 createDisplay 'ENH_VariableViewer'";
    opensNewWindow = 1;
    wikiDescription = "Opens the Variable Viewer. See GUI documentation for detailed information.";
};
class ENH_RPTViewer
{
    text = "$STR_ENH_MAIN_TOOLS_RPTVIEWER";
    action = "'open' call ENH_fnc_RPTViewer";
    opensNewWindow = 1;
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_V};
    wikiDescription = "Opens the RPT Viewer. See GUI documentation for detailed information.";
};
class ENH_ProductInfo
{
    text = "$STR_ENH_MAIN_TOOLS_PRODUCTINFO";
    action = "call ENH_fnc_productInfo";
    wikiDescription = "Logs various information about the game.";
};
class ENH_ClearChat
{
    text = "$STR_ENH_MAIN_TOOLS_CLEARCHAT";
    action = "clearRadio";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_C};
    wikiDescription = "Clears all system messages from the chat window.";
};
class ENH_ExportGUIBaseClasses
{
    text = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES";
    action = "findDisplay 313 createDisplay 'ENH_ExportGUIDefines'";wikiDescription = "Open a GUI to export GUI base classes. See GUI documentation for detailed information.";
};
class ENH_GUITestGrids
{
    text = "$STR_ENH_MAIN_TOOLS_GUITESTGRIDS";
    action = "findDisplay 313 createDisplay 'RscTestGrids'";
    opensNewWindow = 1;
    wikiDescription = "Opens a GUI for testing different UI grids.";
};
