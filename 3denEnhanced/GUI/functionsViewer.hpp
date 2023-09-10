#define SIDEBAR_W 70 * GRID_W

class ENH_FunctionsViewer
{
  idd = IDD_FUNCTIONSVIEWER;
  movingEnable = false;
  onLoad = "_this call ENH_fnc_functionsViewer_onLoad";
  class ControlsBackground
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
    class Background: ctrlStaticBackground
    {
      x = safezoneX;
      y = safezoneY + CTRL_DEFAULT_H;
      w = safezoneW;
      h = safezoneH - CTRL_DEFAULT_H;
    };
    class NumFunctions: ctrlStatic
    {
      idc = IDC_FUNCTIONSVIEWER_NUMFUNCTIONS;
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_NUMFUNCTIONS_TOOLTIP";
      x = safezoneX + GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 10 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = safezoneX;
      y = safezoneY + safezoneH - 7 * GRID_H;
      w = safezoneW;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class MenuStrip: ctrlMenuStrip
    {
      idc = 2200; //IDC_FUNCTIONSVIEWER_MENU
      x = safezoneX;
      y = safezoneY + CTRL_DEFAULT_H;
      w = safezoneW;
      h = CTRL_DEFAULT_H;
      class Items
      {
        items[] =
        {
          "FolderFilter",
          "FolderEdit",
          "FolderHelp"
        };
        class FolderFilter
        {
          text = "Filter";
          items[] = {"ConfigFile", "MissionConfigFile", "CampaignConfigFile", "Separator", "Full", "Categories", "Functions", "OtherFiles", "Separator", "LoadFile", "PreprocessFile", "PreprocessFileLineNumbers"};
        };
        class FolderEdit
        {
          text = "Edit";
          items[] = {"ToggleSidebar", "CollapseAll", "ExpandAll", "Separator", "RecompileSelected", "RecompileAll", "Separator", "Copy", "Separator", "LegacyFunctionsViewer"};
        };
        class FolderHelp
        {
          text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELP_TEXT";
          items[] = {"Documentation", "ShowOnBiki"};
        };
        //Edit
        class ToggleSidebar
        {
          text = "$STR_USRACT_CURATOR_COLLAPSE_PARENT";
          shortcuts[] = {INPUT_CTRL_OFFSET + DIK_B};
          action = "_this call ENH_fnc_functionsViewer_togglePanel";
          picture = "\a3\ui_f_orange\data\igui\rscingameui\elevationarrow_ca.paa";
        };
        class CollapseAll
        {
          text = "$STR_3DEN_CTRLBUTTONCOLLAPSEALL_TEXT";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_UP};
          action = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
          picture = "\a3\3den\data\displays\display3den\tree_expand_ca.paa";
        };
        class ExpandAll
        {
          text = "$STR_3DEN_CTRLBUTTONEXPANDALL_TEXT";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_DOWN};
          action = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
          picture = "\a3\3den\data\displays\display3den\tree_collapse_ca.paa";
        };
        class RecompileSelected
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_RECOMPILESELETECTED_TEXT";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_R};
          picture = "\a3\3den\data\displays\display3den\entitymenu\functions_ca.paa";
          action = "[] call ENH_fnc_functionsViewer_recompileSelected";
        };
        class RecompileAll: RecompileSelected
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_RECOMPILEALL_TEXT";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_A};
          action = "[1] call BIS_fnc_recompile";
        };
        class Copy
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_COPYFUNCTION_TEXT";
          shortcuts[] = {INPUT_CTRL_OFFSET + DIK_C};
          action = "_this call ENH_fnc_functionsViewer_copy";
        };
        class LegacyFunctionsViewer
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_LEGACY";
          action = "[ctrlParent (_this # 0)] call BIS_fnc_help";
        };
        //Config
        class ConfigFile
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_ADDONCONFIG";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 0]; call ENH_fnc_functionsViewer_fillCtrlTV";
          shortcuts[] = {DIK_1};
        };
        class MissionConfigFile: ConfigFile
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_MISSIONCONFIG";
          shortcuts[] = {DIK_2};
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 1]; call ENH_fnc_functionsViewer_fillCtrlTV";
        };
        class CampaignConfigFile: ConfigFile
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_CAMPAIGNCONFIG";
          shortcuts[] = {DIK_3};
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 2]; call ENH_fnc_functionsViewer_fillCtrlTV";
        };
        //Filter
        class Full
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_FULL";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 0]; call ENH_fnc_functionsViewer_fillCtrlTV";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_1};
        };
        class Categories
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_CATEGORIES";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 1]; call ENH_fnc_functionsViewer_fillCtrlTV";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_2};
        };
        class Functions
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_FUNCTIONS";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 2]; call ENH_fnc_functionsViewer_fillCtrlTV";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_3};
        };
        class OtherFiles
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_OTHERFILES";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 3]; call ENH_fnc_functionsViewer_fillCtrlTV";
          shortcuts[] = {INPUT_ALT_OFFSET + DIK_4};
        };
        //Loading Method
        class LoadFile
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_LOADFILE";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 0]; call ENH_fnc_functionsViewer_setUpMenuStrip;";
          shortcuts[] = {INPUT_ALT_OFFSET + INPUT_CTRL_OFFSET + DIK_1};
        };
        class PreprocessFile
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_PREPROCESSFILE";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 1]; call ENH_fnc_functionsViewer_setUpMenuStrip;";
          shortcuts[] = {INPUT_ALT_OFFSET + INPUT_CTRL_OFFSET + DIK_2};
        };
        class PreprocessFileLineNumbers
        {
          text = "$STR_ENH_FUNCTIONSVIEWER_PREPROCESSFILEWITHLINES";
          action = "profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 2]; call ENH_fnc_functionsViewer_setUpMenuStrip;";
          shortcuts[] = {INPUT_ALT_OFFSET + INPUT_CTRL_OFFSET + DIK_3};
        };
        //Help
        class Documentation
        {
          text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
          picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
          weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#functions-viewer";
          opensNewWindow = 1;
        };
        class ShowOnBiki
        {
          text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPBIKI_TEXT";
          picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
          opensNewWindow = 1;
        };
        class Default;
        class Separator;
      };
    };
    class List: ctrlTree
    {
      idc = IDC_FUNCTIONSVIEWER_LIST;
      idcSearch = 1400;
      x = safezoneX + GRID_W;
      y = safezoneY + 2 * CTRL_DEFAULT_H + GRID_H;
      w = SIDEBAR_W;
      h = safezoneH - 3 * CTRL_DEFAULT_H - 3 * GRID_H;
      onTreeSelChanged = "_this call ENH_fnc_functionsViewer_onTreeSelChanged";
      colorLines[] = {1, 1, 1, 1};
      borderSize = 0;
      colorBorder[] = {0, 0, 0, 0};
    };
    class Search: ctrlEdit
    {
      idc = IDC_FUNCTIONSVIEWER_SEARCH;
      tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
      x = safezoneX + 12 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 53 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = safezoneX + 65 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Name: ctrlEdit
    {
      idc = IDC_FUNCTIONSVIEWER_NAME;
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_FUNCTIONNAME_TOOLTIP";
      canModify = false;
      x = safezoneX + 72 * GRID_W;
      y = safezoneY + 2 * CTRL_DEFAULT_H + GRID_H;
      w = WINDOW_WAbs * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Path: Name
    {
      idc = IDC_FUNCTIONSVIEWER_PATH;
      tooltip = "$STR_ENH_FUNCTIONSVIEWER_FUNCTIONPATH_TOOLTIP";
      x = safezoneX + 213 * GRID_W;
      w = safezoneW - 214 * GRID_W;
    };
    class SearchCode: ctrlEdit
    {
      idc = IDC_FUNCTIONSVIEWER_SEARCHCODE;
      tooltip = __EVAL(toUpper format ["%1+%2+%3", localize "STR_DIK_CONTROL", localize "STR_VK_SHIFT", "F"]);
      x = safezoneX + 72 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      onKeyUp = "_this call ENH_fnc_functionsViewer_searchKey";
    };
    class SearchText: ctrlStatic
    {
      idc = IDC_FUNCTIONSVIEWER_SEARCHTEXT;
      x = safezoneX + 113 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchButtonUp: ctrlButtonPictureKeepAspect
    {
      text = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_up_ca.paa";
      x = safezoneX + 135 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
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
      y = safezoneY + 3 * CTRL_DEFAULT_H + 2 * GRID_H;
      w = safezoneW - 73 * GRID_W;
      h = safeZoneH - 4 * CTRL_DEFAULT_H - 4 * GRID_H;
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
      x = safezoneX + safezoneW - 31 * GRID_W;
      y = safezoneY + safezoneH - 6 * GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};