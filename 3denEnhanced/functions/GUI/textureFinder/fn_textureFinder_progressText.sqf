
/*
  Author: Revo

  Description:
  Used by the ENH_TexturFinder GUI. Updates the progressbar at anytime.

  Parameter(s):
  -

  Returns:
  -
*/

disableSerialization;

private _display = findDisplay 140000;
private _ctrlProgText = _display displayCtrl 1002;

//If search is done, don't loop anymore
if (uiNamespace getVariable ["ENH_TextureFinder_TexturesFound",[]] isNotEqualTo []) exitWith
{
  _ctrlProgText ctrlSetStructuredText parseText format
  [
    localize "STR_ENH_UPDATEPROGRESSBAR",
    uiNamespace getVariable "ENH_TextureFinder_ClassesSearched",
    uiNamespace getVariable "ENH_TextureFinder_ClassesFound",
    count (uiNamespace getVariable "ENH_TextureFinder_TexturesFound")
  ];
};

waitUntil {!isNil "ENH_TextureFinder_SearchRunning"};

while {!isNull _display} do
{
  //Exit as soon as uiNamespace vars are set because missioNamespace wars are
  if (uiNamespace getVariable ["ENH_TextureFinder_TexturesFound",[]] isNotEqualTo []) exitWith {[] spawn ENH_fnc_textureFinder_progressText};
  _ctrlProgText ctrlSetStructuredText parseText format
  [
    localize "STR_ENH_UPDATEPROGRESSBAR",
    ENH_TextureFinder_ClassesSearched,
    ENH_TextureFinder_ClassesFound,
    count ENH_TextureFinder_TexturesFound
  ];
  sleep 0.3;
};