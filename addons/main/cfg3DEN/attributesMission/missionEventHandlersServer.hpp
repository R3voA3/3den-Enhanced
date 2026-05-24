class ENH_MissionEventHandlers_Server
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_SERVER_DISPLAYNAME";
    class Attributes
    {
        class ENH_MissionEventHandlers_Server_Subcategory
        {
            description = "$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_SERVER_DESCRIPTION";
            property = "ENH_MissionEventHandlers_Server_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        MEH_CONFIG_SERVER(HandleDisconnect);
        MEH_CONFIG_SERVER(OnUserConnected);
        MEH_CONFIG_SERVER(OnUserDisconnected);
        MEH_CONFIG_SERVER(OnUserClientStateChanged);
        MEH_CONFIG_SERVER(OnUserAdminStateChanged);
        MEH_CONFIG_SERVER(OnUserSelectedPlayer);
        MEH_CONFIG_SERVER(OnUserKicked);
        MEH_CONFIG_SERVER(PlayerConnected);
        MEH_CONFIG_SERVER(PlayerDisconnected);
    };
};
