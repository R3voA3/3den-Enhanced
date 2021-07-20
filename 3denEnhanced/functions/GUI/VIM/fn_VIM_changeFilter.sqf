/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Filters the item list.

  Parameter(s):
  0: CONTROL - Menu Strip
  1: ARRAY - Selected path

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlMenuStrip", "_path"];

private _index = _path # 1;
private _display = uiNamespace getVariable ["ENH_Display_VIM", displayNull];
private _types = uiNamespace getVariable "ENH_VIM_Types";
private _filterType = _ctrlMenuStrip menuData _path;

private _filteredItems = [];

//Collect all items which fit the filter
{
  _y params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort"];
  if (((_specificType == _filterType || _category == _filterType) && (!(_category == _filterType && _specificType in _types) || (_category == _specificType))) && _x != "Zasleh2") then
  {
    _filteredItems pushBack [_x, _displayName, _picture, _addonClass, _addonIcon, _descriptionShort];
  };
} forEach (uiNamespace getVariable "ENH_VIM_itemsHashMap");

//Store items to improve search later
_display setVariable ["ENH_VIM_FilteredItems", _filteredItems];

//Fill listbox via the search function
CTRL(IDC_VIM_SEARCH) call ENH_fnc_VIM_search;

//Scroll all the way to the top to prevent items not being displayed because it was scrolled down too far
CTRL(IDC_VIM_AVAILABLEITEMSLIST) ctrlSetScrollValues [0, 0];