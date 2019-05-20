/*
	Author: Revo

	Description:
	Enable or disables the radio and updates other controls accordingly.

	Parameter(s):
	STRING: _input - "BUTTON", "ONLOAD"

	Returns:
	BOOLEAN: true
*/
disableSerialization;
private _ctrlToggleRadio = (findDisplay 60000) displayCtrl 2300;
private _ctrlCurrentSong = (findDisplay 60000) displayCtrl 2200;
private _input = param [0,"BUTTON",[""]];
private _radioState = profileNamespace getVariable ["Enh_3denRadio_Enabled",false];

_fnc_enableRadio =
{
	if ((profileNamespace getVariable ["Enh_3denRadio_Playlist",[]]) isEqualTo []) exitWith {false};

	Enh_fnc_3denRadio_selectNewSong =
	{
		private _data = (selectRandom (profileNamespace getVariable ["Enh_3denRadio_Playlist",[]]));
		private _class = _data select 1;
		private _songName = _data select 0;
		profileNamespace setVariable ["Enh_3denRadio_CurrentSong",_songName];
		0 fadeMusic (profileNamespace getVariable ["Enh_3denRadio_MusicVolume",0.25]);
		playMusic _class;
		_ctrlCurrentSong ctrlSetText _songName;
	};

	call Enh_fnc_3denRadio_selectNewSong;
	Enh_musicEH = addMusicEventHandler ["MusicStop",
	{
		call Enh_fnc_3denRadio_selectNewSong;
	}];

	profileNamespace setVariable ["Enh_3denRadio_Enabled",true];
	_ctrlToggleRadio ctrlSetText localize "STR_ENH_3denRadio_disableRadio_text";
};

_fnc_disableRadio =
{
	playMusic "";
	if !(isNil "Enh_musicEH") then {removeMusicEventHandler["MusicStop",Enh_musicEH]; Enh_musicEH = nil};
	profileNamespace setVariable ["Enh_3denRadio_Enabled",false];
	_ctrlToggleRadio ctrlSetText localize "STR_ENH_3denRadio_enableRadio_text";
};

if (_input isEqualTo "BUTTON" && _radioState) then {call _fnc_disableRadio};
if (_input isEqualTo "BUTTON" && !_radioState) then {call _fnc_enableRadio};
if (_input isEqualTo "ONLOAD" && _radioState) then {call _fnc_enableRadio};
if (_input isEqualTo "ONLOAD" && !_radioState) exitWith {false};

true