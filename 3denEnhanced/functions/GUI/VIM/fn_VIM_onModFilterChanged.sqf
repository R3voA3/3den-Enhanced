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

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlCombo", "_selectedIndex"];

private _display = uiNamespace getVariable "ENH_Display_VIM";
private _addonClass = (_ctrlCombo lbData _selectedIndex);

//Update edit box and button. Don't update if vanilla Arma 3 is selected
if (_addonClass isEqualTo "") then
{
  CTRL(IDC_VIM_SEARCH) ctrlSetText "";
  CTRL(IDC_VIM_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
}
else
{
  CTRL(IDC_VIM_SEARCH) ctrlSetText "mod " + (_ctrlCombo lbData _selectedIndex);
  CTRL(IDC_VIM_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
};

CTRL(IDC_VIM_SEARCH) call ENH_fnc_VIM_search;