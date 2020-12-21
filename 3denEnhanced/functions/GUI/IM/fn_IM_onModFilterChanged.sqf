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

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlCombo","_selectedIndex"];

private _display = uiNamespace getVariable "Enh_Display_InventoryManager";

//Update edit box and button
CTRL(IDC_IM_SEARCH) ctrlSetText "mod " + (_ctrlCombo lbData _selectedIndex);
CTRL(IDC_IM_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";

CTRL(IDC_IM_SEARCH) call ENH_fnc_IM_search;