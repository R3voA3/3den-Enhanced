/*
   Author: R3vo

   Date: 2020-01-16

   Description:
   Removes an entry from listBox. Saves list to profileNamespace.

   Parameter(s):
   0: STRING - Action to be taken

   Returns:
   BOOLEAN: true
*/

params ["_ctrlLB", "_key", "_shift", "_ctrl", "_alt"];

if (_key isEqualTo 211) then
{
	_ctrlLB lbDelete lbCurSel _ctrlLB;

	//Update list
	_ctrlLB call ENH_fnc_3DENCam_saveList;
};

true