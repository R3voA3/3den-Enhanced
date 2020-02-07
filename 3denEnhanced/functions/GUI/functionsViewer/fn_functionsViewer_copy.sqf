/*
   Author: Revo

   Description:
   Used by the ENH_FunctionViewer GUI. Called when the Copy button is pressed.

   Parameter(s):
   0: CONTROL: Control - Button

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _fncCode = ctrlText (_display displayCtrl 1401);
private _fncName = ctrlText (_display displayCtrl 1402);
private _fncPath = ctrlText (_display displayCtrl 1403);

//Of one of the controls has no text, something is wrong. Exit!
if (([_fncCode,_fncName,_fncPath] find "") > -1) exitWith {false};

_export = "//" + _fncName + endl + "//" + ctrlText (_display displayCtrl 1403) + endl + endl + _fncCode;

copyToClipboard _export;

playSound "FD_Finish_F";

true