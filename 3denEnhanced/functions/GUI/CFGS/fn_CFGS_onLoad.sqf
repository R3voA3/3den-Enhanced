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

#include "\3denEnhanced\defines\defineCommon.inc"

params ["_display"];

uiNamespace setVariable ["ENH_CFGS_Display", _display];
uiNamespace setVariable ["ENH_CFGS_ActiveList", CTRL(IDC_SENTENCESBROWSER_LIST)];
ENH_CFGS_Favorites = profileNamespace getVariable ["ENH_CFGS_Favorites", []];

CTRL(IDC_SENTENCESBROWSER_FAVORITES) ctrlSetFade 1;
CTRL(IDC_SENTENCESBROWSER_FAVORITES) ctrlEnable false;
CTRL(IDC_SENTENCESBROWSER_FAVORITES) ctrlCommit 0;

"fill" call ENH_fnc_CFGS_handleFavorites;
[] call ENH_fnc_CFGS_getCfgSentences;

//Handle search button
CTRL(IDC_SENTENCESBROWSER_SEARCH) ctrlAddEventHandler ["EditChanged",
{
  params ["_ctrlEdit", "_newText"];

  private _image = [TEXTURE_SEARCH_END, TEXTURE_SEARCH_START] select (_newText == "");

  ctrlParent _ctrlEdit displayCtrl IDC_SENTENCESBROWSER_BUTTONSEARCH ctrlSetText _image;
}];

//Handle search button
CTRL(IDC_SENTENCESBROWSER_BUTTONSEARCH) ctrlAddEventHandler ["ButtonClick",
{
  params ["_ctrlButton"];

  //Change search button icon and clear edit control to reset tree view filter
  ctrlParent _ctrlButton displayCtrl IDC_SENTENCESBROWSER_SEARCH ctrlSetText "";
  _ctrlButton ctrlSetText TEXTURE_SEARCH_START;
}];

true