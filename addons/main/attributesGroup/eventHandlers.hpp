class ENH_EventHandlers
{
	collapsed = 1;
	displayName = "Event Handlers";
	class Attributes
	{
		class ENH_EventHandlers_Subcategory
		{
			description = "Event Handlers are triggered upon certain events. The code is only executed where the group is local. Event parameters are passed to it via the <t colorLink='#e69710'><a href='https://community.bistudio.com/wiki/Magic_Variables#this'>_this</a> variable. See <t colorLink='#e69710'><a href='https://community.bistudio.com/wiki/Arma_3:_Event_Handlers'>Arma 3 - Event Handlers</a> for more information.";
			data = "AttributeSystemSubcategory";
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