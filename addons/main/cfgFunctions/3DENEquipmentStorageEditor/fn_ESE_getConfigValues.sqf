#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: Pixelated_Grunt

    Date: 2024-08-20

    Description:
    Return all items configuration details.

    Parameter(s):
    ARRAY - An array of class names or configs to get details for.

    Returns:
    ARRAY - ARRAY of whitelisted items, HASHMAP of items with details, ARRAY of available addons
*/

#define TYPES_WHITELIST ["AssaultRifle", "MachineGun", "SniperRifle", "Shotgun", "SubmachineGun", "RocketLauncher", "Handgun", "Grenade", "Magazine",\
"Mine", "AccessoryBipod", "AccessoryMuzzle", "AccessoryPointer", "AccessorySights", "Uniform", "Vest", "Backpack", "Headgear", "Glasses", "NVGoggles", "Item", "MissileLauncher"]

params [["_input", [], []]];

private _addons = [["", localize "$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT", ""]];// Everything
private _itemsHashMap = createHashMap;

_input apply
{
    private _class = configName _x;

    (_class call BIS_fnc_itemType) params ["_category", "_specificType"];

    if ((_category in TYPES_WHITELIST || _specificType in TYPES_WHITELIST && _specificType != "UnknownEquipment") && {if (isArray (_x >> "muzzles")) then {_class call BIS_fnc_baseWeapon == _class} else {true}}) then
    {
        // Modify some _specificTypes

        // Same type for all launchers
        if (_specificType == "MissileLauncher") then {_specificType = "RocketLauncher"};

        // Same type for all grenades, flares, chemlights, smoke
        if (_specificType in ["Throw", "SmokeShell", "Flare"]) then {_specificType = "Grenade"};

        if (_specificType == "AccessoryBipod" && {_class isKindOf ["CBA_MiscItem", configFile >> "CfgWeapons"]}) then {_specificType = "Item"};

        // Get the DLC, make sure it's a DLC and was not modified by a mod (CBA, ACE)
        (_x call ENH_fnc_getConfigSourceAddon) params [["_addonClass", ""], ["_addonName", ""], ["_addonIcon", ""]];
        _addons pushBackUnique [_addonClass, _addonName, _addonIcon];

        _itemsHashMap set
        [
            toLower _class,
            [
                getText (_x >> "DisplayName"),
                getText (_x >> "Picture"),
                _addonClass,
                _addonIcon,
                _category,
                _specificType,
                getText (_x >> "descriptionShort") regexReplace ["<br[\W ]*\/>", "\n"],
                _class // Properly cased configName for displaying
            ]
        ]
    }
};

[TYPES_WHITELIST, _itemsHashMap, _addons]
