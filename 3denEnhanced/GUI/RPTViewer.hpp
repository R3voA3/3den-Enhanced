#define DIALOG_W 220
#define DIALOG_H 120

class ENH_RPTViewer
{
  idd = -1;
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
    class BackgroundButtons: Background
    {
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Title: ctrlStaticTitle
    {
      idc = IDC_RPTVIEWER_TITLE;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Group: ctrlControlsGroup
    {
      idc = IDC_RPTVIEWER_GROUP;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
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
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Lines: ctrlEdit
    {
      idc = IDC_RPTVIEWER_LINES;
      x = CENTERED_X(DIALOG_W) + 27 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 12 * GRID_W;
      h = CTRL_DEFAULT_H;
      maxChars = 4;
    };
    class ButtonBiki: ctrlButton
    {
      text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPBIKI_TEXT";
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 93 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
      url = "https://community.bistudio.com/wiki/Crash_Files";
    };
    class ButtonUpdate: ButtonBiki
    {
      text = "$STR_A3_RSCDISPLAYPUBLISHMISSION_BUTTONDOUPDATE";
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 62 * GRID_W;
      onButtonClick = "'update' call ENH_fnc_RPTViewer";
      url = "";
    };
    class ButtonClose: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 31 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H + GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};