#include "\x\enh\addons\main\script_component.hpp"

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

disableSerialization;

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

CTRL(IDC_ESE_SEARCH) ctrlSetText "";
CTRL(IDC_ESE_BUTTONSEARCH) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
CTRL(IDC_ESE_FILTERSEARCH) lbSetCurSel 0;

CTRL(IDC_ESE_SEARCH) call ENH_fnc_ESE_search;
