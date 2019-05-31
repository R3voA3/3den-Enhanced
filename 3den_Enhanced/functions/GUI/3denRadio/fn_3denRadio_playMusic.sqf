/*
	Author: Revo

	Description:
	Plays the selected song from one of the listboxes and updates the current song control.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

disableSerialization;

private _display = findDisplay 60000;
private _ctrlCurrentSong = _display displayCtrl 2200;
private _ctrlPlaylist = _display displayCtrl 2000;
private _ctrlSonglist = _display displayCtrl 2000;

//Get data from _ctrlSonglist by default
private _class = _ctrlSonglist lnbData [lnbCurSelRow _ctrlSonglist,0];
profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrlSonglist lnbText [lnbCurSelRow _ctrlSonglist,0]];

//If data is empty, try to get the data from playlist
if (_class isEqualTo "") then
{
	_class = _ctrlPlaylist lbData (lbCurSel _ctrl);
	profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrlPlaylist lbText (lbCurSel _ctrlPlaylist)];
};

//Play song and update current song control
_ctrlCurrentSong ctrlSetText (profileNamespace getVariable ["Enh_3denRadio_CurrentSong",""]);
playMusic _class;

true