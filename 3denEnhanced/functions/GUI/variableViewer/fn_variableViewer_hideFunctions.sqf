/*
   Author: R3vo

   Date: 2020-02-11

   Description:
   Used by the ENH_VariableViewer GUI. Called when checkbox state changed.

   Parameter(s):
   0: CONTROL - Checkbox control
   1: NUMBER - State

   Returns:
   BOOLEAN: true
*/

params ["_ctrlCheckbox","_state"];

profileNamespace setVariable ["ENH_VariableViewer_HideFunctions",[false,true] select _state];

ctrlParent _ctrlCheckbox call ENH_fnc_variableViewer_fillLNB;

true