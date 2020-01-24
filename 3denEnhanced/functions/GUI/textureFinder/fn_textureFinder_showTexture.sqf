/*
   Author: R3vo

   Date: 2020-01-24

   Description:
   Shows selected texture.

   Parameter(s):
   0: CONTROL - ListBox
   1: NUMBER - Selected index

   Returns:
   BOOLEAN: true
*/

params ["_ctrlLB", "_selectedIndex"];

private _display = ctrlParent _ctrlLB;


(_display displayCtrl 1200) ctrlSetText (_ctrlLB lbText _selectedIndex);

true