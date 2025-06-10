#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-11-10

    Description:
    Handles the mod filter in the IM search.

    Parameter(s):
    0: CONTROL - Combo
    1: NUMBER - Selected index

    Returns:
    -
*/

disableSerialization;

params ["_ctrlCombo", "_selectedIndex"];

private _display = uiNamespace getVariable "ENH_Display_ESE";
private _addonClass = (_ctrlCombo lbData _selectedIndex);

// Update edit box and button. Don't update if vanilla Arma 3 is selected
if (_addonClass isEqualTo "") then
{
    CTRL(IDC_ESE_SEARCH) ctrlSetText "";
    CTRL(IDC_ESE_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
}
else
{
    CTRL(IDC_ESE_SEARCH) ctrlSetText "mod " + (_ctrlCombo lbData _selectedIndex);
    CTRL(IDC_ESE_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
};

CTRL(IDC_ESE_SEARCH) call ENH_fnc_ESE_search;
