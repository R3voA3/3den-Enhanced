class Items
{
	items[] +=
	{
		"Enh_MeasureDistance",
		"Enh_ShowModuleDescription"
	};
	class Log
	{
		picture = "\3denEnhanced\data\Enh_icon_clipboard.paa";
		items[] +=
		{
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
	class CreateComment;
	class Enh_MeasureDistance: CreateComment
	{
		action = "[] spawn Enh_fnc_measureDistance";
		Text = $STR_ENH_contextMenu_measureDistance;
		picture = "\3denEnhanced\data\Enh_icon_ruler.paa";
		conditionShow = "1";
		data = "";
	};
	class Enh_ShowModuleDescription: CreateComment
	{
		action = "findDisplay 313 createDisplay 'Enh_ModuleInformation'";
		Text = $STR_ENH_contextMenu_getModuleDescription;
		picture = "";
		conditionShow = "hoverLogic";
		data = "";
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
};
