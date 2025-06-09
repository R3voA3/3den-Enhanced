#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Exports classname of selected song and copies it to the clipboard.

    Parameter(s):
    0: CONTROL - ListNBox
    1: NUMBER - Pressed key
    3: BOOLEAN - CTRL pressed

    Returns:
    -
*/

disableSerialization;

params ["_ctrlSongList", "_key", "", "_ctrl"];

if (_key isEqualTo 46 && _ctrl) then // CTRL + C
{
    copyToClipboard str (_ctrlSongList lnbData [lnbCurSelRow _ctrlSongList, 0]);
    ["ENH_DataCopied"] call BIS_fnc_3DENNotification;
};
