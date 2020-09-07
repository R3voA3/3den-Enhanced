/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Used to update the template list, once a new template is created.

   Parameter(s):
   0: DISPLAY - Display
   
   Returns:
   BOOLEAN: true
*/

params ["_display"];
private _ctrlItems = _display displayCtrl 2200;
_templates = profileNamespace getVariable ["ENH_IM_Templates",[]];
lbClear _ctrlItems;
{
	_x params ["_name","_description","_data"];
	_ctrlItems lbAdd _name;
	_ctrlItems lbSetTooltip [_forEachIndex,_description];
	_ctrlItems lbSetData [_forEachIndex,_data];
} forEach _templates;

true