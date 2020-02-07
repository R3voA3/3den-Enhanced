class ENH_TerrainDetail: Title
{
    attributeLoad = "[_this,_value] call ENH_fnc_terrainDetail_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_terrainDetail_onAttributeSave";
    h = 2 * SIZE_M * GRID_H + 5 * pixelH;
    class Controls: Controls
    {
        class Title: Title {};
        class Value: ctrlToolbox
        {
            idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 2 * SIZE_M * GRID_H;
            rows = 2;
            columns = 3;
            strings[] = 
            {
                $STR_3den_attributes_default_unchanged_text,
                $STR_ENH_terrainGrid_grassDisabled_displayName,
                $STR_ENH_terrainGrid_standard_displayName,
                $STR_ENH_terrainGrid_high_displayName,
                $STR_ENH_terrainGrid_veryHigh_displayName,
                $STR_ENH_terrainGrid_ultra_displayName
            };
            values[] = {-1,50,25,12.5,6.25,3.125};
        };
    };
};