class ENH_ESE
{
    idd = IDD_ESE;
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_TOOLS_ESE";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(WINDOW_HAbs - 4 * CTRL_DEFAULT_H);
        };
        class BackgroundInventoryItemsList: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + (WINDOW_W_WIDE * 2/4) * GRID_W + 2 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W - 2 * GRID_W);
            h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H + GRID_H);
            colorBackground[] = {0, 0, 0, 0.3};
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
        class AvailableItems: ctrlStatic
        {
            idc = IDC_NONE;
            text = "$STR_ENH_MAIN_ESE_AVAILABLEITEMS";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            font = FONT_BOLD;
            sizeEx = QUOTE(4.86 * SIZEEX_BASE);
            style = ST_CENTER;
        };
        class CompatibleItems: AvailableItems
        {
            text = "$STR_ENH_MAIN_ESE_COMPATIBLE_ITEMS";
             x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + (WINDOW_W_WIDE * 1/4) * GRID_W + 2 * GRID_W);
             w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W - GRID_W);
        };
        class InventoryItems: AvailableItems
        {
            text = "$STR_ENH_MAIN_ESE_ITEMSININVENTORY";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + (WINDOW_W_WIDE * 2/4) * GRID_W + 2 * GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W - 2 * GRID_W);
        };
        class Templates: AvailableItems
        {
            text = "$STR_ENH_MAIN_ESE_TEMPLATES";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + (WINDOW_W_WIDE * 3/4) * GRID_W + GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W - 2 * GRID_W);
        };
    };
    class Controls
    {
        class MenuStrip: ctrlMenuStrip
        {
            idc = IDC_ESE_MENU;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            class Items
            {
                items[] =
                {
                    "FolderExport",
                    "FolderInventory",
                    "FolderFilter",
                    "FolderTemplates",
                    "FolderHelp"
                };
                class FolderExport
                {
                    text = "Export";
                    items[] = {"ExportToSQF", "ExportToACEArsenal", "ExportArsenal"};
                };
                class FolderInventory
                {
                    text = "Inventory";
                    items[] =
                    {
                        "IsVirtual",
                        "Separator",
                        "ResetInventory",
                        "Separator",
                        "AddOne",
                        "RemoveOne",
                        "RemoveAll",
                        "Separator",
                        "Arsenal",
                        "Separator",
                        "SortbyName",
                        "SortbyClass",
                        "SortbyCount",
                        "SortbyMod",
                        "SortbyType"
                    };
                };
                class FolderFilter
                {
                    text = "Filter";
                    items[] =
                    {
                        "ARs",
                        "MGs",
                        "Snipers",
                        "Shotguns",
                        "SMGs",
                        "Launchers",
                        "Pistols",
                        "Separator",
                        "Grenades",
                        "Magazines",
                        "Explosives",
                        "InventoryItems",
                        "Separator",
                        "Bipods",
                        "Supressors",
                        "Pointers",
                        "Scopes",
                        "Separator",
                        "Uniforms",
                        "Vests",
                        "Backpacks",
                        "Headgear",
                        "Goggles",
                        "NVGs"
                    };
                };
                class FolderHelp
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELP_TEXT";
                    items[] = {"Documentation"};
                };
               // Export
                class ExportToSQF
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_MISSIONEXPORTSQF_TEXT";
                    action = "'sqf' call ENH_fnc_ESE_export";
                    opensNewWindow = 1;
                };
                class ExportToACEArsenal: ExportToSQF
                {
                    text = "$STR_ENH_MAIN_ESE_EXPORTTOSACEARSENAL";
                    action = "'ace' call ENH_fnc_ESE_export";
                };
                class ExportArsenal: ExportToSQF
                {
                    text = "$STR_ENH_MAIN_ESE_EXPORTTOARSENAL";
                    action = "'arsenal' call ENH_fnc_ESE_export";
                };
                class FolderTemplates
                {
                    text = "$STR_ENH_MAIN_ESE_TEMPLATES";
                    items[] = {"CreateTemplate", "DeleteTemplate", "Separator", "PreviewTemplate"};
                };
               // Templates
                class CreateTemplate
                {
                    text = "$STR_ENH_MAIN_ESE_CREATETEMPLATE";
                    action = "'create' call ENH_fnc_ESE_handleTemplates";
                    opensNewWindow = 1;
                };
                class DeleteTemplate
                {
                    text = "$STR_3DEN_DISPLAY3DEN_ENTITYMENU_DELETE_TEXT";
                    action = "'delete' call ENH_fnc_ESE_handleTemplates";
                    shortcuts[] = {DIK_DELETE};
                };
                class PreviewTemplate
                {
                    text = "$STR_3DEN_TUTORIALS_SCENARIO_SECTIONS_PREVIEW_TEXT";
                    action = "'preview' call ENH_fnc_ESE_handleTemplates";
                };
               // Help
                class Documentation
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
                    picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
                    weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#equipment-storage-editor";
                    opensNewWindow = 1;
                };
               // Inventory
                class IsVirtual
                {
                    text = "$STR_3DEN_ATTRIBUTES_AMMOBOX_TYPE_VIRTUAL";
                    picture = "\x\enh\addons\main\data\infinity_ca.paa";
                    action = "-1 call ENH_fnc_ESE_toggleVirtual";
                };
                class ResetInventory
                {
                    text = "$STR_3DEN_DISPLAY3DEN_ENTITYMENU_ARSENALRESET_TEXT";
                    picture = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
                    action = "call ENH_fnc_ESE_resetStorage";
                };
                class AddOne
                {
                    text = "+1";
                    picture = "\x\enh\addons\main\data\plus_ca.paa";
                    action = "1 call ENH_fnc_ESE_addItem";
                    shortcuts[] = {DIK_RIGHTARROW};
                };
                class RemoveOne
                {
                    text = "-1";
                    picture = "\x\enh\addons\main\data\minus_ca.paa";
                    action = "1 call ENH_fnc_ESE_removeItem";
                    shortcuts[] = {DIK_LEFTARROW};
                };
                class RemoveAll
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_DEFAULT_TEXT";
                    picture = "\a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
                    action = "call ENH_fnc_ESE_clearInventory";
                    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_LEFTARROW};
                };
                class Arsenal
                {
                    text = "$STR_A3_RSCDISPLAYMAIN_BUTTONVIRTUALARSENAL";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacearsenal_ca.paa";
                    action = "call ENH_fnc_ESE_fullArsenal";
                    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_A};
                };
                class SortbyName
                {
                    text = "$STR_ENH_MAIN_ESE_SORTBYNAME";
                    picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\A_ca.paa";
                    action = "'name' call ENH_fnc_ESE_sort";
                    shortcuts[] = {DIK_1};
                };
                class SortbyClass
                {
                    text = "$STR_ENH_MAIN_ESE_SORTBYCLASS";
                    action = "'class' call ENH_fnc_ESE_sort";
                    shortcuts[] = {DIK_2};
                };
                class SortbyCount
                {
                    text = "$STR_ENH_MAIN_ESE_SORTBYCOUNT";
                    action = "'count' call ENH_fnc_ESE_sort";
                    shortcuts[] = {DIK_3};
                };
                class SortbyMod
                {
                    text = "$STR_ENH_MAIN_ESE_SORTBYMOD";
                    picture = "\a3\ui_f\data\logos\arma3_bundle_logo_ca.paa";
                    action = "'mod' call ENH_fnc_ESE_sort";
                    shortcuts[] = {DIK_4};
                };
                class SortbyType
                {
                    text = "$STR_ENH_MAIN_ESE_SORTBYTYPE";
                    action = "'type' call ENH_fnc_ESE_sort";
                    shortcuts[] = {DIK_5};
                };
                class ImportFromClipboard
                {
                    text = "$STR_ENH_MAIN_ESE_IMPORTFROMCLIPBOARD";
                    action = "[false, [], true] call ENH_fnc_ESE_loadAttributeValue";
                    picture = "\a3\ui_f\data\igui\cfg\actions\loadvehicle_ca.paa";
                    shortcuts[] = {DIK_6};
                };
               // Filter
                class ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_ASSAULTRIFLES0";
                    picture = "\x\enh\addons\main\data\weapons\assaultRifle_ca.paa";
                    action = "_this call ENH_fnc_ESE_changeFilter";
                    data = "AssaultRifle";
                };
                class MGs: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_MACHINEGUNS0";
                    picture = "\x\enh\addons\main\data\weapons\machineGun_ca.paa";
                    data = "MachineGun";
                };
                class Snipers: ARs
                {
                    text = "$STR_A3_SNIPER1";
                    picture = "\x\enh\addons\main\data\weapons\marksmanRifle_ca.paa";
                    data = "SniperRifle";
                };
                class Shotguns: ARs
                {
                    text = "$STR_ENH_MAIN_ESE_SHOTGUNS";
                    picture = "\x\enh\addons\main\data\weapons\shotgun_ca.paa";
                    data = "Shotgun";
                };
                class SMGs: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_SUBMACHINEGUNS0";
                    picture = "\x\enh\addons\main\data\weapons\subMachineGun_ca.paa";
                    data = "SubmachineGun";
                };
                class Launchers: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_LAUNCHERS0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\secondaryweapon_ca.paa";
                    data = "RocketLauncher";
                };
                class Pistols: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_PISTOLS0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\handgun_ca.paa";
                    data = "Handgun";
                };
                class Grenades: ARs
                {
                    text = "$STR_A3_GRENADES1";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\cargothrow_ca.paa";
                    data = "Grenade";
                };
                class Magazines: ARs
                {
                    text = "$STR_GEAR_MAGAZINES";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\cargomagall_ca.paa";
                    data = "Magazine";
                };
                class Explosives: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_EXPLOSIVES0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\cargoput_ca.paa";
                    data = "Mine";
                };
                class Bipods: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_BOTTOMSLOT0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itembipod_ca.paa";
                    data = "AccessoryBipod";
                };
                class Supressors: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_FRONTSLOT0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itemmuzzle_ca.paa";
                    data = "AccessoryMuzzle";
                };
                class Pointers: ARs
                {
                    text = "$STR_A3_POINTERS1";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itemacc_ca.paa";
                    data = "AccessoryPointer";
                };
                class Scopes: ARs
                {
                    text = "$STR_A3_SCOPES1";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itemoptic_ca.paa";
                    data = "AccessorySights";
                };
                class Uniforms: ARs
                {
                    text = "$STR_A3_CFGVEHICLECLASSES_UNIFORMS0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\uniform_ca.paa";
                    data = "Uniform";
                };
                class Vests: ARs
                {
                    text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_VESTS0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\vest_ca.paa";
                    data = "Vest";
                };
                class Backpacks: ARs
                {
                    text = "$STR_A3_CFGVEHICLECLASSES_BACKPACKS0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\backpack_ca.paa";
                    data = "Backpack";
                };
                class Headgear: ARs
                {
                    text = "$STR_A3_RSCDISPLAYARSENAL_TAB_HEADGEAR";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\headgear_ca.paa";
                    data = "Headgear";
                };
                class Goggles: ARs
                {
                    text = "$STR_A3_RSCDISPLAYARSENAL_TAB_GOGGLES";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\goggles_ca.paa";
                    data = "Glasses";
                };
                class NVGs: ARs
                {
                    text = "$STR_A3_RSCDISPLAYARSENAL_TAB_NVGS";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\nvgs_ca.paa";
                    data = "NVGoggles";
                };
                class ImportToFilter
                {
                    text = "$STR_ENH_MAIN_ESE_IMPORTFROMCLIPBOARD";
                    picture = "\a3\ui_f\data\igui\cfg\actions\loadvehicle_ca.paa";
                    action = "[] call ENH_fnc_ESE_importToFilter";
                };
                class InventoryItems: ARs
                {
                    text = "$STR_A3_CFGVEHICLECLASSES_ITEMS0";
                    picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\watch_ca.paa";
                    data = "Item";
                };
                MENU_STRIP_DEFAULT
                MENU_STRIP_SEPARATOR
            };
        };
        class AvailableItemsList: ctrlListbox
        {
            idc = IDC_ESE_AVAILABLEITEMSLIST;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W);
            h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H + GRID_H);
            colorBackground[] = {0, 0, 0, 0.3};
        };
        class CompatibleItemsList: AvailableItemsList
        {
            idc = IDC_ESE_COMPATIBLEITEMSLIST;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + (WINDOW_W_WIDE * 1/4) * GRID_W + 2 * GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W - GRID_W);
        };
        class InventoryItemsList: ctrlListNBox
        {
            idc = IDC_ESE_INVENTORYLIST;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + (WINDOW_W_WIDE * 2/4) * GRID_W + 2 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W - 2 * GRID_W);
            h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H + GRID_H);
            columns[] = {0, 0.12, 0.8, 0.88};
            disableOverflow = 1;
        };
        class TemplatesList: AvailableItemsList
        {
            idc = IDC_ESE_TEMPLATESLIST;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + (WINDOW_W_WIDE * 3/4) * GRID_W + GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 1/4) * GRID_W - 2 * GRID_W);
        };
        class FilterSearch: ctrlCombo
        {
            idc = IDC_ESE_FILTERSEARCH;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onLBSelChanged = "_this call ENH_fnc_ESE_onModFilterChanged";
        };
        class Search: ctrlEdit
        {
            idc = IDC_ESE_SEARCH;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 6 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(40 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onKeyUp = "_this call ENH_fnc_ESE_search";
        };
        class ButtonSearch: ctrlButtonSearch
        {
            idc = IDC_ESE_BUTTONSEARCH;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 46 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "_this call ENH_fnc_ESE_resetSearch";
        };
        class Save: ctrlButton
        {
            idc = IDC_ESE_SAVE;
            text = "$STR_DISP_INT_SAVE";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W + WINDOW_W_WIDE * GRID_W - 47 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(22 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "[] call ENH_fnc_ESE_applyAttribute";
        };
        class Close: ctrlButtonClose
        {
            idc = IDC_NONE;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W + WINDOW_W_WIDE * GRID_W - 24 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(22 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "spawn ENH_fnc_ESE_close";
        };
    };
};
