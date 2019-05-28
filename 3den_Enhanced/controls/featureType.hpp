class Enh_FeatureType: Title
{
    attributeLoad = "(_this controlsGroupCtrl 100) lbSetCursel ([0,1,2] find _value)";
    attributeSave = "[0,1,2] select (lbCurSel (_this controlsGroupCtrl 100))";
    h = "15 * (pixelH * pixelGrid * 0.50)";

    class Controls: Controls
    {
        class Title: Title {};
        class Value: ctrlToolbox
        {
            idc = 100;
            x = "48 * (pixelW * pixelGrid * 0.50)";
            w = "82 * (pixelW * pixelGrid * 0.50)";
            h = "15 * (pixelH * pixelGrid * 0.50)";
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