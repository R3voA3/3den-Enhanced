#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Used to fill the inventory listbox with set attribute value.

    Parameter(s):
    0: BOOLEAN - Mode. False to load attribute value, true to insert external value
    1: ARRAY - Attribute data to be applied
    2: BOOLEAN - True to get attribute vales from clipboard

    Returns:
    -
*/

disableSerialization;

params [
    ["_loadAttribute", true],
    ["_attributeValue", []],
    ["_fromClipboard", false, [false]]
];

private _display = uiNamespace getVariable "ENH_Display_ESE";
private _ctrlInventory = CTRL(IDC_ESE_INVENTORYLIST);

if _loadAttribute then
{
    _attributeValue = (ENH_ESE_target get3DENAttribute "ammoBox") # 0
}
else
{
    if _fromClipboard then {_attributeValue = call ENH_fnc_ESE_parseClipboardValues}
};

_attributeValue = parseSimpleArray _attributeValue;// Eden saves attributes as string
_attributeValue params ["_inventory", "_isVirtual"];
_inventory params ["_weapons", "_magazines", "_items", "_backpacks"];

private _itemsHashMap = uiNamespace getVariable "ENH_ESE_itemsHashMap";

private _fnc_addItems =
{
    params ["_configNamesArray", "_amountsArray"];
    {
        private _amount = _amountsArray param [_forEachIndex, 1];// If virtual inventory, then default to amount 1
        (_itemsHashMap get toLower _x) params ["_displayName", "_image", "", "_addonIcon", "", "_specificType", "_descriptionShort", "_configNameCaseSens"];
        [_ctrlInventory, _configNameCaseSens, _displayName, _image, _addonIcon, _amount, _configNameCaseSens + "\n" + _descriptionShort, _specificType] call ENH_fnc_ESE_lnbAdd;
    } forEach _configNamesArray;
};

call ENH_fnc_ESE_clearInventory;

_weapons call _fnc_addItems;
_magazines call _fnc_addItems;
_items call _fnc_addItems;
_backpacks call _fnc_addItems;

[_isVirtual] call ENH_fnc_ESE_toggleVirtual;
