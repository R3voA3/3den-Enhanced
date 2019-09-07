items[] +=
{
	"Enh_MeasureDistance",
	"Enh_ShowModuleInformation",
	"Enh_Garrison",
	"Enh_Extraction"
};
class Log
{
	picture = "\3denEnhanced\data\icon_clipboard.paa";
	items[] +=
	{
		"Enh_LogClassesString",
		"Enh_LogFactions",
		"Enh_LogPositions3D",
		"Enh_LogPositions2D",
		"Enh_LogGridPositon",
		"Enh_Log3DENID",
		"Enh_LogObjectInfo"
	};
};
class Edit
{
	items[] +=
	{
		"Enh_DeleteCrew"
	};
};
class ConnectParent
{
	items[] +=
	{
		"Enh_TriggerOwnerPlayer",
	};
};
class Enh_LogFactions
{
	text = $STR_ENH_contextMenu_logFaction;
	action = "call Enh_fnc_logFactions";
	conditionShow = "hoverObject";
};
class Enh_LogClassesString
{
	action = "call Enh_fnc_logClassesString";
	Text = $STR_ENH_contextMenu_logClassesString;
	conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
};
class Enh_LogPositions3D
{
	action = "call Enh_fnc_logPositions";
	Text = $STR_ENH_contextMenu_logPositions3D;
	conditionShow = "selected - selectedMarker";
};
class Enh_LogPositions2D
{
	action = "call Enh_fnc_logPositions2D";
	Text = $STR_ENH_contextMenu_logPositions2D;
	conditionShow = "selected";
};
class Enh_LogGridPositon
{
	action = "call Enh_fnc_logGridPosition";
	Text = $STR_ENH_contextMenu_logGridPosition;
	conditionShow = "1";
};
class Enh_Log3DENID
{
	action = "call Enh_fnc_log3DENIDs";
	Text = $STR_ENH_contextMenu_log3DENIDs;
	conditionShow = "selected";
};
class Enh_MeasureDistance
{
	action = "[] spawn Enh_fnc_measureDistance";
	Text = $STR_ENH_contextMenu_measureDistance;
	picture = "\3denEnhanced\data\icon_ruler.paa";
	conditionShow = "1";
	SHOW_IN_ROOT;
};
class Enh_ShowModuleInformation
{
	action = "findDisplay 313 createDisplay 'Enh_ModuleInformation'";
	Text = $STR_ENH_contextMenu_getModuleInformation;
	conditionShow = "hoverLogic";
	opensNewWindow = 1;
	SHOW_IN_ROOT;
};
class Enh_Garrison
{
	action = "(findDisplay 313) createDisplay 'Enh_Garrison'";
	Text = $STR_ENH_contextMenu_garrison;
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\getin_ca.paa";
	conditionShow = "selected";
	opensNewWindow = 1;
	SHOW_IN_ROOT;
};
class Enh_Extraction
{
	//action = "call Enh_fnc_3DENCreateExtraction";
	action = "call compile preprocessFileLineNumbers 'fn_3DENCreateExtraction.sqf'";
	Text = "Create Extraction"
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\exit_ca.paa";
	conditionShow = "hoverObjectVehicle";
	opensNewWindow = 1;
	SHOW_IN_ROOT;
};
class Enh_TriggerOwnerPlayer
{
	action = "add3DENConnection ['TriggerOwner',get3DENSelected 'Trigger',player]";
	Text = $STR_ENH_contextMenu_setTriggerOwnerPlayer;
	conditionShow = "hoverTrigger";
};
class Enh_LogObjectInfo: Enh_LogFactions
{
	action = "call Enh_fnc_logObjectInfo";
	Text = $STR_ENH_contextMenu_logObjectInfo;
};
class Enh_DeleteCrew
{
	action = "call Enh_fnc_deleteCrew";
	Text = $STR_ENH_contextMenu_deleteCrew;
	conditionShow = "hoverObjectVehicle";
};