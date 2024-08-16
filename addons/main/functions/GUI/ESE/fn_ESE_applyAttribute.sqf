/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Takes items from inventory list and applies the attribute. Can also only return the attribute value.

    Parameter(s):
    0: BOOLEAN - True to not set the attribute and only return the attribute value. Default: false

    Returns:
    ARRAY, NOTHING: See Parameters
*/

#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;
params [["_return", false]];
private _display = uiNamespace getVariable "ENH_Display_ESE";
private _itemsHashMap = uiNamespace getVariable "ENH_ESE_itemsHashMap";
private _ctrlInventory = CTRL(IDC_ESE_INVENTORYLIST);
private _rows = lnbSize _ctrlInventory select 0;

private _weapons = [];
private _magazines = [];
private _items = [];
private _backpacks = [];

private _weaponsAmount = [];
private _magazinesAmount = [];
private _itemsAmount = [];
private _backpacksAmount = [];

for "_i" from 0 to _rows - 1 do
{
    private _configName = _ctrlInventory lnbData [_i, 0];
    private _amount = _ctrlInventory lnbValue [_i, 1];
    (_itemsHashMap getOrDefault [toLower _configName, []]) params ["", "", "", "", ["_category", ""], ["_specificType", ""]];
    switch (true) do
    {
        case (_category isEqualTo "Weapon"):
        {
            _weapons pushBack _configName;
            _weaponsAmount pushBack _amount;
        };
        case (_category in ["Mine", "Magazine"]):
        {
            _magazines pushBack _configName;
            _magazinesAmount pushBack _amount;
        };
        case (_category in ["Item", "Equipment"]):
        {
            if (_specificType isEqualTo "Backpack") then
            {
                _backpacks pushBack _configName;
                _backpacksAmount pushBack _amount;
            }
            else
            {
                _items pushBack _configName;
                _itemsAmount pushBack _amount;
            };
        };
    };
};

private _value = str
[
    [
        [_weapons, _weaponsAmount],
        [_magazines, _magazinesAmount],
        [_items, _itemsAmount],
        [_backpacks, _backpacksAmount]
    ],
    _display getVariable ["ENH_ESE_IsVirtual", false]
];

if (_return) exitWith {_value};
ENH_ESE_target set3DENAttribute ["ammoBox", _value];

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;