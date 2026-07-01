#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-04-07

    Description:
    Fills the tree view with all tracks from CfgMusic.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value, array with CfgMusic classes

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];

[_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_24, _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_25] call ENH_fnc_initSearchControls;

// Cache stuff
if (uiNamespace getVariable ["ENH_CfgMusic_Classes", []] isEqualTo []) then
{
    private _musicClasses = ("true" configClasses (configFile >> "CfgMusic")) + ("true" configClasses (missionConfigFile >> "CfgMusic"));

    private _data = [];
    private _defaultIcon = "#(rgb,32,32,3)color(1,1,1,0)"; // Texture to indent items without mod icon

    _musicClasses apply
    {
        private _sourceMod = configSourceMod _x;
        private _icon = "";

        if (_sourceMod != "") then
        {
            _icon = modParams [_sourceMod, ["logo"]] param [0, ""];
        };

        private _configName = configName _x;
        private _name = getText (_x >> "name");

        _data pushBack
        [
            _configName,
            [_name, _configName] select (_name == ""),
            [_icon, _defaultIcon] select (_icon == "")
        ];
    };

    uiNamespace setVariable ["ENH_CfgMusic_Classes", _data];
};

private _ctrlClassesTree = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;


(uiNamespace getVariable ["ENH_CfgMusic_Classes", []]) apply
{
    _x params ["_configName", "_name", "_icon"];

    private _isSelected = _configName in _value;

    private _index = _ctrlClassesTree tvAdd [[], _name];
    _ctrlClassesTree tvSetTooltip [[_index], _configName];
    _ctrlClassesTree tvSetData [[_index], _configName];
    _ctrlClassesTree tvSetPictureRight [[_index], [TEXTURE_UNCHECKED,  TEXTURE_CHECKED] select _isSelected];
    _ctrlClassesTree tvSetValue [[_index], parseNumber _isSelected];
    _ctrlClassesTree tvSetPicture [[_index], _icon];
};

_ctrlClassesTree tvSortAll [[], false];
_ctrlClassesTree tvSortByValue [[], false];

_ctrlClassesTree ctrlAddEventHandler ["TreeSelChanged",
{
    params ["_ctrlClassesTree", "_path"];

    private _newValue = 1 - (_ctrlClassesTree tvValue _path);

    // Flip int
    _ctrlClassesTree tvSetValue [_path, _newValue];
    _ctrlClassesTree tvSetPictureRight [_path, [TEXTURE_UNCHECKED,  TEXTURE_CHECKED] select _newValue];
}];

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_24) ctrlSetText "";

    private _ctrlClassesTree = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;

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
}];
