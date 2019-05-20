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

params ["_display"];
private _ctrlVol = _display displayCtrl 1900;
private _ctrlCurSong = _display displayCtrl 2200;
private _ctrlSongList = _display displayCtrl 1500;
private _ctrlToggleRadio = _display displayCtrl 2300;
//Hide 3den panels
["ShowPanelLeft",false] call BIS_fnc_3DENInterface;
["ShowPanelRight",false] call BIS_fnc_3DENInterface;

private _musicVolume = profileNamespace getVariable ["Enh_3denRadio_MusicVolume",0.25];

//Set up slider
_ctrlVol sliderSetRange [0,1.5];
_ctrlVol sliderSetPosition _musicVolume;
_ctrlVol sliderSetSpeed [0.1,0.1];
//Update current song
private _currentSong = profileNamespace getVariable ["Enh_3denRadio_CurrentSong",""];
_ctrlCurSong ctrlSetText _currentSong;
//Update enable radio button
if (profileNamespace getVariable ["Enh_3denRadio_Enabled",false] isEqualTo false) then
{
	_ctrlToggleRadio ctrlSetText localize "STR_ENH_3denRadio_enableRadio_text";
}
else
{
	_ctrlToggleRadio ctrlSetText localize "STR_ENH_3denRadio_disableRadio_text";
};
//Fill playlist listbox
"UPDATE" call Enh_fnc_3denRadio_handlePlaylist;
//Fill music listbox
private _cfgMusic_1 = "!(getText (_x >> 'name') isEqualTo '')" configClasses (configFile >> "CfgMusic");
//Some tracks have to be added manually
private _cfgMusic_2 = "(configName _x in ['Fallout','Wasteland','SkyNet','MAD','Defcon'])" configClasses (configFile >> "CfgMusic");

Enh_3denRadio_cfgMusic = _cfgMusic_1 + _cfgMusic_2;

_ctrlSongList lnbAddColumn 0.6;
_ctrlSongList lnbAddColumn 0.7;
_ctrlSongList lnbAddColumn 0.9;
//Update list and sort by "NAME"
call Enh_fnc_3denRadio_searchList;
"NAME" call Enh_fnc_3denRadio_sortBy;

true