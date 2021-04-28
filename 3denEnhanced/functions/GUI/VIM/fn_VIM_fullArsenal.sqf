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

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
private _display = uiNamespace getVariable "ENH_Display_VIM";
private _addonClassWanted = lbCurSel CTRL(IDC_VIM_FILTERSEARCH);

if (_addonClassWanted == -1) exitWith {};

_addonClassWanted = (uiNamespace getVariable ["ENH_VIM_allAddons", []]) select _addonClassWanted select 0;

call ENH_fnc_VIM_clearInventory;

(uiNamespace getVariable ["ENH_VIM_allItems", []]) apply
{
  _x params ["_configName", "_displayName", "_image", "_addonClass", "_addonIcon"];

  if (_addonClass == _addonClassWanted || _addonClassWanted == "" || (_addonClass == "" && _addonClassWanted == "vanilla")) then
  {
    [CTRL(IDC_VIM_INVENTORYLIST), _configName, _displayName, _image, _addonIcon, 1, _configName] call ENH_fnc_VIM_lnbAdd;
  };
};

[nil, true] call ENH_fnc_VIM_toggleVirtual;