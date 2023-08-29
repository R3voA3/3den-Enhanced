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

//disableSerialization;
//private _display = uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull];
private _fncName = ctrlText ((uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull]) displayCtrl IDC_FUNCTIONSVIEWER_NAME);

if (_fncName isEqualTo "") exitWith {};
_fncName call BIS_fnc_recompile;

//[CTRL(IDC_FUNCTIONSVIEWER_LIST), tvCurSel CTRL(IDC_FUNCTIONSVIEWER_LIST)] call ENH_fnc_functionsViewer_onTreeSelChanged;

playSound "FD_Finish_F";