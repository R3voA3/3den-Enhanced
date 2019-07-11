/*
	Author: Revo

	Description:
	Initialises the 3den Radio GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

disableSerialization;

["ShowPanelLeft",false] call BIS_fnc_3DENInterface;
["ShowPanelRight",false] call BIS_fnc_3DENInterface;

params ["_display"];

private _ctrlVol = _display displayCtrl 1900;
private _ctrlCurSong = _display displayCtrl 2200;
private _ctrlSongList = _display displayCtrl 1500;
private _ctrlToggleRadio = _display displayCtrl 2300;
private _ctrlSort = _display displayCtrl 1600;

//Set up slider
_ctrlVol sliderSetPosition (profileNamespace getVariable ["Enh_3denRadio_MusicVolume",0.25]);

//Set up combo
{
	_ctrlSort lbAdd localize _x;
} forEach ["STR_ENH_3denRadio_sortByTitle","STR_ENH_3denRadio_sortByDuration","STR_ENH_3denRadio_sortByTheme"];

_ctrlSort lbSetCurSel 0;

//Update current song
_ctrlCurSong ctrlSetText (profileNamespace getVariable ["Enh_3denRadio_CurrentSong",""]);

//Update radio button
switch (profileNamespace getVariable ["Enh_3denRadio_Enabled",false]) do
{
	case true:
	{
		_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\Enh_icon_Pause.paa";
	};
	case false:
	{
		_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\Enh_icon_play.paa";
	};
};

//Get all music tracks
Enh_3denRadio_cfgMusic = 
	("true" configClasses (configFile >> "CfgMusic")) + 
	("true" configClasses (missionConfigFile >> "CfgMusic")) + 
	("true" configClasses (campaignConfigFile >> "CfgMusic"));

_ctrlSongList lnbAddColumn 0.5;
_ctrlSongList lnbAddColumn 0.7;
_ctrlSongList lnbAddColumn 0.9;

//Update list
call Enh_fnc_3denRadio_searchList;

//Fill playlist listbox
"UPDATE" call Enh_fnc_3denRadio_handlePlaylist;

"ONLOAD" call Enh_fnc_3denRadio_toggleRadio;

"TITLE" call Enh_fnc_3denRadio_sortBy;

true