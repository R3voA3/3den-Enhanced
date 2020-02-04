/*
   Author: R3vo

   Date: 2020-02-04

   Description:
   Used by the debug options attribute. Enables or disables options.

   Parameter(s):
   0: ARRAY
	0: CONTROL - Listbox control
	1: NUMBER - Selected index

   Returns:
   BOOLEAN: true
*/

params ["_ctrlLB","_index"];

private _state = if (_ctrlLB lbValue _index > 0) then
{
	["\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa",0]
}
else
{
	["\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa",1]
};

_ctrlLB lbSetPicture [_index,_state select 0];
_ctrlLB lbSetValue [_index,_state select 1];

true