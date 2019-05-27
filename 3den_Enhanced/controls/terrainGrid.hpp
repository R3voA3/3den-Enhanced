class Enh_TerrainDetail: Title
{
    attributeLoad = "(_this controlsGroupCtrl 100) lbSetCursel ([-1,50,25,12.5,6.25,3.125] find _value)";
    attributeSave = "[-1,50,25,12.5,6.25,3.125] select (missionNamespace getVariable ['Enh_TerrainGrid_Value',0])";
    h = "2 * 5 * (pixelH * pixelGrid * 0.50)";

    class Controls: Controls
    {
        class Title: Title {};
        class Value: ctrlToolbox
        {
            idc = 100;
            x = "48 * (pixelW * pixelGrid * 0.50)";
            w = "82 * (pixelW * pixelGrid * 0.50)";
            h = "10 * (pixelH * pixelGrid * 0.50)";
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
            onToolboxSelChanged = "Enh_TerrainGrid_Value = _this # 1";
        };
    };
};