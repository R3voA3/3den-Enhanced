class Presence
{
	displayName = $STR_3DEN_OBJECT_ATTRIBUTECATEGORY_PRESENCE;
	collapsed = 1;
	class Attributes
	{
		class ENH_Presence
		{
			displayName = $STR_3DEN_OBJECT_ATTRIBUTE_PRESENCE_DISPLAYNAME;
			tooltip = $STR_3DEN_OBJECT_ATTRIBUTE_PRESENCE_TOOLTIP;
			property = "ENH_WaypointPresence";
			control = "Slider";
			expression = "if (random 1 > _value) then {deleteWaypoint _this}";
			defaultValue = "1";
		};
		class ENH_PresenceCondition
		{
			displayName = $STR_3DEN_OBJECT_ATTRIBUTE_PRESENCECONDITION_DISPLAYNAME;
			tooltip = $STR_3DEN_OBJECT_ATTRIBUTE_PRESENCECONDITION_TOOLTIP;
			property = "ENH_WaypointPresenceCondition";
			control = "EditCode";
			validate = "condition";
			expression = "if !(call compile _value) then {deleteWaypoint _this}";
			defaultValue = "true";
		};
	};
};