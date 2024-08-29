/*
    Author: Pixelated_Grunt

    Date: 2024-08-29

    Description:
    Used by the ENH_ESE GUI. Reset the filter list (left panel) back to all available items.

    Parameter(s):
    -

    Returns:
    -
*/


#include "\x\enh\addons\main\script_component.hpp"
private _display = uiNamespace getVariable ["ENH_Display_ESE", displayNull];

// Restore the ENH_ESE_itemsHashMap variable
uiNamespace setVariable ["ENH_ESE_itemsHashMap", uiNamespace getVariable "ENH_ESE_itemsHashMapClone"];
// Release the memory
uiNamespace setVariable ["ENH_ESE_itemsHashMapClone", nil];
// Call change filter to trigger the list update
[CTRL(IDC_ESE_MENU), [2, 0]] call ENH_fnc_ESE_changeFilter
