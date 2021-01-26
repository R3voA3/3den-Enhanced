/*
  Author: R3vo

  Date: 2019-05-30

  Description:
  Used by ENH_3DENRadio GUI. Selects and plays a new song from playlist.

  Parameter(s):
  0: ARRAY OR BOOLEAN - Boolean -> Random song is selected, ARRAY -> [_songName, _songClass, _songDuration]

  Returns:
  BOOLEAN: True, or false if failed
*/

#include "\3denEnhanced\defineCommon.hpp"
params [["_songData", ["", "", ""], [true, []], 3]];

//If param is bool, a random song is wanted otherwise it's a songclass selected from the listNBox
if (_songData isEqualType true) then
{
  _songData = selectRandom (profileNamespace getVariable ["ENH_3DENRadio_playlist", []]);
};

_songData params [["_songName", ""], ["_songClass", ""], ["_songDuration", ""]];

//Duration was saved as string
_songDuration = parseNumber _songDuration;

uiNamespace setVariable ["ENH_3DENRadio_CurrentSong", _songName];
uiNamespace setVariable ["ENH_3DENRadio_CurrentSongClass", _songClass];
uiNamespace setVariable ["ENH_3DENRadio_CurrentSongDuration", _songDuration];

//Slowly start the song
0 fadeMusic 0;
3 fadeMusic (profileNamespace getVariable ["ENH_3DENRadio_MusicVolume", 0.25]);
playMusic _songClass;

if !(isNull findDisplay IDD_3DENRADIO) then {(findDisplay IDD_3DENRADIO displayCtrl IDC_3DENRADIO_CURRENTSONG) ctrlSetText _songName};

true