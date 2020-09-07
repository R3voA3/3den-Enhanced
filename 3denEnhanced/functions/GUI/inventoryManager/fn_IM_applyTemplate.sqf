/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Applies the selected template.

   Parameter(s):
   0: CONTROL - Control Button

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];
private _display = ctrlparent _ctrlButton;

//Get template data from listbox
private _ctrlItems = _display displayCtrl 2200;
private _row = lbCurSel _ctrlItems;
if (_row isEqualTo -1) exitWith {false};
private _value = _ctrlItems lbData lbCurSel _ctrlItems;
ENH_IM_target set3DENAttribute ["ammoBox",_value];
_display call ENH_fnc_IM_loadAttributeValue;

true