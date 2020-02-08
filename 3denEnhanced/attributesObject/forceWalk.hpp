class ENH_ForceWalk
{
	displayName = $STR_ENH_FORCEWALK_DISPLAYNAME;
	tooltip = "";
	property = "ENH_forceWalk";
	control = "Checkbox";
	expression = "_this forceWalk _value";
	condition = "objectBrain";
	defaultValue = "false";
};