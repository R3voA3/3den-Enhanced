items[] +=
{
  "Separator",
  "ENH_OtherTools"
};
class Log
{
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
    "ENH_TriggerOwnerPlayer"
  };
};
class Select
{
  items[] +=
  {
    "ENH_SelectionFilter",
  };
};
class ENH_OtherTools
{
  text = "$STR_ENH_MAIN_CONTEXTMENU_OTHERTOOLS";
  items[] +=
  {
    "ENH_MeasureDistance",
    "ENH_ShowModuleInformation",
    "ENH_Garrison",
    "ENH_AddToFavorites",
    "ENH_MoveToLayer"
  };
  SHOW_IN_ROOT;
};
class ENH_LogFactions
{
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOGFACTION";
  action = "'FACTIONS' call ENH_fnc_3DENLog";
  conditionShow = "hoverObject";
};
class ENH_LogClassesString
{
  action = "'CLASSES' call ENH_fnc_3DENLog";
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOGCLASSESSTRING";
  conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
};
class ENH_LogPositions3D
{
  action = "'3D' call ENH_fnc_3DENLog";
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOGPOSITIONS3D";
  conditionShow = "selected - selectedMarker";
};
class ENH_LogPositions2D
{
  action = "'2D' call ENH_fnc_3DENLog";
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOGPOSITIONS2D";
  conditionShow = "selected";
};
class ENH_LogGridPositon
{
  action = "'GRIDPOS' call ENH_fnc_3DENLog";
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOGGRIDPOSITION";
  conditionShow = "1";
};
class ENH_Log3DENID
{
  action = "'IDS' call ENH_fnc_3DENLog";
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOG3DENIDS";
  conditionShow = "selected";
};
class ENH_LogVarNames
{
  action = "'VARNAMES' call ENH_fnc_3DENLog";
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOGVARNAMES";
  conditionShow = "selected";
};
class ENH_LogObjectInfo: ENH_LogFactions
{
  action = "'OBJECTINFO' call ENH_fnc_3DENLog";
  text = "$STR_ENH_MAIN_CONTEXTMENU_LOGOBJECTINFO";
};
class ENH_MeasureDistance
{
  action = "0 spawn ENH_fnc_measureDistance";
  text = "$STR_ENH_MAIN_CONTEXTMENU_MEASUREDISTANCE";
  picture = "x\enh\addons\main\data\icon_ruler_ca.paa";
  conditionShow = "1";
};
class ENH_ShowModuleInformation
{
  action = "findDisplay 313 createDisplay 'ENH_ModuleInformation'";
  text = "$STR_ENH_MAIN_CONTEXTMENU_GETMODULEINFORMATION";
  conditionShow = "hoverLogic";
  opensNewWindow = 1;
};
class ENH_Garrison
{
  action = "findDisplay 313 ctrlCreate ['ENH_Garrison', 20100]";
  text = "$STR_ENH_MAIN_CONTEXTMENU_GARRISON";
  picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\getin_ca.paa";
  conditionShow = "selected";
  opensNewWindow = 1;
};
class ENH_TriggerOwnerPlayer
{
  action = "add3DENConnection ['TriggerOwner', get3DENSelected 'Trigger', player]";
  text = "$STR_ENH_MAIN_CONTEXTMENU_SETTRIGGEROWNERPLAYER";
  conditionShow = "hoverTrigger";
};
class ENH_DeleteCrew
{
  action = "call ENH_fnc_deleteCrew";
  text = "$STR_ENH_MAIN_CONTEXTMENU_DELETECREW";
  conditionShow = "hoverObjectVehicle";
};
class ENH_AddToFavorites
{
  action = "['contextMenu'] call ENH_fnc_favoritesList";
  text = "$STR_ENH_MAIN_CONTEXTMENU_FAVORITES";
  picture = "\a3\ui_f_curator\data\displays\rscdisplaycurator\moderecent_ca.paa";
  conditionShow = "hoverObject + hoverLogic";
};
class ENH_MoveToLayer
{
  action = "findDisplay 313 createDisplay 'ENH_MoveToLayer'";
  text = "$STR_ENH_MAIN_SELECTLAYER_MOVETOLAYER";
  picture = "a3\3den\data\displays\display3den\panelleft\entitylist_layer_ca.paa";
  conditionShow = "selected";
};
class ENH_SelectionFilter
{
  action = "findDisplay 313 createDisplay 'ENH_SelectionFilter'";
  text = "$STR_ENH_MAIN_SELECTIONFILTER";
  conditionShow = "selected";
  opensNewWindow = 1;
};
//Modify the original behaviour. Now the map will be moved as well
class MoveCamera
{
  action = "0 spawn ENH_fnc_centerMapOnSelection";
};