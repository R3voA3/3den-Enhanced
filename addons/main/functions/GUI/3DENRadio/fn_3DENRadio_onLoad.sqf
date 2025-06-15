#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Initialises the 3den Radio GUI.

    Parameter(s):
    0: DISPLAY - 3DEN Radio

    Returns:
    -
*/

disableSerialization;

params ["_display"];

// Set up volume slider
CTRL(IDC_3DENRADIO_VOLUME) sliderSetPosition (profileNamespace getVariable ["ENH_3DENRadio_MusicVolume", 0.25]);

// Update current song
CTRL(IDC_3DENRADIO_CURRENTSONG) ctrlSetText (uiNamespace getVariable ["ENH_3DENRadio_CurrentSong", ""]);

// Update radio button
CTRL(IDC_3DENRADIO_TOGGLERADIO) ctrlSetText (
    ["\x\enh\addons\main\data\play_ca.paa", "\x\enh\addons\main\data\pause_ca.paa"] select (profileNamespace getVariable ["ENH_3DENRadio_Enabled", false]));

0 spawn ENH_fnc_3DENRadio_timelineControl;

// Setup list and filter
{
    _x lnbAddColumn 0.45; // Duration
    _x lnbAddColumn 0.55; // Theme
    _x lnbAddColumn 0.67; // Mod + Icon
    _x lnbAddColumn 0.92; // In playlist
} forEach [CTRL(IDC_3DENRADIO_SONGLIST), CTRL(IDC_3DENRADIO_FILTER)];

CTRL(IDC_3DENRADIO_FILTER) lnbAddRow [localize "STR_ENH_MAIN_3DENRADIO_TITLE", localize "STR_ENH_MAIN_3DENRADIO_DURATION", localize "STR_ENH_MAIN_3DENRADIO_THEME", localize "STR_ENH_MAIN_3DENRADIO_MOD", "PL"];// Used for sorting
CTRL(IDC_3DENRADIO_FILTER) lnbSetData [[0, 4], "SortByValue"];// Needed for initListBoxSorting so it knows this column should be sorted by value
[CTRL(IDC_3DENRADIO_FILTER), CTRL(IDC_3DENRADIO_SONGLIST), [0, 1, 2, 3]] call BIS_fnc_initListNBoxSorting;

// Get all music tracks
if ((uiNamespace getVariable ["ENH_3DENRadio_cfgMusic", []]) isEqualTo []) then
{
    private _allMusic = configProperties [missionConfigFile >> "CfgMusic", "getNumber (_x >> 'duration') > 0", true];
    _allMusic append configProperties [configFile >> "CfgMusic", "getNumber (_x >> 'duration') > 0", true];
    _allMusic append configProperties [campaignConfigFile >> "CfgMusic", "getNumber (_x >> 'duration') > 0", true];
    uiNamespace setVariable ["ENH_3DENRadio_cfgMusic", _allMusic];
};

// Update list
call ENH_fnc_3DENRadio_searchList;

// Focus Search EH
_display displayAddEventHandler ["KeyDown",
{
    params ["_display", "_key", "", "_ctrl"];
    if (_key isEqualTo 33 && _ctrl) then
    {
        ctrlSetFocus CTRL(IDC_3DENRADIO_SEARCH);
    }
}];

[CTRL(IDC_3DENRADIO_SEARCH), CTRL(IDC_3DENRADIO_BUTTONSEARCH), ENH_fnc_3DENRadio_searchList] call ENH_fnc_initSearchControls;

// Play selected song
CTRL(IDC_3DENRADIO_SONGLIST) ctrlAddEventHandler ["LBDblClick",
{
    params ["_ctrlLnB", "_selectedIndex"];
    [
        [
            _ctrlLnB lnbText [_selectedIndex, 0],
            _ctrlLnB lnbData [_selectedIndex, 0],
            _ctrlLnB lnbData [_selectedIndex, 1]
        ]
    ] call ENH_fnc_3DENRadio_playNewSong;
}];

// Key down event
CTRL(IDC_3DENRADIO_SONGLIST) ctrlAddEventHandler ["KeyDown",
{
    call ENH_fnc_3DENRadio_handlePlaylist;
    call ENH_fnc_3DENRadio_exportClassname;
}];

// Toggle radio
CTRL(IDC_3DENRADIO_TOGGLERADIO) ctrlAddEventHandler ["ButtonClick",
{
    false call ENH_fnc_3DENRadio_toggleRadio;
}];

// Volume change
CTRL(IDC_3DENRADIO_VOLUME) ctrlAddEventHandler ["SliderPosChanged",
{
    params ["_ctrlSlider", "_value"];
    0 fadeMusic _value;
    profileNamespace setVariable ["ENH_3DENRadio_MusicVolume", _value];
}];

// Music position
CTRL(IDC_3DENRADIO_POSITION) ctrlAddEventHandler ["SliderPosChanged",
{
    params ["_ctrlSlider", "_value"];
    playMusic [uiNamespace getVariable ["ENH_3DENRadio_CurrentSongClass", ""], _value];
}];
