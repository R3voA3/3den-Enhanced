#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-09-25

    Description:
    Creates the sync preview in the Module Information GUI.

    Parameter(s):
    0: DISPLAY - Module Information GUI
    1: STRING - Module class

    Returns:
    NOTHING
*/

#define R1 15
#define ICON_SIZE 6

if (!is3DEN) exitWith {};

disableSerialization;

private _fnc_calculatePosition =
{
    params ["_angle", "_r", "_centerX", "_centerY"];
    [_centerX + sin _angle * _r * GRID_W, _centerY + cos _angle * _r * GRID_H];
};

private _fnc_drawLine =
{
    params ["_xPosStart", "_yPosStart", "_xPosEnd", "_yPosEnd"];

    private _ctrlLine = _displayModuleInformation ctrlCreate ["ctrlStaticLine", -1, _ctrlGroupPreview];

    private _angle = [_xPosStart, _yPosStart] getDir [_xPosEnd, _yPosEnd];

    private _width = 0;
    private _height = 0;

    // Quadrant 1
    if (_angle >= 0 && _angle <= 90) then
    {
        _width = _xPosEnd - _xPosStart;
        _height = _yPosEnd - _yPosStart;
    };

    // Quadrant 2
    if (_angle > 90 && _angle <= 180) then
    {
        _width = _xPosEnd - _xPosStart;
        _height = _yPosEnd - _yPosStart;
    };

    // Quadrant 3
    if (_angle > 180 && _angle <= 270) then
    {
        _width = _xPosEnd - _xPosStart;
        _height = _yPosEnd - _yPosStart;
    };

    // Quadrant 4
    if (_angle > 270 && _angle <= 360) then
    {
        _width = _xPosEnd - _xPosStart;
        _height = _yPosEnd - _yPosStart;
    };

    private _offsetX = 0.5 * ICON_SIZE * GRID_W;
    private _offsetY = 0.5 * ICON_SIZE * GRID_H;

    _ctrlLine ctrlSetPosition
    [
        _xPosStart + _offsetX,
        _yPosStart + _offsetY,
        _width,
        _height
    ];

    _ctrlLine ctrlSetTextColor [0.7, 0.7, 0.7, 0.7];
};

private _fnc_createModuleIcon =
{
    params ["_cfgModule", "_centerX", "_centerY"];

    private _ctrlModule = _displayModuleInformation ctrlCreate ["ctrlActivePictureKeepAspect", -1, _ctrlGroupPreview];

    // Cache data
    private _informationHashMap = [_parentConfig] call ENH_fnc_MI_getInformationData;
    _ctrlModule setVariable ["InformationFormatted", [_informationHashMap] call ENH_fnc_MI_formatInformationData];

    _ctrlModule ctrlSetText (_informationHashMap get "icon");

    _ctrlModule ctrlAddEventHandler ["MouseEnter",
    {
        params ["_ctrl"];

        private _display = ctrlParent _ctrl;

        ctrlPosition _ctrl params ["", "", "_sizeW", "_sizeH"];

        _ctrl setVariable ["ICON_SIZE", [_sizeW, _sizeH]];

        _ctrl ctrlSetPositionW (_sizeW * 1.05);
        _ctrl ctrlSetPositionH (_sizeH * 1.05);
        _ctrl ctrlCommit 0.2;

        private _cfgModule = _ctrl getVariable "config";

        private _ctrlStructuredText = CTRL(IDC_MODULEINFORMATION_DESCRIPTION);

        _ctrlStructuredText ctrlSetStructuredText (_ctrl getVariable "InformationFormatted");
        _ctrlStructuredText call ENH_fnc_MI_resizeInformationControl;
    }];

    _ctrlModule ctrlAddEventHandler ["MouseExit",
    {
        params ["_ctrl"];

        _ctrl getVariable "ICON_SIZE" params ["_sizeW", "_sizeH"];

        _ctrl ctrlSetPositionW _sizeW;
        _ctrl ctrlSetPositionH _sizeH;
        _ctrl ctrlCommit 0.2;
    }];

    _ctrlModule ctrlSetPosition [_centerX, _centerY, ICON_SIZE * GRID_W, ICON_SIZE * GRID_H];
};

private _fnc_createSyncChildren =
{
    params ["_parentConfig", "_centerX", "_centerY", "_cfgModuleMain", ["_centerXPrev", -1], ["_centerYPrev", -1]];

    if (isNull _parentConfig) exitWith
    {
        [format ["Config for module (%1) was null.", _cfgModuleMain]] call BIS_fnc_3DENNotification;
        nil;
    };

    [_parentConfig, _centerX, _centerY] call _fnc_createModuleIcon;

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

    private _newParentConfig = configNull;
    private _angleStep = 360 / (count _children max 1);

    private _initalAngle = if ([_centerXPrev, _centerYPrev] isNotEqualTo [-1, -1]) then
    {
        [_centerXPrev, _centerYPrev] getDir [_centerX, _centerY];
    }
    else
    {
        0;
    };

    {
        private _newParentConfig = _cfgModuleMain >> "ModuleDescription" >> _x;
        [(_forEachIndex * _angleStep) + _initalAngle, R1, _centerX, _centerY] call _fnc_calculatePosition params ["_newCenterX", "_newCenterY"];

        [_centerX, _centerY, _newCenterX, _newCenterY] call _fnc_drawLine;

        [_newParentConfig, _newCenterX, _newCenterY, _cfgModuleMain, _centerX, _centerY] call _fnc_createSyncChildren;
    } forEach _children;
};

params ["_displayModuleInformation", "_logicClass"];

private _ctrlGroupPreview = _displayModuleInformation displayCtrl IDC_MODULEINFORMATION_SYNC_GROUP;

// Clear previous preview
allControls _ctrlGroupPreview apply {ctrlDelete _x};
ctrlPosition _ctrlGroupPreview params ["", "", "_w", "_h"];

private _centerX = 0.5 * _w - 0.5 * ICON_SIZE * GRID_W;
private _centerY = 0.5 * _h - 0.5 * ICON_SIZE * GRID_H;
private _cfgModuleMain = configFile >> "CfgVehicles" >> _logicClass;

[_cfgModuleMain, _centerX, _centerY, _cfgModuleMain] call _fnc_createSyncChildren;

allControls _displayModuleInformation apply {_x ctrlCommit 0};

nil
