/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Used to fill the inventory listbox with set attribute value.

  Parameter(s):
  0: BOOLEAN - Mode. False to load attribute value, true to insert external value

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"
disableSerialization;

params [["_loadAttribute", true], ["_attributeValue", []]];

private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlInventory = CTRL(IDC_VIM_INVENTORYLIST);

if (_loadAttribute) then
{
  _attributeValue = (ENH_VIM_target get3DENAttribute "ammoBox") # 0;
};

_attributeValue = parseSimpleArray _attributeValue;//Eden saves attributes as string
_attributeValue params ["_inventory", "_isVirtual"];
_inventory params ["_weapons", "_magazines", "_items", "_backpacks"];

private _itemsHashMap = uiNamespace getVariable "ENH_VIM_itemsHashMap";

private _fnc_addItems =
{
  params ["_configNamesArray", "_amountsArray"];
  {
    private _amount = _amountsArray param [_forEachIndex, 1];//If virtual inventory, then default to amount 1
    (_itemsHashMap get toLower _x) params ["_displayName", "_image", "", "_addonIcon", "", "_specificType", "_descriptionShort", "_configNameCaseSens"];
    [_ctrlInventory, _configNameCaseSens, _displayName, _image, _addonIcon, _amount, _configNameCaseSens + "\n" + _descriptionShort, _specificType] call ENH_fnc_VIM_lnbAdd;
  } forEach _configNamesArray;
};

call ENH_fnc_VIM_clearInventory;

_weapons call _fnc_addItems;
_magazines call _fnc_addItems;
_items call _fnc_addItems;
_backpacks call _fnc_addItems;

[_isVirtual] call ENH_fnc_VIM_toggleVirtual;