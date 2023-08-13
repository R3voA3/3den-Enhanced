/*
	Author: linkion

	Description:
	Open Virtual Arsenal Manager preset menu

	Parameter(s):
	0: display of preset menu

	Returns:
	-

	Usage:
	[_displayPreset] call ENH_fnc_VAM_openPresetsMenu;
*/
#include "\3denEnhanced\defines\defineCommon.inc"

#define WINDOW_W 200

disableSerialization;

params ["_display"];

private _displayPreset = _display createDisplay "ENH_VAM_PresetMenu";

private _filterCtrl = _displayPreset displayCtrl IDC_VAM_PRESET_ListNBoxFilter;
private _contentCtrl = _displayPreset displayCtrl IDC_VAM_PRESET_ListNBoxContent;

// Add columns:
{
	_x lnbAddColumn 0.5;
} forEach [_filterCtrl, _contentCtrl];

// Add column headers:
_filterCtrl lnbAddRow ["Name", "Group"];

// Add content rows:
{
	_contentCtrl lnbAddRow [name _x, groupId group _x];
} forEach allUnits;

[_filterCtrl, _contentCtrl] call BIS_fnc_initListNBoxSorting;

ctrlSetFocus _contentCtrl; // Without this line, the user has to click _contentCtrl first in order to use the sorting buttons.