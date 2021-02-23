/*
  Author: R3vo

  Date: 2020-11-10

  Description:
  Used to reset search in the ENH_IM GUI.

  Parameter(s):
  0: CONTROL - Search Button

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

CTRL(IDC_IM_SEARCH) ctrlSetText "";
CTRL(IDC_IM_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";

CTRL(IDC_IM_SEARCH) call ENH_fnc_IM_search;