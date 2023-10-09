class ENH_TextureFinder
{
  idd = IDD_TEXTUREFINDER;
  onLoad = "0 spawn ENH_fnc_textureFinder_findTextures";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TEXTUREFINDER";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
      moving = 0;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class BackgroundPreview: ctrlStaticBackgroundDisableTiles
    {
      idc = IDC_TEXTUREFINDER_PREVIEWBACKGROUND;
      x = 0;
      y = 0;
      w = 0;
      h = 0;
      tileH = 4 / (32 * pixelH) * 32;
      tileW = 8 / (32 * pixelW) * 32;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class TextureList: ctrlTree
    {
      idc = IDC_TEXTUREFINDER_TEXTURELIST;
      idcSearch = IDC_TEXTUREFINDER_SEARCH;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H;
      w = (WINDOW_W_ATTRIBUTES - 2) * GRID_W;
      h = WINDOW_HAbs - 80 * GRID_H + CTRL_DEFAULT_H;
      borderSize = 0;
      colorBorder[] = {0, 0, 0, 0};
      colorBackground[] = {COLOR_TAB_RGBA};
    };
    class Preview: ctrlStaticPictureKeepAspect
    {
      idc = IDC_TEXTUREFINDER_PREVIEW;
      x = 0;
      y = 0;
      w = 0;
      h = 0;
      colorBackground[] = {1, 1, 1, 1};
    };
    class Search: ctrlEdit
    {
      idc = IDC_TEXTUREFINDER_SEARCH;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
      tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_TEXTUREFINDER_BUTTONSEARCH;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 31 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = 5 * GRID_H;
    };
    class CollapseAll: ctrlButtonCollapseAll
    {
      idc = IDC_TEXTUREFINDER_COLLAPSEALL;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 36 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = 5 * GRID_H;
    };
    class ExpandAll: ctrlButtonExpandAll
    {
      idc = IDC_TEXTUREFINDER_EXPANDALL;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 41 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = 5 * GRID_H;
    };
    class ProgessText: ctrlStructuredText
    {
      idc = IDC_TEXTUREFINDER_PROGRESSTEXT;
      style = ST_LEFT;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 46 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 80 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES - 25 - 1) * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};