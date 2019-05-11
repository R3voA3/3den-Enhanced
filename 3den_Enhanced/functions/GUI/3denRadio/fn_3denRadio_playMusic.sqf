/*
	Author: Revo

	Description:
	Plays the selected song from one of the listboxes and updates the current song control.

	Parameter(s):
	-

	Returns:
	BOOLEAN - true
*/

disableSerialization;

private _ctrl = param [0,controlNull,[controlNull]];
private _ctrlCurrentSong = (findDisplay 60000) displayCtrl 2200;


//Get data from lnb by default
private _class = _ctrl lnbData [lnbCurSelRow _ctrl,0];
profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrl lnbText [lnbCurSelRow _ctrl,0]];

//If data is empty, try to get the data from playlist
if (_class isEqualTo "") then
{
	_class = _ctrl lbData (lbCurSel _ctrl);
	profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_ctrl lbText (lbCurSel _ctrl)];
};

//Play song and update current song control
_ctrlCurrentSong ctrlSetText (profileNamespace getVariable ["Enh_3denRadio_CurrentSong",""]);
playMusic _class;

true

