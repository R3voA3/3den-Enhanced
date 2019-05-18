/*
   Author: Revo

   Description:
   Used by the Enh_FunctionViewer GUI. Called when the Copy button is pressed.

   Parameter(s):
   0: Control - Button

   Returns:
   BOOLEAN - true
*/

private _disp = findDisplay 180000;
private _ctrlCode = _disp displayCtrl 1401;
private _ctrlFncName = _disp displayCtrl 1402;
private _ctrlFncPath = _disp displayCtrl 1403;

private _export = "/*" + ctrlText _ctrlFncName + "*/" + endl + "/*" + ctrlText _ctrlFncPath + "*/" + endl + endl + ctrlText _ctrlCode;

copyToClipboard _export;

playSound "FD_Finish_F";

true