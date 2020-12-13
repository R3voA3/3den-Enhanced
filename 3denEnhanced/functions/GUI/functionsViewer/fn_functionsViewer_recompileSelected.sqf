/*
  Author: Revo

  Description:
  Used by the ENH_FunctionViewer GUI. Called when Recompile Selected button is pressed.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _fncName = ctrlText ((ctrlParent _ctrlButton) displayCtrl IDC_FUNCTIONSVIEWER_NAME);

if (_fncName isEqualTo "") exitWith {};
_fncName call BIS_fnc_recompile;
playSound "FD_Finish_F";