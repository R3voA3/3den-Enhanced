class Enh_FeatureType: Title
{
    attributeLoad = "[_this,_value] call Enh_fnc_featureType_onAttributeLoad";
    attributeSave = "_this call Enh_fnc_featureType_onAttributeSave";
    h = 3 * SIZE_M * GRID_H;
    class Controls: Controls
    {
        class Title: Title {};
        class Value: ctrlToolbox
        {
            idc = 100;
            x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
            h = 3 * SIZE_M * GRID_H;

            rows = 3;
            columns = 1;
            strings[] = 
            {
                $STR_3den_attributes_default_unchanged_text,
                $STR_ENH_featureType_objectViewDistance_text,
				$STR_ENH_featureType_terrainViewDistance_text
            };
			tooltips[] = 
			{
				$STR_3den_attributes_default_unchanged_tooltip,
				$STR_ENH_featureType_objectViewDistance_tooltip,
				$STR_ENH_featureType_terrainViewDistance_tooltip
			};
            values[] = {0,1,2};
        };
    };
};