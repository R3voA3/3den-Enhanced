class Enh_VisualSettings
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_visualSettings;
	class Attributes
	{
		class Enh_ViewDistance
		{
			displayName = $STR_ENH_viewDistance_displayName;
			tooltip = $STR_ENH_viewDistance_tooltip;
			property = "Enh_viewDistance";
			control = "Edit";
			expression = "if (_value > 0 && !is3DEN && hasInterface) then {setViewDistance _value}";
			defaultValue = "-1";
			typeName = "NUMBER";
		};
		class Enh_ObjViewDistance: Enh_ViewDistance
		{
			displayName = $STR_ENH_objViewDistance_displayName;
			property = "Enh_objViewDistance";
			expression = "if (_value > 0 && !is3DEN && hasInterface) then {setObjectViewDistance _value}";
		};
		class Enh_TerrainDetail: Enh_ViewDistance
		{
			displayName = $STR_ENH_terrainDetail_displayName;
			tooltip = "";
			property = "Enh_terrainDetail";
			control = "Enh_TerrainDetail";
			expression = "if (_value > 0 && !is3DEN && hasInterface) then {setTerrainGrid _value}";
		};
	};
};