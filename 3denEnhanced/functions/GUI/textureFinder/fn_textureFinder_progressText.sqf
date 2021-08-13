
/*
  Author: R3vo

  Description:
  Used by the ENH_TexturFinder GUI. Updates the progressbar at anytime.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"
#define CHECK (uiNamespace getVariable ["ENH_TextureFinder_TexturesFound", []] isNotEqualTo [])

disableSerialization;
private _display = findDisplay IDD_TEXTUREFINDER;
private _ctrlProgText = CTRL(IDC_TEXTUREFINDER_PROGRESSTEXT);
private _text = localize "STR_ENH_UPDATEPROGRESSBAR";

//If search is done, don't loop anymore
if CHECK exitWith
{
  _ctrlProgText ctrlSetStructuredText parseText format
  [
    localize "STR_ENH_UPDATEPROGRESSBAR",
    uiNamespace getVariable "ENH_TextureFinder_ClassesSearched",
    uiNamespace getVariable "ENH_TextureFinder_ClassesFound",
    count (uiNamespace getVariable "ENH_TextureFinder_TexturesFound")
  ];
};

while {!isNull _display} do
{
  //Exit as soon as uiNamespace vars are set because missioNamespace vars will become nil
  if CHECK exitWith {[] spawn ENH_fnc_textureFinder_progressText; CTRL(IDC_TEXTUREFINDER_PREVIEW) ctrlSetAngle [0, 0.5, 0.5];};
  _ctrlProgText ctrlSetStructuredText parseText format
  [
    _text,
    ENH_TextureFinder_ClassesSearched,
    ENH_TextureFinder_ClassesFound,
    count ENH_TextureFinder_TexturesFound
  ];
  //Let's rotate the default image, looks neat
  CTRL(IDC_TEXTUREFINDER_PREVIEW) ctrlSetAngle [(ctrlAngle CTRL(IDC_TEXTUREFINDER_PREVIEW) # 0) + 2, 0.5, 0.5];
  CTRL(IDC_TEXTUREFINDER_PREVIEW) ctrlCommit 0;
  sleep 0.02;
};