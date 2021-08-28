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