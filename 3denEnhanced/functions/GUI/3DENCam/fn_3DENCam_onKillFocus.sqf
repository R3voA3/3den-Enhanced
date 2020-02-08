/*
   Author: R3vo

   Date: 2020-01-16

   Description:
   Sets text of description textBox.

   Parameter(s):
   0: CONTROL - TextBox control

   Returns:
   BOOLEAN: true
*/

params ['_ctrlEdit'];

if (ctrlText _ctrlEdit isEqualTo '') then 
{
	_ctrlEdit ctrlSetText localize "STR_ENH_3DENCAM_DESCRIPTION";
};

true