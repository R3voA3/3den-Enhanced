/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the intro text attribute. Call when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
	sliderPosition (_ctrlGroup controlsGroupCtrl 100),
	ctrlText (_ctrlGroup controlsGroupCtrl 102),
	ctrlText (_ctrlGroup controlsGroupCtrl 103),
	ctrlText (_ctrlGroup controlsGroupCtrl 104),
   lbCurSel (_ctrlGroup controlsGroupCtrl 105)
]