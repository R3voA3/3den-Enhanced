/*
  Author: linkion

  Description:
  Open Virtual Arsenal Manager preset menu

  Parameter(s):
  0: DISPLAY: Display of preset menu

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

disableSerialization;

params ["_display"];

private _displayPreset = _display createDisplay "ENH_VAM_PresetMenu";
uiNamespace setVariable ["ENH_VAM_Presets_Display", _displayPreset];

private _filterCtrl = _displayPreset displayCtrl IDC_VAM_PRESET_LISTNBOXFILTER;
private _contentCtrl = _displayPreset displayCtrl IDC_VAM_PRESET_LISTNBOXCONTENT;

private _presetsArray = profileNamespace getVariable ["ENH_VAM_Presets", []];
// [ _name , _itemCount , [keys _selectHashMap, values _selectHashMap] , _dateCreated , _dateUsed ]
// DO NOT CHANGE, PLAYER OWNED DATA ^^^
// or atleast try to parse different versions somehow

{
  _x lnbAddColumn 0.25;
  _x lnbAddColumn 0.5;
  _x lnbAddColumn 0.75;
} forEach [_filterCtrl, _contentCtrl];

_filterCtrl lnbAddRow ["Name", "Items", "Created", "Last Used"];

{
  private _row = _contentCtrl lnbAddRow [ _x # 0 , format [ "%1 items", _x # 1 ], format["%1/%2/%3", _x # 3 # 2, _x # 3 # 1, _x # 3 # 0], format["%1/%2/%3", _x # 4 # 2, _x # 4 # 1, _x # 4 # 0] ];
  _contentCtrl lnbSetData [[_row, 0], _forEachIndex ];
  _contentCtrl lnbSetData [[_row, 1], str(_x # 2) ];
  _contentCtrl lnbSetData [[_row, 2], dateToNumber (_x # 3) ];
  _contentCtrl lnbSetData [[_row, 3], dateToNumber (_x # 4) ];
} forEach _presetsArray;

[_filterCtrl, _contentCtrl] call BIS_fnc_initListNBoxSorting;

//Without this line, the user has to click _contentCtrl first in order to use the sorting buttons.
ctrlSetFocus _contentCtrl;

//Load preset
(_displayPreset displayCtrl IDC_VAM_PRESET_LOADBUTTON) ctrlAddEventHandler ["ButtonClick",
{
  params ["_ctrlButton"];

  private _contentCtrl = (ctrlParent _ctrlButton) displayCtrl IDC_VAM_PRESET_LISTNBOXCONTENT;
  private _PresetData = parseSimpleArray (_contentCtrl lnbData [lnbCurSelRow _contentCtrl, 1]);
  private _newSelectionHashmap = (_PresetData # 0) createHashMapFromArray (_PresetData # 1);

  // set current selectHashMap to new hashmap from preset
  uiNamespace setVariable ["ENH_VAM_selectHashMap", _newSelectionHashmap];
  format ["Loaded Preset: %1", _contentCtrl lnbText [lnbCurSelRow _contentCtrl, 0]] call BIS_fnc_3DENNotification;

  // Update Last Used date
  private _presetsArray = profileNamespace getVariable ["ENH_VAM_Presets", []];
  private _presetIndex = parseNumber(_contentCtrl lnbData [lnbCurSelRow _contentCtrl, 0]);
  private _values = _presetsArray # _presetIndex;
  _values set [4, systemTime];
  _presetsArray set [_presetIndex, _values];
  profileNamespace setVariable ["ENH_VAM_Presets", _presetsArray];

  ctrlParent _ctrlButton closeDisplay 1;
}];

//Save preset
(_displayPreset displayCtrl IDC_VAM_PRESET_SAVEBUTTON) ctrlAddEventHandler ["ButtonClick",
{
  params["_ctrlButton"];

  private _displayInput = ctrlParent _ctrlButton createDisplay "Display3DENRename";

  _displayInput displayCtrl 1 ctrlAddEventHandler ["ButtonClick",
  {
    params ["_ctrlButton"];

    private _presetsArray = profileNamespace getVariable ["ENH_VAM_Presets", []];

    //Player input for preset name
    private _presetName = ctrlText (ctrlParent _ctrlButton displayCtrl 101);

    private _selectHashMap = uiNamespace getVariable "ENH_VAM_selectHashMap";

    _presetsArray pushBack [ _presetName, count _selectHashMap, [keys _selectHashMap, values _selectHashMap], systemTime, systemTime ];

    profileNamespace setVariable ["ENH_VAM_Presets", _presetsArray];
    saveProfileNamespace;
  }];

  _displayInput displayAddEventHandler ["Unload",
  {
    private _display = uiNamespace getVariable "ENH_VAM_PRESETS_display";
    private _presetArray = profileNamespace getVariable "ENH_VAM_Presets";
    (_presetArray # (count _presetArray - 1)) params ["_name", "_itemCount", "_presetData"];
    private _contentCtrl = _display displayCtrl IDC_VAM_PRESET_LISTNBOXCONTENT;

    //Add new preset to ListNBox
    private _row = _contentCtrl lnbAddRow [ _name , format [ "%1 items", _itemCount ], format["%1/%2/%3", systemTime # 2, systemTime # 1, systemTime # 0], format["%1/%2/%3", systemTime # 2, systemTime # 1, systemTime # 0]];
    _contentCtrl lnbSetData [[_row, 0], count _presetsArray];
    _contentCtrl lnbSetData [[_row, 1], str _presetData];
    _contentCtrl lnbSetData [[_row, 2], dateToNumber systemTime];
    _contentCtrl lnbSetData [[_row, 3], dateToNumber systemTime];
  }];
}];

//Delete preset
(_displayPreset displayCtrl IDC_VAM_PRESET_DELETEBUTTON) ctrlAddEventHandler ["ButtonClick",
{
  params["_ctrlButton"];

  private _presetsArray = profileNamespace getVariable ["ENH_VAM_Presets", []];
  private _contentCtrl = (ctrlParent _ctrlButton) displayCtrl IDC_VAM_PRESET_LISTNBOXCONTENT;
  private _currSelRow = lnbCurSelRow _contentCtrl;
  private _presetIndex = (_contentCtrl lnbData [_currSelRow, 0]);

  _presetsArray deleteAt (parseNumber _presetIndex);
  _contentCtrl lnbDeleteRow _currSelRow;

  profileNamespace setVariable ["ENH_VAM_Presets", _presetsArray];
  saveProfileNamespace;
}];

//Update tvTree to display new selecthashmap
_displayPreset displayAddEventHandler ["Unload",
{
  [] call ENH_fnc_VAM_loadSelectHashMap;
}];