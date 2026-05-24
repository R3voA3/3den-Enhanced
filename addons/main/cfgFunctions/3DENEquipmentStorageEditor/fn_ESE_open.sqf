#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Initialises the GUI.

    Parameter(s):
    -

    Returns:
    -
*/

disableSerialization;

ENH_ESE_target = get3DENSelected "Object" select 0;

if (isNil "ENH_ESE_target" || {ENH_ESE_target isKindOf "CAManBase" || !(ENH_ESE_target call ENH_fnc_hasStorage)}) exitWith
{
    ["ENH_NoEntitiesWithInventorySelected"] call BIS_fnc_3DENNotification;
};

private _display = findDisplay IDD_DISPLAY3DEN createDisplay "ENH_ESE";
uiNamespace setVariable ["ENH_Display_ESE", _display];

[] call ENH_fnc_getAllItems;
[] call ENH_fnc_ESE_loadAttributeValue;

// Get all addons and add them to filter control
{
    _x params ["_addonClass", "_addonName", "_addonIcon"];
    [CTRL(IDC_ESE_FILTERSEARCH), _addonName, _addonClass, "", _addonIcon] call ENH_fnc_ESE_lbAdd;
} forEach (uiNamespace getVariable "ENH_ESE_allAddons");

// By default select no mod
CTRL(IDC_ESE_FILTERSEARCH) lbSetCurSel 0;

[CTRL(IDC_ESE_MENU), [2, 0]] call ENH_fnc_ESE_changeFilter; // Load ARs as default

// Overwrite default ESC behaviour
_display displayAddEventHandler ["KeyDown",
{
    params ["", "_key"];
    if (_key == DIK_ESCAPE) then {call ENH_fnc_ESE_close; true};
}];

// Fille compatible items list if selection changed
CTRL(IDC_ESE_AVAILABLEITEMSLIST) ctrlAddEventHandler ["LBSelChanged",
{
    params ["_lbAvailableItems", "_lbCurSel"];

    private _className = toLower (_lbAvailableItems lbData _lbCurSel);
    private _itemsHashMap = uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap];
    private _lbCompItems = ctrlParent _lbAvailableItems displayCtrl IDC_ESE_COMPATIBLEITEMSLIST;

    // Use the clone if exist
    private _clone = uiNamespace getVariable ["ENH_ESE_itemsHashMapClone", nil];
    if (!isNil("_clone")) then {_itemsHashMap = _clone};

    lbClear _lbCompItems;

    {
        private _lCaseClassName = toLower _x;
        [
            _lbCompItems,
            (_itemsHashMap get _lCaseClassName) select 0,
            (_itemsHashMap get _lCaseClassName) select 7,
            (_itemsHashMap get _lCaseClassName) select 1,
            (_itemsHashMap get _lCaseClassName) select 3
        ] call ENH_fnc_ESE_lbAdd;
    } forEach (compatibleItems _className + compatibleMagazines _className);
}];

["update"] call ENH_fnc_ESE_handleTemplates;
