/*
  Author: R3vo

  Description:
  Initialises the 3den Radio GUI.

  Parameter(s):
  0: DISPLAY - 3DEN Radio

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"
disableSerialization;

params ["_display"];

//Set up volume slider
CTRL(IDC_3DENRADIO_VOLUME) sliderSetPosition (profileNamespace getVariable ["ENH_3DENRadio_MusicVolume", 0.25]);

//Update current song
CTRL(IDC_3DENRADIO_CURRENTSONG) ctrlSetText (uiNamespace getVariable ["ENH_3DENRadio_CurrentSong", ""]);

//Update radio button
CTRL(IDC_3DENRADIO_TOGGLERADIO) ctrlSetText (
  ["\3denEnhanced\data\icon_play.paa", "\3denEnhanced\data\icon_Pause_ca.paa"] select (profileNamespace getVariable ["ENH_3DENRadio_Enabled", false]));

[] spawn ENH_fnc_3DENRadio_timelineControl;

//Setup list and filter
{
  _x lnbAddColumn 0.45; //Duration
  _x lnbAddColumn 0.55; //Theme
  _x lnbAddColumn 0.7;  //Mod + Icon
  _x lnbAddColumn 0.92; //In Listbox
} forEach [CTRL(IDC_3DENRADIO_SONGLIST), CTRL(IDC_3DENRADIO_FILTER)];

CTRL(IDC_3DENRADIO_FILTER) lnbAddRow [localize "STR_ENH_3DENRADIO_TITLE", localize "STR_ENH_3DENRADIO_DURATION", localize "STR_ENH_3DENRADIO_THEME", localize "STR_ENH_3DENRADIO_MOD", "PL"];//Used for sorting
CTRL(IDC_3DENRADIO_FILTER) lnbSetData [[0, 4], "SortByValue"];//Needed for initListBoxSorting so it knows this column should be sorted by value
[CTRL(IDC_3DENRADIO_FILTER), CTRL(IDC_3DENRADIO_SONGLIST), [0, 1, 2, 3]] call BIS_fnc_initListNBoxSorting;

//Get all music tracks
if ((uiNamespace getVariable ["ENH_3DENRadio_cfgMusic", []]) isEqualTo []) then
{
  private _allMusic = configProperties [missionConfigFile >> "CfgMusic", "getNumber (_x >> 'duration') > 0", true];
  _allMusic append configProperties [configFile >> "CfgMusic", "getNumber (_x >> 'duration') > 0", true];
  _allMusic append configProperties [campaignConfigFile >> "CfgMusic", "getNumber (_x >> 'duration') > 0", true];
  uiNamespace setVariable ["ENH_3DENRadio_cfgMusic", _allMusic];
};

//Update list
call ENH_fnc_3DENRadio_searchList;

//Focus Search EH
_display displayAddEventHandler ["keyDown",
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && _shift) then
  {
    ctrlSetFocus CTRL(IDC_3DENRADIO_SEARCH);
  }
}];