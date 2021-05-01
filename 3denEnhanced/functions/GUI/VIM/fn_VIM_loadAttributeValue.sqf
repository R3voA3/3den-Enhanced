/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Used to fill the inventory listbox with set attribute value.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"
disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlInventory = CTRL(IDC_VIM_INVENTORYLIST);

private _attributeValue = (ENH_VIM_target get3DENAttribute "ammoBox") # 0;
_attributeValue = call compile _attributeValue;//Eden saves attributes as string
_attributeValue params ["_inventory", "_isVirtual"];
_inventory params ["_weapons", "_magazines", "_items", "_backpacks"];

private _itemsHashMap = uiNamespace getVariable "ENH_VIM_allItemsHashMap";

private _fnc_addItems =
{
  params ["_configNamesArray", "_amountsArray"];
  {
    private _amount = _amountsArray param [_forEachIndex, 1];//If virtual inventory, then default to amount 1
    (_itemsHashMap get _x) params ["_displayName", "_image", "", "_addonIcon"];
    [_ctrlInventory, _x, _displayName, _image, _addonIcon, _amount, _x] call ENH_fnc_VIM_lnbAdd;
  } forEach _configNamesArray;
};

call ENH_fnc_VIM_clearInventory;

_weapons call _fnc_addItems;
_magazines call _fnc_addItems;
_items call _fnc_addItems;
_backpacks call _fnc_addItems;

[CTRL(IDC_VIM_VIRTUAL), _isVirtual] call ENH_fnc_VIM_toggleVirtual;
CTRL(IDC_VIM_VIRTUAL) cbSetChecked _isVirtual;