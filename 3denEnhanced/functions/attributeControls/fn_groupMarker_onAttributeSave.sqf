/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the group marker attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

private _ctrlComboType =_ctrlGroup controlsGroupCtrl 100;
private _ctrlComboColor =_ctrlGroup controlsGroupCtrl 101;
private _ctrlEdit =_ctrlGroup controlsGroupCtrl 102;
private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl 103;

[
	_ctrlComboType lbData lbCurSel _ctrlComboType,
	_ctrlComboColor lbData lbCurSel _ctrlComboColor,
	ctrlText _ctrlEdit,
	cbChecked _ctrlCheckbox
]