#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Updates the slider and color preview control when the edit text is changed.
    Input is validated.

    Parameter(s):
    0: CONTROL - Edit
    1: STRING - New Text

    Returns:
    true
*/

params ["_ctrlEdit", "_newText"];

// The engine code fills the edit box with markerColor from config by default
// KK used the following code to prevent that
if (_newText != "" && {_newtext select [0, 1] != "#"}) then
{
    _ctrlEdit ctrlSetText "";
};

// We only want our controls to be updated if we have a valid color code
// Trim all whitespaces
_newText = trim _newText regexReplace [" ", ""];

if (_newText regexMatch "#\([0-9.]+,[0-9.]+,[0-9.]+,[0-9.]+\)") then
{
    // Turn the string into an array
    _newText splitString "#(,)" apply {parseNumber _x} params ["_red", "_green", "_blue", "_alpha"];

    // Clamp the value
    _red = _red min 1 max 0;
    _green = _green min 1 max 0;
    _blue = _blue min 1 max 0;
    _alpha = _alpha min 1 max 0;

    private _ctrlGroup = ctrlParentControlsGroup _ctrlEdit;

    _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01 sliderSetPosition _red;
    _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 sliderSetPosition _green;
    _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05 sliderSetPosition _blue;
    _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07 sliderSetPosition _alpha;
    _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09 ctrlSetBackgroundColor
    [
        _red,
        _green,
        _blue,
        _alpha
    ];
};

true
