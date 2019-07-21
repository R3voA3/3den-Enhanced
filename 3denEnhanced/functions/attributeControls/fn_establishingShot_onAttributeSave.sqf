/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the establishingShot attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
	call compile ctrlText (_ctrlGroup controlsGroupCtrl 100),
	ctrlText (_ctrlGroup controlsGroupCtrl 101),
	sliderPosition (_ctrlGroup controlsGroupCtrl 102),
	sliderPosition (_ctrlGroup controlsGroupCtrl 104),
	sliderPosition (_ctrlGroup controlsGroupCtrl 106),
   lbCurSel (_ctrlGroup controlsGroupCtrl 108)
]