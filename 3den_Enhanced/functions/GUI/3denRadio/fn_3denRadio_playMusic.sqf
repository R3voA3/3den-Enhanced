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

params ["_ctrlList","_selectedIndex"];

private _display = ctrlParent _ctrlList;
private _ctrlCurrentSong = _display displayCtrl 2200;

private _class = switch (ctrlType _ctrlList) do
{
	case 5://Playlist
	{
		profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrlList lbText _selectedIndex];
		_ctrlList lbData _selectedIndex;
	};
	case 102://Song List
	{
		profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrlList lnbText [_selectedIndex,0]];
		_ctrlList lnbData [_selectedIndex,0];
	};
};
systemChat format ["Class: %1",_class];
//Play song and update current song control
_ctrlCurrentSong ctrlSetText (profileNamespace getVariable ["Enh_3denRadio_CurrentSong",""]);
playMusic _class;

true

/* private _display = findDisplay 60000;
private _ctrlCurrentSong = _display displayCtrl 2200;

//Get data from _ctrlSonglist by default
private _class = _ctrlSonglist lnbData [lnbCurSelRow _ctrlSonglist,0];
profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrlSonglist lnbText [lnbCurSelRow _ctrlSonglist,0]];

//If data is empty, try to get the data from playlist
if (_class isEqualTo "") then
{
	_class = _ctrlPlaylist lbData (lbCurSel _ctrl);
	profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrlPlaylist lbText (lbCurSel _ctrlPlaylist)];
}; */


