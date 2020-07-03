/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Clear the inventory list.

   Parameter(s):
   0: CONTROL - Control Button

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];
lnbClear ((ctrlParent _ctrlButton) displayCtrl 1501);

true