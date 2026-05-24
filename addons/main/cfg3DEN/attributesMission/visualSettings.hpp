class ENH_VisualSettings
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_ATTRIBUTECATEGORY_VISUALSETTINGS";
    class Attributes
    {
        class ENH_ViewDistance
        {
            displayName = "$STR_ENH_MAIN_VIEWDISTANCE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_VIEWDISTANCE_TOOLTIP";
            property = "ENH_viewDistance";
            control = "Edit";
            expression = "if (!is3DEN && _value > 0 && hasInterface) then {setViewDistance _value}";
            defaultValue = -1;
            typeName = "NUMBER";
        };
        class ENH_ObjViewDistance: ENH_ViewDistance
        {
            displayName = "$STR_ENH_MAIN_OBJVIEWDISTANCE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_OBJVIEWDISTANCE_TOOLTIP";
            property = "ENH_objViewDistance";
            expression = "if (!is3DEN && _value > 0 && hasInterface) then {setObjectViewDistance _value}";
        };
        class ENH_TerrainDetail
        {
            control = "Combo";
            property = "ENH_terrainDetail";
            displayName = "$STR_ENH_MAIN_TERRAINDETAIL_DISPLAYNAME";
            expression = "if (!is3DEN && _value > 0 && hasInterface) then {setTerrainGrid _value}";
            defaultValue = -1;
            typeName = "NUMBER";
            class Values
            {
                class Unchanged
                {
                    name = "$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT";
                    value = -1;
                };
                class GrassDisabled
                {
                    name = "$STR_ENH_MAIN_TERRAINGRID_GRASSDISABLED_DISPLAYNAME";
                    value = 50;
                };
                class Standard
                {
                    name = "$STR_ENH_MAIN_TERRAINGRID_STANDARD_DISPLAYNAME";
                    value = 25;
                };
                class High
                {
                    name = "$STR_ENH_MAIN_TERRAINGRID_HIGH_DISPLAYNAME";
                    value = 12.5;
                };
                class VeryHigh
                {
                    name = "$STR_ENH_MAIN_TERRAINGRID_VERYHIGH_DISPLAYNAME";
                    value = 6.25;
                };
                class Ultra
                {
                    name = "$STR_ENH_MAIN_TERRAINGRID_ULTRA_DISPLAYNAME";
                    value = 3.125;
                };
            };
        };
    };
};
