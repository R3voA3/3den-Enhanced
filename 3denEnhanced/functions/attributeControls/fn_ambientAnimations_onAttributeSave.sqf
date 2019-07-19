/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the ambient animation attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Animation data
*/

params ["_ctrlGroup"];

[
	(_ctrlGroup controlsGroupCtrl 100) lbData lbCurSel (_this controlsGroupCtrl 100),
	(_this controlsGroupCtrl 101) lbData lbCurSel (_this controlsGroupCtrl 101)
]