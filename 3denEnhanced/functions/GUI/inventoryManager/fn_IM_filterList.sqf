/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Filters the item list.

   Parameter(s):
   0: CONTROL - Control Toolbox
   1: NUMBER - Selected Index

   Returns:
   BOOLEAN: true
*/

params ["_ctrlFilter","_selectedIndex"];

private _display = ctrlparent _ctrlFilter;
private _ctrlItems = _display displayCtrl 2200;
private _types = uiNamespace getVariable "ENH_IM_Types";
private _filterType = _types select _selectedIndex;
private _filteredItems = [];

lbClear _ctrlItems;

{
	_x params ["_configName","_displayName","_picture","_addonIcon","_category","_specificType","_addon"];
	if (_specificType isEqualTo _filterType || _category isEqualTo _filterType) then
	{
      if (_category isEqualTo _filterType && _specificType in _types) exitWith {false};
		[_ctrlItems,_displayName,_configName,_picture,_addonIcon,"Double click to preview an item."] call ENH_fnc_IM_lbAdd;
		_filteredItems pushBack [_configName,_displayName,_picture,_addonIcon,_addon];
	};
} forEach (uiNamespace getVariable "ENH_IM_allItems");

lbSort [_ctrlItems,"ASC"];

//Store items to improve search later
uiNamespace setVariable ["ENH_IM_FilteredItems",_filteredItems];
(_display displayCtrl 3400) call ENH_fnc_IM_search;

true