/*
	Author: Revo

	Description:
	Saves the playlist, settings and closes the radio menu.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

params ["_display"];

"SAVE" call Enh_fnc_3denRadio_handlePlaylist;

profileNamespace setVariable ["Enh_3denRadio_MusicVolume",musicVolume];

_display closeDisplay 1;

["ShowPanelLeft",true] call BIS_fnc_3DENInterface;
["ShowPanelRight",true] call BIS_fnc_3DENInterface;

true