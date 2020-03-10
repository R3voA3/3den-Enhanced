/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the hold action attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
   ctrlText (_ctrlGroup controlsGroupCtrl 100),
   (_ctrlGroup controlsGroupCtrl 101) lbText lbCurSel (_ctrlGroup controlsGroupCtrl 101),
   (_ctrlGroup controlsGroupCtrl 102) lbText lbCurSel (_ctrlGroup controlsGroupCtrl 102),
   ctrlText (_ctrlGroup controlsGroupCtrl 103),
   ctrlText (_ctrlGroup controlsGroupCtrl 104),
   ctrlText (_ctrlGroup controlsGroupCtrl 105),
   ctrlText (_ctrlGroup controlsGroupCtrl 106),
   ctrlText (_ctrlGroup controlsGroupCtrl 107),
   ctrlText (_ctrlGroup controlsGroupCtrl 108),
   sliderPosition (_ctrlGroup controlsGroupCtrl 109),
   sliderPosition (_ctrlGroup controlsGroupCtrl 111),
   cbChecked (_ctrlGroup controlsGroupCtrl 113),
   cbChecked (_ctrlGroup controlsGroupCtrl 114)
];