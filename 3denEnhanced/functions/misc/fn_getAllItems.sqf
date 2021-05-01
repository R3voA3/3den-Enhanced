/*
  Author: R3vo

  Date: 2021-01-24

  Description:
  Gets all items available for unit and vehicle loadouts and saves them int he uiNamespace avariables ENH_VIM_allItems. See _items array in the for the format.
  Furthermore, it stores all addons in the uiNamespace variable ENH_VIM_allAddons.

  Parameter(s):
  -

  Returns:
  -
*/

#define ITEM_TYPES_WHITELIST ["AssaultRifle", "MachineGun", "SniperRifle", "Shotgun", "SubmachineGun", "RocketLauncher", "Handgun", "Grenade", "Magazine",\
"Mine", "AccessoryBipod", "AccessoryMuzzle", "AccessoryPointer", "AccessorySights", "Uniform", "Vest", "Backpack", "Headgear", "Glasses", "NVGoggles", "Item"]

#define SPECIAL_ITEMS [["Antibiotic", "Antibiotics", "\a3\Missions_F_Oldman\Props\data\Antibiotic_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Antimalaricum", "Antimalarial Pills", "\a3\Missions_F_Oldman\Props\data\Antimalaricum_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["AntimalaricumVaccine", "Atrox Counteragent", "\a3\Missions_F_Oldman\Props\data\AntimalaricumVaccine_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Bandage", "Bandages", "\a3\Missions_F_Oldman\Props\data\Bandage_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Files", "Files", "\a3\Missions_F_Oldman\Props\data\Files_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Files_diary", "Journal", "\a3\Missions_F_Oldman\Props\data\Files_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Files_researchNotes", "Research Notes", "\a3\Missions_F_Oldman\Props\data\Files_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["FileTopSecret", "File (Top Secret)", "\a3\Missions_F_Oldman\Props\data\FileTopSecret_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["FileNetworkStructure", "Network Structure Plans", "\a3\Missions_F_Oldman\Props\data\FileNetworkStructure_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["FilesSecret", "File (Top Secret)", "\a3\Missions_F_Oldman\Props\data\FilesSecret_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["DocumentsSecret", "File", "\a3\Missions_F_Oldman\Props\data\DocumentsSecret_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Wallet_ID", "Wallet (ID)", "\a3\Missions_F_Oldman\Props\data\Wallet_ID_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Keys", "Keys", "\a3\Missions_F_Oldman\Props\data\Keys_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Csat_Id_01", "Access Card (v1) [CSAT]", "\a3\Missions_F_Oldman\Props\data\Csat_Id_01_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Csat_Id_02", "Access Card (v2) [CSAT]", "\a3\Missions_F_Oldman\Props\data\Csat_Id_02_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Csat_Id_03", "Access Card (v3) [CSAT]", "\a3\Missions_F_Oldman\Props\data\Csat_Id_03_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Csat_Id_04", "Access Card (v4) [CSAT]", "\a3\Missions_F_Oldman\Props\data\Csat_Id_04_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Csat_Id_05", "Access Card (v5) [CSAT]", "\a3\Missions_F_Oldman\Props\data\Csat_Id_05_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Laptop_Unfolded", "Laptop (Open)", "\a3\Missions_F_Oldman\Props\data\Laptop_Unfolded_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Laptop_Closed", "Laptop (Closed)", "\a3\Missions_F_Oldman\Props\data\Laptop_Closed_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["SatPhone", "Satellite Phone", "\a3\Missions_F_Oldman\Props\data\SatPhone_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["MobilePhone", "Mobile Phone (Old)", "\a3\Missions_F_Oldman\Props\data\MobilePhone_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["SmartPhone", "Mobile Phone (New)", "\a3\Missions_F_Oldman\Props\data\SmartPhone_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["FlashDisk", "Flash Drive", "\a3\Missions_F_Oldman\Props\data\FlashDisk_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["ButaneCanister", "Butane Canister (Full)", "\a3\Missions_F_Oldman\Props\data\ButaneCanister_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Money", "Money", "\a3\Missions_F_Oldman\Props\data\Money_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Money_bunch", "Money (Notes)", "\a3\Missions_F_Oldman\Props\data\Money_bunch_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Money_roll", "Money (Roll)", "\a3\Missions_F_Oldman\Props\data\Money_roll_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Money_stack", "Money (Stack)", "\a3\Missions_F_Oldman\Props\data\Money_stack_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Money_stack_quest", "Money (Large Stack)", "\a3\Missions_F_Oldman\Props\data\Money_stack_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"], ["Sleeping_bag_folded_01", "Sleeping Bag (Folded)", "\a3\Missions_F_Oldman\Props\data\Sleeping_bag_folded_01_ca.paa", "expansion", "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa", "Item", "Map"]]

#define CONDITION "getNumber (_x >> 'scope') == 2 && getText (_x >> 'picture') != '' && getText (_x >> 'model') != ''"

if (uiNamespace getVariable ["ENH_VIM_allItems", []] isNotEqualTo []) exitWith {};

private _addons = [["", localize "$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT", ""]];//Everything
private _items = [];

private _itemsHashMap = createHashMap;

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
    _items append [[_configName, getText (_x >> "DisplayName"), getText (_x >> "Picture"), _addonClass, _addonIcon, _category, _specificType]];

    _itemsHashMap insert [[_configName, [getText (_x >> "DisplayName"), getText (_x >> "Picture"), _addonClass, _addonIcon, _category, _specificType]]];
  };
} forEach _allItemConfigs;

uiNamespace setVariable ["ENH_VIM_types", ITEM_TYPES_WHITELIST];
uiNamespace setVariable ["ENH_VIM_allItemsHashMap", _itemsHashMap];
uiNamespace setVariable ["ENH_VIM_allItems", _items + SPECIAL_ITEMS];
uiNamespace setVariable ["ENH_VIM_allAddons", _addons];