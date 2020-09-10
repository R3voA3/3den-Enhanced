/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Adds an item to the inventory list.

   Parameter(s):
   0: NUMBER - Amount of items to be added

   Returns:
   BOOLEAN: true
*/

params ["_amount"];
private _display = uiNamespace getVariable "Enh_Display_InventoryManager";
private _ctrlInventory = _display displayCtrl 2300;
private _ctrlItems = _display displayCtrl 2200;
private _row = lbCurSel _ctrlItems;

if (_row isEqualTo -1) exitWith {false};

private _rows = lnbSize _ctrlInventory select 0;
private _displayName = _ctrlItems lbText _row;
private _configName = _ctrlItems lbData _row;
private _allItems = uiNamespace getVariable "ENH_IM_allItems";

_index = _allItems findIf {_x select 0 isEqualTo _configName};
private _itemData = _allItems select _index;
_itemData params ["_configName","_displayName","_image","_addonIcon"];

private _itemAdded = false;

for "_i" from 0 to (( _rows - 1)) max 0 do
{
	if (_configName == _ctrlInventory lnbData [_i,0]) exitWith
	{
		private _currentAmount = _ctrlInventory lnbValue [_i,1];
		private _newAmount = _currentAmount + _amount;
		_ctrlInventory lnbSetText [[_i,2],str _newAmount];
		_ctrlInventory lnbSetValue [[_i,1],_newAmount];
		_itemAdded = true;
	};
};
if !(_itemAdded) then//If item was not found in the list, add it
{
	[_ctrlInventory,_configName,_displayName,_image,_addonIcon,_amount] call ENH_fnc_IM_LnbAddItem;
};

//Everytime inventory changes, amount is either set to "∞" or the actual amount (Easy workaround)
[
	_ctrlInventory,
	uiNamespace getVariable ["ENH_IM_IsVirtual",false]
] call ENH_fnc_IM_toggleVirtual;

true