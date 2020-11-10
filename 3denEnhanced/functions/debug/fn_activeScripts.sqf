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

diag_log "------------------------------------------------ACTIVE SQF SCRIPTS START------------------------------------------------";

{
  _x params ["_scriptName", "_fileName", "_isRunning", "_currentLine"];
  diag_log _scriptname;
  diag_log _fileName;
  diag_log _isRunning;
  diag_log _currentLine;
} foreach diag_activeSQFScripts;

diag_log "-------------------------------------------------ACTIVE SQF SCRIPTS END-------------------------------------------------";

/* diag_log "------------------------------------------------ACTIVE SQS SCRIPTS START------------------------------------------------";

{
  _x params ["_scriptName", "_fileName", "_isRunning", "_currentLine"];
  diag_log _scriptname;
  diag_log _fileName;
  diag_log _isRunning;
  diag_log _currentLine;
} foreach diag_activeSQSScripts;

diag_log "-------------------------------------------------ACTIVE SQS SCRIPTS END-------------------------------------------------"; */


diag_log "---------------------------------------------------ACTIVE FSMs START----------------------------------------------------";

{
  _x params ["_scriptName", "_state", "_timeOut"];
  diag_log _scriptname;
  diag_log _state;
  diag_log _timeOut;
} foreach diag_activeMissionFSMs;

diag_log "----------------------------------------------------ACTIVE FSMs END-----------------------------------------------------";

diag_log "-----------------------------------------------ACTIVE MISSION EHs START-------------------------------------------------";

private _EHs = diag_allMissionEventHandlers;

for "_i" from 0 to (count _EHs - 1) step 2 do
{
  if (_i == (count _EHs -1)) exitWith {};
  private _type = _EHs # _i;
  private _count = _EHs # (_i + 1);
  if (_count > 0) then
  {
    diag_log format ["%1 / %2", _EHs # _i, _EHs # (_i +1)];
  };
};

diag_log "---------------------------------------------------ACTIVE MISSION EHs END---------------------------------------------------";

systemChat "Debug information logged.";