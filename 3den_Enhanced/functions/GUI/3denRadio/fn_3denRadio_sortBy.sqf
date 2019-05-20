/*
	Author: Revo

	Description:
	Sorts the song list listbox according to input.

	Parameter(s):
	STRING: _sortBy - "NAME","DURATION","THEME"

	Returns:
	BOOLEAN: true
*/

disableSerialization;

params [["_sortBy","NAME",[""]]];
private _ctrlSongList = (findDisplay 60000) displayCtrl 1500;

switch _sortBy do
{
	case "NAME":
	{
		_ctrlSongList lnbSort [0,false];
	};
	case "DURATION":
	{
		_ctrlSongList lnbSortByValue [1,true];
	};
	case "THEME":
	{
		_ctrlSongList lnbSort [2,false];
	};
};

true