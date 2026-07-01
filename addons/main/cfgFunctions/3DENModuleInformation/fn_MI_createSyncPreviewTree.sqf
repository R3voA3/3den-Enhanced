#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-09-30

    Description:
    Creates a tree view displaying how the module should be synced in the
    Module Information UI.

    Parameter(s):
    0: DISPLAY - ENH_ModuleInformation
    1: STRING - Class name of the main module from CfgVehicles

    Return Value:
    NOTHING
*/

if (!is3DEN) exitWith {};

disableSerialization;

params ["_displayModuleInformation", "_logicClass"];

private _ctrlGroupPreview = _displayModuleInformation displayCtrl IDC_MODULEINFORMATION_SYNC_GROUP;

// Clear previous preview
allControls _ctrlGroupPreview apply {ctrlDelete _x};

ctrlPosition _ctrlGroupPreview params ["", "", "_w", "_h"];

private _ctrlTV = _displayModuleInformation ctrlCreate ["ctrlTree", -1, _ctrlGroupPreview];

_ctrlTV ctrlSetPosition [0, 0, _w, _h];
_ctrlTV ctrlCommit 0;

private _fnc_createSyncChildren =
{
    params ["_parentPath", "_parentConfig", "_ctrlTV", "_cfgModuleMain"];

    if (isNull _parentConfig) exitWith
    {
        [format ["Config for module (%1) was null.", _cfgModuleMain]] call BIS_fnc_3DENNotification;
        nil;
    };

    private _newParentPath = [];
    private _newParentConfig = configNull;

    private _informationHashMap = [_parentConfig] call ENH_fnc_MI_getInformationData;
    private _informationStructText = [_informationHashMap] call ENH_fnc_MI_formatInformationData;

    private _index = _ctrlTV tvAdd
    [
        _parentPath,
        format
        [
            "%1 (%2)",
            _informationHashMap get "displayName",
            _informationHashMap get "configName"
        ]
    ];

    _newParentPath = _parentPath + [_index];

    _ctrlTV tvSetPicture [_newParentPath, _informationHashMap get "icon"];

    // Store date for selection changed event
    private _informationCache = _ctrlTV getVariable ["InformationCache", createHashMap];
    _informationCache set [_newParentPath, _informationStructText];
    _ctrlTV setVariable ["InformationCache", _informationCache];

    // Get all children
    private _children = [];

    if (isClass (_parentConfig >> "ModuleDescription")) then
    {
        _children = getArray(_parentConfig >> "ModuleDescription" >> "sync");
    }
    else
    {
        _children = getArray(_parentConfig >> "sync");
    };

    {
        private _newParentConfig = _cfgModuleMain >> "ModuleDescription" >> _x;
        [_newParentPath, _newParentConfig, _ctrlTV, _cfgModuleMain] call _fnc_createSyncChildren;
    } forEach _children;
};

_ctrlTV ctrlAddEventHandler ["TreeSelChanged",
{
    params ["_ctrlTV", "_path"];

    private _informationStructText = (_ctrlTV getVariable "InformationCache") get _path;
    private _ctrlStructuredText = ctrlParent _ctrlTV displayCtrl IDC_MODULEINFORMATION_DESCRIPTION;

    _ctrlStructuredText ctrlSetStructuredText _informationStructText;
    _ctrlStructuredText call ENH_fnc_MI_resizeInformationControl;
}];

private _cfgModuleMain = configFile >> "CfgVehicles" >> _logicClass;

[[], _cfgModuleMain, _ctrlTV, _cfgModuleMain] call _fnc_createSyncChildren;

tvExpandAll _ctrlTV;

_ctrlTV tvSetCurSel [0];

nil;
