#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-10-20

    Description:
    Used by the CfgSentences Browser GUI. Init.

    Parameter(s):
    0: DISPLAY

    Returns:
    BOOLEAN: True
*/

params ["_display"];

uiNamespace setVariable ["ENH_CFGS_Display", _display];
uiNamespace setVariable ["ENH_CFGS_ActiveList", CTRL(IDC_SENTENCESBROWSER_LIST)];
ENH_CFGS_Favorites = profileNamespace getVariable ["ENH_CFGS_Favorites", []];

CTRL(IDC_SENTENCESBROWSER_FAVORITES) ctrlSetFade 1;
CTRL(IDC_SENTENCESBROWSER_FAVORITES) ctrlEnable false;
CTRL(IDC_SENTENCESBROWSER_FAVORITES) ctrlCommit 0;

"fill" call ENH_fnc_CFGS_handleFavorites;
[] call ENH_fnc_CFGS_getCfgSentences;

[CTRL(IDC_SENTENCESBROWSER_SEARCH), CTRL(IDC_SENTENCESBROWSER_BUTTONSEARCH)] call ENH_fnc_initSearchControls;

true
