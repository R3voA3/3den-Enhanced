#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-05-26

    Description:
    Handles the ENH_ZeusAddons GUI.

    Parameter(s):
    -

    Returns:
    -
*/

disableSerialization;

private _display = findDisplay IDD_DISPLAY3DEN createDisplay "ENH_ZeusAddons";
private _ctrlTVPatches = CTRL(10);
private _validCfgPatches = [];

ENH_fnc_manageZeusAddons_invertSelection =
{
    params ["_ctrlTVPatches", "_path"];

    if (_ctrlTVPatches tvValue _path == 0) then
    {
        _ctrlTVPatches tvSetPicture [_path, TEXTURE_CHECKED];
        _ctrlTVPatches tvSetValue [_path, 1];
        _ctrlTVPatches tvSetColor [_path, [145 / 255, 199 / 255, 127 / 255, 1]];
    }
    else
    {
        _ctrlTVPatches tvSetPicture [_path, TEXTURE_UNCHECKED];
        _ctrlTVPatches tvSetValue [_path, 0];
        _ctrlTVPatches tvSetColor [_path, [1, 1, 1, 1]];
    };
};

// Get Valid Patches (Only with atleast one unit with scopeCurator == 2), result is cached
if (uiNamespace getVariable ["ENH_ZeusAddons_ValidPatches", []] isEqualTo []) then
{
    ("true" configClasses (configFile >> "CfgPatches")) apply
    {
        private _patch = _x;
        private _units = getArray (_x >> "units");
        if (_units isEqualTo []) then {continue};
        _units apply
        {
            // Exit if first vehicle with scopeCurator == 2 is found
            if (getNumber (configFile >> "CfgVehicles" >> _x >> "scopeCurator") == 2) exitWith {_validCfgPatches pushBack _patch};
        };
    };
    uiNamespace setVariable ["ENH_ZeusAddons_ValidPatches", _validCfgPatches]
};

// Fill tree
private _addons = [];
(uiNamespace getVariable "ENH_ZeusAddons_ValidPatches") apply
{
    (_x call ENH_fnc_getConfigSourceAddon) params [["_addonClass", ""], ["_addonName", ""], ["_addonIcon", ""]];

    if !(_addonClass in _addons) then
    {
        if (_addonName isEqualTo "") then {_addonName = "Arma 3"};
        private _index = _ctrlTVPatches tvAdd [[], _addonName];
        _ctrlTVPatches tvSetPictureRight [[_index], _addonIcon];
        _ctrlTVPatches tvSetTooltip [[_index], _addonClass];
        _addons pushBack _addonClass;
    };
    private _indexAddon = _addons find _addonClass;
    private _indexPatch = _ctrlTVPatches tvAdd [[_indexAddon], configName _x];
    private _previouslyEnabled = profileNamespace getVariable ["ENH_EnabledZeusAddons", []];

    _ctrlTVPatches tvSetData [[_indexAddon, _indexPatch], _addonClass];
    _ctrlTVPatches tvSetPicture [[_indexAddon, _indexPatch], TEXTURE_UNCHECKED];
    _ctrlTVPatches tvSetTooltip [[_indexAddon, _indexPatch], configName _x];
    _ctrlTVPatches tvSetValue [[_indexAddon, _indexPatch], parseNumber (configName _x in _previouslyEnabled)];
    [_ctrlTVPatches, [_indexAddon, _indexPatch]] call ENH_fnc_manageZeusAddons_invertSelection;
};

_ctrlTVPatches tvSortAll [[], false];

// Save setup when GUI is closed
_display displayAddEventHandler ["Unload",
{
    params ["_display"];
    private _ctrlTVPatches = CTRL(IDC_ZEUSADDONS_CFGPATCHES);
    private _enabled = [];

    for "_indexAddon" from 0 to (_ctrlTVPatches tvCount []) - 1 do
    {
        for "_indexPatch" from 0 to (_ctrlTVPatches tvCount [_indexAddon]) - 1 do
        {
            if (_ctrlTVPatches tvValue [_indexAddon, _indexPatch] == 1) then
            {
                _enabled append [_ctrlTVPatches tvText [_indexAddon, _indexPatch]];
            };
        };
    };
    profileNamespace setVariable ["ENH_EnabledZeusAddons", _enabled];
}];

