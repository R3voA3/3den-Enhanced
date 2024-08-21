/*
    Author: Pixelated_Grunt

    Date: 2024-08-20

    Description:
    Used by the ENH_ESE GUI. Read and convert array from clipboard to inventory attributes.

    Parameter(s):
    -

    Returns:
    ARRAY - Result attributes that can be loaded into the inventory screen. Return all if failed.
*/


#include "\3denEnhanced\defines\defineCommon.inc"
private _importList = call compile copyFromClipboard;

// Verify import list is in correct format
if (isNil "_importList" || {!(_importList isEqualType [])} || {!(_importList isEqualTypeAll "")}) exitWith {
    playSound ["3DEN_notificationWarning", true];
    (ENH_ESE_target get3DENAttribute "ammoBox") # 0
};

private _configs = _importList apply {
    if (isClass(configFile >> "CfgWeapons" >> _x)) then {
        configFile >> "CfgWeapons" >> _x
    } else {
        if (isClass(configFile >> "CfgMagazines" >> _x)) then {
            configFile >> "CfgMagazines" >> _x
        } else {
            if (isClass(configFile >> "CfgGlasses" >> _x)) then {
                configFile >> "CfgGlasses" >> _x
            } else {
                if (isClass(configFile >> "CfgVehicles" >> _x)) then {
                    configFile >> "CfgVehicles" >> _x
                }
            }
        }
    }
};

private _attributeValue = ([_configs] call ENH_fnc_ESE_getConfigValues) select 1;
[true, _attributeValue] call ENH_fnc_ESE_applyAttribute
