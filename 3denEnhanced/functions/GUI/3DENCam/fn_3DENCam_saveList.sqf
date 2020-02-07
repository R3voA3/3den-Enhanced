/*
   Author: R3vo

   Date: 2020-01-16

   Description:
   Updates profileNamespace variable according to listBox control.

   Parameter(s):
   0: CONTROL - ListBox control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlLB"];

private _lbMaxIndex = lbSize _ctrlLB - 1;
private _data = [];
for "_i" from 0 to _lbMaxIndex do
{
	_data pushBack call compile (_ctrlLB lbData _i);
};

profileNamespace setVariable ["ENH_Cam3DENSavedPositions",_data];

true