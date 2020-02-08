class ENH_FeatureType: Title
{
    attributeLoad = "[_this,_value] call ENH_fnc_featureType_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_featureType_onAttributeSave";
    h = 3 * SIZE_M * GRID_H + 5 * pixelH;
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
                $STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT,
                $STR_ENH_FEATURETYPE_OBJECTVIEWDISTANCE_TEXT,
				$STR_ENH_FEATURETYPE_TERRAINVIEWDISTANCE_TEXT
            };
			tooltips[] = 
			{
				$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TOOLTIP,
				$STR_ENH_FEATURETYPE_OBJECTVIEWDISTANCE_TOOLTIP,
				$STR_ENH_FEATURETYPE_TERRAINVIEWDISTANCE_TOOLTIP
			};
            values[] = {0,1,2};
        };
    };
};