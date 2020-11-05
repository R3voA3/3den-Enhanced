class ENH_DebugOptions
{
    collapsed = 1;
    displayName = $STR_ENH_DEBUG_OPTIONS;
    class Attributes
    {
        class ENH_DebugOptions_Description
        {
            description = $STR_ENH_DEBUGOPTIONS_DESCRIPTION;
            data = "AttributeSystemSubcategory";
            control = "StructuredText2";//"SubCategoryNoHeader2";
        };
        class ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_ARSENAL_DISPLAYNAME;
            property = "ENH_DebugOptions_Arsenal";
            control = "Checkbox";
            expression = "";
            defaultValue = "false";
        };
        class ENH_DebugOptions_Garage: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_GARAGE_DISPLAYNAME;
            property = "ENH_DebugOptions_Garage";
        };
        class ENH_DebugOptions_FPS: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_FPS_DISPLAYNAME;
            property = "ENH_DebugOptions_FPS";
        };
        class ENH_DebugOptions_KillBLUFOR: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_KILLBLUFOR_DISPLAYNAME;
            tooltip = $STR_ENH_DEBUGOPTIONS_KILLUNITS_TOOLTIP;
            property = "ENH_DebugOptions_KillBLUFOR";
        };
        class ENH_DebugOptions_KillOPFOR: ENH_DebugOptions_KillBLUFOR
        {
            displayName = $STR_ENH_DEBUGOPTIONS_KILLOPFOR_DISPLAYNAME;
            property = "ENH_DebugOptions_KillOPFOR";
        };
        class ENH_DebugOptions_KillINDFOR: ENH_DebugOptions_KillBLUFOR
        {
            displayName = $STR_ENH_DEBUGOPTIONS_KILLINDFOR_DISPLAYNAME;
            property = "ENH_DebugOptions_KillINDFOR";
        };
        class ENH_DebugOptions_KillCIVFOR: ENH_DebugOptions_KillBLUFOR
        {
            displayName = $STR_ENH_DEBUGOPTIONS_KILLCIVFOR_DISPLAYNAME;
            property = "ENH_DebugOptions_KillCIVFOR";
        };
        class ENH_DebugOptions_KillCursor: ENH_DebugOptions_KillBLUFOR
        {
            displayName = $STR_ENH_DEBUGOPTIONS_KILLCURSOR_DISPLAYNAME;
            property = "ENH_DebugOptions_KillCursor";
        };
        class ENH_DebugOptions_DeleteCorpse: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_DELETECORPSE_DISPLAYNAME;
            property = "ENH_DebugOptions_DeleteCorpse";
        };
        class ENH_DebugOptions_Teleport: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_TELEPORT;
            tooltip = $STR_ENH_DEBUGOPTIONS_TELEPORT_TOOLTIP;
            property = "ENH_DebugOptions_Teleport";
        };
        class ENH_DebugOptions_VariableViewer: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_VARIABLEVIEWER_HEADER;
            property = "ENH_DebugOptions_VariableViewer";
        };
        class ENH_DebugOptions_ActiveScripts: ENH_DebugOptions_Arsenal
        {
            displayName = "Log active Scripts";
            tooltip = "When activated, all active scripts will be logged into the .rpt file."
            property = "ENH_DebugOptions_ActiveScripts";
        };
        //----------------PLAYER
        class ENH_DebugOptions_Subcategory_Player: ENH_DebugOptions_Description
        {
            displayName = $STR_MPTABLE_NAME;
            description = "";
            control = "SubCategory";
        };
        class ENH_DebugOptions_Invulnerability: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_INVULNERABILITY_DISPLAYNAME;
            property = "ENH_DebugOptions_Invulnerability";
        };
        class ENH_DebugOptions_Captive: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_CAPTIVE_DISPLAYNAME;
            tooltip = $STR_ENH_CAPTIVE_TOOLTIP;
            property = "ENH_DebugOptions_Captive";
        };
        class ENH_DebugOptions_Stamina: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_STAMINA_DISPLAYNAME;
            property = "ENH_DebugOptions_Stamina";
        };
        class ENH_DebugOptions_BulletTracking: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_BULLETTRACKING_DISPLAYNAME;
            tooltip = $STR_ENH_DEBUGOPTIONS_BULLETTRACKING_TOOLTIP;
            property = "ENH_DebugOptions_BulletTracking";
        };
        class ENH_DebugOptions_Zeus: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_ZEUS_DISPLAYNAME;
            property = "ENH_DebugOptions_Zeus";
        };
        class ENH_DebugOptions_NoRecoil: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_NORECOIL;
            property = "ENH_DebugOptions_NoRecoil";
        };
        class ENH_DebugOptions_NoSway: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_NOSWAY;
            property = "ENH_DebugOptions_NoSway";
        };
        class ENH_DebugOptions_UnlimitedAmmo: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_UNLIMITEDAMMO;
            property = "ENH_DebugOptions_UnlimitedAmmo";
        };
        class ENH_DebugOptions_NoReload: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_NORELOAD;
            property = "ENH_DebugOptions_NoReload";
        };
        //----------------DRAW
        class ENH_DebugOptions_Subcategory_Drawing: ENH_DebugOptions_Subcategory_Player
        {
            displayName = $STR_A3_ENDGAME_DEBRIEFING_DRAW;
        };
        class ENH_DebugOptions_ShowUnits: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_SHOWUNITS_DISPLAYNAME;
            tooltip = $STR_ENH_DEBUGOPTIONS_SHOWUNITS_TOOLTIP;
            property = "ENH_DebugOptions_ShowUnits";
        };
        class ENH_DebugOptions_DrawIcons: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_DRAWICONS_DISPLAYNAME;
            property = "ENH_DebugOptions_DrawIcons";
        };
        class ENH_DebugOptions_ShowWaypoints: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_SHOWWAYPOINTS_DISPLAYNAME;
            tooltip = $STR_ENH_DEBUGOPTIONS_SHOWWAYPOINTS_TOOLTIP;
            property = "ENH_DebugOptions_ShowWaypoints";
        };
        class ENH_DebugOptions_DrawViewDirection: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_DRAWVIEWDIRECTION;
            tooltip = $STR_ENH_DEBUGOPTIONS_DRAWVIEWDIRECTION_TOOLTIP;
            property = "ENH_DebugOptions_DrawViewDirection";
        };
        //----------------ENVIRONMENT
        class ENH_DebugOptions_Subcategory_Environment: ENH_DebugOptions_Subcategory_Player
        {
            displayName = $STR_A3_CREDITS_ENVIRONMENT;
        };
        class ENH_DebugOptions_SkipTime: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_SKIPTIME;
            property = "ENH_DebugOptions_SkipTime";
        };
        class ENH_DebugOptions_TimeMultiplier: ENH_DebugOptions_Arsenal
        {
            displayName = $STR_ENH_DEBUGOPTIONS_TIMEMULTIPLIER;
            property = "ENH_DebugOptions_TimeMultiplier";
        };
    };
};