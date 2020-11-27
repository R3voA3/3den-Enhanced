/*
  Author: Revo

  Description:
  Used to filter/search the song list of 3den Radio.

  Parameter(s):
  0: DISPLAY - 3DEN Radio

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"
#define IN_PLAYLIST [_songName,_songClass,str _songDuration] in _playlist

disableSerialization;

private _display = findDisplay IDD_3DENRADIO;
private _ctrlSongList = CTRL(IDC_3DENRADIO_SONGLIST);
private _filter = toUpper (ctrlText CTRL(IDC_3DENRADIO_SEARCH));
private _filteredClasses = [];
private _playlist = profileNamespace getVariable ["ENH_3DENRadio_playlist",[]];
private _songName = "";
private _songDuration = 0;
private _songDurationStr = "00:00";
private _theme = "";
private _songClass = "";
private _modData = ["",""];
private _row = 0;

lbClear _ctrlSongList;

//Filter all classes according to input in search control
{
  _songName = getText (_x >> "name");
  _songClass = configName _x;
  if (_songName == "") then {_songName = _songClass};
  if ((toUpper _songName find _filter) >= 0 || _filter == "") then
  {
    _songDuration =  getNumber (_x >> "duration");
    _songDurationStr = _songDuration call ENH_fnc_floatToTime;
    _theme = getText (configFile >> "CfgMusicClasses" >> getText (_x >> "musicClass") >> "displayName");

    _modData = if (configSourceMod _x != '') then {modParams [configSourceMod  _x,["name","logoSmall"]]} else {["",""]};
    _modData params [["_modName",""],["_modLogo",""]];

    //Add filtered entries
    _row = _ctrlSongList lnbAddRow [_songName,_songDurationStr,_theme,_modName,""];
    _ctrlSongList lnbSetData [[_row,0],_songClass];
    _ctrlSongList lnbSetData [[_row,1],str _songDuration];
    _ctrlSongList lnbSetPicture [[_row,3],_modLogo];

    if (IN_PLAYLIST) then
    {
      _ctrlSongList lnbSetPicture [[_row,4],"\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"];
    }
    else
    {//This is a workaround right now because picture can not be removed once it was added, just replaced
      _ctrlSongList lnbSetPicture [[_row,4],"\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
    };
    _ctrlSongList lnbSetValue [[_row,4],parseNumber (IN_PLAYLIST)];
  };
} forEach (uiNamespace getVariable ["ENH_3DENRadio_cfgMusic",[]]);