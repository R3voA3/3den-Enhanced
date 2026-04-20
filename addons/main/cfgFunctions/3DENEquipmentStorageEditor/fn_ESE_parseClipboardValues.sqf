#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: Pixelated_Grunt

    Date: 2024-08-20

    Description:
    Used by the ENH_ESE GUI. Read and convert array from clipboard to inventory attributes.

    Parameter(s):
    BOOL - true to return variable only. Default is false.

    Returns:
    ARRAY - Result attributes that can be loaded into the filter and inventory screens. Return all items if failed.
*/

params [["_return", false, [false]]];

private _importList = call compile copyFromClipboard;

// Verify import list is in correct format
if !(_importList isEqualType [] && _importList isEqualTypeAll "") exitWith
{
    playSound ["3DEN_notificationWarning", true];
    (ENH_ESE_target get3DENAttribute "ammoBox") # 0
};

private _configs = _importList apply
{
    if (isClass(configFile >> "CfgWeapons" >> _x)) then
    {
        configFile >> "CfgWeapons" >> _x
    }
    else
    {
        if (isClass(configFile >> "CfgMagazines" >> _x)) then
        {
            configFile >> "CfgMagazines" >> _x
        }
        else
        {
            if (isClass(configFile >> "CfgGlasses" >> _x)) then
            {
                configFile >> "CfgGlasses" >> _x
            }
            else
            {
                if (isClass(configFile >> "CfgVehicles" >> _x)) then
                {
                    configFile >> "CfgVehicles" >> _x
                }
            }
        }
    }
};

private _attributeValue = ([_configs] call ENH_fnc_ESE_getConfigValues) select 1;
if _return exitWith {_attributeValue};
[true, _attributeValue] call ENH_fnc_ESE_applyAttribute;
