/*
  Author: R3vo

  Date: 2021-05-08

  Description:
  Exports all items from the inventory list in format of the ACE 3 Arsenal.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlInventory = CTRL(IDC_VIM_INVENTORYLIST);

private _rows = lnbSize _ctrlInventory select 0;
private _items = [];

for "_i" from 0 to _rows do
{
  _items append [_ctrlInventory lnbData [_i - 1, 0]];
};

copyToClipboard str _items;

["ENH_DataCopied"] call BIS_fnc_3DENNotification;