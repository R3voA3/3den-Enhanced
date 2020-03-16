/*
	Author: Revo

	Description:
	Used to filter/search the song list of 3den Radio.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

disableSerialization;

private _display = findDisplay 60000;
private _ctrlSongList = _display displayCtrl 1500;
private _ctrlSearch = _display displayCtrl 1400;
private _filter = toUpper (ctrlText _ctrlSearch);
private _filteredClasses = [];

lbClear _ctrlSongList;

//Filter all classes according to input in search control, private here to avoid in loop
private ["_name","_configName","_duration","_logo","_theme"];

{
	_name = getText (_x >> "name");
	if (_name == "") then {_name = configName _x};
	if (((toUpper _name) find _filter) >= 0 || _filter == "") then
	{
		_configName = configName _x;
		_duration =  getNumber (_x >> "duration");
		_duration = _duration call ENH_fnc_floatToTime;
		_logo = if (configSourceMod _x == '') then {[""]} else {modParams [configSourceMod  _x,["logoSmall"]]};
		_logo = _logo # 0;
		_theme = getText (configFile >> "CfgMusicClasses" >> getText (_x >> "musicClass") >> "displayName");
		_filteredClasses pushBack [_name,_configName,_duration,_theme,_logo];
	};
} forEach ENH_3DENRadio_cfgMusic;

//Add all classes to the list box, must be in two steps otherwise previewing songs and sorting the list box doesn't work anymore
{
	private _data = _filteredClasses # _forEachIndex;
	_data params ["_songName","_configName","_duration","_theme","_logo"];

	_ctrlSongList lnbAddRow [_songName,_duration,_theme];//Song Name, Duration, Theme
	_ctrlSongList lnbSetData [[_forEachIndex,0],_configName];//Config Name
	_ctrlSongList lnbSetData [[_forEachIndex,1],_duration];//Duration
	_ctrlSongList lnbSetPicture [[_forEachIndex,3],_logo];//Logo
} forEach _filteredClasses;

true