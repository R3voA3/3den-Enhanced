#include "\x\enh\addons\main\script_component.hpp"

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

params ["_display"];

// Store selection for later use
ENH_selectionFilter_currentSelection = [[],[],[],[],[],[],[],[]];

ENH_selectionFilter_currentSelection set [0, get3DENSelected "Object" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [1, get3DENSelected "Group" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [2, get3DENSelected "Trigger" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [3, get3DENSelected "Logic" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [4, get3DENSelected "Waypoint" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [5, get3DENSelected "Marker" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [6, get3DENSelected "Comment" apply {get3DENEntityID _x}];
ENH_selectionFilter_currentSelection set [7, get3DENSelected "Layer" apply {get3DENEntityID _x}];

// Disable checkboxes of types that are not in the selection
private _fnc_disableCheckbox =
{
    params ["_entityType", "_idc"];
    if (get3DENSelected _entityType isEqualTo []) then
    {
        _display displayCtrl _idc ctrlEnable false;
    };
};

// Only enable checkboxes of types that are in selection
["Object", IDC_SELECTIONMANAGER_FILTER_OBJECTS] call _fnc_disableCheckbox;
["Group", IDC_SELECTIONMANAGER_FILTER_GROUPS] call _fnc_disableCheckbox;
["Trigger", IDC_SELECTIONMANAGER_FILTER_TRIGGERS] call _fnc_disableCheckbox;
["Logic", IDC_SELECTIONMANAGER_FILTER_SYSTEMS] call _fnc_disableCheckbox;
["Waypoint", IDC_SELECTIONMANAGER_FILTER_WAYPOINTS] call _fnc_disableCheckbox;
["Marker", IDC_SELECTIONMANAGER_FILTER_MARKERS] call _fnc_disableCheckbox;
["Comment", IDC_SELECTIONMANAGER_FILTER_COMMENTS] call _fnc_disableCheckbox;
["Layer", IDC_SELECTIONMANAGER_FILTER_LAYERS] call _fnc_disableCheckbox;

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

    if ([_display, IDC_SELECTIONMANAGER_FILTER_OBJECTS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 0};
    if ([_display, IDC_SELECTIONMANAGER_FILTER_GROUPS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 1};
    if ([_display, IDC_SELECTIONMANAGER_FILTER_TRIGGERS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 2};
    if ([_display, IDC_SELECTIONMANAGER_FILTER_SYSTEMS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 3};
    if ([_display, IDC_SELECTIONMANAGER_FILTER_WAYPOINTS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 4};
    if ([_display, IDC_SELECTIONMANAGER_FILTER_MARKERS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 5};
    if ([_display, IDC_SELECTIONMANAGER_FILTER_COMMENTS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 6};
    if ([_display, IDC_SELECTIONMANAGER_FILTER_LAYERS] call _isChecked) then {_filteredSelectionIDs append ENH_selectionFilter_currentSelection # 7};

    set3DENSelected _filteredSelectionIDs;
};

ENH_fnc_selectionFilter_onCheckedChanged =
{
    params ["_cb"];
    _cb ctrlSetFade ([0.5, 0] select (cbChecked _cb));
    _cb ctrlCommit 0;

    (ctrlParent _cb) call ENH_fnc_selectionFilter_updateSelection;
};

ENH_fnc_selectionFilter_editAttributes =
{
    params ["_ctrlButton"];

    // Close display first, otherwise Arma 3 will crash
    (ctrlParent _ctrlButton) closeDisplay 0;
    waitUntil {isNull ctrlParent _ctrlButton};

    // Open attributes
    do3DENAction "OpenAttributes";
};

ENH_fnc_selectionFilter_cancel =
{
    params ["_ctrlButton"];
    (ctrlParent _ctrlButton) closeDisplay 0;

    // Restore original selection
    set3DENSelected flatten ENH_selectionFilter_currentSelection;
};
