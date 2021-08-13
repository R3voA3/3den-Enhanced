/*
  Author: R3vo

  Date: 2021-04-28

  Description:
  Fills the inventory list with all items of selected addon.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
private _display = uiNamespace getVariable "ENH_Display_VIM";
private _addonClassWanted = lbCurSel CTRL(IDC_VIM_FILTERSEARCH);

if (_addonClassWanted == -1) exitWith {};

_addonClassWanted = (uiNamespace getVariable ["ENH_VIM_allAddons", []]) select _addonClassWanted select 0;

call ENH_fnc_VIM_clearInventory;

{
  _y params ["_displayName", "_image", "_addonClass", "_addonIcon", "", "_specificType", "_descriptionShort"];

  if (_addonClass == _addonClassWanted || _addonClassWanted == "") then
  {
    [CTRL(IDC_VIM_INVENTORYLIST), _x, _displayName, _image, _addonIcon, 10, _x + "\n" + _descriptionShort, _specificType] call ENH_fnc_VIM_lnbAdd;
  };
} forEach (uiNamespace getVariable ["ENH_VIM_itemsHashmap", []]);

[true] call ENH_fnc_VIM_toggleVirtual;