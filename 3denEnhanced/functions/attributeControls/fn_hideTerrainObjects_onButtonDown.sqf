/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the hide terrain objects attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

((ctrlParentControlsGroup _ctrlButton) controlsGroupCtrl 100) lbSetCurSel 0;

private _ctrlLB = (ctrlParentControlsGroup _ctrlButton) controlsGroupCtrl 110;

for "_i" from 0 to lbSize _ctrlLB -1 do
{
	_ctrlLB lbSetPicture [_i,"\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa"];
	_ctrlLB lbSetValue [_i,0];
};

true