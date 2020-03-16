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
		profileNamespace setVariable ["ENH_3DENRadio_CurrentSong",_ctrlList lbText _selectedIndex];
		_ctrlList lbData _selectedIndex;
	};
	case 102://Song List
	{
		profileNamespace setVariable ["ENH_3DENRadio_CurrentSong",_ctrlList lnbText [_selectedIndex,0]];
		_ctrlList lnbData [_selectedIndex,0];
	};
};

//Play song and update current song control
_ctrlCurrentSong ctrlSetText (profileNamespace getVariable ["ENH_3DENRadio_CurrentSong",""]);
playMusic _class;

true