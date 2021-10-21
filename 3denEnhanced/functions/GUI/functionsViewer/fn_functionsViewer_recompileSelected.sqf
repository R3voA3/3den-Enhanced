/*
  Author: R3vo

  Description:
  Used by the ENH_FunctionViewer GUI.

  Parameter(s):
  -

  Returns:
  -
*/

private _fncName = ctrlText ((uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull]) displayCtrl IDC_FUNCTIONSVIEWER_NAME);

if (_fncName isEqualTo "") exitWith {};
_fncName call BIS_fnc_recompile;
playSound "FD_Finish_F";