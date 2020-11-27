/*
  Author: R3vo

  Date: 2019-05-30

  Description:
  Used by ENH_3DENRadio GUI. Selects and plays a new song from playlist.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

private _display = findDisplay IDD_3DENRADIO;
private _data = (selectRandom (profileNamespace getVariable ["ENH_3DENRadio_Playlist",[]]));
_data params ["_songName","_class"];

profileNamespace setVariable ["ENH_3DENRadio_CurrentSong",_songName];

0 fadeMusic (profileNamespace getVariable ["ENH_3DENRadio_MusicVolume",0.25]);
playMusic _class;

CTRL(IDC_3DENRADIO_CURRENTSONG) ctrlSetText _songName;