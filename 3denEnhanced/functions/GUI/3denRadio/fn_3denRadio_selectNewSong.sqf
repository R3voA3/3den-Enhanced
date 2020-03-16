/*
   Author: R3vo

   Date: 2019-05-30

   Description:
   Used by ENH_3DENRadio GUI. Selects and plays a new song from playlist.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _ctrlCurrentSong = (findDisplay 60000) displayCtrl 2200;
private _data = (selectRandom (profileNamespace getVariable ["ENH_3DENRadio_Playlist",[]]));
_data params ["_songName","_class"];

profileNamespace setVariable ["ENH_3DENRadio_CurrentSong",_songName];

0 fadeMusic (profileNamespace getVariable ["ENH_3DENRadio_MusicVolume",0.25]);
playMusic _class;

_ctrlCurrentSong ctrlSetText _songName;

true