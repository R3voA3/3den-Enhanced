/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Used to search the item listbox.

   Parameter(s):
   0: CONTROL - Control Edit

   Returns:
   BOOLEAN: true
*/

params ["_ctrlSearch"];
private _display = ctrlParent _ctrlSearch;
private _ctrlItems = _display displayCtrl 1500;
private _filter = toUpper (ctrlText _ctrlSearch);
private _classesToSearch = uiNamespace getVariable ["ENH_IM_FilteredItems",[]];

if (_classesToSearch isEqualTo [] || _filter isEqualTo "") exitWith {false};

lbClear _ctrlItems;
{
	_x params ["_configName","_displayName","_picture","_addonIcon"];
	if ((toUpper _displayName find _filter) >= 0 || _filter == "") then
	{
		[_ctrlItems,_displayName,_configName,_picture,_addonIcon] call ENH_fnc_IM_lbAdd;
	};
} forEach _classesToSearch;

lbSort [_ctrlItems,"ASC"];

true