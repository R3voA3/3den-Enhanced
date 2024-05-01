/*
  Author: R3vo

  Date: 2022-09-17

  Description:
  Handles the selection filter UI.

  Parameter(s):
  0: DISPLAY - Selection Filter UI

  Returns:
  NOTHING
*/

#include "\x\enh\addons\main\script_component.hpp"

params ["_display"];

//Focus cancel button
ctrlSetFocus (_display displayCtrl 18);

//Store selection for later use
ENH_selectionFilter_currentSelection = [[],[],[],[],[],[],[],[]];

ENH_selectionFilter_currentSelection set [0, get3DENSelected "Object" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [1, get3DENSelected "Group" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [2, get3DENSelected "Trigger" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [3, get3DENSelected "Logic" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [4, get3DENSelected "Waypoint" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [5, get3DENSelected "Marker" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [6, get3DENSelected "Comment" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [7, get3DENSelected "Layer" apply {get3DENEntityID _x}];

//Disable checkboxes of types that are not in the selection
private _fnc_disableCheckbox =
{
  params ["_entityType", "_idc"];
  if (get3DENSelected _entityType isEqualTo []) then
  {
    _display displayCtrl _idc ctrlEnable false;
  };
};

//Only enable checkboxes of types that are in selection
["Object", 10] call _fnc_disableCheckbox;
["Group", 11] call _fnc_disableCheckbox;
["Trigger", 12] call _fnc_disableCheckbox;
["Logic", 13] call _fnc_disableCheckbox;
["Waypoint", 14] call _fnc_disableCheckbox;
["Marker", 15] call _fnc_disableCheckbox;
["Comment", 16] call _fnc_disableCheckbox;
["Layer", 17] call _fnc_disableCheckbox;

if (!isNil "ENH_fnc_selectionFilter_updateSelection") exitWith {};

ENH_fnc_selectionFilter_updateSelection =
{
  params ["_display"];

  private _isChecked =
  {
    params ["_display", "_idd"];
    cbChecked (_display displayCtrl _idd);
  };

  private _filteredSelectionIDs = [];

  if ([_display, 10] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 0};
  if ([_display, 11] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 1};
  if ([_display, 12] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 2};
  if ([_display, 13] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 3};
  if ([_display, 14] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 4};
  if ([_display, 15] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 5};
  if ([_display, 16] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 6};
  if ([_display, 17] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 7};

  set3DENSelected _filteredSelectionIDs;
};

ENH_fnc_selectionFilter_onCheckedChanged =
{
  params ['_cb'];
  _cb ctrlSetFade ([0.5, 0] select (cbChecked _cb));
  _cb ctrlCommit 0;

  (ctrlparent _cb) call ENH_fnc_selectionFilter_updateSelection;
};

ENH_fnc_selectionFilter_editAttributes =
{
  params ["_ctrlButton"];

  //Close display first, otherwise Arma 3 will crash
  (ctrlParent _ctrlButton) closeDisplay 0;
  waitUntil {isNull ctrlParent _ctrlButton};

  //Open attributes
  do3DENAction "OpenAttributes";
};

ENH_fnc_selectionFilter_cancel =
{
  params ["_ctrlButton"];
  (ctrlParent _ctrlButton) closeDisplay 0;

  //Restore original selection
  set3DENSelected flatten ENH_selectionFilter_currentSelection;
};