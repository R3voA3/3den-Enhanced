#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Used by the marker color attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    BOOLEAN: true
*/

params ["_ctrlGroup", "_value"];

// Exit onLoad code if only one marker is selected
if (_value isEqualType configNull && {count get3DENSelected "Marker" == 1}) exitWith {};

// If config is provided then we are in the onLoad code and need update the variables
if (_value isEqualType configNull) then
{
    _ctrlGroup = ctrlParentControlsGroup _ctrlGroup;
    _value = [false, "#(1,1,1)"];
};

_value params ["_enabled", "_colorString"];
private _colorRGB = _colorString splitString ",#()" apply {parseNumber _x};

_ctrlGroup setVariable
[
    "fnc_toggleControlState",
    {
        params ["_ctrlGroup", "_enabled"];

        for "_idc" from IDC_ATTRIBUTE_CONTROL_01 to IDC_ATTRIBUTE_CONTROL_08 do
        {
            _ctrlGroup controlsGroupCtrl _idc ctrlEnable _enabled;
        };

        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetFade ([0.5, 0] select _enabled);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlCommit 0;
    }
];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) ctrlAddEventHandler ["CheckedChanged",
{
    params ["_ctrlCheckbox", "_state"];

    private _ctrlGroup = ctrlParentControlsGroup _ctrlCheckbox;

    [_ctrlGroup, [false, true] select _state] call (_ctrlGroup getVariable "fnc_toggleControlState");
}];

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02), "%", _colorRGB#0] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04), "%", _colorRGB#1] call BIS_fnc_initSliderValue;

[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06), "%"] call BIS_fnc_initSliderValue;
[(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05), (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06), "%", _colorRGB#2] call BIS_fnc_initSliderValue;

// Add event handler for updating the preview
#define UPDATE_PREVIEW private _ctrlGroup = ctrlParentControlsGroup (_this select 0);\
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetBackgroundColor\
[\
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01),\
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03),\
    sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05),\
    1\
];\
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08) lbSetCurSel 0;\

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlAddEventHandler ["SliderPosChanged", {UPDATE_PREVIEW}];
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlAddEventHandler ["SliderPosChanged", {UPDATE_PREVIEW}];
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlAddEventHandler ["SliderPosChanged", {UPDATE_PREVIEW}];

// Apply saved value
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) cbSetChecked _enabled;

[_ctrlGroup, _enabled] call (_ctrlGroup getVariable "fnc_toggleControlState");

// Update the preview
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetBackgroundColor (_colorRGB + [1]);

private _ctrlComboHistory = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08;
lbClear _ctrlComboHistory;

_ctrlComboHistory lbAdd "Custom Color";

// Add history
{
    _y params ["_r", "_g", "_b"];

    _ctrlComboHistory lbAdd format
    [
        "#(%1,%2,%3)",
        _r,
        _g,
        _b
    ];

    _ctrlComboHistory lbSetData [_forEachIndex + 1, _x];
    _ctrlComboHistory lbSetPicture [_forEachIndex + 1, format ["#(rgb,1,1,1)color(%1,%2,%3,1)", _r, _g, _b]];
    _ctrlComboHistory lbSetPictureColor [_forEachIndex+ 1, [_r, _g, _b, 1]];

    if (hashValue _colorRGB == _x) then {_ctrlComboHistory lbSetCurSel _forEachIndex + 1} else {_ctrlComboHistory lbSetCurSel 0};

} forEach (profileNamespace getVariable ["ENH_Attributes_MarkerColor_History", createHashMap]);

_ctrlComboHistory ctrlAddEventHandler ["LBSelChanged",
{
    params ["_ctrlCombo", "_index"];

    if (_index == 0) exitWith {};

    private _hash = _ctrlCombo lbData _index;
    private _colorRGB = (profileNamespace getVariable ["ENH_Attributes_MarkerColor_History", createHashMap]) get _hash;

    // Update sliders
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01 sliderSetPosition _colorRGB#0;
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03 sliderSetPosition _colorRGB#1;
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl 1IDC_ATTRIBUTE_CONTROL_05 sliderSetPosition _colorRGB#2;

    // Update edit controls
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02 ctrlSetText format ["%1%2", _colorRGB#0 * 100, "%"];
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04 ctrlSetText format ["%1%2", _colorRGB#1 * 100, "%"];
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06 ctrlSetText format ["%1%2", _colorRGB#2 * 100, "%"];

    // Update preview
    ctrlParentControlsGroup _ctrlCombo controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07 ctrlSetBackgroundColor [_colorRGB#0, _colorRGB#1, _colorRGB#2, 1];
}];
