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

private _fnc_addItems =
{
  params ["_configNamesArray", "_amountsArray"];
  {
    private _amount = _amountsArray param [_forEachIndex, 1];//If virtual inventory, then default to amount 1
    private _currentClass = _x;
    _x params ["_configName", "_displayName", "_image", "_addonIcon"];
    {
      if (_x # 0 isEqualTo _currentClass) exitWith
      {
        _x params ["_configName", "_displayName", "_image", "", "_addonIcon"];
        ([_ctrlInventory, _configName, _displayName, _image, _addonIcon, _amount, _configName]) call ENH_fnc_VIM_lnbAdd;
      };
    } forEach (uiNamespace getVariable "ENH_VIM_allItems");
  } forEach _configNamesArray;
};
lnbClear _ctrlInventory;

_weapons call _fnc_addItems;
_magazines call _fnc_addItems;
_items call _fnc_addItems;
_backpacks call _fnc_addItems;


[CTRL(IDC_VIM_VIRTUAL), _isVirtual] call ENH_fnc_VIM_toggleVirtual;
CTRL(IDC_VIM_VIRTUAL) cbSetChecked _isVirtual;