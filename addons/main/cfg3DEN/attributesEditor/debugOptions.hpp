class ENH_DebugOptions
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_DEBUG_OPTIONS";
    class Attributes
    {
        class ENH_DebugOptions_Subcategory
        {
            description = "$STR_ENH_MAIN_DEBUGOPTIONS_DESCRIPTION";
            property = "ENH_DebugOptions_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        class ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_ARSENAL_DISPLAYNAME";
            property = "ENH_DebugOptions_Arsenal";
            control = "Checkbox";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Arsenal', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Arsenal', false]";
        };
        class ENH_DebugOptions_Garage: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_GARAGE_DISPLAYNAME";
            property = "ENH_DebugOptions_Garage";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Garage', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Garage', false]";
        };
        class ENH_DebugOptions_KillBLUFOR: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_KILLBLUFOR_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_KILLUNITS_TOOLTIP";
            property = "ENH_DebugOptions_KillBLUFOR";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillBLUFOR', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillBLUFOR', false]";
        };
        class ENH_DebugOptions_KillOPFOR: ENH_DebugOptions_KillBLUFOR
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_KILLOPFOR_DISPLAYNAME";
            property = "ENH_DebugOptions_KillOPFOR";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillOPFOR', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillOPFOR', false]";
        };
        class ENH_DebugOptions_KillIndependent: ENH_DebugOptions_KillBLUFOR
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_KILLINDEPENDENT_DISPLAYNAME";
            property = "ENH_DebugOptions_KillIndependent";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillIndependent', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillIndependent', false]";
        };
        class ENH_DebugOptions_KillCivilian: ENH_DebugOptions_KillBLUFOR
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_KILLCIVILIAN_DISPLAYNAME";
            property = "ENH_DEBUGOPTIONS_KILLCIVILIAN";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillCivilian', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillCivilian', false]";
        };
        class ENH_DebugOptions_KillCursor: ENH_DebugOptions_KillBLUFOR
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_KILLCURSOR_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_KILLCURSOR_TOOLTIP";
            property = "ENH_DebugOptions_KillCursor";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillCursor', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillCursor', false]";
        };
        class ENH_DebugOptions_DeleteCorpse: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_DELETECORPSE_DISPLAYNAME";
            property = "ENH_DebugOptions_DeleteCorpse";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DeleteCorpse', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DeleteCorpse', false]";
        };
        class ENH_DebugOptions_Teleport: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_TELEPORT";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_TELEPORT_TOOLTIP";
            property = "ENH_DebugOptions_Teleport";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Teleport', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Teleport', false]";
        };
        class ENH_DebugOptions_VariableViewer: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_VARIABLEVIEWER_HEADER";
            property = "ENH_DebugOptions_VariableViewer";
        };
        class ENH_DebugOptions_ActiveScripts: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_LOGSCRIPTS_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_LOGSCRIPTS_TOOLTIP";
            property = "ENH_DebugOptions_ActiveScripts";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_ActiveScripts', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_ActiveScripts', false]";
        };
        // Player
        class ENH_DebugOptions_Player_Subcategory: ENH_DebugOptions_Subcategory
        {
            description = "$STR_MPTABLE_NAME";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        class ENH_DebugOptions_Invulnerability: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_INVULNERABILITY_DISPLAYNAME";
            property = "ENH_DebugOptions_Invulnerability";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Invulnerability', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Invulnerability', false]";
        };
        class ENH_DebugOptions_Captive: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_CAPTIVE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_CAPTIVE_TOOLTIP";
            property = "ENH_DebugOptions_Captive";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Captive', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Captive', false]";
        };
        class ENH_DebugOptions_Stamina: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_STAMINA_DISPLAYNAME";
            property = "ENH_DebugOptions_Stamina";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Stamina', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Stamina', false]";
        };
        class ENH_DebugOptions_Zeus: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_ZEUS_DISPLAYNAME";
            property = "ENH_DebugOptions_Zeus";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Zeus', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Zeus', false]";
        };
        class ENH_DebugOptions_NoRecoil: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_NORECOIL";
            property = "ENH_DebugOptions_NoRecoil";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_NoRecoil', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_NoRecoil', false]";
        };
        class ENH_DebugOptions_NoSway: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_NOSWAY";
            property = "ENH_DebugOptions_NoSway";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_NoSway', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_NoSway', false]";
        };
        class ENH_DebugOptions_UnlimitedAmmo: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_UNLIMITEDAMMO";
            property = "ENH_DebugOptions_UnlimitedAmmo";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_UnlimitedAmmo', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_UnlimitedAmmo', false]";
        };
        class ENH_DebugOptions_NoReload: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_NORELOAD";
            property = "ENH_DebugOptions_NoReload";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_NoReload', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_NoReload', false]";
        };
        // Visualization
        class ENH_DebugOptions_Subcategory_Drawing: ENH_DebugOptions_Player_Subcategory
        {
            description = "$STR_ENH_MAIN_DEBUGOPTIONS_CATEGORY_VISUALIZATION";
        };
        class ENH_DebugOptions_BulletTracking: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_BULLETTRACKING_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_BULLETTRACKING_TOOLTIP";
            property = "ENH_DebugOptions_BulletTracking";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_BulletTracking', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_BulletTracking', false]";
        };
        class ENH_DebugOptions_FPS: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_FPS_DISPLAYNAME";
            property = "ENH_DebugOptions_FPS";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_FPS', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_FPS', false]";
        };
        class ENH_DebugOptions_DrawViewDirection: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_DRAWVIEWDIRECTION";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_DRAWVIEWDIRECTION_TOOLTIP";
            property = "ENH_DebugOptions_DrawViewDirection";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DrawViewDirection', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DrawViewDirection', false]";
        };
        class ENH_DebugOptions_DynSimDebug: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_3DEN_DYNAMICSIMULATION_TEXTSINGULAR";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_DYNSIMDEBUG_TOOLTIP";
            property = "ENH_DebugOptions_DynSimDebug";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DynSimDebug', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DynSimDebug', false]";
        };
        class ENH_DebugOptions_ShowGroups: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_SHOWGROUPS_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_SHOWGROUPS_TOOLTIP";
            property = "ENH_DebugOptions_ShowGroups";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_ShowGroups', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_ShowGroups', false]";
        };
        class ENH_DebugOptions_DrawTriggers: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_DRAWTRIGGERS_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_DEBUGOPTIONS_DRAWTRIGGERS_TOOLTIP";
            property = "ENH_DebugOptions_DrawTriggers";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DrawTriggers', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DrawTriggers', false]";
        };
        class ENH_DebugOptions_DebugPath: ENH_DebugOptions_Arsenal
        {
            displayName = "Debug Path";
            property = "ENH_DebugOptions_DebugPath";
            control = "Combo";
            typeName = "NUMBER";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DebugPath', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DebugPath', 0]";
            class Values
            {
                class Disabled
                {
                    name = "$STR_DISABLED";
                    value = 0;
                };
                class 2D
                {
                    name = "2D";
                    value = 1;
                };
                class 2Dand3D
                {
                    name = "2D + 3D";
                    value = 2;
                };
            };
        };
        // Environment
        class ENH_DebugOptions_Environment_Subcategory: ENH_DebugOptions_Player_Subcategory
        {
            description = "$STR_A3_CREDITS_ENVIRONMENT";
        };
        class ENH_DebugOptions_SkipTime: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_SKIPTIME";
            property = "ENH_DebugOptions_SkipTime";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_SkipTime', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_SkipTime', false]";
        };
        class ENH_DebugOptions_TimeMultiplier: ENH_DebugOptions_Arsenal
        {
            displayName = "$STR_ENH_MAIN_DEBUGOPTIONS_TIMEMULTIPLIER";
            property = "ENH_DebugOptions_TimeMultiplier";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_TimeMultiplier', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_TimeMultiplier', false]";
        };
    };
};
