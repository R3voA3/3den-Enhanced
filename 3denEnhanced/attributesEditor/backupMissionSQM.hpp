class ENH_BackupMissionSQM
{
  displayName = "$STR_ENH_BACKUPMISSIONSQM_DISPLAYNAME";
  tooltip = "$STR_ENH_BACKUPMISSIONSQM_TOOLTIP";
  property = "ENH_BackupMissionSQM";
  control = "Checkbox";
  expression = "profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQM', _value]";
  defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQM', false]";
};
class ENH_BackupMissionSQMPath
{
  displayName = "Path for mission backups"; // TODO: i18n
  tooltip = "If empty, save to .enh_mission_sqm_backups in the mission directory. To save outside, use a full path, e.g. C:\\temp"; // TODO: i18n
  property = "ENH_BackupMissionSQMPath";
  control = "EditShort";
  expression = "profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQMPath', _value]";
  defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQMPath', '']";
};
