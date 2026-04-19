#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Filters the item list.

    Parameter(s):
    0: CONTROL - Menu Strip
    1: ARRAY - Selected path

    Returns:
    -
*/

disableSerialization;
params ["_ctrlMenuStrip", "_path"];

private _index = _path # 1;
private _display = uiNamespace getVariable ["ENH_Display_ESE", displayNull];
private _types = uiNamespace getVariable "ENH_ESE_Types";
private _filterType = _ctrlMenuStrip menuData _path;

private _filteredItems = [];

// Collect all items which fit the filter
{
    _y params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort"];
    if (((_specificType == _filterType || _category == _filterType) && (!(_category == _filterType && _specificType in _types) || (_category == _specificType))) && _x != "Zasleh2") then
    {
        _filteredItems pushBack [_x, _displayName, _picture, _addonClass, _addonIcon, _descriptionShort];
    };
} forEach (uiNamespace getVariable "ENH_ESE_itemsHashMap");

// Store items to improve search later
_display setVariable ["ENH_ESE_FilteredItems", _filteredItems];

// Fill listbox via the search function
CTRL(IDC_ESE_SEARCH) call ENH_fnc_ESE_search;

// Scroll all the way to the top to prevent items not being displayed because it was scrolled down too far
CTRL(IDC_ESE_AVAILABLEITEMSLIST) ctrlSetScrollValues [0, 0];
