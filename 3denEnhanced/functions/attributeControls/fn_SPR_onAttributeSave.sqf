/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the SPR attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
   lbCurSel (_ctrlGroup controlsGroupCtrl 100),
	sliderPosition (_ctrlGroup controlsGroupCtrl 101),
	cbChecked (_ctrlGroup controlsGroupCtrl 103),
   cbChecked (_ctrlGroup controlsGroupCtrl 104)
]