#define DIALOG_W (safeZoneW / (1 * GRID_W) - 120 - 10)
#define DIALOG_H 140
#define IDC_ESE_COMPATIBLEITEMSLIST 4100
#define IDC_ESE_TEMPLATESLIST 4200

class ENH_ESE
{
  idd = IDD_ESE;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
    class InventoryItemsListBackground: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W) + (DIALOG_W * 2/4) * GRID_W + 2 * GRID_W;
      y = DIALOG_TOP + 3 * CTRL_DEFAULT_H + GRID_H;
      w = (DIALOG_W * 1/4) * GRID_W - 2 * GRID_W
      h = DIALOG_H * GRID_H - 4 * CTRL_DEFAULT_H + GRID_H;
      colorBackground[] = {0,0,0,0.3};
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TOOLS_ESE";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + DIALOG_H * GRID_H - 2 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class AvailableItems: ctrlStatic
    {
      idc = -1;
      text = "$STR_ENH_ESE_AVAILABLEITEMS";
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 2 * CTRL_DEFAULT_H + GRID_H;
      w = (DIALOG_W * 1/4) * GRID_W;
      h = CTRL_DEFAULT_H;
      font = FONT_BOLD;
      sizeEx = SIZEEX_PURISTA(SIZEEX_L);
      style = ST_CENTER;
    };
    class CompatibleItems: AvailableItems
    {
      text = "Compatible Items";
       x = CENTERED_X(DIALOG_W) + (DIALOG_W * 1/4) * GRID_W + 2 * GRID_W;
       w = (DIALOG_W * 1/4) * GRID_W - GRID_W;
    };
    class InventoryItems: AvailableItems
    {
      text = "$STR_ENH_ESE_ITEMSININVENTORY";
      x = CENTERED_X(DIALOG_W) + (DIALOG_W * 2/4) * GRID_W + 2 * GRID_W;
      w = (DIALOG_W * 1/4) * GRID_W - 2 * GRID_W
    };
    class Templates: AvailableItems
    {
      text = "Templates";
      x = CENTERED_X(DIALOG_W) + (DIALOG_W * 3/4) * GRID_W + GRID_W;
      w = (DIALOG_W * 1/4) * GRID_W - 2 * GRID_W;
    };
  };
  class Controls
  {
    class MenuStrip: ctrlMenuStrip
    {
      idc = IDC_ESE_MENU;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
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
        //Export
        class ExportToSQF
        {
          text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_MISSIONEXPORTSQF_TEXT";
          action = "'sqf' call ENH_fnc_ESE_export";
          opensNewWindow = 1;
        };
        class ExportToACEArsenal: ExportToSQF
        {
          text = "$STR_ENH_ESE_EXPORTTOSACEARSENAL";
          action = "'ace' call ENH_fnc_ESE_export";
        };
        class ExportArsenal: ExportToSQF
        {
          text = "$STR_ENH_ESE_EXPORTTOARSENAL";
          action = "'arsenal' call ENH_fnc_ESE_export";
        };
        class FolderTemplates
        {
          text = "$STR_ENH_ESE_TEMPLATES";
          items[] = {"CreateTemplate", "DeleteTemplate", "Separator", "PreviewTemplate"};
        };
        //Templates
        class CreateTemplate
        {
          text = "$STR_ENH_ESE_CREATETEMPLATE";
          action = "'openCreateGUI' call ENH_fnc_ESE_handleTemplates";
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
        //Help
        class Documentation
        {
          text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
          picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
          weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#equipment-storage-editor";
          opensNewWindow = 1;
        };
        //Inventory
        class IsVirtual
        {
          text = "$STR_3DEN_ATTRIBUTES_AMMOBOX_TYPE_VIRTUAL";
          picture = "\3denEnhanced\data\infinity_ca.paa";
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
          picture = "\a3\3den\data\displays\display3den\tree_expand_ca.paa";
          action = "1 call ENH_fnc_ESE_addItem";
          shortcuts[] = {DIK_RIGHTARROW};
        };
        class RemoveOne
        {
          text = "-1";
          picture = "\a3\3den\data\displays\display3den\tree_collapse_ca.paa";
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
          text = "$STR_ENH_ESE_SORTBYNAME";
          picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\A_ca.paa";
          action = "'name' call ENH_fnc_ESE_sort";
          shortcuts[] = {DIK_1};
        };
        class SortbyClass
        {
          text = "$STR_ENH_ESE_SORTBYCLASS";
          action = "'class' call ENH_fnc_ESE_sort";
          shortcuts[] = {DIK_2};
        };
        class SortbyCount
        {
          text = "$STR_ENH_ESE_SORTBYCOUNT";
          action = "'count' call ENH_fnc_ESE_sort";
          shortcuts[] = {DIK_3};
        };
        class SortbyMod
        {
          text = "$STR_ENH_ESE_SORTBYMOD";
          picture = "\a3\ui_f\data\logos\arma3_bundle_logo_ca.paa";
          action = "'mod' call ENH_fnc_ESE_sort";
          shortcuts[] = {DIK_4};
        };
        class SortbyType
        {
          text = "$STR_ENH_ESE_SORTBYTYPE";
          action = "'type' call ENH_fnc_ESE_sort";
          shortcuts[] = {DIK_5};
        };
        //Filter
        class ARs
        {
          text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_ASSAULTRIFLES0";
          picture = "\3denEnhanced\data\arifle_SPAR_01_blk_F_X_CA.paa";
          action = "_this call ENH_fnc_ESE_changeFilter";
          data = "AssaultRifle";
        };
        class MGs: ARs
        {
          text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_MACHINEGUNS0";
          picture = "\3denEnhanced\data\gear_m200_ca.paa";
          data = "MachineGun";
        };
        class Snipers: ARs
        {
          text = "$STR_A3_SNIPER1";
          picture = "\3denEnhanced\data\gear_dmr_01_x_ca.paa";
          data = "SniperRifle";
        };
        class Shotguns: ARs
        {
          text = "$STR_ENH_ESE_SHOTGUNS";
          picture = "\3denEnhanced\data\gear_m4_ssas_ca.paa";
          data = "Shotgun";
        };
        class SMGs: ARs
        {
          text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_SUBMACHINEGUNS0";
          picture = "\3denEnhanced\data\gear_smg_01_x_ca.paa";
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
        class InventoryItems: ARs
        {
          text = "$STR_A3_CFGVEHICLECLASSES_ITEMS0";
          picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\watch_ca.paa";
          data = "Item";
        };
        class Default;
        class Separator;
      }
    };
    class AvailableItemsList: ctrlListbox
    {
      idc = IDC_ESE_AVAILABLEITEMSLIST;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 3 * CTRL_DEFAULT_H + GRID_H;
      w = (DIALOG_W * 1/4) * GRID_W;
      h = DIALOG_H * GRID_H - 4 * CTRL_DEFAULT_H + GRID_H;
      colorBackground[] = {0,0,0,0.3};
    };
    class CompatibleItemsList: AvailableItemsList
    {
      idc = IDC_ESE_COMPATIBLEITEMSLIST;
      x = CENTERED_X(DIALOG_W) + (DIALOG_W * 1/4) * GRID_W + 2 * GRID_W;
      w = (DIALOG_W * 1/4) * GRID_W - GRID_W;
      colorBackground[] = {0,0,0,0.3};
    };
    class InventoryItemsList: ctrlListNBox
    {
      idc = IDC_ESE_INVENTORYLIST;
      x = CENTERED_X(DIALOG_W) + (DIALOG_W * 2/4) * GRID_W + 2 * GRID_W;
      y = DIALOG_TOP + 3 * CTRL_DEFAULT_H + GRID_H;
      w = (DIALOG_W * 1/4) * GRID_W - 2 * GRID_W
      h = DIALOG_H * GRID_H - 4 * CTRL_DEFAULT_H + GRID_H;
      columns[] = {0, 0.08, 0.8, 0.88};
    };
    class TemplatesList: AvailableItemsList
    {
      idc = IDC_ESE_TEMPLATESLIST;
      x = CENTERED_X(DIALOG_W) + (DIALOG_W * 3/4) * GRID_W + GRID_W;
      w = (DIALOG_W * 1/4) * GRID_W - 2 * GRID_W;
    };
    class FilterSearch: ctrlCombo
    {
      idc = IDC_ESE_FILTERSEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "_this call ENH_fnc_ESE_onModFilterChanged";
    };
    class Search: ctrlEdit
    {
      idc = IDC_ESE_SEARCH;
      x = CENTERED_X(DIALOG_W) + 6 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      onKeyUp = "_this call ENH_fnc_ESE_search";
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_ESE_BUTTONSEARCH;
      x = CENTERED_X(DIALOG_W) + 46 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_ESE_resetSearch";
    };
    class Save: ctrlButton
    {
      idc = IDC_ESE_SAVE;
      text = "$STR_DISP_INT_SAVE";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 47 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] call ENH_fnc_ESE_applyAttribute";
    };
    class Close: ctrlButtonClose
    {
      idc = -1;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 24 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] spawn ENH_fnc_ESE_close";
    };
  };
};

