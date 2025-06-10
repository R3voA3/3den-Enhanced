#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-11

    Description:
    Used by the ENH_VariableViewer GUI. Called on load.

    Parameter(s):
    0: Display - ENH_VariableViewer GUI

    Returns:
    -
*/

disableSerialization;
params ["_display"];

private _ctrlNamespace = CTRL(IDC_VARIABLEVIEWER_NAMESPACE);

CTRL(IDC_VARIABLEVIEWER_HIDEFUNCTIONS) cbSetChecked (profileNamespace getVariable ["ENH_VariableViewer_HideFunctions", false]);

// Get all namespaces
private _worldSizeHalf = worldSize / 2;

// Sort units, vehicles, groups and locations first, then add special namespaces so that they are at the beginning of the combo box
private _namespaces = allUnits + vehicles + allGroups + (nearestLocations [[_worldSizeHalf, _worldSizeHalf, 0], [], _worldSizeHalf * sqrt 2]) + entities [["Logic"], []];
_namespaces sort true;
_namespaces = ["missionNamespace", "localNamespace", "profileNamespace", "parsingNamespace", "uiNamespace", "player", "cursorTarget"] + _namespaces;

uiNamespace setVariable ["ENH_VariableViewer_Namespaces", _namespaces];

// We add special namespaces first, otherwise they are all named NAMESPACE
private _lastNamespace = uiNamespace getVariable ["ENH_VariableViewer_LastNamespace", "missionNamespace"];
private _icon = "";
{
    if (_x isEqualType "") then
    {
        _ctrlNamespace lbAdd _x;
    }
    else
    {
        _ctrlNamespace lbAdd str _x;
    };
    if (_x isEqualTo _lastNamespace) then
    {
        _ctrlNamespace lbSetCurSel _forEachIndex;
    };
    switch (typeName _x) do
    {
        case "OBJECT":
        {
            _icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
        };
        case "GROUP":
        {
            _icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
        };
        case "LOCATION":
        {
            _icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\locationList_ca.paa";
        };
        case "STRING":
        {
            _icon = "\a3\Modules_F_Curator\Data\portraitLightning_ca.paa";
        };
    };
    _ctrlNamespace lbSetPicture [_forEachIndex, _icon];
} forEach _namespaces;

CTRL(IDC_VARIABLEVIEWER_NAMESPACE) ctrlAddEventHandler ["LBSelChanged", ENH_fnc_variableViewer_onFilterChanged];

// Handle searching
CTRL(IDC_VARIABLEVIEWER_SEARCH) ctrlAddEventHandler ["EditChanged",
{
    params ["_ctrlEdit", "_newText"];
    private _display = ctrlParent _ctrlEdit;

    [] call ENH_fnc_variableViewer_fillLNB;

    if (_newText == "") then
    {
        CTRL(IDC_VARIABLEVIEWER_SEARCHBUTTON) ctrlSetText TEXTURE_SEARCH_START;
    }
    else
    {
        CTRL(IDC_VARIABLEVIEWER_SEARCHBUTTON) ctrlSetText TEXTURE_SEARCH_END;
    };
}];

// CTRL + F to focus search
_display displayAddEventHandler ["KeyDown", // Focus Search
{
    params ["_display", "_key", "", "_ctrl"];
    if (_key isEqualTo 33 && _ctrl) then
    {
        ctrlSetFocus CTRL(IDC_VARIABLEVIEWER_SEARCH);
    }
}];

// Reset search
CTRL(IDC_VARIABLEVIEWER_SEARCHBUTTON) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    private _display = ctrlParent _ctrlButton;

    CTRL(IDC_VARIABLEVIEWER_SEARCH) ctrlSetText "";
    _ctrlButton ctrlSetText TEXTURE_SEARCH_START
}];

CTRL(IDC_VARIABLEVIEWER_LIST) ctrlAddEventHandler ["LBSelChanged", ENH_fnc_variableViewer_onLNBSelChanged];

// Update list if show functions state changes
CTRL(IDC_VARIABLEVIEWER_HIDEFUNCTIONS) ctrlAddEventHandler ["CheckedChanged",
{
    profileNamespace setVariable ["ENH_VariableViewer_HideFunctions", [false, true] select _this#1];
    [] call ENH_fnc_variableViewer_fillLNB;
}];

// Fill ListNbox
CTRL(IDC_VARIABLEVIEWER_LIST) call ENH_fnc_variableViewer_fillLNB;

// Set up Filter
CTRL(IDC_VARIABLEVIEWER_FILTER) lnbAddRow [localize "STR_ENH_MAIN_VARIABLEVIEWER_VARIABLENAME", localize "STR_ENH_MAIN_VARIABLEVIEWER_VARIABLEVALUE", localize "STR_ENH_MAIN_VARIABLEVIEWER_VARIABLETYPE"];

// Used for sorting
[CTRL(IDC_VARIABLEVIEWER_FILTER), CTRL(IDC_VARIABLEVIEWER_LIST), [0, 1, 2]] call BIS_fnc_initListNBoxSorting;
