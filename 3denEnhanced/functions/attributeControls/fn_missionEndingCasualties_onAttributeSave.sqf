/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the mission ending casualties attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
	sliderPosition (_ctrlGroup controlsGroupCtrl 100),
	(_ctrlGroup controlsGroupCtrl 102) lbText lbCurSel (_ctrlGroup controlsGroupCtrl 102),
	cbChecked (_ctrlGroup controlsGroupCtrl 103),
	[west,east,independent,civilian] select lbCurSel (_ctrlGroup controlsGroupCtrl 104)
]