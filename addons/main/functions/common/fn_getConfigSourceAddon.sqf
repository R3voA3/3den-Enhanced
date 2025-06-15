#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-05-15

    Description:
    Returns addon name and image of given config.

    Parameter(s):
    0: CONFIG - Config to be checked

    Returns:
    ARRAY: Array in format:
        0: STRING - Addon class
        1: STRING - Addon name
        2: STRING - Addon image/icon
    In case of not addon (vanilla) an empty array is returned
*/

params [["_config", configNull]];

// Get the DLC, make sure it's a DLC and was not modified by a mod (CBA, ACE)
private _addonClass = "";
private _sourceConfigs = configSourceAddonList _config;

// Exit if there are no source addons
if (_sourceConfigs isEqualTo []) exitWith {[]};

private _mods = configSourceModList (configFile >> "CfgPatches" >> _sourceConfigs # 0);

// Exit if there are no mods
if (_mods isEqualTo []) exitWith {[]};

_addonClass = _mods # 0;

// Exit if class name is empty (Vanilla Arma 3)
if (_addonClass == "") exitWith {[]};

// Return class, name and image of the addon
[_addonClass, modParams [_addonClass, ["name"]] # 0, modParams [_addonClass, ["logoSmall"]] # 0]
