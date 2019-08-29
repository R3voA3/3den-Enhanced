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

private _lastRadius = profileNamespace getVariable ['Enh_garrison_lastRadius',"500"];
private _lastStance = profileNamespace getVariable ['Enh_garrison_lastStance',0];
private _lastCoverage = profileNamespace getVariable ['Enh_garrison_lastCoverage',1];

(_display displayCtrl 100) ctrlSetText _lastRadius;
(_display displayCtrl 200) lbSetCurSel _lastCoverage;
(_display displayCtrl 300) lbSetCurSel _lastStance;

true