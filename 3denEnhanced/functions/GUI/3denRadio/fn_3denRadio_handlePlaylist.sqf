/*
  Author: R3vo

  Description:
  Handles the playlist of 3DENRadio GUI.

  Parameter(s):
  0: CONTROL - ListNBox
  1: NUMBER - Key

  Returns:
  -
 */

#include "\3denEnhanced\defines\defineCommon.inc"
#define IN_PLAYLIST [_songName, _songClass, _songDuration] in _playlist

disableSerialization;

params ["_ctrlSongList", "_key"];

if (_key in [DIK_SPACE, DIK_DELETE]) then
{
  private _playlist = profileNamespace getVariable ["ENH_3DENRadio_playlist", []];
  private _row = lnbCurSelRow _ctrlSongList;
  private _songName = _ctrlSongList lnbText [_row, 0];
  private _songClass = _ctrlSongList lnbData [_row, 0];
  private _songDuration = _ctrlSongList lnbData [_row, 1];

  if (IN_PLAYLIST) then
  {
    _ctrlSongList lnbSetPicture [[_row, 4], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
    _ctrlSongList lnbSetValue [[_row, 4], 0];
    _playlist = _playlist - [[_songName, _songClass, _songDuration]];
  }
  else
  {
    _ctrlSongList lnbSetPicture [[_row, 4], "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"];
    _ctrlSongList lnbSetValue [[_row, 4], 1];
    _playlist append [[_songName, _songClass, _songDuration]];
  };
  profileNamespace setVariable ["ENH_3DENRadio_playlist", _playlist];
  saveProfileNamespace;
};