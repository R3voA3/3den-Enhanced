#include "\3denEnhanced\defineCommon.hpp"
#define DIALOG_W 200
#define DIALOG_H 106

class ENH_RPT
{
  idd = IDD_RPT;
  movingEnable = true;
  onLoad = "[_this # 0, 'onLoad'] call ENH_fnc_rpt_load";
  class ControlsBackground
  {
    class BackgroundDisable: ctrlStaticBackgroundDisable {};
    class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles {};
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
    class TitleHeader: ctrlStaticTitle
    {
      text = "Latest RPT";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class Group: ctrlControlsGroup
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = (DIALOG_H - 7) * GRID_H;
      class Controls
      {
        class Content: ctrlEditMulti
        {
          idc = IDC_RPT_CONTENT;
          x = 0;
          y = 0;
          w = DIALOG_W * GRID_W;
          h = (DIALOG_H - 7) * GRID_H;
          style = ST_NO_RECT + ST_MULTI;
          canModify = false;
        };
      };
    };
    class Lines: ctrlStatic
    {
      text = "Lines:";
      tooltip = "Define the number of lines to be shown. 30 means the last 30 lines are shown. Use a small number to speed up the process. Use a very large number to display all lines.";
      x = CENTERED_X(DIALOG_W) + (200 - 80) * GRID_W;
      y = DIALOG_TOP + 105 * GRID_H;
      w = 15 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class EditLines: ctrlEdit
    {
      idc = IDC_RPT_LINES;
      tooltip = "Define the number of lines to be shown. 30 means the last 30 lines are shown. Use a small number to speed up the process. Use a very large number to display all lines.";
      x = CENTERED_X(DIALOG_W) + (200 - 65) * GRID_W;
      y = DIALOG_TOP + 105 * GRID_H;
      w = 12 * GRID_W;
      h = CTRL_DEFAULT_H;
      maxChars = 3;
    };
    class Progress: ctrlProgress
    {
      idc = IDC_RPT_PROGRESS;
      tooltip = "Shows the progress. A full bar indicates that all available lines were loaded.";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 104 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = GRID_H;
      colorFrame[] = {0,0,0,0};
    };
    class Reload: ctrlButton
    {
      text = "Reload";
      x = CENTERED_X(DIALOG_W) + (174 - 26) * GRID_W;
      y = DIALOG_TOP + 105 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[_this # 0, 'reload'] call ENH_fnc_rpt_load";
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + 174 * GRID_W;
      y = DIALOG_TOP + 105 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};