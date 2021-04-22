items[] +=
{
  "Separator",
  "ENH_MeasureDistance",
  "ENH_ShowModuleInformation",
  "ENH_Garrison",
  "ENH_Extraction"
};
class Log
{
  picture = "\3denEnhanced\data\icon_clipboard_ca.paa";
  items[] +=
  {
    "ENH_LogClassesString",
    "SeparatorSelected",
    "ENH_LogVarNames",
    "ENH_LogFactions",
    "SeparatorSelected",
    "ENH_LogPositions3D",
    "ENH_LogPositions2D",
    "ENH_LogGridPositon",
    "SeparatorSelected",
    "ENH_Log3DENID",
    "ENH_LogObjectInfo"
  };
};
class Edit
{
  items[] +=
  {
    "ENH_DeleteCrew"
  };
};
class ConnectParent
{
  items[] +=
  {
    "ENH_TriggerOwnerPlayer",
  };
};
class ENH_LogFactions
{
  text = "$STR_ENH_CONTEXTMENU_LOGFACTION";
  action = "'FACTIONS' call ENH_fnc_log";
  conditionShow = "hoverObject";
};
class ENH_LogClassesString
{
  action = "'CLASSES' call ENH_fnc_log";
  text = "$STR_ENH_CONTEXTMENU_LOGCLASSESSTRING";
  conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
};
class ENH_LogPositions3D
{
  action = "'3D' call ENH_fnc_log";
  text = "$STR_ENH_CONTEXTMENU_LOGPOSITIONS3D";
  conditionShow = "selected - selectedMarker";
};
class ENH_LogPositions2D
{
  action = "'2D' call ENH_fnc_log";
  text = "$STR_ENH_CONTEXTMENU_LOGPOSITIONS2D";
  conditionShow = "selected";
};
class ENH_LogGridPositon
{
  action = "'GRIDPOS' call ENH_fnc_log";
  text = "$STR_ENH_CONTEXTMENU_LOGGRIDPOSITION";
  conditionShow = "1";
};
class ENH_Log3DENID
{
  action = "'IDS' call ENH_fnc_log";
  text = "$STR_ENH_CONTEXTMENU_LOG3DENIDS";
  conditionShow = "selected";
};
class ENH_LogVarNames
{
  action = "'VARNAMES' call ENH_fnc_log";
  text = "$STR_ENH_CONTEXTMENU_LOGVARNAMES";
  conditionShow = "selected";
};
class ENH_LogObjectInfo: ENH_LogFactions
{
  action = "'OBJECTINFO' call ENH_fnc_log";
  text = "$STR_ENH_CONTEXTMENU_LOGOBJECTINFO";
};
class ENH_MeasureDistance
{
  action = "[] spawn ENH_fnc_measureDistance";
  text = "$STR_ENH_CONTEXTMENU_MEASUREDISTANCE";
  picture = "\3denEnhanced\data\icon_ruler_ca.paa";
  conditionShow = "1";
  SHOW_IN_ROOT;
};
class ENH_ShowModuleInformation
{
  action = "findDisplay 313 createDisplay 'ENH_ModuleInformation'";
  text = "$STR_ENH_CONTEXTMENU_GETMODULEINFORMATION";
  conditionShow = "hoverLogic";
  opensNewWindow = 1;
  SHOW_IN_ROOT;
};
class ENH_Garrison
{
  action = "findDisplay 313 createDisplay 'ENH_Garrison'";
  text = "$STR_ENH_CONTEXTMENU_GARRISON";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\getin_ca.paa";
  conditionShow = "selected";
  opensNewWindow = 1;
  SHOW_IN_ROOT;
};
class ENH_Extraction
{
  action = "findDisplay 313 createDisplay 'ENH_Extraction'";
  text = "$STR_ENH_CONTEXTMENU_CREATEEXTRACTION";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\exit_ca.paa";
  conditionShow = "hoverObjectVehicle";
  opensNewWindow = 1;
  SHOW_IN_ROOT;
};
class ENH_TriggerOwnerPlayer
{
  action = "add3DENConnection ['TriggerOwner', get3DENSelected 'Trigger', player]";
  text = "$STR_ENH_CONTEXTMENU_SETTRIGGEROWNERPLAYER";
  conditionShow = "hoverTrigger";
};
class ENH_DeleteCrew
{
  action = "call ENH_fnc_deleteCrew";
  text = "$STR_ENH_CONTEXTMENU_DELETECREW";
  conditionShow = "hoverObjectVehicle";
};