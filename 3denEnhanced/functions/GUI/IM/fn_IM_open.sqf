/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Initialises the GUI.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true / false
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
ENH_IM_ShowTemplates = nil;
ENH_IM_target = get3DENSelected "Object" select 0;

if (isNil "ENH_IM_target" || {ENH_IM_target isKindOf "CAManBase" || !(ENH_IM_target call ENH_fnc_hasStorage)}) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
  false
};

private _display = findDisplay IDD_3DEN createDisplay "ENH_InventoryManager";
uiNamespace setVariable ["Enh_Display_InventoryManager",_display];

if ((uiNamespace getVariable ["ENH_IM_allItems",[]]) isEqualTo []) then
{
  uiNamespace setVariable
  [
    "ENH_IM_Types",
    [
      "AssaultRifle",
      "MachineGun",
      "SniperRifle",
      "Shotgun",
      "SubmachineGun",
      "RocketLauncher",
      "Handgun",
      "Grenade",
      "Magazine",
      "Mine",
      "AccessoryBipod",
      "AccessoryMuzzle",
      "AccessoryPointer",
      "AccessorySights",
      "Uniform",
      "Vest",
      "Backpack",
      "Headgear",
      "Glasses",
      "NVGoggles",
      "Item"
    ]
  ];

  #define CONDITION "getNumber (_x >> 'scope') == 2 && getText (_x >> 'picture') != '' && getText (_x >> 'model') != ''"

  private _cfgWeapons = CONDITION configClasses (configfile >> "CfgWeapons");
  private _cfgMagazines = CONDITION configClasses (configFile >> "CfgMagazines");
  private _cfgGlasses = CONDITION configClasses (configFile >> "CfgGlasses");
  private _cfgVehicles = CONDITION configClasses (configFile >> "CfgVehicles");

  private _allItemConfigs = _cfgWeapons + _cfgMagazines + _cfgGlasses + _cfgVehicles;
  private _allItemsConfigsCount = count _allItemsConfig;

  private _itemsCache = [];
  private _addons = [];
  private _blacklist = ["","Unknown","UnknownEquipment","UnknownWeapon","VehicleWeapon"];

  {
    private _configName = configName _x;
    (_configName call BIS_fnc_itemType) params ["_category","_specificType"];
    if (!(_category in _blacklist || _specificType in _blackList) && {if (isArray (_x >> "muzzles")) then {_configName call BIS_fnc_baseWeapon == _configName} else {true}}) then
    {
      //Modify some _specificTypes
      if (_specificType == "MissileLauncher") then {_specificType = "RocketLauncher"};//Same type for all launchers
      if (_specificType in ["Throw","SmokeShell","Flare"]) then {_specificType = "Grenade"};//Same type for all grenades, flares, chemlights, smoke
      if (_specificType == "AccessoryBipod" && (_configName isKindOf ["CBA_MiscItem",configFile >> "CfgWeapons"])) then {_specificType = "Item"};

      //Get the DLC, make sure it's a DLC and was not modified by a mod only (CBA,ACE)
      private _dlc = "";
      if (count configSourceAddonList _x > 0) then
      {
        private _mods = configsourcemodlist (configfile >> "CfgPatches" >> configSourceAddonList _x # 0);
        if (count _mods > 0) then
        {
          _dlc = _mods # 0;
        };
      };

      private _addonName = "";
      private _addonIcon = "";
      if (_dlc != "") then //To prevent "ModParams - Undefined or empty mod directory" rpt spam
      {
        _addonName = modParams [_dlc,["name"]] # 0;
        _addonIcon = modParams [_dlc,["logoSmall"]] # 0;
        //Get all addons so they can be added to filter later
        _addons pushBackUnique [_dlc,_addonName,_addonIcon];
      };

      _itemsCache pushBack
      [
        _configName,
        getText (_x >> "DisplayName"),
        getText(_x >> "Picture"),
        _addonIcon,
        _category,
        _specificType,
        _dlc,
        _addonName
      ];
    };
  } forEach _allItemConfigs;
  uiNamespace setVariable ["ENH_IM_allItems",_itemsCache];
  uiNamespace setVariable ["ENH_IM_allAddons",_addons];
};

//Get all addons and add them to filter control
{
  _x params ["_addonClass","_addonName","_addonIcon"];
  [CTRL(IDC_IM_FILTERSEARCH),_addonName,_addonClass,"",_addonIcon] call ENH_fnc_IM_lbAdd;
} forEach (uiNamespace getVariable "ENH_IM_allAddons");

[CTRL(IDC_IM_FILTER),0] call ENH_fnc_IM_filterList;
call ENH_fnc_IM_loadAttributeValue;

//Add background icon
private _icon = getText (configFile >> "CfgVehicles" >> typeOf ENH_IM_target >> "icon");

//Stupid workaround because some vehicles / crates don't have the icon texture in their config...
if !(".paa" in _icon) then
{
  _icon = getText (configfile >> "CfgVehicleIcons" >> _icon);
};
CTRL(IDC_IM_BACKGROUNDICON) ctrlSetText _icon;

{
  CTRL(_x) ctrlEnable false;
} forEach [IDC_IM_CREATETEMPLATE,IDC_IM_DELETETEMPLATE,IDC_IM_APPLYTEMPLATE];

true