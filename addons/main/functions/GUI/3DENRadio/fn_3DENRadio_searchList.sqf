#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Used to filter/search the song list of 3den Radio.

    Parameter(s):
    0: DISPLAY - 3DEN Radio

    Returns:
    -
*/

#define IN_PLAYLIST [_songName, _class, str _duration] in _playlist

disableSerialization;

private _display = findDisplay IDD_3DENRADIO;
private _ctrlSongList = CTRL(IDC_3DENRADIO_SONGLIST);
private _filter = toUpper (ctrlText CTRL(IDC_3DENRADIO_SEARCH));
private _filteredClasses = [];
private _playlist = profileNamespace getVariable ["ENH_3DENRadio_playlist", []];
private _songName = "";
private _duration = 0;
private _durationStr = "00:00";
private _theme = "";
private _class = "";
private _row = 0;

lbClear _ctrlSongList;

// Filter all classes according to input in search control
{
    _songName = getText (_x >> "name");
    _class = configName _x;
    if (_songName == "") then {_songName = _class};
    if ((toUpper _songName find _filter) >= 0 || _filter == "") then
    {
        _duration =  getNumber (_x >> "duration");
        _durationStr = _duration call ENH_fnc_floatToTime;
        _theme = getText (configFile >> "CfgMusicClasses" >> getText (_x >> "musicClass") >> "displayName");

        (_x call ENH_fnc_getConfigSourceAddon) params [["_addonClass", ""], ["_addonName", ""], ["_addonIcon", ""]];

        // Add filtered entries
        _row = _ctrlSongList lnbAddRow [_songName, _durationStr, _theme, _addonName, ""];
        _ctrlSongList lnbSetData [[_row, 0], _class];
        _ctrlSongList lnbSetData [[_row, 1], str _duration];
        _ctrlSongList lnbSetPicture [[_row, 3], _addonIcon];

        if (IN_PLAYLIST) then
        {
            _ctrlSongList lnbSetPicture [[_row, 4], "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"];
        }
        else
        {// This is a workaround right now because picture can not be removed once it was added, just replaced
            _ctrlSongList lnbSetPicture [[_row, 4], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
        };
        _ctrlSongList lnbSetValue [[_row, 4], parseNumber (IN_PLAYLIST)];
    };
} forEach (uiNamespace getVariable ["ENH_3DENRadio_cfgMusic", []]);
