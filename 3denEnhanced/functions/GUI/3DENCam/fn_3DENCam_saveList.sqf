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

params ["_ctrlLnB"];

private _lnbMaxIndex = (lnbSize _ctrlLnB select 0) - 1;
private _data = [];

systemChat str ((lnbSize _ctrlLnB select 0) - 1);

for "_i" from 0 to _lbMaxIndex do
{
	_data pushBack call compile (_ctrlLnB lnbData [_i,0]);
};

profileNamespace setVariable ["ENH_Cam3DENSavedPositions",_data];

true