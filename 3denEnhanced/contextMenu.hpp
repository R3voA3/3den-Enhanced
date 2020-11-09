items[] +=
{
    "ENH_MeasureDistance",
    "ENH_ShowModuleInformation",
    "ENH_Garrison",
    "ENH_Extraction"
};
class Log
{
    picture = "\3denEnhanced\data\icon_clipboard.paa";
    items[] +=
    {
        "ENH_LogClassesString",
        "ENH_LogFactions",
        "ENH_LogPositions3D",
        "ENH_LogPositions2D",
        "ENH_LogGridPositon",
        "ENH_Log3DENID",
        "ENH_LogObjectInfo"
    };
};
class Edit
{
    items[] +=
    {
        "ENH_DeleteCrew",
        "ENH_FirstPerson"
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
    text = $STR_ENH_CONTEXTMENU_LOGFACTION;
    action = "call ENH_fnc_logFactions";
    conditionShow = "hoverObject";
};
class ENH_LogClassesString
{
    action = "call ENH_fnc_logClassesString";
    Text = $STR_ENH_CONTEXTMENU_LOGCLASSESSTRING;
    conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
};
class ENH_LogPositions3D
{
    action = "call ENH_fnc_logPositions3D";
    Text = $STR_ENH_CONTEXTMENU_LOGPOSITIONS3D;
    conditionShow = "selected - selectedMarker";
};
class ENH_LogPositions2D
{
    action = "call ENH_fnc_logPositions2D";
    Text = $STR_ENH_CONTEXTMENU_LOGPOSITIONS2D;
    conditionShow = "selected";
};
class ENH_LogGridPositon
{
    action = "call ENH_fnc_logGridPosition";
    Text = $STR_ENH_CONTEXTMENU_LOGGRIDPOSITION;
    conditionShow = "1";
};
class ENH_Log3DENID
{
    action = "call ENH_fnc_log3DENIDs";
    Text = $STR_ENH_CONTEXTMENU_LOG3DENIDS;
    conditionShow = "selected";
};
class ENH_LogObjectInfo: ENH_LogFactions
{
    action = "call ENH_fnc_logObjectInfo";
    Text = $STR_ENH_CONTEXTMENU_LOGOBJECTINFO;
};
class ENH_MeasureDistance
{
    action = "[] spawn ENH_fnc_measureDistance";
    Text = $STR_ENH_CONTEXTMENU_MEASUREDISTANCE;
    picture = "\3denEnhanced\data\icon_ruler.paa";
    conditionShow = "1";
    SHOW_IN_ROOT;
};
class ENH_ShowModuleInformation
{
    action = "findDisplay 313 createDisplay 'ENH_ModuleInformation'";
    Text = $STR_ENH_CONTEXTMENU_GETMODULEINFORMATION;
    conditionShow = "hoverLogic";
    opensNewWindow = 1;
    SHOW_IN_ROOT;
};
class ENH_Garrison
{
    action = "findDisplay 313 createDisplay 'ENH_Garrison'";
    Text = $STR_ENH_CONTEXTMENU_GARRISON;
    picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\getin_ca.paa";
    conditionShow = "selected";
    opensNewWindow = 1;
    SHOW_IN_ROOT;
};
class ENH_Extraction
{
    action = "findDisplay 313 createDisplay 'ENH_Extraction'";
    Text = $STR_ENH_CONTEXTMENU_CREATEEXTRACTION;
    picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\exit_ca.paa";
    conditionShow = "hoverObjectVehicle";
    opensNewWindow = 1;
    SHOW_IN_ROOT;
};
class ENH_TriggerOwnerPlayer
{
    action = "add3DENConnection ['TriggerOwner',get3DENSelected 'Trigger',player]";
    Text = $STR_ENH_CONTEXTMENU_SETTRIGGEROWNERPLAYER;
    conditionShow = "hoverTrigger";
};
class ENH_DeleteCrew
{
    action = "call ENH_fnc_deleteCrew";
    Text = $STR_ENH_CONTEXTMENU_DELETECREW;
    conditionShow = "hoverObjectVehicle";
};
class ENH_FirstPerson
{
    action = "call ENH_fnc_firstPerson";
    Text = $STR_ENH_CONTEXTMENU_FIRSTPERSON;
    conditionShow = "hoverObjectBrain";
};