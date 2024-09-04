class ENH_ForceWalk
{
    displayName = "$STR_ENH_MAIN_FORCEWALK_DISPLAYNAME";
    tooltip = "";
    property = "ENH_forceWalk";
    control = "Checkbox";
    expression = "[_this, _value] remoteExec ['forceWalk', _this]";
    condition = "objectBrain";
    defaultValue = "false";
};
