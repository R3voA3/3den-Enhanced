#define SIDEBAR_W 70 * GRID_W

class ENH_FunctionsViewer
{
  idd = IDD_FUNCTIONSVIEWER;
  movingEnable = false;
  onLoad = "_this call  ENH_fnc_functionsViewer_onLoad";
  class ControlsBackground
  {
    class Background: ctrlStaticBackground
    {
      x = safezoneX;
      y = safezoneY + CTRL_DEFAULT_H;
      w = safezoneW;
      h = safezoneH - CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_FUNCTIONSVIEWER_HEADER";
      x = safezoneX;
      y = safezoneY;
      w = safezoneW;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {COLOR_ACTIVE_RGBA};
      moving = false;
    };
    class FilterConfig: ctrlToolbox
    {
      idc = IDC_FUNCTIONSVIEWER_FILTERCONFIG;
      x = safezoneX + GRID_W;
      y = safezoneY + 6 * GRID_H;
      w = SIDEBAR_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 3;
      strings[] = //Do not localize
      {
        "configFile",
        "missionConfig",
        "campaignConfig"
      };
      values[] = {0,1,2};
      onToolBoxSelChanged  = "_this call ENH_fnc_functionsViewer_fillCtrlTV";
    };
    class FilterMode: FilterConfig
    {
      idc = IDC_FUNCTIONSVIEWER_FILTERMODE;
      x = safezoneX + GRID_W;
      y = safezoneY + 12 * GRID_H;
      h = 11 * GRID_H;
      rows = 2;
      columns = 3;
      strings[] =
      {
        "$STR_ENH_FUNCTIONSVIEWER_FULL",
        "$STR_ENH_FUNCTIONSVIEWER_CATEGORIES",
        "$STR_ENH_FUNCTIONSVIEWER_FUNCTIONS",
        "$STR_ENH_FUNCTIONSVIEWER_SCRIPTS",
        ".inc",
        ".hpp"
      };
      values[] = {0,1,2,3,4,5};
      onToolBoxSelChanged  = "_this call ENH_fnc_functionsViewer_fillCtrlTV";
    };
    class LoadFileMode: ctrlCombo
    {
      idc = IDC_FUNCTIONSVIEWER_LOADMODE;
      x = safezoneX + GRID_W;
      y = safezoneY + 24 * GRID_H;
      w = SIDEBAR_W;
      h = CTRL_DEFAULT_H;
      class Items
      {
        class LoadFile
        {
          text = "loadFile";
          default = 1;
        };
        class PreprocessFile
        {
          text = "preprocessFile";
        };
        class PreprocessFileLineNumbers
        {
          text = "preprocessFileLineNumbers";
        };
      };
      onLBSelChanged  = "_this call ENH_fnc_functionsViewer_fillCtrlTV";
    };
    class List: ctrlTree
    {
      idc = IDC_FUNCTIONSVIEWER_LIST;
      idcSearch = 1400;
      x = safezoneX + GRID_W;
      y = safezoneY + 30 * GRID_H;
      w = SIDEBAR_W;
      h = safezoneH - 37 * GRID_H;
      onTreeSelChanged = "_this call ENH_fnc_functionsViewer_onTreeSelChanged";
      colorLines[] = {1,1,1,1};
      borderSize = 0;
      colorBorder[] = {0,0,0,0};
    };
    class NumFunctions: ctrlStatic
    {
      idc = IDC_FUNCTIONSVIEWER_NUMFUNCTIONS;
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_NUMFUNCTIONS_TOOLTIP";
      x = safezoneX + GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 10 * GRID_W;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {COLOR_ACTIVE_RGBA};
    };
    class Search: ctrlEdit
    {
      idc = IDC_FUNCTIONSVIEWER_SEARCH;
      tooltip = __EVAL(format ["%1+%2",toUpper localize "STR_DIK_CONTROL","F"]);
      x = safezoneX + 12 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 44 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = safezoneX + 56 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Collapse: ctrlButtonCollapseAll
    {
      x = safezoneX + 61 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
    };
    class Expand: Collapse
    {
      x = safezoneX + 66 * GRID_W;
      onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
    };
    class TogglePanelLeft: ctrlButton
    {
      idc = IDC_FUNCTIONSVIEWER_PANNEL;
      text = "«";
      x = safezoneX + 71 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick  = "_this call ENH_fnc_functionsViewer_togglePanel";
    };
    class Name: ctrlEdit
    {
      idc = IDC_FUNCTIONSVIEWER_NAME;
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_FUNCTIONNAME_TOOLTIP";
      canModify = false;
      x = safezoneX + 72 * GRID_W;
      y = safezoneY + 6 * GRID_H;
      w = safezoneW - 155 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Path: Name
    {
      idc = IDC_FUNCTIONSVIEWER_PATH;
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_FUNCTIONPATH_TOOLTIP";
      y = safezoneY + 12 * GRID_H;
    };
    class RecompileSelected: ctrlButton
    {
      idc = IDC_FUNCTIONSVIEWER_RECOMPILESELECTED;
      text = "$STR_ENH_FUNCTIONSVIEWER_RECOMPILESELETECTED_TEXT";
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_RECOMPILESELETECTED_TOOLTIP";
      x = safezoneX + safezoneW - 82 * GRID_W;
      y = safezoneY + 6 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_functionsViewer_recompileSelected";
    };
    class Copy: RecompileSelected
    {
      idc = IDC_FUNCTIONSVIEWER_COPY;
      text = "$STR_ENH_FUNCTIONSVIEWER_COPYFUNCTION_TEXT";
      tooltip = __EVAL(toUpper format ["%1+%2",localize "STR_DIK_CONTROL","X"]);
      y = safezoneY + 12 * GRID_H;
      onButtonClick = "_this call ENH_fnc_functionsViewer_copy";
    };
    class RecompileAll: RecompileSelected
    {
      idc = IDC_FUNCTIONSVIEWER_RECOMPILEALL;
      text = "$STR_ENH_FUNCTIONSVIEWER_RECOMPILEALL_TEXT";
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_RECOMPILEALL_TOOLTIP";
      x = safezoneX + safezoneW - 41 * GRID_W;
      onButtonClick = "1 call BIS_fnc_recompile; playSound 'FD_Finish_F'";
    };
    class Biki: RecompileSelected
    {
      idc = IDC_FUNCTIONSVIEWER_BIKI;
      text = "$STR_ENH_FUNCTIONSVIEWER_BIKI";
      tooltip = "";
      x = safezoneX + safezoneW - 41 * GRID_W;
      y = safezoneY + 12 * GRID_H;
    };
    class SearchCode: ctrlEdit
    {
      idc = IDC_FUNCTIONSVIEWER_SEARCHCODE;
      tooltip = __EVAL(toUpper format ["%1+%2+%3",localize "STR_DIK_CONTROL",localize "STR_VK_SHIFT","F"]);
      x = safezoneX + 72 * GRID_W;
      y = safezoneY + 18 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      onKeyUp = "_this call ENH_fnc_functionsViewer_searchKey";
    };
    class SearchText: ctrlStatic
    {
      idc = IDC_FUNCTIONSVIEWER_SEARCHTEXT;
      x = safezoneX + 113 * GRID_W;
      y = safezoneY + 18 * GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchButtonUp: ctrlButtonPictureKeepAspect
    {
      text = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_up_ca.paa";
      x = safezoneX + 135 * GRID_W;
      y = safezoneY + 18 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[_this # 0, -1] call ENH_fnc_FunctionsViewer_IncrementKey";
    };
    class SearchButtonDown: SearchButtonUp
    {
      text = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_down_ca.paa";
      x = safezoneX + 129 * GRID_W;
      onButtonClick = "[_this # 0, 1] call ENH_fnc_functionsViewer_incrementKey";
    };
    class Preview: ctrlControlsGroup
    {
      idc = IDC_FUNCTIONSVIEWER_GROUP;
      x = safezoneX + 72 * GRID_W;
      y = safezoneY + 24 * GRID_H;
      w = safezoneW - 73 * GRID_W;
      h = safeZoneH - 31 * GRID_H;
      class Controls
      {
        class Lines: ctrlStructuredText
        {
          idc = IDC_FUNCTIONSVIEWER_LINES;
          canModify = false;
          x = 0;
          y = 0;
          w = 0.070;
          h = 2;
          font = "EtelkaMonospacePro";
          shadow = 0;
          colorBackground[] = {COLOR_OVERLAY_RGBA};
        };
        class Code: ctrlEditMulti
        {
          idc = IDC_FUNCTIONSVIEWER_CODE;
          canModify = false;
          x = 0.075;
          w = 4;
          h = 2;
          font = "EtelkaMonospacePro";
          shadow = 0;
          style = ST_NO_RECT + ST_MULTI;
        };
      };
    };
    class Close: ctrlButtonClose
    {
      x = safezoneX + safezoneW - 41 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};