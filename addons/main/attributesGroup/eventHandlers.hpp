class ENH_EventHandlers
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_ATTRIBUTES_EVENT_HANDLERS_DISPLAYNAME";
    class Attributes
    {
        class ENH_EventHandlers_Subcategory
        {
            description = "$STR_ENH_MAIN_GROUP_ATTRIBUTES_EVENT_HANDLERS_DESCRIPTION";
            property = "ENH_EventHandlers_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        EH_CONFIG(CombatModeChanged,1);
        EH_CONFIG(CommandChanged,1);
        EH_CONFIG(Deleted,1);
        EH_CONFIG(Empty,1);
        EH_CONFIG(EnableAttackChanged,1);
        EH_CONFIG(EnemyDetected,1);
        EH_CONFIG(Fleeing,1);
        EH_CONFIG(FormationChanged,1);
        EH_CONFIG(GroupIdChanged,1);
        EH_CONFIG(KnowsAboutChanged,1);
        EH_CONFIG(LeaderChanged,1);
        EH_CONFIG(Local,1);
        EH_CONFIG(SpeedModeChanged,1);
        EH_CONFIG(UnitJoined,1);
        EH_CONFIG(UnitKilled,1);
        EH_CONFIG(UnitLeft,1);
        EH_CONFIG(VehicleAdded,1);
        EH_CONFIG(VehicleRemoved,1);
        EH_CONFIG(WaypointComplete,1);
    };
};
