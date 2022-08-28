/*
  Author: R3vo

  Date: 2020-11-03

  Description:
  Logs all active sqf, sqs and fms scripts to the .rpt file. Also logs all mission eventhandlers.

  Parameter(s):
  -

  Returns:
  -
*/

private _export = "------------------------------------------------ACTIVE SQF SCRIPTS------------------------------------------------" + endl;

{
  _x params ["_scriptName", "_fileName", "_isRunning", "_currentLine"];
  _export = _export + _scriptname + " - ";
  _export = _export + _fileName + " - ";
  _export = _export + str _isRunning + " - ";
  _export = _export + str _currentLine + endl;
} foreach diag_activeSQFScripts;

_export = _export + "---------------------------------------------------ACTIVE FSMs----------------------------------------------------" + endl;

{
  _x params ["_scriptName", "_state", "_timeOut"];
  _export = _export + _scriptname + " - ";
  _export = _export + _state + " - ";
  _export = _export + str _timeOut + endl;
} foreach diag_activeMissionFSMs;

_export = _export + "-----------------------------------------------ACTIVE MISSION EHs-------------------------------------------------" + endl;

private _EHs = diag_allMissionEventHandlers;

private _counts = diag_allMissionEventHandlers select {_x isEqualType 0};
private _types = diag_allMissionEventHandlers select {_x isEqualType ""};

{
  if (_x > 0) then
  {
    _export = _export + format ["%1x %2%3", _x, _types select _forEachIndex, endl];
  };
} forEach _counts;

uiNamespace setVariable ["display3DENCopy_data", ["", _export]];
(call BIS_fnc_displayMission) createDisplay "display3denCopy";