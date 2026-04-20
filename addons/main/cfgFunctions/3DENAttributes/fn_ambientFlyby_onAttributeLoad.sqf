#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the ambient flyby attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params
[
    "_classes",
    "_startPos",
    "_endPos",
    "_alt",
    "_speed",
    "_side",
    "_delay",
    ["_rndStartOffset", 0], // Default value for backwards compatibility
    ["_rndEndOffset", 0] // Default value for backwards compatibility
];

// Was stored as string in older versions
if (_classes isEqualType "") then
{
    _classes = call compile _classes;
};

[_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15, _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_16] call ENH_fnc_initSearchControls;

private _ctrlClassesTree = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17;

// Cache stuff
if (uiNamespace getVariable ["ENH_AmbientFlyby_AirClasses", []] isEqualTo []) then
{
    private _vehicleClasses = "getNumber (_x >> 'scope') == 2 && {configName _x isKindOf ['Air', configFile >> 'CfgVehicles']}" configClasses (configFile >> "CfgVehicles");

    private _data = [];

    _vehicleClasses apply
    {
        _data pushBack
        [
            configName _x,
            [_x] call BIS_fnc_displayName,
            getText (_x >> "icon"),
            [[getNumber (_x >> "side")] call BIS_fnc_sideType] call BIS_fnc_sideColor
        ];
    };

    uiNamespace setVariable ["ENH_AmbientFlyby_AirClasses", _data]
};

(uiNamespace getVariable ["ENH_AmbientFlyby_AirClasses", []]) apply
{
    _x params ["_configName", "_displayName", "_icon", "_sideColor"];

    private _isSelected = _configName in _classes;

    private _index = _ctrlClassesTree tvAdd [[], _displayName];
    _ctrlClassesTree tvSetTooltip [[_index], _configName];
    _ctrlClassesTree tvSetData [[_index], _configName];
    _ctrlClassesTree tvSetPictureRight [[_index], [TEXTURE_UNCHECKED,  TEXTURE_CHECKED] select _isSelected];
    _ctrlClassesTree tvSetValue [[_index], parseNumber _isSelected];
    _ctrlClassesTree tvSetPicture [[_index], _icon];
    _ctrlClassesTree tvSetPictureColor [[_index], _sideColor];
};

_ctrlClassesTree tvSortByValue [[], false];

_ctrlClassesTree ctrlAddEventHandler ["TreeSelChanged",
{
    params ["_ctrlClassesTree", "_path"];

    private _newValue = 1 - (_ctrlClassesTree tvValue _path);

    // Flip int
    _ctrlClassesTree tvSetValue [_path, _newValue];
    _ctrlClassesTree tvSetPictureRight [_path, [TEXTURE_UNCHECKED,  TEXTURE_CHECKED] select _newValue];
}];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText str (_startPos#0);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText str (_startPos#1);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText str (_startPos#2);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText str (_rndStartOffset);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText str (_endPos#0);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText str (_endPos#1);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText str (_endPos#2);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08) ctrlSetText str (_rndEndOffset);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09) ctrlSetText str _alt;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10) lbSetCurSel (["limited", "normal", "full"] find _speed);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11) lbSetCurSel ([west, east, independent, civilian] find _side);

// Backwards compatibility
if (_delay isEqualType 0) then {_delay = [_delay, _delay, _delay]};

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12) ctrlSetText str (_delay#0);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13) ctrlSetText str (_delay#1);
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14) ctrlSetText str (_delay#2);

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15) ctrlAddEventHandler ["ButtonClick",
{
    private _array = call ENH_fnc_array3FromClipboard;

    if (_array isNotEqualTo []) then
    {
        private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText str (_array#0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText str (_array#1);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText str (_array#2);
    };
}];

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_16) ctrlAddEventHandler ["ButtonClick",
{
    private _array = call ENH_fnc_array3FromClipboard;

    if (_array isNotEqualTo []) then
    {
        private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText str (_array#0);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText str (_array#1);
        (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText str (_array#2);
    };
}];

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    // Reset filter
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_15) ctrlSetText "";

    private _ctrlClassesTree = (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_17);

    // Delay the reset. The engine needs a moment to reset the filtered list
    _ctrlClassesTree spawn
    {
        params ["_ctrlClassesTree"];

        sleep 0.05;

        for "_i" from 0 to (_ctrlClassesTree tvCount []) - 1 do
        {
            if (_ctrlClassesTree tvValue [_i] > 0) then
            {
                _ctrlClassesTree tvSetValue [[_i], 0];
                _ctrlClassesTree tvSetPictureRight [[_i], TEXTURE_UNCHECKED];
            };
        };
    };

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) ctrlSetText "0";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) ctrlSetText "0";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_05) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_06) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_07) ctrlSetText "0";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_08) ctrlSetText "0";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_09) ctrlSetText "500";

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_10) lbSetCurSel 1;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_11) lbSetCurSel 0;

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_12) ctrlSetText "300";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_13) ctrlSetText "300";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_14) ctrlSetText "300";
}];
