class ENH_ZeusAddons
{
   idd = -1;
   class ControlsBackground
   {
      DISABLE_BACKGROUND
      class Title: ctrlStaticTitle
      {
         text = "$STR_ENH_MAIN_ZEUSADDONS_HEADER";
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
         y = QUOTE(WINDOW_TOPAbs);
         w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
      };
      class Background: ctrlStaticBackground
      {
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
         w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
         h = QUOTE(WINDOW_HAbs - 3 * CTRL_DEFAULT_H);
      };
      class Footer: ctrlStaticFooter
      {
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
         w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
      };
   };
   class Controls
   {
      class CfgPatchesLabel: ctrlStatic
      {
         text = "$STR_ENH_MAIN_ZEUSADDONS_CFGPATCHES";
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H);
         w = QUOTE(80 * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
         font = FONT_BOLD;
         //sizeEx = SIZEEX_PURISTA(SIZEEX_L);
         sizeEx = QUOTE(4.86 * SIZEEX_BASE);
      };
      class CfgPatches: ctrlTree
      {
         idc = IDC_ZEUSADDONS_CFGPATCHES;
         idcSearch = 50;
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W);
         y = QUOTE(WINDOW_TOPAbs + 2 * (CTRL_DEFAULT_H + GRID_H));
         w = QUOTE(WINDOW_W_ATTRIBUTES / 2 * GRID_W - 2 * GRID_W);
         h = QUOTE(WINDOW_HAbs - 6 * CTRL_DEFAULT_H);
         borderSize = 0;
         colorBorder[] = {0, 0, 0, 0};
         colorBackground[] = {COLOR_TAB_RGBA};
      };
      class UnitsLabel: CfgPatchesLabel
      {
         text = "$STR_ENH_MAIN_ZEUSADDONS_CONTENT";
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + WINDOW_W_ATTRIBUTES / 2 * GRID_W - GRID_W);
      };
      class Units: ctrlListbox
      {
         idc = IDC_ZEUSADDONS_UNITS;
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + WINDOW_W_ATTRIBUTES / 2 * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + 2 * (CTRL_DEFAULT_H + GRID_H));
         w = QUOTE(WINDOW_W_ATTRIBUTES / 2 * GRID_W - GRID_W);
         h = QUOTE(WINDOW_HAbs - 6 * CTRL_DEFAULT_H);
         rowHeight = "10 * GRID_H";
      };
      class Copy: ctrlButton
      {
         idc = IDC_ZEUSADDONS_EXPORT;
         text = "$STR_CA_COPY";
         x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 52 * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
         w = QUOTE(25 * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
      };
      class Wiki: Copy
      {
         text = "?";
         tooltip = "";
         x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 58 * GRID_W);
         w = QUOTE(5 * GRID_W);
         url = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#zeus-addons";
      };
      class Close: ctrlButtonClose
      {
         x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
         w = QUOTE(25 * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
      };
      class InvertSelection: Copy
      {
         idc = IDC_ZEUSADDONS_INVERT;
         text = "$STR_ENH_MAIN_ZEUSADDONS_INVERT";
         tooltip = "";
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W);
      };
      class Search: ctrlEdit
      {
         idc = IDC_ZEUSADDONS_SEARCH;
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 27 * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
         w = QUOTE(30 * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
      };
      class ButtonSearch: ctrlButtonSearch
      {
         idc = IDC_ZEUSADDONS_BUTTONSEARCH;
         text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 57 * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
         w = QUOTE(5 * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
      };
      class Collapse: ctrlButtonCollapseAll
      {
         idc = IDC_ZEUSADDONS_COLLAPSE;
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 62 * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
         w = QUOTE(5 * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
      };
      class Expand: ctrlButtonExpandAll
      {
         idc = IDC_ZEUSADDONS_EXPAND;
         x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 67 * GRID_W);
         y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
         w = QUOTE(5 * GRID_W);
         h = QUOTE(CTRL_DEFAULT_H);
      };
   };
};