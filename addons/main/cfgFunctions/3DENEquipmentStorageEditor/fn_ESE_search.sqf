#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Used to search the item listbox.

    Parameter(s):
    0: CONTROL - Control Edit

    Returns:
    -
*/

disableSerialization;

params ["_ctrlSearch"];
private _display = uiNamespace getVariable "ENH_Display_ESE";
private _ctrlItems = CTRL(IDC_ESE_AVAILABLEITEMSLIST);
private _filter = toUpper ctrlText _ctrlSearch;

if (_filter == "") then
{
    CTRL(IDC_ESE_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
}
else
{
    CTRL(IDC_ESE_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
};

lbClear _ctrlItems;
{
    _x params ["_configName", "_displayName", "_picture", "_addonClass", "_addonIcon", "_descriptionShort"];
    if (_filter in ("MOD" + " " + toUpper _addonClass)) then
    {
        [_ctrlItems, _displayName, _configName, _picture, _addonIcon, _configName + "\n" + _descriptionShort] call ENH_fnc_ESE_lbAdd;
    }
    else
    {
        if ((_filter in toUpper _displayName) || (_filter == "")) then
        {
            [_ctrlItems, _displayName, _configName, _picture, _addonIcon, _configName + "\n" + _descriptionShort] call ENH_fnc_ESE_lbAdd;
        };
    };
} forEach (_display getVariable ["ENH_ESE_FilteredItems", []]);

lbSort [_ctrlItems, "ASC"];
