class Enh_TerrainGrid: Title
{
	attributeLoad = "[_this controlsGroupCtrl 100,_config] call Enh_fnc_attributeLoadCombo";
	attributeSave = "[_this controlsGroupCtrl 100,_config] call Enh_fnc_attributeSaveCombo";

	class Controls: Controls
	{
		class Title: Title {};
		class Value: ctrlCombo
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;

			class Items
			{
				class NoChange
				{
					text = $STR_3den_attributes_default_unchanged_text;
					tooltip = $STR_3den_attributes_default_unchanged_tooltip;
					data = "-1";
					default = 1;
				};
				class Low
				{
					text = $STR_ENH_terrainGrid_grassDisabled_displayName;
					data = "50";
				};
				class Standard
				{
					text = $STR_ENH_terrainGrid_standard_displayName;
					data = "25";
				};
				class High
				{
					text = $STR_ENH_terrainGrid_high_displayName;
					data = "12.5";
				};
				class VeryHigh
				{
					text = $STR_ENH_terrainGrid_veryHigh_displayName;
					data = "6.25";
				};
				class Ultra
				{
					text = $STR_ENH_terrainGrid_ultra_displayName;
					data = "3.125";
				};
			};
		};
	};
};
