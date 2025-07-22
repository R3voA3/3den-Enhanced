class ENH_Interface
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_INTERFACE";
    class Attributes
    {
        class ENH_CollapseAssetBrowser
        {
            displayName = "$STR_ENH_MAIN_COLLAPSEASSETBROWSER";
            property = "ENH_CollapseAssetBrowser";
            control = "Checkbox";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_CollapseAssetBrowser', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_CollapseAssetBrowser', false]";
        };
        class ENH_CollapseEntityList: ENH_CollapseAssetBrowser
        {
            displayName = "$STR_ENH_MAIN_COLLAPSEENTITYLIST";
            property = "ENH_CollapseEntityList";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_CollapseEntityList', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_CollapseEntityList', false]";
        };
        class ENH_ShowPanelLeft: ENH_CollapseAssetBrowser
        {
            displayName = "$STR_ENH_MAIN_SHOWLEFTPANEL";
            property = "ENH_ShowPanelLeft";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowPanelLeft', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowPanelLeft', true]";
        };
        class ENH_ShowPanelRight: ENH_ShowPanelLeft
        {
            displayName = "$STR_ENH_MAIN_SHOWRIGHTPANEL";
            property = "ENH_ShowPanelRight";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowPanelRight', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowPanelRight', true]";
        };
        class ENH_MinimapSize
        {
            displayName = "$STR_ENH_MAIN_MINIMAPSIZE";
            property = "ENH_MinimapSize";
            control = "Combo";
            class Values
            {
                class Disabled
                {
                    name = "$STR_DISABLED";
                    value = 0;
                };
                class Small
                {
                    name = "$STR_SMALL";
                    value = 1;
                };
                class Medium
                {
                    name = "$STR_MEDIUM";
                    value = 2;
                };
                class Large
                {
                    name = "$STR_LARGE";
                    value = 3;
                };
            };
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_MinimapSize', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_MinimapSize', 0]";
            typeName = "NUMBER";
        };
        class ENH_MinimapScaleMultiplier
        {
            displayName = "$STR_ENH_MAIN_MINIMAPSCALEMULTIPLIER";
            property = "ENH_MinimapScaleMultiplier";
            control = "SliderCameraSpeedMult";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_MinimapScaleMultiplier', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_MinimapScaleMultiplier', 1]";
        };
        class ENH_EntityCounter: ENH_ShowPanelLeft
        {
            displayName = "$STR_ENH_MAIN_STATUSBAR_ENTITYCOUNTER_DISPLAYNAME";
            property = "ENH_Statusbar_EntityCounter";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_EntityCounter', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_EntityCounter', true]";
        };
        class ENH_ToggleDrawBuildingPositions: ENH_ShowPanelLeft
        {
            displayName = "$STR_ENH_MAIN_TOOLS_DRAWBUILDINGPOSITIONS";
            property = "ENH_DrawBuildingPositions";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_DrawBuildingPositions', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_DrawBuildingPositions', false]";
        };
        class ENH_DrawDLCIcons: ENH_ShowPanelLeft
        {
            displayName = "$STR_ENH_MAIN_TOOLS_DRAWDLCICONS";
            property = "ENH_DrawDLCIcons";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_DrawDLCIcons', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_DrawDLCIcons', false]";
        };
        class ENH_ShowCustomMarkerColorAndShape: ENH_ShowPanelLeft
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_SHOW_CUSTOM_MARKER_COLOR_AND_SHAPE_DISPLAYNAME";
            property = "ENH_ShowCustomMarkerColorAndShape";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowCustomMarkerColorAndShape', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowCustomMarkerColorAndShape', true]";
        };
        class ENH_AdjustTitleTextWidth: ENH_ShowPanelLeft
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_ADJUST_TITLE_WIDTH_DISPLAYNAME";
            property = "ENH_AdjustTitleTextWidth";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_AdjustTitleTextWidth', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_AdjustTitleTextWidth', true]";
        };
        class ENH_3DENCommandPalette_Path: ENH_ShowPanelLeft
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_3DEN_COMMAND_PALETTE_PATH_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_PREFERENCES_3DEN_COMMAND_PALETTE_PATH_TOOLTIP";
            property = "ENH_3DENCommandPalette_Path";
            control = "Edit";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_3DENCommandPalette_Path', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_3DENCommandPalette_Path', '']";
        };
    };
};
