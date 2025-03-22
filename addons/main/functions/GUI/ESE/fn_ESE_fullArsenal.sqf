#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-04-28

    Description:
    Fills the inventory list with all items of selected addon.

    Parameter(s):
    -

    Returns:
    -
*/

disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_ESE";
private _addonClassWanted = lbCurSel CTRL(IDC_ESE_FILTERSEARCH);

if (_addonClassWanted == -1) exitWith {};

_addonClassWanted = (uiNamespace getVariable ["ENH_ESE_allAddons", []]) select _addonClassWanted select 0;

call ENH_fnc_ESE_clearInventory;

{
    _y params ["_displayName", "_image", "_addonClass", "_addonIcon", "", "_specificType", "_descriptionShort"];

    if (_addonClass == _addonClassWanted || _addonClassWanted == "") then
    {
        [CTRL(IDC_ESE_INVENTORYLIST), _x, _displayName, _image, _addonIcon, 10, _x + "\n" + _descriptionShort, _specificType] call ENH_fnc_ESE_lnbAdd;
    };
} forEach (uiNamespace getVariable ["ENH_ESE_itemsHashmap", []]);

[true] call ENH_fnc_ESE_toggleVirtual;
