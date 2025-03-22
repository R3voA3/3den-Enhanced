#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Used to remove items from inventory listbox.

    Parameter(s):
    0: NUMBER - The amount that should be removed

    Returns:
    -
*/

disableSerialization;

params ["_amount"];

private _display = uiNamespace getVariable "ENH_Display_ESE";
private _ctrlInventory = CTRL(IDC_ESE_INVENTORYLIST);
private _row = lnbCurSelRow _ctrlInventory;

if (_row == -1) exitWith {};

private _currentAmount = _ctrlInventory lnbValue [_row, 1];
private _newAmount = _currentAmount - _amount;

if (_newAmount <= 0) exitWith
{
    _ctrlInventory lnbDeleteRow _row;
};

_ctrlInventory lnbSetText [[_row, 2], str _newAmount];
_ctrlInventory lnbSetValue [[_row, 1], _newAmount];
