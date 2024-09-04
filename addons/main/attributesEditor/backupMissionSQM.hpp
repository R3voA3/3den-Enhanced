class ENH_BackupMissionSQM
{
    displayName = "$STR_ENH_MAIN_BACKUPMISSIONSQM_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_BACKUPMISSIONSQM_TOOLTIP";
    property = "ENH_BackupMissionSQM";
    control = "Checkbox";
    expression = "profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQM', _value]";
    defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQM', false]";
};
class ENH_BackupMissionSQMPath
{
    displayName = "$STR_ENH_MAIN_BACKUPMISSIONSQMPATH_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_BACKUPMISSIONSQMPATH_TOOLTIP";
    property = "ENH_BackupMissionSQMPath";
    control = "Edit";
    expression = "profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQMPath', _value]";
    defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQMPath', '']";
};
class ENH_BackupMissionSQMBlacklist
{
    displayName = "$STR_ENH_MAIN_BACKUPMISSIONSQMBLACKLIST_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_BACKUPMISSIONSQMBLACKLIST_TOOLTIP";
    property = "ENH_BackupMissionSQMBlacklist";
    control = "Edit";
    expression = "profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQMBlacklist', _value]";
    defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQMBlacklist', '']";
};
