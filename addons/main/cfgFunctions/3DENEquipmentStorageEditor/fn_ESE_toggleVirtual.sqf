#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-06-22

    Description:
    Used by the ENH_ESE GUI. Used to change virtual state

    Parameter(s):
    1: BOOLEAN or NUMBER - -1 to invert current state, true to set to virtual, false to set to normal

    Returns:
    -
*/

disableSerialization;

params [["_isVirtual", -1, [true, 0]]];

private _display = uiNamespace getVariable "ENH_Display_ESE";
private _ctrlInventory = CTRL(IDC_ESE_INVENTORYLIST);
private _rows = (lnbSize _ctrlInventory) # 0;

// Reverse state
if (_isVirtual isEqualTo -1) then
{
    _isVirtual = !(_display getVariable ["ENH_ESE_IsVirtual", false]);
};

if _isVirtual then
{
    for "_i" from 0 to _rows - 1 do
    {
        _ctrlInventory lnbSetText [[_i, 2], "∞"];
    };
}
else
{
    for "_i" from 0 to _rows - 1 do
    {
        _ctrlInventory lnbSetText [[_i, 2], str (_ctrlInventory lnbValue [_i, 1])];
    };
};

_display setVariable ["ENH_ESE_IsVirtual", _isVirtual];
