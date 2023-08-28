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

private _filterCtrl = _displayPreset displayCtrl IDC_VAM_PRESET_LISTNBOXFILTER;
private _contentCtrl = _displayPreset displayCtrl IDC_VAM_PRESET_LISTNBOXCONTENT;

private _presetsArray = profileNamespace getVariable ["ENH_VAM_Presets", []];
// [ _name , _itemCount , _selectionHashmap , _dateCreated ]

// Add columns:
{
	_x lnbAddColumn 0.5;
} forEach [_filterCtrl, _contentCtrl];

// Add column headers:
_filterCtrl lnbAddRow ["Name", "Items", "Last Used"];

// Add content rows:
{
	private _row = _contentCtrl lnbAddRow [ _x # 0 , _x # 1, _x # 3];
	_contentCtrl lnbSetData [[_row, 0], _x # 2 ];
} forEach _presetsArray;

[_filterCtrl, _contentCtrl] call BIS_fnc_initListNBoxSorting;

ctrlSetFocus _contentCtrl; // Without this line, the user has to click _contentCtrl first in order to use the sorting buttons.

(_displayPreset displayCtrl IDC_VAM_PRESET_LOADBUTTON) ctrlAddEventHandler ["ButtonClick", {
	private _newSelectionHashmap = createHashMap;
	_newSelectionHashmap = _contentCtrl lnbData [lnbCurSelRow _contentCtrl, 0];
	
	[_newSelectionHashmap] call ENH_fnc_VAM_loadSelectHashMap;
	format ["Loaded New Preset"] call BIS_fnc_3DENNotification;
	_displayPreset closeDisplay 1;
}];

(_displayPreset displayCtrl IDC_VAM_PRESET_SAVEBUTTON) ctrlAddEventHandler ["ButtonClick", {
	
}];