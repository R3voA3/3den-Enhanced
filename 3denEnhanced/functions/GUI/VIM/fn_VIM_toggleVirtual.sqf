/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Used to search the item listbox.

  Parameter(s):
  0: Not used. Left for backwards compatibility
  1: BOOLEAN - True to set to virtual

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
params ["", "_isVirtual"];
private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlInventory = CTRL(IDC_VIM_INVENTORYLIST);
private _rows = (lnbSize _ctrlInventory) # 0;

//onCheckedChange EH returns NUMBER, while other functions use BOOLEAN as parameter
if (_isVirtual isEqualType 0) then {_isVirtual = [false, true] select _isVirtual};

if (_isVirtual) then
{
  for "_i" from 0 to _rows - 1 do
  {
    _ctrlInventory lnbSetText [[_i, 2], "∞"];
  };
}
else
{
  for "_i" from 0 to _rows - 1 do
  {
    _ctrlInventory lnbSetText [[_i, 2], str (_ctrlInventory lnbValue [_i, 1])];
  };
};

uiNamespace setVariable ["ENH_VIM_IsVirtual", _isVirtual];

CTRL(IDC_VIM_VIRTUAL) cbSetChecked _isVirtual;