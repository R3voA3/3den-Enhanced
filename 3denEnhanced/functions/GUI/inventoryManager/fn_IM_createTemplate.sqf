/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_InventoryManager GUI. Create a template.

    Parameter(s):
    0: CONTROL - Control Button

    Returns:
    BOOLEAN: true
*/

params ["_ctrlButton"];
private _displayParent = uiNamespace getVariable "Enh_Display_InventoryManager";
private _ctrlInventory = _displayParent displayCtrl 2300;
private _templates = profileNamespace getVariable ["ENH_IM_Templates",[]];

//Return inventory data
private _value = [true] call ENH_fnc_IM_applyAttribute;

private _displayChild = ctrlParent _ctrlButton;
private _templateTitle = ctrlText (_displayChild displayCtrl 1000);
private _templateDescription = ctrlText (_displayChild displayCtrl 2000);

if !(_templateTitle isEqualTo "") then
{
    _templates pushBack [_templateTitle,_templateDescription,_value];
    profileNamespace setVariable ["ENH_IM_Templates",_templates];
    _displayChild closeDisplay 1;
    call ENH_fnc_IM_updateTemplateList;
};

true