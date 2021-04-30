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
      onButtonClick = "_this call ENH_fnc_VIM_applyTemplate";
    };
    class IsVirtualText: ctrlStatic
    {
      idc = IDC_VIM_VIRTUAL_TEXT;
      text = "$STR_ENH_VIM_ISVIRTUAL";
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 125 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 15 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class IsVirtualCheckbox: ctrlCheckbox
    {
      idc = IDC_VIM_VIRTUAL;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 110 * GRID_W;
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
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 105 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      action = "call ENH_fnc_VIM_resetStorage";
    };
    class FilterSearch: ctrlCombo
    {
      idc = IDC_VIM_FILTERSEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 99 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "_this call ENH_fnc_VIM_onModFilterChanged";
    };
    class Search: ctrlEdit
    {
      idc = IDC_VIM_SEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 94 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onKeyUp = "_this call ENH_fnc_VIM_search";
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_VIM_BUTTONSEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 69 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_VIM_resetSearch";
    };
    class Ok: ctrlButtonOK
    {
      idc = IDC_VIM_BUTTONOK;
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 63 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[] call ENH_fnc_VIM_applyAttribute";
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 32 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 30 * GRID_W;
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
      text = "$STR_ENH_SCENARIOATTRIBUTESMANAGERTEMPLATEDATA_TITLE";
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
      text = "$STR_ENH_SCENARIOATTRIBUTESMANAGERTEMPLATEDATA_DESCRIPTION";
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