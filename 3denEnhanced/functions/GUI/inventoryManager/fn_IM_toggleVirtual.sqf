/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_InventoryManager GUI. Used to search the item listbox.

    Parameter(s):
    0: CONTROL - Some control within the GUI
    1: BOOLEAN - True to set to virtual

    Returns:
    BOOLEAN: true
*/

params ["_ctrlCheckbox", "_isVirtual"];
private _display = ctrlParent _ctrlCheckbox;
private _ctrlInventory = _display displayCtrl 2300;
private _rows = (lnbSize _ctrlInventory) # 0;

//onCheckedChange EH returns NUMBER, while other functions use BOOLEAN as parameter
if (_isVirtual isEqualType 0) then {_isVirtual = [false,true] select _isVirtual};

if (_isVirtual) then
{
    for "_i" from 0 to _rows - 1 do
    {
        _ctrlInventory lnbSetText [[_i,2],"∞"];
    };
}
else
{
    for "_i" from 0 to _rows - 1 do
    {
        _ctrlInventory lnbSetText [[_i,2],str (_ctrlInventory lnbValue [_i,1])];
    };
};

uiNamespace setVariable ["ENH_IM_IsVirtual",_isVirtual];

true