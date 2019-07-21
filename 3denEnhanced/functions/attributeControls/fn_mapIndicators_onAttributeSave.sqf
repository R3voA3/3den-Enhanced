/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the mapindicators attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Array with booleans, attribute value
*/

params ["_ctrlGroup"];

[
	cbChecked (_ctrlGroup controlsGroupCtrl 100),
	cbChecked (_ctrlGroup controlsGroupCtrl 101),
	cbChecked (_ctrlGroup controlsGroupCtrl 102),
	cbChecked (_ctrlGroup controlsGroupCtrl 103)
]