#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Adds an item to the inventory list.

    Parameter(s):
    0: NUMBER - Amount of items to be added

    Returns:
    -
*/

disableSerialization;
params ["_amount"];
private _display = uiNamespace getVariable "ENH_Display_ESE";
private _ctrlInventory = CTRL(IDC_ESE_INVENTORYLIST);
private _lbSource = focusedCtrl _display;
private _row = lbCurSel _lbSource;

// Check if the focused control is actually one of the two lists
if !(ctrlIDC _lbSource in [IDC_ESE_AVAILABLEITEMSLIST, IDC_ESE_COMPATIBLEITEMSLIST]) exitWith {};

// Check if something is selected
if (_row isEqualTo -1) exitWith {};

private _rows = lnbSize _ctrlInventory select 0;
private _configName = _lbSource lbData _row;
private _itemsHashMap = uiNamespace getVariable "ENH_ESE_itemsHashMap";

(_itemsHashMap get toLower _configName) params ["_displayName", "_image", "", "_addonIcon", "", "_specificType", "_descriptionShort", "_configNameCaseSens"];

private _itemAdded = false;

for "_i" from 0 to ( _rows - 1) do
{
    if (_configNameCaseSens == _ctrlInventory lnbData [_i, 0]) exitWith
    {
        private _currentAmount = _ctrlInventory lnbValue [_i, 1];
        private _newAmount = _currentAmount + _amount;
        _ctrlInventory lnbSetText [[_i, 2], str _newAmount];
        _ctrlInventory lnbSetValue [[_i, 1], _newAmount];
        _itemAdded = true;
    };
};
if !_itemAdded then// If item was not found in the list, add it
{
    [_ctrlInventory, _configNameCaseSens, _displayName, _image, _addonIcon, _amount, _configNameCaseSens + "\n" + _descriptionShort, _specificType] call ENH_fnc_ESE_lnbAdd;
};

// Everytime inventory changes, amount is either set to "∞" or the actual amount (Easy workaround)
[
    _display getVariable ["ENH_ESE_IsVirtual", false]
] call ENH_fnc_ESE_toggleVirtual;
