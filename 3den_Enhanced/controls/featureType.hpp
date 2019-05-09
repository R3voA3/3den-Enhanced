class Enh_FeatureType: Title
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
				class Unchanged
				{
					text = $STR_3den_attributes_default_unchanged_text;
					tooltip = $STR_3den_attributes_default_unchanged_tooltip;
					data = "0";
					default = 1;
				};
				class ObjectViewDistance
				{
					text = $STR_ENH_featureType_objectViewDistance_text;
					tooltip = $STR_ENH_featureType_objectViewDistance_tooltip;
					data = "1";
				};
				class TerrainViewDistance
				{
					text = $STR_ENH_featureType_terrainViewDistance_text;
					tooltip = $STR_ENH_featureType_terrainViewDistance_tooltip;
					data = "2";
				};
			};
		};
	};
};
