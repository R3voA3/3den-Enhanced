/* 
	Author: Revo

	Description:
	Handles the playlist of 3DENRadio GUI.

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
private _display = findDisplay 60000;
private _ctrlPL = _display displayCtrl 2000;
private _ctrlSL = _display displayCtrl 1500;

switch (_action) do
{
	case "EXPORT":
	{
		"SAVE" call ENH_fnc_3DENRadio_handlePlaylist;
		copyToClipboard str (profileNamespace getVariable ["ENH_3DENRadio_Playlist",[]]);
		["ENH_DataCopied"] call BIS_fnc_3DENNotification;
	};
	case "IMPORT":
	{
		private _clipboard = call compile copyFromClipboard;
		if !(_clipboard isEqualTypeParams [["",""]]) exitWith {false};
		profileNamespace setVariable ["ENH_3DENRadio_Playlist",_clipboard];
		["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
		"UPDATE" call ENH_fnc_3DENRadio_handlePlaylist;
	};
	case "UPDATE":
	{
		private _playlist = profileNamespace getVariable ["ENH_3DENRadio_Playlist",[]];
		lbClear _ctrlPL;
		{
			_x params ["_name","_class"];
			private _index = _ctrlPL lbAdd _name;
			_ctrlPL lbSetTooltip [_index,_name];
			_ctrlPL lbSetData [_index,_class];
		} forEach _playlist;

		lbSort _ctrlPL;
	};
	case "ADDSONG":
	{
		if (_key == 57) then
		{
			private _name = _ctrlSL lnbText [(lbCurSel _ctrlSL),0];
			private _class = _ctrlSL lnbData [(lbCurSel _ctrlSL),0];
			private _index = _ctrlPL lbAdd _name;
			_ctrlPL lbSetTooltip [_index,_name];
			_ctrlPL lbSetData [_index,_class];
			"SAVE" call ENH_fnc_3DENRadio_handlePlaylist;
		};
	};
	case "REMOVESONG":
	{
		if (_key == 211) then
		{
			_ctrlPL lbDelete (lbCurSel _ctrlPL);
		};
		"SAVE" call ENH_fnc_3DENRadio_handlePlaylist;
	};
	case "SAVE":
	{
		private _playlist = [];
		for "_i" from 0 to (lbSize _ctrlPL - 1) do
		{
			_playlist pushBack [_ctrlPL lbText _i,_ctrlPL lbData _i];
		};
		profileNamespace setVariable ["ENH_3DENRadio_Playlist",_playlist];
	};
};

true