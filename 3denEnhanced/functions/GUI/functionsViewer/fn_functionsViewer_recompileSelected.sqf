/*
   Author: Revo

   Description:
   Used by the ENH_FunctionViewer GUI. Called when Recompile Selected button is pressed.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

params ["_ctrlButton"];

private _fncName = ctrlText ((ctrlParent _ctrlButton) displayCtrl 1402);

if (_fncName isEqualTo "") exitWith {false};
_fncName call BIS_fnc_recompile;
playSound "FD_Finish_F";

true