/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Adds an item to the inventory list.

  Parameter(s):
  0: NUMBER - Amount of items to be added

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
params ["_amount"];
private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlInventory = CTRL(IDC_VIM_INVENTORYLIST);
private _row = lbCurSel CTRL(IDC_VIM_AVAILABLEITEMSLIST);

if (_row isEqualTo -1) exitWith {};

private _rows = lnbSize _ctrlInventory select 0;
private _displayName = CTRL(IDC_VIM_AVAILABLEITEMSLIST) lbText _row;
private _configName = CTRL(IDC_VIM_AVAILABLEITEMSLIST) lbData _row;
private _itemsHashMap = uiNamespace getVariable "ENH_VIM_itemsHashMap";

(_itemsHashMap get toLower _configName) params ["_displayName", "_image", "", "_addonIcon", "", "_specificType", "_descriptionShort", "_configNameCaseSens"];

private _itemAdded = false;

for "_i" from 0 to ( _rows - 1) do
{
  if (_configNameCaseSens == _ctrlInventory lnbData [_i, 0]) exitWith
  {
    private _currentAmount = _ctrlInventory lnbValue [_i, 1];
    private _newAmount = _currentAmount + _amount;
    _ctrlInventory lnbSetText [[_i, 2], str _newAmount];
    _ctrlInventory lnbSetValue [[_i, 1], _newAmount];
    _itemAdded = true;
  };
};
if !(_itemAdded) then//If item was not found in the list, add it
{
  [_ctrlInventory, _configNameCaseSens, _displayName, _image, _addonIcon, _amount, _configNameCaseSens + "\n" + _descriptionShort, _specificType] call ENH_fnc_VIM_lnbAdd;
};

//Everytime inventory changes, amount is either set to "∞" or the actual amount (Easy workaround)
[
  _display getVariable ["ENH_VIM_IsVirtual", false]
] call ENH_fnc_VIM_toggleVirtual;