/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Used to fill the inventory listbox with set attribute value.

   Parameter(s):
   0: DISPLAY - Display

   Returns:
   BOOLEAN: true
*/

params ["_display"];
private _ctrlInventory = _display displayCtrl 1501;
private _ctrlIsVirtual = _display displayCtrl 2800;

if (isNull ENH_IM_target) exitWith {false};

private _attributeValue = (ENH_IM_target get3DENAttribute "ammoBox") # 0;
_attributeValue = call compile _attributeValue;//Eden saves attributes as string
_attributeValue params ["_inventory","_isVirtual"];
_inventory params ["_weapons","_magazines","_items","_backpacks"];

private _fnc_addItems =
{
	params ["_configNamesArray","_amountsArray"];
	{	
		private _amount = _amountsArray param [_forEachIndex,1];//If virtual inventory, then default to amount 1
		private _currentClass = _x;
		_x params ["_configName","_displayName","_image","_addonIcon"];
		{
			if (_x # 0 isEqualTo _currentClass) exitWith
			{
				_x params ["_configName","_displayName","_image","_addonIcon"];
				([_ctrlInventory,_configName,_displayName,_image,_addonIcon,_amount]) call ENH_fnc_IM_LnbAddItem;
			};
		} forEach (uiNamespace getVariable "ENH_IM_allItems");
	} forEach _configNamesArray;
};
lnbClear _ctrlInventory;

_weapons call _fnc_addItems;
_magazines call _fnc_addItems;
_items call _fnc_addItems;
_backpacks call _fnc_addItems;


[_ctrlIsVirtual,_isVirtual] call ENH_fnc_IM_toggleVirtual;
_ctrlIsVirtual cbSetChecked _isVirtual;

true