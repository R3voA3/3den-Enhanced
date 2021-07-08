#define DIALOG_W 200
#define DIALOG_H 140

class ENH_VIM
{
  idd = IDD_VIM;
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
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TOOLS_VIM";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class AvailableItems: ctrlStatic
    {
      idc = IDC_VIM_AVAILABLEITEMSTEXT;
      text = "$STR_ENH_VIM_AVAILABLEITEMS";
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 2 * CTRL_DEFAULT_H + GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      font = FONT_BOLD;
      sizeEx = SIZEEX_PURISTA(SIZEEX_L);
    };
    class InventoryItems: AvailableItems
    {
      text = "$STR_ENH_VIM_ITEMSININVENTORY";
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
    };
  };
  class Controls
  {
    class MenuStrip: ctrlMenuStrip
    {
      idc = IDC_VIM_MENU;
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
          action = "'sqf' call ENH_fnc_VIM_export";
          opensNewWindow = 1;
        };
        class ExportToACEArsenal: ExportToSQF
        {
          text = "$STR_ENH_VIM_EXPORTTOSACEARSENAL";
          action = "'ace' call ENH_fnc_VIM_export";
        };
        class ExportArsenal: ExportToSQF
        {
          text = "$STR_ENH_VIM_EXPORTTOARSENAL";
          action = "'arsenal' call ENH_fnc_VIM_export";
        };
        class FolderTemplates
        {
          text = "$STR_ENH_VIM_TEMPLATES";
          items[] = {"ShowTemplates", "Separator", "CreateTemplate", "DeleteTemplate", "Separator", "PreviewTemplate"};
        };
        //Templates
        class ShowTemplates
        {
          text = "$STR_ENH_VIM_SHOWTEMPLATES";
          action = "'toggle' call ENH_fnc_VIM_handleTemplates";
        };
        class CreateTemplate
        {
          text = "$STR_ENH_VIM_CREATETEMPLATE";
          action = "'openCreateGUI' call ENH_fnc_VIM_handleTemplates";
          opensNewWindow = 1;
        };
        class DeleteTemplate
        {
          text = "$STR_3DEN_DISPLAY3DEN_ENTITYMENU_DELETE_TEXT";
          action = "'delete' call ENH_fnc_VIM_handleTemplates";
          shortcuts[] = {DIK_DELETE};
        };
        class PreviewTemplate
        {
          text = "$STR_3DEN_TUTORIALS_SCENARIO_SECTIONS_PREVIEW_TEXT";
          action = "'preview' call ENH_fnc_VIM_handleTemplates";
        };
        //Help
        class Documentation
        {
          text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
          picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
          weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#vehicle-inventory-manager-vim";
          opensNewWindow = 1;
        };
        //Inventory
        class IsVirtual
        {
          text = "$STR_3DEN_ATTRIBUTES_AMMOBOX_TYPE_VIRTUAL";
          picture = "\3denEnhanced\data\infinity_ca.paa";
          action = "-1 call ENH_fnc_VIM_toggleVirtual";
        };
        class ResetInventory
        {
          text = "$STR_3DEN_DISPLAY3DEN_ENTITYMENU_ARSENALRESET_TEXT";
          picture = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
          action = "call ENH_fnc_VIM_resetStorage";
        };
        class AddOne
        {
          text = "+1";
          picture = "\a3\3den\data\displays\display3den\tree_expand_ca.paa";
          action = "1 call ENH_fnc_VIM_addItem";
          shortcuts[] = {DIK_RIGHTARROW};
        };
        class RemoveOne
        {
          text = "-1";
          picture = "\a3\3den\data\displays\display3den\tree_collapse_ca.paa";
          action = "1 call ENH_fnc_VIM_removeItem";
          shortcuts[] = {DIK_LEFTARROW};
        };
        class RemoveAll
        {
          text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_DEFAULT_TEXT";
          picture = "\a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
          action = "call ENH_fnc_VIM_clearInventory";
          shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_LEFTARROW};
        };
        class Arsenal
        {
          text = "$STR_A3_RSCDISPLAYMAIN_BUTTONVIRTUALARSENAL";
          picture = "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacearsenal_ca.paa";
          action = "call ENH_fnc_VIM_fullArsenal";
          shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_A};
        };
        class SortbyName
        {
          text = "$STR_ENH_VIM_SORTBYNAME";
          picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\A_ca.paa";
          action = "'name' call ENH_fnc_VIM_sort";
          shortcuts[] = {DIK_1};
        };
        class SortbyClass
        {
          text = "$STR_ENH_VIM_SORTBYCLASS";
          action = "'class' call ENH_fnc_VIM_sort";
          shortcuts[] = {DIK_2};
        };
        class SortbyCount
        {
          text = "$STR_ENH_VIM_SORTBYCOUNT";
          action = "'count' call ENH_fnc_VIM_sort";
          shortcuts[] = {DIK_3};
        };
        class SortbyMod
        {
          text = "$STR_ENH_VIM_SORTBYMOD";
          picture = "\a3\ui_f\data\logos\arma3_bundle_logo_ca.paa";
          action = "'mod' call ENH_fnc_VIM_sort";
          shortcuts[] = {DIK_4};
        };
        class SortbyType
        {
          text = "$STR_ENH_VIM_SORTBYTYPE";
          action = "'type' call ENH_fnc_VIM_sort";
          shortcuts[] = {DIK_5};
        };
        //Filter
        class ARs
        {
          text = "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_ASSAULTRIFLES0";
          picture = "\3denEnhanced\data\arifle_SPAR_01_blk_F_X_CA.paa";
          action = "_this call ENH_fnc_VIM_changeFilter";
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
          text = "$STR_ENH_VIM_SHOTGUNS";
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
      idc = IDC_VIM_AVAILABLEITEMSLIST;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 3 * CTRL_DEFAULT_H + GRID_H;
      w = (DIALOG_W / 2 - 1) * GRID_W;
      h = DIALOG_H * GRID_H - 4 * CTRL_DEFAULT_H + 2 * GRID_H;
      colorBackground[] = {0, 0, 0, 0};
    };
    class InventoryItemsList: ctrlListNBox
    {
      idc = IDC_VIM_INVENTORYLIST;
      x = CENTERED_X(DIALOG_W) + (DIALOG_W / 2) * GRID_W;
      y = DIALOG_TOP + 3 * CTRL_DEFAULT_H + GRID_H;
      w = DIALOG_W / 2 * GRID_W;
      h = DIALOG_H * GRID_H - 4 * CTRL_DEFAULT_H + 2 * GRID_H;
      columns[] = {0, 0.08, 0.8, 0.88};
    };
    class FilterSearch: ctrlCombo
    {
      idc = IDC_VIM_FILTERSEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "_this call ENH_fnc_VIM_onModFilterChanged";
    };
    class Search: ctrlEdit
    {
      idc = IDC_VIM_SEARCH;
      x = CENTERED_X(DIALOG_W) + 6 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      onKeyUp = "_this call ENH_fnc_VIM_search";
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_VIM_BUTTONSEARCH;
      x = CENTERED_X(DIALOG_W) + 46 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_VIM_resetSearch";
    };
    class Save: ctrlButton
    {
      idc = IDC_VIM_SAVE;
      text = "$STR_DISP_INT_SAVE";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 47 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] call ENH_fnc_VIM_applyAttribute";
    };
    class Close: ctrlButtonClose
    {
      idc = -1;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 24 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] spawn ENH_fnc_VIM_close";
    };
  };
};

