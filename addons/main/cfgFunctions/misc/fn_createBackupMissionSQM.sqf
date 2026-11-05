#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2023-09-10
    Description:
    Invokes the Pythia function that creates a backup of the current mission.sqm.

    Parameter(s):
    -

    Returns:
    BOOLEAN - True on success, false if failed
*/

// Just to be sure
if (!is3DEN) exitWith {false};

// Opt-in via preferences
if !(profileNamespace getVariable ["ENH_EditorPreferences_BackupMissionSQM", false]) exitWith {false};

// Opt-out scenario specific
if ("Scenario" get3DENMissionAttribute "ENH_BackupMissionSQMDisable") exitWith {false};

// Pythia is needed
if !(isClass (configFile >> "CfgPatches" >> "PY3_Pythia")) exitWith
{
    ["ENH_PythiaMissingForBackup", 1, 10] call BIS_fnc_3DENNotification;
    false
};

if !(fileExists "mission.sqm") exitWith {false};

private _missionRoot = getMissionPath "";
private _backupRoot = profileNamespace getVariable ["ENH_EditorPreferences_BackupMissionSQMPath", ""];
private _prefix = "";

if (_backupRoot == "") then
{
    _backupRoot = _missionRoot + ".enh_mission_sqm_backups";
}
else
{
    // If we dump all backups into one dir, we should add some prefix for convenience
    _prefix = format ["%1.%2_", missionName, worldName]; // "scriptLibrary.VR_"
};

private _sysTimeFormatted = systemTime apply {str _x} joinString "_";

["ENH_Pythia.BackupMissionSQM", [_missionRoot, _backupRoot, _prefix, _sysTimeFormatted]] call (uiNamespace getVariable "py3_fnc_callExtension");

true
