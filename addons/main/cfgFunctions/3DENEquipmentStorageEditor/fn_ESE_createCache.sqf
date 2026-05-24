#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-01-24

    Description:
    Gets all items available for unit and vehicle loadouts and saves them in the uiNamespace variables ENH_ESE_allItems.
    See _items array for the format.
    Furthermore, it stores all addons in the uiNamespace variable ENH_ESE_allAddons.

    Parameter(s):
    -

    Returns:
    -
*/

private _specialItems =
[
    [
        "Antibiotic",
        [
            getText (configFile >> "CfgMagazines" >> "Antibiotic" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Antibiotic_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Antimalaricum",
        [
            getText (configFile >> "CfgMagazines" >> "Antimalaricum" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Antimalaricum_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "AntimalaricumVaccine",
        [
            getText (configFile >> "CfgMagazines" >> "AntimalaricumVaccine" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\AntimalaricumVaccine_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Bandage",
        [
            getText (configFile >> "CfgMagazines" >> "Bandage" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Bandage_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Files",
        [
            getText (configFile >> "CfgMagazines" >> "Files" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Files_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Files_diary",
        [
            getText (configFile >> "CfgMagazines" >> "Files_diary" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Files_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Files_researchNotes",
        [
            getText (configFile >> "CfgMagazines" >> "Files_researchNotes" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Files_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "FileTopSecret",
        [
            getText (configFile >> "CfgMagazines" >> "FileTopSecret" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\FileTopSecret_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "FileNetworkStructure",
        [
            getText (configFile >> "CfgMagazines" >> "FileNetworkStructure" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\FileNetworkStructure_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "FilesSecret",
        [
            getText (configFile >> "CfgMagazines" >> "FilesSecret" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\FilesSecret_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "DocumentsSecret",
        [
            getText (configFile >> "CfgMagazines" >> "DocumentsSecret" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\DocumentsSecret_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Wallet_ID",
        [
            getText (configFile >> "CfgMagazines" >> "Wallet_ID" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Wallet_ID_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Keys",
        [
            getText (configFile >> "CfgMagazines" >> "Keys" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Keys_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Csat_Id_01",
        [
            getText (configFile >> "CfgMagazines" >> "Csat_Id_01" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Csat_Id_01_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Csat_Id_02",
        [
            getText (configFile >> "CfgMagazines" >> "Csat_Id_02" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Csat_Id_02_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Csat_Id_03",
        [
            getText (configFile >> "CfgMagazines" >> "Csat_Id_03" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Csat_Id_03_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Csat_Id_04",
        [
            getText (configFile >> "CfgMagazines" >> "Csat_Id_04" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Csat_Id_04_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Csat_Id_05",
        [
            getText (configFile >> "CfgMagazines" >> "Csat_Id_05" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Csat_Id_05_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Laptop_Unfolded",
        [
            getText (configFile >> "CfgMagazines" >> "Laptop_Unfolded" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Laptop_Unfolded_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Laptop_Closed",
        [
            getText (configFile >> "CfgMagazines" >> "Laptop_Closed" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Laptop_Closed_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "SatPhone",
        [
            getText (configFile >> "CfgMagazines" >> "SatPhone" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\SatPhone_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "MobilePhone",
        [
            getText (configFile >> "CfgMagazines" >> "MobilePhone" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\MobilePhone_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "SmartPhone",
        [
            getText (configFile >> "CfgMagazines" >> "SmartPhone" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\SmartPhone_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "FlashDisk",
        [
            getText (configFile >> "CfgMagazines" >> "FlashDisk" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\FlashDisk_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "ButaneCanister",
        [
            getText (configFile >> "CfgMagazines" >> "ButaneCanister" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\ButaneCanister_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Money",
        [
            getText (configFile >> "CfgMagazines" >> "Money" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Money_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Money_bunch",
        [
            getText (configFile >> "CfgMagazines" >> "Money_bunch" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Money_bunch_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Money_roll",
        [
            getText (configFile >> "CfgMagazines" >> "Money_roll" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Money_roll_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Money_stack",
        [
            getText (configFile >> "CfgMagazines" >> "Money_stack" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Money_stack_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Money_stack_quest",
        [
            getText (configFile >> "CfgMagazines" >> "Money_stack_quest" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Money_stack_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ],
    [
        "Sleeping_bag_folded_01",
        [
            getText (configFile >> "CfgMagazines" >> "Sleeping_bag_folded_01" >> "displayName"),
            "\a3\Missions_F_OldMan\Props\data\Sleeping_bag_folded_01_ca.paa",
            "expansion",
            "a3\data_f_exp\logos\arma3_exp_logo_small_ca.paa",
            "Item",
            "Map",
            ""
        ]
    ]
];

#define CONDITION "getNumber (_x >> 'scope') >= 2 && getText (_x >> 'picture') != '' && getText (_x >> 'model') != ''"

if (uiNamespace getVariable ["ENH_ESE_itemsHashMap", []] isNotEqualTo []) exitWith {};

private _allItemConfigs = (CONDITION configClasses (configFile >> "CfgWeapons")) +
                          (CONDITION configClasses (configFile >> "CfgMagazines")) +
                          (CONDITION configClasses (configFile >> "CfgGlasses")) +
                          (CONDITION configClasses (configFile >> "CfgVehicles"));

private _allItemsData = [_allItemConfigs] call ENH_fnc_ESE_getConfigValues;

// Insert items that are hidden by BI but still useful
_allItemsData insert _specialItems;

uiNamespace setVariable ["ENH_ESE_itemsHashMap", _allItemsData];

// Cache all addons that add equipment
// Default addon for filtering
private _addons = [["", localize "$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT", ""]];

"getArray (_x >> 'weapons') isNotEqualTo []" configClasses (configFile >> "CfgPatches") apply
{
    private _addonData = _x call ENH_fnc_getConfigSourceAddon;
    if (_addonData isNotEqualTo []) then
    {
        _addons pushBackUnique _addonData;
    }
};

uiNamespace setVariable
[
    "ENH_ESE_allAddons",
    _addons
];
