#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-10-20

    Description:
    Used by the CfgSentences Browser GUI. Called when filter is changed.

    Parameter(s):
    0: CONTROL - Toolbox
    1: NUMBER - Index

    Returns:
    -
*/

params ["_ctrlFilter", "_selectedIndex"];
[_ctrlFilter lbData _selectedIndex] call ENH_fnc_CFGS_getCfgSentences;

(ctrlParent _ctrlFilter) displayCtrl IDC_SENTENCESBROWSER_SEARCH ctrlSetText "";
