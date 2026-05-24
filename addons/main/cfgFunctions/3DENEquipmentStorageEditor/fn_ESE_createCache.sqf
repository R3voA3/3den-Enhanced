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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Antibiotic")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Antimalaricum")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "AntimalaricumVaccine")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Bandage")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Files")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Files_diary")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Files_researchNotes")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "FileTopSecret")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "FileNetworkStructure")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "FilesSecret")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "DocumentsSecret")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Wallet_ID")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Keys")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Csat_Id_01")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Csat_Id_02")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Csat_Id_03")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Csat_Id_04")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Csat_Id_05")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Laptop_Unfolded")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Laptop_Closed")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "SatPhone")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "MobilePhone")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "SmartPhone")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "FlashDisk")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "ButaneCanister")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Money")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Money_bunch")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Money_roll")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Money_stack")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Money_stack_quest")),
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
            localize (getTextRaw (configFile >> "CfgMagazines" >> "Sleeping_bag_folded_01")),
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

uiNamespace setVariable ["ENH_ESE_itemsHashMap", [_allItemConfigs] call ENH_fnc_ESE_getConfigValues];

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
