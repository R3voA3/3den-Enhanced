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
_ctrlVol sliderSetPosition (profileNamespace getVariable ["ENH_3DENRadio_MusicVolume",0.25]);

//Set up combo
{
	_ctrlSort lbAdd localize _x;
} forEach ["STR_ENH_3DENRADIO_SORTBYTITLE","STR_ENH_3DENRADIO_SORTBYDURATION","STR_ENH_3DENRADIO_SORTBYTHEME"];

_ctrlSort lbSetCurSel 0;

//Update current song
_ctrlCurSong ctrlSetText (profileNamespace getVariable ["ENH_3DENRadio_CurrentSong",""]);

//Update radio button
switch (profileNamespace getVariable ["ENH_3DENRadio_Enabled",false]) do
{
	case true:
	{
		_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\icon_Pause.paa";
	};
	case false:
	{
		_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\icon_play.paa";
	};
};

//Get all music tracks
ENH_3DENRadio_cfgMusic = 
	("true" configClasses (configFile >> "CfgMusic")) + 
	("true" configClasses (missionConfigFile >> "CfgMusic")) + 
	("true" configClasses (campaignConfigFile >> "CfgMusic"));

_ctrlSongList lnbAddColumn 0.59;
_ctrlSongList lnbAddColumn 0.7;
_ctrlSongList lnbAddColumn 0.9;

//Update list
call ENH_fnc_3DENRadio_searchList;

//Fill playlist listbox
"UPDATE" call ENH_fnc_3DENRadio_handlePlaylist;

"ONLOAD" call ENH_fnc_3DENRadio_toggleRadio;

"TITLE" call ENH_fnc_3DENRadio_sortBy;

true