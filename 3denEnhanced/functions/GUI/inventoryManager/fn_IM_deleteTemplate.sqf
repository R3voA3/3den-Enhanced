/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_InventoryManager GUI. Deletes the selected template.

    Parameter(s):
    0: CONTROL - Control Button

    Returns:
    BOOLEAN: true
*/

params ["_ctrlButton"];
private _display = ctrlParent _ctrlButton;
private _ctrlItems = _display displayCtrl 2200;
private _row = lbCurSel _ctrlItems;

_ctrlItems lbDelete _row;

//Update templates variable
private _templates = profileNamespace getVariable ["ENH_IM_Templates",[]];
_templates deleteAt _row;
profileNamespace setVariable ["ENH_IM_Templates",_templates];

true