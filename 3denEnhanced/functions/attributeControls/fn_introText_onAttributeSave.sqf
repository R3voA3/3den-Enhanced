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

_ctrlDelay = _ctrlGroup controlsGroupCtrl 100;
_ctrlLine1 = _ctrlGroup controlsGroupCtrl 102;
_ctrlLine2 = _ctrlGroup controlsGroupCtrl 103;
_ctrlLine3 = _ctrlGroup controlsGroupCtrl 104;
_ctrlIntroType = _ctrlGroup controlsGroupCtrl 105;

[
	sliderPosition _ctrlDelay,
	ctrlText _ctrlLine1,
	ctrlText _ctrlLine2,
	ctrlText _ctrlLine3,
	cbChecked _ctrlIntroType
];