/*
   Author: R3vo

   Date: 2020-02-11

   Description:
   Used by the ENH_VariableViewer GUI. Called when a different namespace was selected.

   Parameter(s):
   0: CONTROL - ComboBox control
   1: NUMBER - Selected index

   Returns:
   BOOLEAN: true
*/

params ["_ctrlNamespace","_index"];

uiNamespace setVariable 
[
	"ENH_VariableViewer_LastNamespace",
	(uiNamespace getVariable 
	[
		"ENH_VariableViewer_Namespaces",
		["missionNamespace"]
	]) param [_index,"missionNamespace",["",objNull,locationNull,grpNull]]
];

ctrlParent _ctrlNamespace call ENH_fnc_variableViewer_fillLNB;

true