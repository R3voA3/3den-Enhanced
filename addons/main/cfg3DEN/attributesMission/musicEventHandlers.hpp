class ENH_MusicEventHandlers_Global
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_MUSIC_GLOBAL_DISPLAYNAME";
    class Attributes
    {
        class ENH_MusicEventHandlers_Server_Subcategory
        {
            description = "$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_MUSIC_GLOBAL_DESCRIPTION";
            property = "ENH_MusicEventHandlers_Server_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        MUSICEH_CONFIG(MusicStart);
        MUSICEH_CONFIG(MusicStop);
    };
};
