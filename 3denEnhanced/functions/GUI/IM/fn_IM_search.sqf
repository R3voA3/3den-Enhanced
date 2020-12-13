/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Used to search the item listbox.

  Parameter(s):
  0: CONTROL - Control Edit

  Returns:
  BOOLEAN: true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlSearch"];
private _display = uiNamespace getVariable "Enh_Display_InventoryManager";
private _ctrlItems = CTRL(IDC_IM_AVAILABLEITEMSLIST);
private _filter = toUpper ctrlText (_display displayCtrl 3400);

if (_filter == "") then
{
  (_display displayCtrl 3500) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
}
else
{
  (_display displayCtrl 3500) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
};

lbClear _ctrlItems;
{
  _x params ["_configName","_displayName","_picture","_addonIcon","_addon"];

  if ((_filter select [0,3] == "MOD") && ((_filter select [4,50]) in toUpper _addon)) then
  {
    [_ctrlItems,_displayName,_configName,_picture,_addonIcon,_configName + "\n" + localize "STR_ENH_IM_PREVIEW_TOOLTIP"] call ENH_fnc_IM_lbAdd;
  }
  else
  {
    if ((_filter in toUpper _displayName) || (_filter == "")) then
    {
      [_ctrlItems,_displayName,_configName,_picture,_addonIcon,_configName + "\n" + localize "STR_ENH_IM_PREVIEW_TOOLTIP"] call ENH_fnc_IM_lbAdd;
    };
  };
} forEach (uiNamespace getVariable ["ENH_IM_FilteredItems",[]]);

lbSort [_ctrlItems,"ASC"];

true