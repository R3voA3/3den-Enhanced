/*
  Author: R3vo

  Description:
  Used by the ENH_FunctionViewer GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

private _fncName = ctrlText ((uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull]) displayCtrl IDC_FUNCTIONSVIEWER_NAME);

//Function was not found anywhere. It's a script file then
if (isNil {uiNamespace getVariable _fncName} && isNil {missionNamespace getVariable _fncName}) exitWith {};

_fncName call BIS_fnc_recompile;