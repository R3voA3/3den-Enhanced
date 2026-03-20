#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Used by the marker color attribute. Called when attribute is loaded.
    This is an engine driven attribute.

    Parameter(s):
    See control event handler onLoad

    Returns:
    -
*/

params ["_ctrl", "_config"];

private _ctrlGroup = ctrlParentControlsGroup _ctrl;
private _value = get3DENSelected "marker" #0 get3DENAttribute "BaseColor" param [0, ""];

private _colorRGBA = if (_value select [0, 1] != "#") then
{
    [0, 0, 0, 0]
}
else
{
    _value splitString ",#()" apply {parseNumber _x};
};

_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01 sliderSetPosition _colorRGBA#0;
_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 sliderSetPosition _colorRGBA#1;
_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05 sliderSetPosition _colorRGBA#2;
_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07 sliderSetPosition _colorRGBA#3;

// Add event handler for updating the preview
#define UPDATE private _ctrlGroup = ctrlParentControlsGroup (_this select 0);\
    private _red = round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) * 100) / 100;\
    private _green = round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) * 100) / 100;\
    private _blue = round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) * 100) / 100;\
    private _alpha = round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) * 100) / 100;\
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09) ctrlSetBackgroundColor [_red, _green, _blue, _alpha];\
    (_ctrlGroup controlsGroupCtrl 100) ctrlSetText format ["#(%1,%2,%3,%4)", _red, _green, _blue, _alpha];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlAddEventHandler ["SliderPosChanged", {UPDATE}];
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlAddEventHandler ["SliderPosChanged", {UPDATE}];
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlAddEventHandler ["SliderPosChanged", {UPDATE}];
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlAddEventHandler ["SliderPosChanged", {UPDATE}];

// Update the preview
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09) ctrlSetBackgroundColor _colorRGBA;

private _ctrlComboHistory = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10;

_ctrlComboHistory call ENH_fnc_markerColor_fillLBHistory;

_ctrlComboHistory ctrlAddEventHandler ["LBSelChanged",
{
    params ["_ctrlCombo", "_index"];

    if (_index == 0) exitWith {};

    private _ctrlGroup = ctrlParentControlsGroup _ctrlCombo;
    private _hash = _ctrlCombo lbData _index;
    private _colorRGBA = (profileNamespace getVariable ["ENH_Attributes_MarkerColor_History", createHashMap]) get _hash;

    // Update sliders
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01 sliderSetPosition _colorRGBA#0;
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 sliderSetPosition _colorRGBA#1;
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05 sliderSetPosition _colorRGBA#2;

    UPDATE;
}];

// Add button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
    private _ctrlComboHistory = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10;
    private _history = profileNamespace getVariable ["ENH_Attributes_MarkerColor_History", createHashMap];
    private _colorRGBA =
    [
        round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) * 100) / 100,
        round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) * 100) / 100,
        round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) * 100) / 100,
        round (sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) * 100) / 100
    ];

    private _hash = hashValue _colorRGBA;
    private _notNew = _history set [_hash, _colorRGBA, true];

    if (!_notNew) then
    {
        profileNamespace setVariable ["ENH_Attributes_MarkerColor_History", _history];
        saveProfileNamespace;

        _ctrlComboHistory call ENH_fnc_markerColor_fillLBHistory;
    };
}];

// Remove button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    private _ctrlComboHistory = (ctrlParentControlsGroup _ctrlButton) controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10;
    private _curSelected = lbCurSel _ctrlComboHistory;

    if (_curSelected <= 0) exitWith {};

    private _history = profileNamespace getVariable ["ENH_Attributes_MarkerColor_History", createHashMap];
    _history deleteAt (_ctrlComboHistory lbData _curSelected);
    saveProfileNamespace;

    _ctrlComboHistory call ENH_fnc_markerColor_fillLBHistory;
}];
