/*
	Author: Revo

	Description:
	Used to filter/search the song list of 3den Radio.

	Parameter(s):
	-

	Returns:
	BOOLEAN - true
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
		_theme = _theme select [0,20];//Shorten text
		_name = _name select [0,70];//Shorten text
		_filteredClasses pushBack [_name,_configName,_duration,_theme,_logo];
	};
} forEach Enh_3denRadio_cfgMusic;
//Add all classes to the list box, must be in two steps otherwise previewing songs and sorting the list box doesn't work anymore
{
	private _data = _filteredClasses # _forEachIndex;
	_ctrlSongList lnbAddRow [_data # 0,str (_data # 2),_data # 3];//Song Name, Duration, Theme
	_ctrlSongList lnbSetData [[_forEachIndex,0],_data # 1];//Config Name
	_ctrlSongList lnbSetValue [[_forEachIndex,1],_data # 2];//Duration
	_ctrlSongList lnbSetPicture [[_forEachIndex,3],_data # 4];//Logo
} forEach _filteredClasses;

true