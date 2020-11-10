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

uiNamespace setVariable ["ENH_CFGS_Display",_display];
uiNamespace setVariable ["ENH_CFGS_ActiveList",_display displayCtrl 2000];
ENH_CFGS_Favorites = profileNamespace getVariable ["ENH_CFGS_Favorites",[]];

_tvFavorites = _display displayCtrl 4000;
_tvFavorites ctrlSetFade 1;
_tvFavorites ctrlEnable false;
_tvFavorites ctrlCommit 0;

"fill" call ENH_fnc_CFGS_handleFavorites;
[] call ENH_fnc_CFGS_getCfgSentences;

true