class ENH_VIM_TemplateData
{
  idd = IDD_VIM_TEMPLATEDATA;
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
      idc = IDC_VIM_TEMPLATEDATA_TITLE;
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
      idc = IDC_VIM_TEMPLATEDATA_DESCRIPTION;
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
      onButtonClick = "'create' call ENH_fnc_VIM_handleTemplates";
    };
  };
};

/*
#define DIALOG_W 240
#define DIALOG_H 140

class ENH_VIM
{
  idd = IDD_VIM;
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
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TOOLS_VIM";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class AvailableItems: ctrlStatic
    {
      idc = IDC_VIM_AVAILABLEITEMSTEXT;
      text = "$STR_ENH_VIM_AVAILABLEITEMS";
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 4 * CTRL_DEFAULT_H + GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      font = FONT_BOLD;
      sizeEx = SIZEEX_PURISTA(SIZEEX_L);
    };
    class InventoryItems: AvailableItems
    {
      text = "$STR_ENH_VIM_ITEMSININVENTORY";
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
    };
    class InventoryListBackground: ctrlStaticPictureKeepAspect
    {
      idc = IDC_VIM_BACKGROUNDICON;
      text = "";
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
      y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
      w = DIALOG_W * GRID_W  / 2 - 8 * GRID_W;
      h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
      colorText[] = {0.1, 0.1, 0.1, 0.9};
    };
  };
  class Controls
  {
    class Filter: ctrlToolbox
    {
      idc = IDC_VIM_FILTER;
      columns = 7;
      rows = 3;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = 3 * CTRL_DEFAULT_H;
      strings[] =
      {
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_ASSAULTRIFLES0",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_MACHINEGUNS0",
        "$STR_A3_SNIPER1",
        "$STR_ENH_VIM_SHOTGUNS",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_SUBMACHINEGUNS0",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_LAUNCHERS0",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_PISTOLS0",
        "$STR_A3_GRENADES1",
        "$STR_GEAR_MAGAZINES",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_EXPLOSIVES0",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_BOTTOMSLOT0",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_FRONTSLOT0",
        "$STR_A3_POINTERS1",
        "$STR_A3_SCOPES1",
        "$STR_A3_CFGVEHICLECLASSES_UNIFORMS0",
        "$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_VESTS0",
        "$STR_A3_CFGVEHICLECLASSES_BACKPACKS0",
        "$STR_A3_RSCDISPLAYARSENAL_TAB_HEADGEAR",
        "$STR_A3_RSCDISPLAYARSENAL_TAB_GOGGLES",
        "$STR_A3_RSCDISPLAYARSENAL_TAB_NVGS",
        "$STR_A3_CFGVEHICLECLASSES_ITEMS0"
      };
      onToolBoxSelChanged = "_this call ENH_fnc_VIM_filterList";
    };
    class AvailableItemsList: ctrlListbox
    {
      idc = IDC_VIM_AVAILABLEITEMSLIST;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
      w = DIALOG_W * GRID_W  / 2 - 7 * GRID_W;
      h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
      colorBackground[] = {1, 0, 0, 0};
    };
    class InventoryItemsList: ctrlListNBox
    {
      idc = IDC_VIM_INVENTORYLIST;
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
      y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
      w = DIALOG_W * GRID_W  / 2 - 8 * GRID_W;
      h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
      columns[] = {0, 0.08, 0.8, 0.88};
    };
    class AddOne: ctrlButton
    {
      idc = IDC_VIM_ADDONE;
      text = ">";
      tooltip = "+1";
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W - 5 * GRID_W;
      y = DIALOG_TOP + 10 * CTRL_DEFAULT_H;
      w = 10 * GRID_W;
      h = 2 * CTRL_DEFAULT_H;
      onButtonClick = "1 call ENH_fnc_VIM_addItem";
    };
    class AddTen: AddOne
    {
      idc = IDC_VIM_ADDTEN;
      text = ">>";
      tooltip = "+10";
      y = DIALOG_TOP + 12 * CTRL_DEFAULT_H + GRID_W;
      onButtonClick = "10 call ENH_fnc_VIM_addItem";
    };
    class RemoveOne: AddOne
    {
      idc = IDC_VIM_REMOVEONE;
      text = "<";
      tooltip = "-1";
      y = DIALOG_TOP + 14 * CTRL_DEFAULT_H + 2 * GRID_W;
      onButtonClick = "1 call ENH_fnc_VIM_removeItem";
    };
    class RemoveTen: AddOne
    {
      idc = IDC_VIM_REMOVETEN;
      text = "<<";
      tooltip = "-10";
      y = DIALOG_TOP + 16 * CTRL_DEFAULT_H + 3 * GRID_W;
      onButtonClick = "10 call ENH_fnc_VIM_removeItem";
    };
    class RemoveAll: AddOne
    {
      idc = IDC_VIM_REMOVEALL;
      text = "<<<";
      tooltip = "$STR_ENH_VIM_REMOVESELECTED_TOOLTIP";
      y = DIALOG_TOP + 18 * CTRL_DEFAULT_H + 4 * GRID_W;
      onButtonClick = "call ENH_fnc_VIM_clearInventory";
    };
    class FullArsenal: AddOne
    {
      idc = IDC_VIM_FULLARSENAL;
      text = "A";
      tooltip = "$STR_ENH_VIM_FULLARSENAL_TOOLTIP";
      y = DIALOG_TOP + 20 * CTRL_DEFAULT_H + 5 * GRID_W;
      colorBackground[] = {1, 0, 0, 1};
      onButtonClick = "call ENH_fnc_VIM_fullArsenal";
    };
    class ShowTemplates: ctrlButton
    {
      text = "$STR_ENH_VIM_SHOWTEMPLATES";
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_VIM_showTemplates";
    };
    class CreateTemplate: ShowTemplates
    {
      idc = IDC_VIM_CREATETEMPLATE;
      text = "$STR_ENH_VIM_CREATETEMPLATE";
      x = CENTERED_X(DIALOG_W) + GRID_W + 31 * GRID_W;
      onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_VIM_TemplateData'";
    };
    class DeleteTemplate: ctrlButtonPictureKeepAspect
    {
      idc = IDC_VIM_DELETETEMPLATE;
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
      tooltip = "$STR_ENH_VIM_DELETETEMPLATE";
      x = CENTERED_X(DIALOG_W) + GRID_W + 62 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_VIM_deleteTemplate";
      colorBackground[] = {0, 0, 0, 0};
      colorBackgroundDisabled[] = {0, 0, 0, 0};
    };
    class ApplyTemplate: ShowTemplates
    {
      idc = IDC_VIM_APPLYTEMPLATE;
      text = "$STR_EDITOR_MENU_FILE_PREVIEW";
      x = CENTERED_X(DIALOG_W) + GRID_W + 68 * GRID_W;
      onButtonClick = "_this call ENH_fnc_VIM_previewTemplate";
    };
    class IsVirtualText: ctrlStatic
    {
      idc = IDC_VIM_VIRTUAL_TEXT;
      text = "$STR_ENH_VIM_ISVIRTUAL";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 128 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 15 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class IsVirtualCheckbox: ctrlCheckbox
    {
      idc = IDC_VIM_VIRTUAL;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 113 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onCheckedChanged = "call ENH_fnc_VIM_toggleVirtual";
    };
    class Reset: ctrlButtonPictureKeepAspect
    {
      idc = IDC_VIM_RESET;
      text = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
      tooltip = "$STR_ENH_VIM_RESET_TOOLTIP";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 107 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      action = "call ENH_fnc_VIM_resetStorage";
    };
    class FilterSearch: ctrlCombo
    {
      idc = IDC_VIM_FILTERSEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 101 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "_this call ENH_fnc_VIM_onModFilterChanged";
    };
    class Search: ctrlEdit
    {
      idc = IDC_VIM_SEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 96 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
      onKeyUp = "_this call ENH_fnc_VIM_search";
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_VIM_BUTTONSEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 76 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_VIM_resetSearch";
    };
    class ExportACE: ctrlButton
    {
      idc = -1;
      text = "$STR_ENH_VIM_EXPORTACE_DISPLAYNAME";
      tooltip = "$STR_ENH_VIM_EXPORTACE_TOOLTIP";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 70 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] call ENH_fnc_VIM_exportAsACEArsenal";
    };
    class test: ctrlButton
    {
      idc = -1;
      text = "$STR_ENH_VIM_EXPORTACE_DISPLAYNAME";
      tooltip = "$STR_ENH_VIM_EXPORTACE_TOOLTIP";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 70 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H + CTRL_DEFAULT_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] call ENH_fnc_VIM_exportAsACEArsenal";
    };
    class Save: ctrlButton
    {
      idc = IDC_VIM_BUTTONOK;
      text = "$STR_DISP_INT_SAVE";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 47 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] call ENH_fnc_VIM_applyAttribute";
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 24 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};

class ENH_VIM_TemplateData
{
  idd = IDD_VIM_TEMPLATEDATA;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 51 * GRID_H;
    };
  };
  class Controls
  {
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
      idc = IDC_VIM_TEMPLATEDATA_TITLE;
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
      idc = IDC_VIM_TEMPLATEDATA_DESCRIPTION;
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
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 100 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_VIM_createTemplate";
    };
  };
};
*/