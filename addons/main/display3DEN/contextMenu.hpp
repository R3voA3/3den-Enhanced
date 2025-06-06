items[] +=
{
    "Separator",
    "ENH_OtherTools",
    "ENH_AddToFavorites"
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
        "ENH_MoveToLayer"
    };
    SHOW_IN_ROOT;
};
class ENH_LogFactions
{
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOGFACTION";
    action = "'FACTIONS' call ENH_fnc_3DENLog";
    conditionShow = "hoverObject";
    wikiDescription = "Logs all unique factions of all selected entities.";
};
class ENH_LogClassesString
{
    action = "'CLASSES' call ENH_fnc_3DENLog";
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOGCLASSESSTRING";
    conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
    wikiDescription = "Logs all unique classes of all selected entities.";
};
class ENH_LogPositions3D
{
    action = "'3D' call ENH_fnc_3DENLog";
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOGPOSITIONS3D";
    conditionShow = "selected - selectedMarker";
    wikiDescription = "Logs all 3D positions of all selected entities.";
};
class ENH_LogPositions2D
{
    action = "'2D' call ENH_fnc_3DENLog";
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOGPOSITIONS2D";
    conditionShow = "selected";
    wikiDescription = "Logs all 2D positions of all selected entities.";
};
class ENH_LogGridPositon
{
    action = "'GRIDPOS' call ENH_fnc_3DENLog";
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOGGRIDPOSITION";
    conditionShow = "1";
    wikiDescription = "Logs all grid positions of all selected entities.";
};
class ENH_Log3DENID
{
    action = "'IDS' call ENH_fnc_3DENLog";
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOG3DENIDS";
    conditionShow = "selected";
    wikiDescription = "Logs all entity ids of all selected entities.";
};
class ENH_LogVarNames
{
    action = "'VARNAMES' call ENH_fnc_3DENLog";
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOGVARNAMES";
    conditionShow = "selected";
    wikiDescription = "Logs all variable names of all selected entities.";
};
class ENH_LogObjectInfo: ENH_LogFactions
{
    action = "'OBJECTINFO' call ENH_fnc_3DENLog";
    text = "$STR_ENH_MAIN_CONTEXTMENU_LOGOBJECTINFO";
    wikiDescription = "Logs various information about each selected entity.";
};
class ENH_MeasureDistance
{
    action = "0 spawn ENH_fnc_measureDistance";
    text = "$STR_ENH_MAIN_CONTEXTMENU_MEASUREDISTANCE";
    picture = "\x\enh\addons\main\data\ruler_ca.paa";
    conditionShow = "1";
    wikiDescription = "Allows the measuring between two points, both in 2D and 3D.";
};
class ENH_ShowModuleInformation
{
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_ModuleInformation');
    text = "$STR_ENH_MAIN_CONTEXTMENU_GETMODULEINFORMATION";
    conditionShow = "hoverLogic";
    opensNewWindow = 1;
    wikiDescription = "Shows informationa about selected system entity. Useful for modules that have no eden editor description.";
};
class ENH_Garrison
{
    action = QUOTE(findDisplay IDD_DISPLAY3DEN ctrlCreate ARR_2(['ENH_Garrison',IDC_GARRISON_GROUP]));
    text = "$STR_ENH_MAIN_CONTEXTMENU_GARRISON";
    picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\getin_ca.paa";
    conditionShow = "selected";
    opensNewWindow = 1;
    wikiDescription = "Opens a UI that allows for quick garrison of selected entities.";
};
class ENH_TriggerOwnerPlayer
{
    action = "add3DENConnection ['TriggerOwner', get3DENSelected 'Trigger', player]";
    text = "$STR_ENH_MAIN_CONTEXTMENU_SETTRIGGEROWNERPLAYER";
    conditionShow = "hoverTrigger";
    wikiDescription = "Sets the player as trigger of selected trigger.";
};
class ENH_DeleteCrew
{
    action = "call ENH_fnc_deleteCrew";
    text = "$STR_ENH_MAIN_CONTEXTMENU_DELETECREW";
    conditionShow = "hoverObjectVehicle";
    wikiDescription = "Deletes the crew of all selected vehicles.";
};
class ENH_AddToFavorites
{
    action = "['contextMenu'] call ENH_fnc_favoritesList";
    text = "$STR_ENH_MAIN_CONTEXTMENU_FAVORITES";
    picture = "\a3\ui_f_curator\data\displays\rscdisplaycurator\moderecent_ca.paa";
    conditionShow = "hoverObject + hoverLogic + hoverMarker";
    wikiDescription = "Adds all selected entities to the favorites tab.";
    SHOW_IN_ROOT;
};
class ENH_MoveToLayer
{
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_MoveToLayer');
    text = "$STR_ENH_MAIN_SELECTLAYER_MOVETOLAYER";
    picture = "a3\3den\data\displays\display3den\panelleft\entitylist_layer_ca.paa";
    conditionShow = "selected";
    wikiDescription = "Opens a UI that allows to quickly change the layer of all selected entities.";
};
class ENH_SelectionFilter
{
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_SelectionFilter');
    text = "$STR_ENH_MAIN_SELECTIONFILTER";
    conditionShow = "selected";
    opensNewWindow = 1;
    wikiDescription = "Opens a UI that allows to adjust current selection based on various filters.";
};
//Modify the original behaviour. Now the map will be moved as well
class MoveCamera
{
    action = "0 spawn ENH_fnc_centerMapOnSelection";
};
