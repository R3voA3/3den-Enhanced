#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-09-27

    Description:
    Gets raw data of module or sync entity.

    Parameter(s):
    0: CONFIG - Module config

    Return Value:
    HASHMAP - Information data
*/

params ["_cfgModule"];

private _data = createHashMap;
private _configName = configName _cfgModule;
private _cfgModuleBaseDescription = configFile >> "CfgVehicles" >> "Module_F" >> "ModuleDescription";

// Config name
_data set ["configName", _configName];

// DisplayName
private _displayName = [_cfgModule] call BIS_fnc_displayName;

if (_displayName == _configName) then
{
    _displayName = [configFile >> "CfgVehicles" >> configName _cfgModule] call BIS_fnc_displayName;
};

// Triggers somehow don't have a class or displayName
if (_displayName == "" && {"trigger" in toLower _configName}) then
{
    _displayName = localize "$STR_3DEN_TRIGGER_TEXTSINGULAR";
};

_data set ["displayName", _displayName];

// Description
// If we have a module we need to get the full description from main config
// Check if a class with that config name exists in cfg vehicles and if it inherits from module_f
// This one has a proper description then

private _cfgModuleDescription = _cfgModule;
if (isClass (configFile >> "CfgVehicles" >> _configName) && {"Module_F" in ([configFile >> "CfgVehicles" >> _configName, true] call BIS_fnc_returnParents)}) then
{
    _cfgModuleDescription = _cfgModule >> "ModuleDescription";
};

// Optional
private _optional = if (getNumber (_cfgModuleDescription >> "optional") > 0) then
{
    localize "$STR_A3_RSCDISPLAYARCADEMODULES_OPTIONAL";
}
else
{
    ""
};

_data set ["optional", _optional];

// Area
private _area = if (getNumber (_cfgModuleDescription >> "area") > 0) then
{
    localize "$STR_A3_CFGVEHICLES_LOCATIONAREA_F_0";
}
else
{
    ""
};

_data set ["area", _area];

// Duplicate
private _duplicate = if (getNumber (_cfgModuleDescription >> "duplicate") > 0) then
{
    getText (_cfgModuleBaseDescription >> "duplicateEnabled");
}
else
{
    getText(_cfgModuleBaseDescription >> "duplicateDisabled");
};

_data set ["duplicate", _duplicate];

// Position
private _position = if (getNumber (_cfgModuleDescription >> "position") > 0) then
{
    getText (_cfgModuleBaseDescription >> "positionEnabled");
}
else
{
    getText(_cfgModuleBaseDescription >> "positionDisabled");
};

_data set ["position", _position];

// Direction
private _direction = if (getNumber (_cfgModuleDescription >> "direction") > 0) then
{
    getText (_cfgModuleBaseDescription >> "directionEnabled");
}
else
{
    getText(_cfgModuleBaseDescription >> "directionDisabled");
};

_data set ["direction", _direction];

private _descriptionRaw = [_cfgModuleDescription >> "description", nil, 0] call BIS_fnc_returnConfigEntry;

private _description = "";
switch (true) do
{
    case (_descriptionRaw isEqualType ""): {_description = _descriptionRaw};
    case (_descriptionRaw isEqualType []):
    {
        {
            _description = _description + _x + LB_HTML
        } forEach _descriptionRaw;

        _description;
    };
    default {""};
};

_data set ["description", _description];

// Icon
_data set ["icon", _cfgModule call ENH_fnc_MI_getModuleIcon];

_data