class ENH_ESE_TemplateData
{
  idd = IDD_ESE_TEMPLATEDATA;
  class ControlsBackground
  {
    DISABLE_BACKGROUND

  };
  class Controls
  {
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 51 * GRID_H;
    };
    class Header: ctrlStaticTitle
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Title: ctrlStatic
    {
      text = "$STR_ENH_SAM_TEMPLATE_DATA_TITLE";
      x = CENTERED_X(60);
      y = DIALOG_TOP + 56 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TitleValue: ctrlEdit
    {
      idc = IDC_ESE_TEMPLATEDATA_TITLE;
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 62 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Description: ctrlStatic
    {
      text = "$STR_ENH_SAM_TEMPLATE_DATA_DESCRIPTION";
      x = CENTERED_X(60);
      y = DIALOG_TOP + 68 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class DescriptionValue: ctrlEditMulti
    {
      idc = IDC_ESE_TEMPLATEDATA_DESCRIPTION;
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 74 * GRID_H;
      w = 58 * GRID_W;
      h = 25 * GRID_H;
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(60) + 34 * GRID_W;
      y = DIALOG_TOP + 100 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class OK: ctrlButtonOk
    {
      idc = -1;
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 100 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "'create' call ENH_fnc_ESE_handleTemplates";
    };
  };
};