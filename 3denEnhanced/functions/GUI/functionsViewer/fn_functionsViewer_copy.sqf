/*
  Author: R3vo

  Description:
  Used by the ENH_FunctionViewer GUI. Called when the Copy button is pressed.

  Parameter(s):
  0: CONTROL: Control - Button

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _fncCode = CTRL(IDC_FUNCTIONSVIEWER_CODE);
private _fncName = CTRL(IDC_FUNCTIONSVIEWER_NAME);
private _fncPath = CTRL(IDC_FUNCTIONSVIEWER_PATH);

//Of one of the controls has no text, something is wrong. Exit!
if (([_fncCode, _fncName, _fncPath] find "") > -1) exitWith {false};

_export = "//" + ctrlText _fncName + endl + "//" + ctrlText _fncPath + endl + endl + ctrlText _fncCode;

copyToClipboard _export;

playSound "FD_Finish_F";