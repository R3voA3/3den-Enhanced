class ENH_3denShortcuts
{
  idd = -1;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_3DENShortcuts_init";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_3DENSHORTCUTS_DISPLAYNAME";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_PREVIEW_HAbs;
    };
    class BackgroundFilter: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {0, 0, 0, 1};
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = 7 * GRID_H;
    };
  };
  class Controls
  {
    class ContentFilter: ctrlListNBox
    {
        idc = IDC_SHORTCUTS_FILTER;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
      columns[] = {0, 10 * GRID_W, 80 * GRID_W};
    };
    class Content: ctrlListNBox
    {
      idc = IDC_SHORTCUTS_CONTENT;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H;
      w = (WINDOW_W_ATTRIBUTES - 2) * GRID_W;
      h = WINDOW_PREVIEW_HAbs - 2 * CTRL_DEFAULT_H - 3 * GRID_H;
      colorBackground[] = {COLOR_OVERLAY_RGBA};
      columns[] = {0, 10 * GRID_W, 80 * GRID_W};
      disableOverflow = 1;
    };
    class Search: ctrlEdit
    {
      idc = IDC_SHORTCUTS_SEARCH;
      x = CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_SHORTCUTS_BUTTONSEARCH;
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      tooltip = "";
      x = CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W + 36 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES - 26) * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};