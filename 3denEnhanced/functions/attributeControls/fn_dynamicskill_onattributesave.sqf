/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the dynamic skill attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
	cbChecked (_ctrlGroup controlsGroupCtrl 100),
	sliderPosition (_ctrlGroup controlsGroupCtrl 101),
	sliderPosition (_ctrlGroup controlsGroupCtrl 103),
	sliderPosition (_ctrlGroup controlsGroupCtrl 105),
	sliderPosition (_ctrlGroup controlsGroupCtrl 107),
	sliderPosition (_ctrlGroup controlsGroupCtrl 109),
	sliderPosition (_ctrlGroup controlsGroupCtrl 111),
	sliderPosition (_ctrlGroup controlsGroupCtrl 113),
	sliderPosition (_ctrlGroup controlsGroupCtrl 115),
	sliderPosition (_ctrlGroup controlsGroupCtrl 117),
	sliderPosition (_ctrlGroup controlsGroupCtrl 119),
	sliderPosition (_ctrlGroup controlsGroupCtrl 121),
	sliderPosition (_ctrlGroup controlsGroupCtrl 123)
]