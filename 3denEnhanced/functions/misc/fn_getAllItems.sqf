/*
  Author: R3vo

  Date: 2021-01-24

  Description:
  Gets all items available for unit and vehicle loadouts and saves them int he uiNamespace avariables ENH_IM_allItems. See _items array in the for the format.
  Furthermore, it stores all addons in the uiNamespace variable ENH_IM_allAddons.

  Parameter(s):
  -

  Returns:
  -
*/

#define ITEM_TYPES_WHITELIST ["AssaultRifle", "MachineGun", "SniperRifle", "Shotgun", "SubmachineGun", "RocketLauncher", "Handgun", "Grenade", "Magazine",\
"Mine", "AccessoryBipod", "AccessoryMuzzle", "AccessoryPointer", "AccessorySights", "Uniform", "Vest", "Backpack", "Headgear", "Glasses", "NVGoggles", "Item"]

#define CONDITION "getNumber (_x >> 'scope') == 2 && getText (_x >> 'picture') != '' && getText (_x >> 'model') != ''"

if (uiNamespace getVariable ["ENH_IM_allItems", []] isNotEqualTo []) exitWith {};

private _addons = [];
private _items = [];

private _allItemConfigs = (CONDITION configClasses (configfile >> "CfgWeapons")) + (CONDITION configClasses (configFile >> "CfgMagazines")) +
                          (CONDITION configClasses (configFile >> "CfgGlasses")) + (CONDITION configClasses (configFile >> "CfgVehicles"));

{
  private _configName = configName _x;
  (_configName call BIS_fnc_itemType) params ["_category", "_specificType"];
  if ((_category in ITEM_TYPES_WHITELIST || _specificType in ITEM_TYPES_WHITELIST) && {if (isArray (_x >> "muzzles")) then {_configName call BIS_fnc_baseWeapon == _configName} else {true}}) then
  {
    //Modify some _specificTypes
    if (_specificType == "MissileLauncher") then {_specificType = "RocketLauncher"};//Same type for all launchers
    if (_specificType in ["Throw", "SmokeShell", "Flare"]) then {_specificType = "Grenade"};//Same type for all grenades, flares, chemlights, smoke
    if (_specificType == "AccessoryBipod" && (_configName isKindOf ["CBA_MiscItem", configFile >> "CfgWeapons"])) then {_specificType = "Item"};

    //Get the DLC, make sure it's a DLC and was not modified by a mod (CBA, ACE)
    private _addonClass = "";
    if (count configSourceAddonList _x > 0) then
    {
      private _mods = configsourcemodlist (configfile >> "CfgPatches" >> configSourceAddonList _x # 0);
      if (count _mods > 0) then
      {
        _addonClass = _mods # 0;
      };
    };

    //Get all addons so they can be added to filter later
    private _addonName = "";
    private _addonIcon = "";
    if (_addonClass != "") then //To prevent "ModParams - Undefined or empty mod directory" rpt spam
    {
      _addonName = modParams [_addonClass, ["name"]] # 0;
      _addonIcon = modParams [_addonClass, ["logoSmall"]] # 0;
      _addons pushBackUnique [_addonClass, _addonName, _addonIcon];
    };
    _items append [[_configName, getText (_x >> "DisplayName"), getText(_x >> "Picture"), _addonClass, _addonName, _addonIcon, _category, _specificType]];
  };
} forEach _allItemConfigs;

uiNamespace setVariable ["ENH_IM_types", ITEM_TYPES_WHITELIST];
uiNamespace setVariable ["ENH_IM_allItems", _items];
uiNamespace setVariable ["ENH_IM_allAddons", _addons];