/*
  Author: Revo

  Description:
  Initialises the 3den Radio GUI.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params ["_display"];

private _ctrlSongList = CTRL(IDC_3DENRADIO_SONGLIST);
private _ctrlSort = CTRL(IDC_3DENRADIO_SORT);

//Set up slider
CTRL(IDC_3DENRADIO_VOLUME) sliderSetPosition (profileNamespace getVariable ["ENH_3DENRadio_MusicVolume",0.25]);

//Set up combo
{
  _ctrlSort lbAdd localize _x;
} forEach ["STR_ENH_3DENRADIO_SORTBYTITLE","STR_ENH_3DENRADIO_SORTBYDURATION","STR_ENH_3DENRADIO_SORTBYTHEME"];

_ctrlSort lbSetCurSel 0;

//Update current song
CTRL(IDC_3DENRADIO_CURRENTSONG) ctrlSetText (profileNamespace getVariable ["ENH_3DENRadio_CurrentSong",""]);

//Update radio button
switch (profileNamespace getVariable ["ENH_3DENRadio_Enabled",false]) do
{
  case true:
  {
    CTRL(IDC_3DENRADIO_TOGGLERADIO) ctrlSetText "\3denEnhanced\data\icon_Pause.paa";
  };
  case false:
  {
    CTRL(IDC_3DENRADIO_TOGGLERADIO) ctrlSetText "\3denEnhanced\data\icon_play.paa";
  };
};

//Get all music tracks

if ((uiNamespace getVariable ["ENH_3DENRadio_cfgMusic",[]]) isEqualTo []) then
{
  uiNamespace setVariable
  [
    "ENH_3DENRadio_cfgMusic",
    ("true" configClasses (configFile >> "CfgMusic")) +
    ("true" configClasses (missionConfigFile >> "CfgMusic")) +
    ("true" configClasses (campaignConfigFile >> "CfgMusic"))
  ];
};

_ctrlSongList lnbAddColumn 0.59;
_ctrlSongList lnbAddColumn 0.7;
_ctrlSongList lnbAddColumn 0.9;

//Update list
call ENH_fnc_3DENRadio_searchList;

//Fill playlist listbox
"UPDATE" call ENH_fnc_3DENRadio_handlePlaylist;

"ONLOAD" call ENH_fnc_3DENRadio_toggleRadio;

"TITLE" call ENH_fnc_3DENRadio_sortBy;

true