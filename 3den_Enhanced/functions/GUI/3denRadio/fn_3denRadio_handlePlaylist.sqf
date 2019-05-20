/* 
	Author: Revo

	Description:
	Handles the playlist of 3denRadio GUI.

	Parameter(s):
	0: STRING - Action to be taken, can be:
		"EXPORT"
		"IMPORT"
		"UPDATE"
		"SAVE"
		"ADDSONG"
		"REMOVESONG"
		"CLEAR"
	1: NUMBER - (Optional, default -1) - Key code used by some functionalities

	Returns:
	BOOLEAN: true
 */

disableSerialization;

params [["_action","EXPORT",[""]],["_key",-1,[-1]]];
private _disp = findDisplay 60000;
private _ctrlPL = _disp displayCtrl 2000;
private _ctrlSL = _disp displayCtrl 1500;

switch (_action) do
{
	case "EXPORT":
	{
		"SAVE" call Enh_fnc_3denRadio_handlePlaylist;
		copyToClipboard str (profileNamespace getVariable ["Enh_3denRadio_Playlist",[]]);
		["Enh_DataCopied"] call BIS_fnc_3DENNotification;
	};
	case "IMPORT":
	{
		private _clipboard = call compile copyFromClipboard;
		if !(_clipboard isEqualTypeParams [["",""]]) exitWith {false};
		profileNamespace setVariable ["Enh_3denRadio_Playlist",_clipboard];
		["Enh_actionPerformed"] call BIS_fnc_3DENNotification;
		"UPDATE" call Enh_fnc_3denRadio_handlePlaylist;
	};
	case "UPDATE":
	{
		private _playlist = profileNamespace getVariable ["Enh_3denRadio_Playlist",[]];
		lbClear _ctrlPL;
		{
			private _index = _ctrlPL lbAdd (_x select 0);
			_ctrlPL lbSetData [_index,_x select 1];
		} forEach _playlist;

		lbSort _ctrlPL;
	};
	case "ADDSONG":
	{
		if (_key == 57) then
		{
			private _songName = _ctrlSL lnbText [(lbCurSel _ctrlSL),0];
			private _class = _ctrlSL lnbData [(lbCurSel _ctrlSL),0];
			private _newIndex = _ctrlPL lbAdd _songName;
			_ctrlPL lbSetData [_newIndex,_class];
			"SAVE" call Enh_fnc_3denRadio_handlePlaylist;
		};
	};
	case "REMOVESONG":
	{
		if (_key == 211) then
		{
			_ctrlPL lbDelete (lbCurSel _ctrlPL);
		};
		"SAVE" call Enh_fnc_3denRadio_handlePlaylist;
	};
	case "CLEAR": {lbClear _ctrlPL};
	case "SAVE":
	{
		private _playlist = [];
		for "_i" from 0 to (lbSize _ctrlPL - 1) do
		{
			_playlist pushBack [_ctrlPL lbText _i,_ctrlPL lbData _i];
		};
		profileNamespace setVariable ["Enh_3denRadio_Playlist",_playlist];
	};
};

true