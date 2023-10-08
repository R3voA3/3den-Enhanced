/*
  Author: R3vo

  Date: 2023-09-10
  File: 3denEnhanced\functions\misc\fn_createBackupMissionSQM.sqf

  Description:
  Invokes Pythia function that creates a backup of current mission.sqm fillWeaponsFromPool.

  Parameter(s):
  -

  Return Value:
  BOOLEAN - True on success, false if failed
*/

//Just to be sure
if (!is3DEN) exitWith {false};

//Opt-in via preferences
if !(profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQM', false]) exitWith {};

//Pythia is needed
if !(isClass (configfile >> "CfgPatches" >> "PY3_Pythia")) exitWith
{
  if (profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQM', false]) then
  {
    ["ENH_PythiaMissingForBackup", 1, 10] call BIS_fnc_3DENNotification;
  };
  false
};

if !(fileExists "mission.sqm") exitWith {false};

private _root = getMissionPath "";
private _sysTimeFormatted = systemTime apply {str _x} joinString "_";

["ENH_Pythia.BackupMissionSQM", [_root, _sysTimeFormatted]] call (uiNamespace getVariable "py3_fnc_callExtension");

true