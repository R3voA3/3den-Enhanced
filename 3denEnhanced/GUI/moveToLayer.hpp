#define DIALOG_W 100
#define DIALOG_H 60

class ENH_MoveToLayer
{
  idd = -1;
  movingEnable = true;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = (DIALOG_H + 1) * GRID_H;
    };
    class BackgroundButton: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 59 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_SELECTLAYER_MOVETOLAYER";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class LayerList: ctrlListBox
    {
      idc = 100;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = 11 * CTRL_DEFAULT_H - 3 * GRID_H;
      onLoad = "_this call ENH_fnc_moveToLayer_onLoad";
    };
    class Move: ctrlButtonOK
    {
      idc = IDC_CREATEOBJECT_CLOSE;
      text = "$STR_A3_BOOT_M02_BIS_SIGN_MARKER";
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 57 * GRID_W;
      y = DIALOG_TOP + 60 * GRID_H;
      w = 27 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_moveToLayer_move";
    };
    class Cancel: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 28 * GRID_W;
      y = DIALOG_TOP + 60 * GRID_H;
      w = 27 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};