/*
   Author: R3vo

   Date: 2019-08-03

   Description:
   Called when Enh_Garrison GUI is created. Used to set default values.

   Parameter(s):
   0: DISPLAY - Display

   Returns:
   BOOLEAN: true
*/

params ["_display"];

private _ctrlEdit = _display displayCtrl 100;
private _ctrlToolbox = _display displayCtrl 200;
private _lastRadius = profileNamespace getVariable ['Enh_garrison_lastRadius',"500"];
private _lastCoverage = profileNamespace getVariable ['Enh_garrison_lastCoverage',1];

_ctrlEdit ctrlSetText _lastRadius;
_ctrlToolbox lbSetCurSel _lastCoverage;

true