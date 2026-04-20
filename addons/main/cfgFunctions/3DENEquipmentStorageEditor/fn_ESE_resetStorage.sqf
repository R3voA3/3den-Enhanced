#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-09-09

    Description:
    Used by the ENH_Inventory Manager GUI. Gets default storage from vehicle's config and adds it to the GUI.

    Parameter(s):
    -

    Returns:
    -
*/

disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_ESE";
private _ctrlInventory = CTRL(IDC_ESE_INVENTORYLIST);
private _itemsHashMap = uiNamespace getVariable "ENH_ESE_itemsHashMap";

call ENH_fnc_ESE_clearInventory;

// Get all items defined in vehicle's config and add them to the listbox
{
    private _classes = "true" configClasses (configOf ENH_ESE_target >> _x);
    {
        private _amount = getNumber (_x >> "count");
        private _configName = configName _x trim ["_xx_", 1];
        (_itemsHashMap get toLower _configName) params ["_displayName", "_image", "", "_addonIcon", "", "_specificType", "_descriptionShort", "_configNameCaseSens"];

        [_ctrlInventory, _configNameCaseSens, _displayName, _image, _addonIcon, _amount, _configNameCaseSens + "\n" + _descriptionShort, _specificType] call ENH_fnc_ESE_lnbAdd;
    } forEach _classes;
} forEach ["TransportWeapons", "TransportMagazines", "TransportItems", "TransportBackpacks"];

[false] call ENH_fnc_ESE_toggleVirtual;
