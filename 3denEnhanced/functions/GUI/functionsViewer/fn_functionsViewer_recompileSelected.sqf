/*
   Author: Revo

   Description:
   Used by the Enh_FunctionViewer GUI. Called when Recompile Selected button is pressed.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

private _ctrlFncName = findDisplay 180000 displayCtrl 1402;
private _fncName = ctrlText _ctrlFncName;

if (_fncName isEqualTo "") exitWith {false};

_fncName call BIS_fnc_recompile;
playSound "FD_Finish_F";

true