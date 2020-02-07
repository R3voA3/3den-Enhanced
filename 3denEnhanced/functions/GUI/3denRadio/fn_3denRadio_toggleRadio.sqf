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

params ["_input"];

private _display = findDisplay 60000;
private _ctrlToggleRadio = _display displayCtrl 2300;
private _ctrlCurrentSong = _display displayCtrl 2200;
private _radioState = profileNamespace getVariable ["ENH_3denRadio_Enabled",false];
private _playlist = profileNamespace getVariable ["ENH_3denRadio_Playlist",[]];

_fnc_enableRadio =
{
	call ENH_fnc_3denRadio_selectNewSong;
	ENH_3denRadio_MusicEH = addMusicEventHandler ["MusicStop",
	{
		call ENH_fnc_3denRadio_selectNewSong;
	}];

	profileNamespace setVariable ["ENH_3denRadio_Enabled",true];
	_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\icon_pause.paa";
};

_fnc_disableRadio =
{
	playMusic "";
	if !(isNil "ENH_3denRadio_MusicEH") then {removeMusicEventHandler["MusicStop",ENH_3denRadio_MusicEH]; ENH_3denRadio_MusicEH = nil};

	profileNamespace setVariable ["ENH_3denRadio_Enabled",false];
	profileNamespace setVariable ["ENH_3denRadio_CurrentSong",""];

	_ctrlCurrentSong ctrlSetText "";
	_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\icon_play.paa";
};

if (_input isEqualTo "BUTTON" && _radioState) exitWith {call _fnc_disableRadio};
if (_input isEqualTo "BUTTON" && !_radioState && !(_playlist isEqualTo [])) exitWith {call _fnc_enableRadio};

//Check if radio is enabled but not running
if (_input isEqualTo "ONLOAD" && _radioState && isNil "ENH_3denRadio_MusicEH") then {call _fnc_enableRadio};
if (_input isEqualTo "ONLOAD" && (_playlist isEqualTo [])) then {call _fnc_disableRadio};

true