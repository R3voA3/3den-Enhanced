#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Enable or disables the radio and updates other controls accordingly.

    Parameter(s):
    BOOLEAN: True if called from Eden Event Handler, false if called from within GUI. Default: true

    Returns:
    -
*/

disableSerialization;

params [["_onLoad", true]];

private _playlist = profileNamespace getVariable ["ENH_3DENRadio_Playlist", []];

// Exit if playlist is empty
if (_playlist isEqualTo []) exitWith {};

private _fnc_enableRadio =
{
    true call ENH_fnc_3DENRadio_playNewSong;
    ENH_3DENRadio_MusicEH = addMusicEventHandler ["MusicStop",
    {
        true call ENH_fnc_3DENRadio_playNewSong;
    }];

    profileNamespace setVariable ["ENH_3DENRadio_Enabled", true];

    // Only change controls if GUI is visible
    if !(isNull findDisplay IDD_3DENRADIO) then
    {
        (findDisplay IDD_3DENRADIO displayCtrl IDC_3DENRADIO_TOGGLERADIO) ctrlSetText "\x\enh\addons\main\data\pause_ca.paa";
    };
};

private _fnc_disableRadio =
{
    playMusic "";
    if !(isNil "ENH_3DENRadio_MusicEH") then {removeMusicEventHandler["MusicStop", ENH_3DENRadio_MusicEH]; ENH_3DENRadio_MusicEH = nil};

    profileNamespace setVariable ["ENH_3DENRadio_Enabled", false];
    uiNamespace setVariable ["ENH_3DENRadio_CurrentSong", ""];

    // Only change controls if GUI is visible
    if !(isNull findDisplay IDD_3DENRADIO) then
    {
        (findDisplay IDD_3DENRADIO displayCtrl IDC_3DENRADIO_CURRENTSONG) ctrlSetText "";
        (findDisplay IDD_3DENRADIO displayCtrl IDC_3DENRADIO_TOGGLERADIO) ctrlSetText "\x\enh\addons\main\data\play_ca.paa";
    };
};

private _radioState = profileNamespace getVariable ["ENH_3DENRadio_Enabled", false];

// Check if radio should run but was not yet initialised (onTerrainNew, onMissionNew, onMissionPreviewEnd)
if (_onLoad && _radioState) exitWith {call _fnc_enableRadio};

// Turn it off by pressing the button
if (!_onLoad && _radioState) exitWith {call _fnc_disableRadio};

// Turn it on by pressing the button
if (!_onLoad && !_radioState) exitWith {call _fnc_enableRadio};
