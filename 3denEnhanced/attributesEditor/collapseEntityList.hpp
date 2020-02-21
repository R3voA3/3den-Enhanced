class ENH_CollapseEntityList
{
	displayName = $STR_ENH_COLLAPSEENTITYLIST;
	property = "ENH_CollapseEntityList";
	control = "Checkbox";
	expression = "profileNamespace setVariable ['%s',_value]";
	defaultValue = "profileNamespace getVariable ['ENH_CollapseEntityList',false]";
};