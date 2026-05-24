class ENH_MissionEventHandlers_Global
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_GLOBAL_DISPLAYNAME";
    class Attributes
    {
        class ENH_MissionEventHandlers_Global_Subcategory
        {
            description = "$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_GLOBAL_DESCRIPTION";
            property = "ENH_MissionEventHandlers_Global_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        MEH_CONFIG(ArtilleryShellFired);
        MEH_CONFIG(BuildingChanged);
        MEH_CONFIG(CommandModeChanged);
        MEH_CONFIG(ControlsShifted);
        MEH_CONFIG(Draw2D);
        MEH_CONFIG(Draw3D);
        MEH_CONFIG(Drowned);
        MEH_CONFIG(EachFrame);
        MEH_CONFIG(Ended);
        MEH_CONFIG(MPEnded);
        MEH_CONFIG(EntityCreated);
        MEH_CONFIG(EntityDeleted);
        MEH_CONFIG(EntityKilled);
        MEH_CONFIG(EntityRespawned);
        MEH_CONFIG(ExtensionCallback);
        MEH_CONFIG(GroupCreated);
        MEH_CONFIG(GroupDeleted);
        MEH_CONFIG(GroupIconClick);
        MEH_CONFIG(GroupIconOverEnter);
        MEH_CONFIG(GroupIconOverLeave);
        MEH_CONFIG(HandleAccTime);
        MEH_CONFIG(HandleChatMessage);
        MEH_CONFIG(HCGroupSelectionChanged);
        MEH_CONFIG(Loaded);
        MEH_CONFIG(Map);
        MEH_CONFIG(MapSingleClick);
        MEH_CONFIG(MarkerCreated);
        MEH_CONFIG(MarkerDeleted);
        MEH_CONFIG(MarkerUpdated);
        MEH_CONFIG(PlayerViewChanged);
        MEH_CONFIG(PreloadStarted);
        MEH_CONFIG(PreloadFinished);
        MEH_CONFIG(ProjectileCreated);
        MEH_CONFIG(SaveGame);
        MEH_CONFIG(ScriptError);
        MEH_CONFIG(SelectedActionPerformed);
        MEH_CONFIG(SelectedActionChanged);
        MEH_CONFIG(SelectedRotorLibActionPerformed);
        MEH_CONFIG(SelectedRotorLibActionChanged);
        MEH_CONFIG(Service);
        MEH_CONFIG(TeamSwitch);
        MEH_CONFIG(UAVCrewCreated);
    };
};
