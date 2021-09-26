#define DIALOG_W 120
#define DIALOG_H 47

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
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
    class CollapseAll: ctrlButtonCollapseAll //Need to be background controls. Otherwise they get rendered on top of the list when expanded
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + (DIALOG_H - 1) * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1600)";
    };
    class ExpandAll: ctrlButtonExpandAll
    {
      x = CENTERED_X(DIALOG_W) + 5 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H - 1) * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1600)";
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + (DIALOG_H + 5) * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Description: ctrlStructuredText
    {
      text = "$STR_ENH_BATCHREPLACE_DESCRIPTION";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = 2 * CTRL_DEFAULT_H;
    };
    class Search: ctrlEdit
    {
      idc = IDC_BATCHREPLACE_SEARCH;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 14 * GRID_H;
      w = DIALOG_W / 2 * GRID_W - 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTERED_X(DIALOG_W) + (DIALOG_W / 2 - 4) * GRID_W;
      y = DIALOG_TOP + 14 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class List: ctrlTree
    {
      idc = IDC_BATCHREPLACE_LIST;
      idcSearch = IDC_BATCHREPLACE_SEARCH;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 19 * GRID_H;
      w = DIALOG_W / 2 * GRID_W;
      h = (DIALOG_H - 21) * GRID_H;
      colorLines[] = {1, 1, 1, 1};
      colorBorder[] = {1, 1, 1, 0};
      colorBackGround[] = {COLOR_BACKGROUND_RGBA};
    };
    class ReplaceWithText: ctrlStatic
    {
      text = "$STR_ENH_BATCHREPLACE_REPLACEWITH";
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W;
      y = DIALOG_TOP + 14 * GRID_H;
      w = DIALOG_W / 2 * GRID_W - GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ReplaceWithValue: ctrlEditMulti
    {
      idc = IDC_BATCHREPLACE_REPLACEWITH;
      tooltip = "$STR_ENH_BATCHREPLACE_REPLACEWITH_TOOLTIP";
      x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + GRID_W;
      y = DIALOG_TOP + 19 * GRID_H;
      w = DIALOG_W / 2 * GRID_W - 2 * GRID_W;
      h = (DIALOG_H - 21) * GRID_H;
    };
    class Replace: ctrlButton
    {
      text = "$STR_ENH_BATCHREPLACE_REPLACE";
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 48)* GRID_W;
      y = DIALOG_TOP + (DIALOG_H - 1) * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "call ENH_fnc_batchReplace";
    };
    class Close: ctrlButtonCancel
    {
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 24)* GRID_W;
      y = DIALOG_TOP + (DIALOG_H - 1) * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Preview: ctrlStaticPictureKeepAspect
    {
      idc = IDC_BATCHREPLACE_PREVIEW;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = DIALOG_W * GRID_W;
      h = (DIALOG_H - 21) * GRID_H;
    };
  };
};