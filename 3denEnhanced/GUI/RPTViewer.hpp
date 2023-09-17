class ENH_RPTViewer
{
  idd = -1;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      idc = IDC_RPTVIEWER_TITLE;
      x = CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W;
      y = WINDOW_TOPAbs;
      w = WINDOW_W_WIDE * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_WIDE * GRID_W;
      h = WINDOW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class BackgroundButtons: Background
    {
      y = WINDOW_TOPAbs + DIALOG_H * GRID_H + CTRL_DEFAULT_H;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_WIDE * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Group: ctrlControlsGroup
    {
      idc = IDC_RPTVIEWER_GROUP;
      x = CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_WIDE * GRID_W;
      h = WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H;
      class Controls
      {
        class Edit: ctrlEditMulti
        {
          idc = IDC_RPTVIEWER_EDIT;
          w = 400 * GRID_W;
          h = 400 * GRID_H;
          sizeEx = SIZEEX_ETELKA(SIZEEX_XS);
          font = FONT_MONO;
          canModify = 0;
        };
      };
    };
    class LinesText: ctrlStatic
    {
      text = "$STR_ENH_RPTVIEWER_NUMBEROFLINES";
      x = CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Lines: ctrlEdit
    {
      idc = IDC_RPTVIEWER_LINES;
      x = CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 27 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 12 * GRID_W;
      h = CTRL_DEFAULT_H;
      maxChars = 4;
    };
    class ButtonHelp: ctrlButton
    {
      text = "?";
      x = CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 58 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      url = "https://community.bistudio.com/wiki/Crash_Files";
    };
    class ButtonUpdate: ctrlButton
    {
      text = "$STR_A3_RSCDISPLAYPUBLISHMISSION_BUTTONDOUPDATE";
      x = CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 52 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "'update' call ENH_fnc_RPTViewer";
      url = "";
    };
    class ButtonClose: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 26 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};