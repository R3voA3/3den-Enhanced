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
                $STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT,
                $STR_ENH_TERRAINGRID_GRASSDISABLED_DISPLAYNAME,
                $STR_ENH_TERRAINGRID_STANDARD_DISPLAYNAME,
                $STR_ENH_TERRAINGRID_HIGH_DISPLAYNAME,
                $STR_ENH_TERRAINGRID_VERYHIGH_DISPLAYNAME,
                $STR_ENH_TERRAINGRID_ULTRA_DISPLAYNAME
            };
            values[] = {-1,50,25,12.5,6.25,3.125};
        };
    };
};