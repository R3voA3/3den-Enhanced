#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: Pixelated_Grunt

    Date: 2024-08-29

    Description:
    Used by the ENH_ESE GUI. Import a list from clipboard to the available list (left panel).
    The import list is same as ACE arsenal export format i.e. ["item1", "item2"].

    Parameter(s):
    -

    Returns:
    -
*/

private _allAttributes = [true] call ENH_fnc_ESE_parseClipboardValues;
private _display = uiNamespace getVariable ["ENH_Display_ESE", displayNull];

// Backup the existing ENH_ESE_itemsHashMap
uiNamespace setVariable ["ENH_ESE_itemsHashMapClone", uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]];

// Replace the hashmap
uiNamespace setVariable ["ENH_ESE_itemsHashMap", _allAttributes];

// Call change filter to trigger the list update
[CTRL(IDC_ESE_MENU), [2, 0]] call ENH_fnc_ESE_changeFilter;
