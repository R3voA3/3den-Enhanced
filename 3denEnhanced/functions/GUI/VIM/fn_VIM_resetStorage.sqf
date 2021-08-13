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

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlInventory = CTRL(IDC_VIM_INVENTORYLIST);
private _itemsHashMap = uiNamespace getVariable "ENH_VIM_itemsHashMap";

call ENH_fnc_VIM_clearInventory;

//Get all items defined in vehicle's config and add them to the listbox
{
  private _classes = "true" configClasses (configOf ENH_VIM_target >> _x);
  {
    private _amount = getNumber (_x >> "count");
    private _configName = configName _x trim ["_xx_", 1];
    (_itemsHashMap get toLower _configName) params ["_displayName", "_image", "", "_addonIcon", "", "_specificType", "_descriptionShort", "_configNameCaseSens"];

    [_ctrlInventory, _configNameCaseSens, _displayName, _image, _addonIcon, _amount, _configNameCaseSens + "\n" + _descriptionShort, _specificType] call ENH_fnc_VIM_lnbAdd;
  } forEach _classes;
} forEach ["TransportWeapons", "TransportMagazines", "TransportItems", "TransportBackpacks"];

[false] call ENH_fnc_VIM_toggleVirtual;