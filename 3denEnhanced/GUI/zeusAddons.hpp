#include "\3denEnhanced\ENH_defineCommon.hpp"

#define DIALOG_W 180
#define DIALOG_H 100

class ENH_ZeusAddons
{
  idd = -1;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Title: ctrlStaticTitle
    {
      text = "$STR_ENH_ZEUSADDONS_HEADER";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = (DIALOG_H + 7) * GRID_H;
    };
    class BackgroundButtons: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
      w = DIALOG_W * GRID_W;
    };
  };
  class Controls
  {
    class CfgPatchesLabel: ctrlStatic
    {
      text = "$STR_ENH_ZEUSADDONS_CFGPATCHES";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H + GRID_H;
      w = 80 * GRID_W;
      h = CTRL_DEFAULT_H;
      font = FONT_BOLD;
      sizeEx = SIZEEX_PURISTA(SIZEEX_L);
    };
    class CfgPatches: ctrlTree
    {
      idc = IDC_ZEUSADDONS_CFGPATCHES;
      idcSearch = 50;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 2 * (CTRL_DEFAULT_H + GRID_H);
      w = DIALOG_W / 2 * GRID_W - 2 * GRID_W;
      h = DIALOG_H * GRID_H - CTRL_DEFAULT_H - 3 * GRID_H;
      rowHeight = 4 * GRID_H;
    };
    class UnitsLabel: CfgPatchesLabel
    {
      text = "$STR_ENH_ZEUSADDONS_CONTENT";
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W - GRID_W;
    };
    class Units: ctrlListbox
    {
      idc = IDC_ZEUSADDONS_UNITS;
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W;
      y = DIALOG_TOP + 2 * (CTRL_DEFAULT_H + GRID_H);
      w = DIALOG_W / 2 * GRID_W - GRID_W;
      h = DIALOG_H * GRID_H - CTRL_DEFAULT_H - 3 * GRID_H;
      rowHeight = 10 * GRID_H;
    };
    class Copy: ctrlButton
    {
      idc = IDC_ZEUSADDONS_EXPORT;
      text = "$STR_CA_COPY";
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 62 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Wiki: Copy
    {
      text = "?";
      tooltip = "";
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 68 * GRID_W;
      w = 5 * GRID_W;
      url = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#zeus-addons";
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 31 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class InvertSelection: Copy
    {
      idc = IDC_ZEUSADDONS_INVERT;
      text = "$STR_ENH_ZEUSADDONS_INVERT";
      tooltip = "";
      x = CENTERED_X(DIALOG_W) + GRID_W;
    };
    class Search: ctrlEdit
    {
      idc = IDC_ZEUSADDONS_SEARCH;
      x = CENTERED_X(DIALOG_W) + 32 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTERED_X(DIALOG_W) + 62 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Collapse: ctrlButtonCollapseAll
    {
      idc = IDC_ZEUSADDONS_COLLAPSE;
      x = CENTERED_X(DIALOG_W) + 67 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Expand: ctrlButtonExpandAll
    {
      idc = IDC_ZEUSADDONS_EXPAND;
      x = CENTERED_X(DIALOG_W) + 72 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};