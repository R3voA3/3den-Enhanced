#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-11-26

    Description:
    Updates the timeline control of 3DEN Radio.

    Parameter(s):
    0: DISPLAY - 3DEN Radio

    Returns:
    -
*/

#define DURATION uiNamespace getVariable ["ENH_3DENRadio_CurrentSongDuration", 0]

disableSerialization;

private _display = findDisplay IDD_3DENRADIO;

if (isNull _display) exitWith {};

// Set slider up
CTRL(IDC_3DENRADIO_POSITION) sliderSetPosition getMusicPlayedTime;
CTRL(IDC_3DENRADIO_POSITION) sliderSetRange [0, DURATION];
CTRL(IDC_3DENRADIO_POSITION) sliderSetSpeed [10, 5];

// Update text control while display is opened. Do not update slider since that would bug it
while {!isNull _display} do
{
    CTRL(IDC_3DENRADIO_TIME) ctrlSetText (getMusicPlayedTime call ENH_fnc_floatToTime);
    CTRL(IDC_3DENRADIO_POSITION) sliderSetPosition getMusicPlayedTime;
    sleep 1;
};
