/*
  Author: Revo

  Description:
  Saves the playlist, settings and closes the radio menu.

  Parameter(s):
  -

  Returns:
  -
*/

disableSerialization;

params ["_display"];

"SAVE" call ENH_fnc_3DENRadio_handlePlaylist;

profileNamespace setVariable ["ENH_3DENRadio_MusicVolume",musicVolume];

_display closeDisplay 1;