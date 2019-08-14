/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the ambient animations attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
	(_ctrlGroup controlsGroupCtrl 100) lbText lbCurSel (_ctrlGroup controlsGroupCtrl 100),
	cbChecked (_ctrlGroup controlsGroupCtrl 101),
   cbChecked (_ctrlGroup controlsGroupCtrl 102),
   cbChecked (_ctrlGroup controlsGroupCtrl 103)
]