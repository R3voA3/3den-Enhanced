class ENH_VisualSettings
{
	collapsed = 1;
	displayName = $STR_ENH_ATTRIBUTECATEGORY_VISUALSETTINGS;
	class Attributes
	{
		class ENH_ViewDistance
		{
			displayName = $STR_ENH_VIEWDISTANCE_DISPLAYNAME;
			tooltip = $STR_ENH_VIEWDISTANCE_TOOLTIP;
			property = "ENH_viewDistance";
			control = "Edit";
			expression = "if (!is3DEN && {_value > 0 && {hasInterface}}) then {setViewDistance _value}";
			defaultValue = "-1";
			typeName = "NUMBER";
		};
		class ENH_ObjViewDistance: ENH_ViewDistance
		{
			displayName = $STR_ENH_OBJVIEWDISTANCE_DISPLAYNAME;
			property = "ENH_objViewDistance";
			expression = "if (!is3DEN && {_value > 0 && {hasInterface}}) then {setObjectViewDistance _value}";
		};
		class ENH_TerrainDetail: ENH_ViewDistance
		{
			displayName = $STR_ENH_TERRAINDETAIL_DISPLAYNAME;
			tooltip = "";
			property = "ENH_terrainDetail";
			control = "ENH_TerrainDetail";
			expression = "if (!is3DEN && {_value > 0 && {hasInterface}}) then {setTerrainGrid _value}";
		};
	};
};