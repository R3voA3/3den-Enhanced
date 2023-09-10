class ENH_BackupMissionSQM
{
  displayName = "$STR_ENH_BACKUPMISSIONSQM_DISPLAYNAME";
  tooltip = "$STR_ENH_BACKUPMISSIONSQM_TOOLTIP";
  property = "ENH_BackupMissionSQM";
  control = "Checkbox";
  expression = "profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQM', _value]";
  defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQM', false]";
};