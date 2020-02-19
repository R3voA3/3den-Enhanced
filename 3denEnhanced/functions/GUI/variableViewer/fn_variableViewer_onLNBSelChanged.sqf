/*
   Author: R3vo

   Date: 2020-02-11

   Description:
   Used by the ENH_VariableViewer GUI. Called when listNbox selection changed.

   Parameter(s):
   0: CONTROL - ListNBox control
   1: NUMBER - Selected index

   Returns:
   BOOLEAN: true
*/

params ["_ctrlLNB","_selectedRow"];

private _display = ctrlParent _ctrlLNB;
private _ctrlVariableName = _display displayCtrl 8000;
private _ctrlVariableValue = _display displayCtrl 5000;

private _varName = _ctrlLNB lnbText [_selectedRow,0];
private _varData = _ctrlLNB lnbText [_selectedRow,1];

_ctrlVariableName ctrlSetText _varName;
_ctrlVariableValue ctrlSetText _varData;

true