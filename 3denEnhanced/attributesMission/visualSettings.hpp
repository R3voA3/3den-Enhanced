class ENH_VisualSettings
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_visualSettings;
	class Attributes
	{
		class ENH_ViewDistance
		{
			displayName = $STR_ENH_viewDistance_displayName;
			tooltip = $STR_ENH_viewDistance_tooltip;
			property = "ENH_viewDistance";
			control = "Edit";
			expression = "if (_value > 0 && !is3DEN && hasInterface) then {setViewDistance _value}";
			defaultValue = "-1";
			typeName = "NUMBER";
		};
		class ENH_ObjViewDistance: ENH_ViewDistance
		{
			displayName = $STR_ENH_objViewDistance_displayName;
			property = "ENH_objViewDistance";
			expression = "if (_value > 0 && !is3DEN && hasInterface) then {setObjectViewDistance _value}";
		};
		class ENH_TerrainDetail: ENH_ViewDistance
		{
			displayName = $STR_ENH_terrainDetail_displayName;
			tooltip = "";
			property = "ENH_terrainDetail";
			control = "ENH_TerrainDetail";
			expression = "if (_value > 0 && !is3DEN && hasInterface) then {setTerrainGrid _value}";
		};
	};
};