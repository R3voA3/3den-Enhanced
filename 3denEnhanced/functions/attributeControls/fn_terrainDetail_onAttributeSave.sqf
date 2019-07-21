/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the terrain detail attribute. Call when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   NUMBER: Attribute value
*/

params ["_ctrlGroup"];

[-1,50,25,12.5,6.25,3.125] select (lbCurSel (_ctrlGroup controlsGroupCtrl 100))