// Fill units list
_ctrlTVPatches ctrlAddEventHandler ["TreeSelChanged",
{
    _this spawn
    {
        params ["_ctrlTVPatches", "_path"];

        if (count _path < 2) exitWith {};

        private _ctrlLBUnits = ctrlParent _ctrlTVPatches displayCtrl IDC_ZEUSADDONS_UNITS;
        private _class = _ctrlTVPatches tvText _path;
        private _units = getArray (configFile >> "CfgPatches" >> _class >> "units");

        lbClear _ctrlLBUnits;

        _units apply
        {
            if (getNumber (configFile >> "CfgVehicles" >> _x >> "scopeCurator") < 2) then {continue};
            private _displayName = getText (configFile >> "CfgVehicles" >> _x >> "displayName");

            private _row = _ctrlLBUnits lbAdd _displayName;
            _ctrlLBUnits lbSetTooltip [_row, _displayName + endl + _x];

            // Try to get a proper image
            private _picture = getText (configFile >> "CfgVehicles" >> _x >> "editorPreview");
            if !(fileExists _picture) then {_picture = getText (configFile >> "CfgVehicles" >> _x >> "portrait")};
            if !(fileExists _picture) then {_picture = getText (configFile >> "CfgVehicles" >> _x >> "icon")};
            if !(fileExists _picture) then {_picture = getText (configFile >> "CfgVehicles" >> _x >> "picture")};
            if !(fileExists _picture) then {continue};
            _ctrlLBUnits lbSetPictureRight [_row, _picture];
        };
        lbSort [_ctrlLBUnits, "ASC"];
    };
}];

// Change state
_ctrlTVPatches ctrlAddEventHandler ["TreeSelChanged",
{
    params ["_ctrlTVPatches", "_path"];
    if (count _path < 2) exitWith {};
    [_ctrlTVPatches, _path] call ENH_fnc_manageZeusAddons_invertSelection;
}];

// Copy
ctrlParent _ctrlTVPatches displayCtrl IDC_ZEUSADDONS_EXPORT ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    private _ctrlTVPatches = ctrlParent _ctrlButton displayCtrl IDC_ZEUSADDONS_CFGPATCHES;
    private _export = "";

    for "_indexAddon" from 0 to (_ctrlTVPatches tvCount []) - 1 do
    {
        for "_indexPatch" from 0 to (_ctrlTVPatches tvCount [_indexAddon]) - 1 do
        {
            if (_ctrlTVPatches tvValue [_indexAddon, _indexPatch] == 1) then
            {
                _export = _export + str (_ctrlTVPatches tvText [_indexAddon, _indexPatch]) + ", ";
            };
        };
    };

    // Set variable used by display3denCopy and create the display
    uiNamespace setVariable ["display3DENCopy_data", ["CfgPatches", _export trim [", ", 2]]];
    ctrlParent _ctrlButton createDisplay "display3denCopy";
}];

// Invert selection
ctrlParent _ctrlTVPatches displayCtrl IDC_ZEUSADDONS_INVERT ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    private _ctrlTVPatches = ctrlParent _ctrlButton displayCtrl IDC_ZEUSADDONS_CFGPATCHES;

    for "_indexAddon" from 0 to (_ctrlTVPatches tvCount []) - 1 do
    {
        for "_indexPatch" from 0 to (_ctrlTVPatches tvCount [_indexAddon]) - 1 do
        {
            [_ctrlTVPatches, [_indexAddon, _indexPatch]] call ENH_fnc_manageZeusAddons_invertSelection;
        };
    };
}];

// Collapse tree view
CTRL(IDC_ZEUSADDONS_COLLAPSE) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    tvCollapseAll (ctrlParent _ctrlButton displayCtrl IDC_ZEUSADDONS_CFGPATCHES);
}];

// Expand tree view
CTRL(IDC_ZEUSADDONS_EXPAND) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    tvExpandAll (ctrlParent _ctrlButton displayCtrl IDC_ZEUSADDONS_CFGPATCHES);
}];

[CTRL(IDC_ZEUSADDONS_SEARCH), CTRL(IDC_ZEUSADDONS_BUTTONSEARCH)] call ENH_fnc_initSearchControls;
