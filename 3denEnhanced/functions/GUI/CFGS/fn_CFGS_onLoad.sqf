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

#include "\3denEnhanced\ENH_defineCommon.hpp"

params ["_display"];

uiNamespace setVariable ["ENH_CFGS_Display", _display];
uiNamespace setVariable ["ENH_CFGS_ActiveList", CTRL(IDC_SENTENCES_LIST)];
ENH_CFGS_Favorites = profileNamespace getVariable ["ENH_CFGS_Favorites", []];

CTRL(IDC_SENTENCES_FAVORITES) ctrlSetFade 1;
CTRL(IDC_SENTENCES_FAVORITES) ctrlEnable false;
CTRL(IDC_SENTENCES_FAVORITES) ctrlCommit 0;

"fill" call ENH_fnc_CFGS_handleFavorites;
[] call ENH_fnc_CFGS_getCfgSentences;

true