/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Used to search the item listbox.

  Parameter(s):
  0: CONTROL - Control Edit

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlSearch"];
private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlItems = CTRL(IDC_VIM_AVAILABLEITEMSLIST);
private _filter = toUpper ctrlText _ctrlSearch;

if (_filter == "") then
{
  CTRL(IDC_VIM_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
}
else
{
  CTRL(IDC_VIM_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
};

lbClear _ctrlItems;
{
  _x params ["_configName", "_displayName", "_picture", "_addonClass", "_addonIcon", "_descriptionShort"];
  if (_filter in ("MOD" + " " + toUpper _addonClass)) then
  {
    [_ctrlItems, _displayName, _configName, _picture, _addonIcon, _configName + "\n" + _descriptionShort] call ENH_fnc_VIM_lbAdd;
  }
  else
  {
    if ((_filter in toUpper _displayName) || (_filter == "")) then
    {
      [_ctrlItems, _displayName, _configName, _picture, _addonIcon, _configName + "\n" + _descriptionShort] call ENH_fnc_VIM_lbAdd;
    };
  };
} forEach (_display getVariable ["ENH_VIM_FilteredItems", []]);

lbSort [_ctrlItems, "ASC"];