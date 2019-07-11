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
lbClear _ctrlSongList;
private _filteredClasses = [];

//Filter all classes according to input in search control
{
	private _name = getText (_x >> "name");
	if (_name == "") then {_name = configName _x};
	if (((toUpper _name) find _filter) >= 0 || _filter == "") then
	{
		private _configName = configName _x;
		private _duration = parseNumber ((getNumber (_x >> "duration")) toFixed 0);
		private _logo = if (configSourceMod _x == '') then {[""]} else {modParams [configSourceMod  _x,["logoSmall"]]};
		private _logo = _logo # 0;
		private _theme = getText (configFile >> "CfgMusicClasses" >> getText (_x >> "musicClass") >> "displayName");
		_filteredClasses pushBack [_name,_configName,_duration,_theme,_logo];
	};
} forEach Enh_3denRadio_cfgMusic;

//Add all classes to the list box, must be in two steps otherwise previewing songs and sorting the list box doesn't work anymore
{
	private _data = _filteredClasses # _forEachIndex;
	_data params ["_songName","_configName","_duration","_theme","_logo"];

	_ctrlSongList lnbAddRow [_songName,str _duration,_theme];//Song Name, Duration, Theme
	_ctrlSongList lnbSetData [[_forEachIndex,0],_configName];//Config Name
	_ctrlSongList lnbSetValue [[_forEachIndex,1],_duration];//Duration
	_ctrlSongList lnbSetPicture [[_forEachIndex,3],_logo];//Logo
} forEach _filteredClasses;

true