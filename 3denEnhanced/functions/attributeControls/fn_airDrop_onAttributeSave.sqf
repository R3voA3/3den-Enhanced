/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the airdrop attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

[
	ctrlText (_ctrlGroup controlsGroupCtrl 100) splitString ";, []" + endl,//Convert string to array with strings
	parseSimpleArray ctrlText (_ctrlGroup controlsGroupCtrl 101),
	ctrlText (_ctrlGroup controlsGroupCtrl 102),
	sliderPosition (_ctrlGroup controlsGroupCtrl 103),
	sliderPosition (_ctrlGroup controlsGroupCtrl 105),
	[west,east,independent,civilian] # lbCurSel (_ctrlGroup controlsGroupCtrl 107)
]