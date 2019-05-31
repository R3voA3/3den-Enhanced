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

//Hide Eden interface
if (round (ctrlfade (findDisplay 313 displayctrl 1023)) < 1) then
{
	"showinterface" call BIS_fnc_3DENInterface
};

params ["_display"];

private _ctrlVol = _display displayCtrl 1900;
private _ctrlCurSong = _display displayCtrl 2200;
private _ctrlSongList = _display displayCtrl 1500;
private _ctrlToggleRadio = _display displayCtrl 2300;

//Set up slider
_ctrlVol sliderSetPosition (profileNamespace getVariable ["Enh_3denRadio_MusicVolume",0.25]);

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
		_ctrlToggleRadio ctrlSetText "\a3\3DEN\Data\Controls\ctrlMenu\arrow_ca.paa";
	};
};

//Fill music listbox
private _cfgMusic_1 = "!(getText (_x >> 'name') isEqualTo '')" configClasses (configFile >> "CfgMusic");

//Some tracks have to be added manually
private _cfgMusic_2 = "(configName _x in ['Fallout','Wasteland','SkyNet','MAD','Defcon'])" configClasses (configFile >> "CfgMusic");

Enh_3denRadio_cfgMusic = _cfgMusic_1 + _cfgMusic_2;

_ctrlSongList lnbAddColumn 0.585;
_ctrlSongList lnbAddColumn 0.69;
_ctrlSongList lnbAddColumn 0.91;

//Update list and sort by "NAME"
call Enh_fnc_3denRadio_searchList;

//Fill playlist listbox
"UPDATE" call Enh_fnc_3denRadio_handlePlaylist;

"ONLOAD" call Enh_fnc_3denRadio_toggleRadio;

"NAME" call Enh_fnc_3denRadio_sortBy;

true