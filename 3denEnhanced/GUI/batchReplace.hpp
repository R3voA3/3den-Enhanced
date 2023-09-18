#define DIALOG_W 120

class ENH_BatchReplace
{
  idd = IDD_BATCHREPLACE;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_batchReplace_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = WINDOW_TOPAbs + 10 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = WINDOW_HAbs - 15 * GRID_H;
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_BATCHREPLACE";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = WINDOW_TOPAbs + 5 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = WINDOW_TOPAbs - 12 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class Description: ctrlStructuredText
    {
      text = "$STR_ENH_BATCHREPLACE_DESCRIPTION";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = WINDOW_TOPAbs + 10 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class Search: ctrlEdit
    {
      idc = IDC_BATCHREPLACE_SEARCH;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 16 * GRID_H;
      w = 44 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + 45 * GRID_W;
      y = WINDOW_TOPAbs + 16 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class CollapseAll: ctrlButtonCollapseAll
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + 50 * GRID_W;
      y = WINDOW_TOPAbs + 16 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1600)";
    };
    class ExpandAll: ctrlButtonExpandAll
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + 55 * GRID_W;
      y = WINDOW_TOPAbs + 16 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1600)";
    };
    class List: ctrlTree
    {
      idc = IDC_BATCHREPLACE_LIST;
      idcSearch = IDC_BATCHREPLACE_SEARCH;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 22 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs * 0.3;
      colorLines[] = {1, 1, 1, 1};
      colorBorder[] = {1, 1, 1, 0};
      colorBackGround[] = {COLOR_BACKGROUND_RGBA};
    };
    class ReplaceWithText: ctrlStatic
    {
      text = "$STR_ENH_BATCHREPLACE_REPLACEWITH";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 22 * GRID_H +  WINDOW_HAbs * 0.3 + GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ReplaceWithValue: ctrlEditMulti
    {
      idc = IDC_BATCHREPLACE_REPLACEWITH;
      tooltip = "$STR_ENH_BATCHREPLACE_REPLACEWITH_TOOLTIP";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 22 * GRID_H +  WINDOW_HAbs * 0.3 + 6 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs * 0.1 + 2 * GRID_H;
    };
    class Preview: ctrlStaticPicture
    {
      idc = IDC_BATCHREPLACE_PREVIEW;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 22 * GRID_H +  WINDOW_HAbs * 0.3 + 9 * GRID_H + WINDOW_HAbs * 0.1;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = (DIALOG_W * GRID_W - 2 * GRID_W) / 16 * 9;
    };
    class Replace: ctrlButton
    {
      text = "$STR_ENH_BATCHREPLACE_REPLACE";
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 52 * GRID_W;
      y = WINDOW_TOPAbs - 11 * GRID_H;
       w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "call ENH_fnc_batchReplace";
    };
    class Close: ctrlButtonCancel
    {
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 26 * GRID_W;
      y = WINDOW_TOPAbs - 11 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};