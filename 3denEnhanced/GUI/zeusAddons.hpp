class ENH_ZeusAddons
{
  idd = -1;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Title: ctrlStaticTitle
    {
      text = "$STR_ENH_ZEUSADDONS_HEADER";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class CfgPatchesLabel: ctrlStatic
    {
      text = "$STR_ENH_ZEUSADDONS_CFGPATCHES";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP + CTRL_DEFAULT_H + GRID_H;
      w = 80 * GRID_W;
      h = CTRL_DEFAULT_H;
      font = FONT_BOLD;
      sizeEx = SIZEEX_PURISTA(SIZEEX_L);
    };
    class CfgPatches: ctrlTree
    {
      idc = IDC_ZEUSADDONS_CFGPATCHES;
      idcSearch = 50;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOP + 2 * (CTRL_DEFAULT_H + GRID_H);
      w = WINDOW_W_ATTRIBUTES / 2 * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs - 6 * CTRL_DEFAULT_H;
      rowHeight = 4 * GRID_H;
    };
    class UnitsLabel: CfgPatchesLabel
    {
      text = "$STR_ENH_ZEUSADDONS_CONTENT";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + WINDOW_W_ATTRIBUTES / 2 * GRID_W - GRID_W;
    };
    class Units: ctrlListbox
    {
      idc = IDC_ZEUSADDONS_UNITS;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + WINDOW_W_ATTRIBUTES / 2 * GRID_W;
      y = WINDOW_TOP + 2 * (CTRL_DEFAULT_H + GRID_H);
      w = WINDOW_W_ATTRIBUTES / 2 * GRID_W - GRID_W;
      h = WINDOW_HAbs - 6 * CTRL_DEFAULT_H;
      rowHeight = 10 * GRID_H;
    };
    class Copy: ctrlButton
    {
      idc = IDC_ZEUSADDONS_EXPORT;
      text = "$STR_CA_COPY";
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 52 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Wiki: Copy
    {
      text = "?";
      tooltip = "";
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 58 * GRID_W;
      w = 5 * GRID_W;
      url = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#zeus-addons";
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class InvertSelection: Copy
    {
      idc = IDC_ZEUSADDONS_INVERT;
      text = "$STR_ENH_ZEUSADDONS_INVERT";
      tooltip = "";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
    };
    class Search: ctrlEdit
    {
      idc = IDC_ZEUSADDONS_SEARCH;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 27 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_ZEUSADDONS_BUTTONSEARCH;
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 57 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Collapse: ctrlButtonCollapseAll
    {
      idc = IDC_ZEUSADDONS_COLLAPSE;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 62 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Expand: ctrlButtonExpandAll
    {
      idc = IDC_ZEUSADDONS_EXPAND;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 67 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};