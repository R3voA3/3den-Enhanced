#define DIALOG_W 140

class ENH_3DENCamPositions
{
  idd = IDD_3DENCAMPOS;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_3DENCam_updateList";
  class ControlsBackground
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_3DENCAM_HEADER";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 5 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 10 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = WINDOW_HAbs - 15 * GRID_H;
    };
    class BackgroundButton: ctrlStaticFooter
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 12 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class List: ctrlListNBox
    {
      idc = IDC_3DENCAMPOS_LIST;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 17 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs - 30 * GRID_H;
      onLBDblClick = "_this call ENH_fnc_3DENCam_set3DENCameraParameters";
      onKeyDown = "_this call ENH_fnc_3DENCam_deleteEntry";
    };
    class Description: ctrlEdit
    {
      idc = IDC_3DENCAMPOS_DESCRIPTION;
      text = "$STR_ENH_3DENCAM_DESCRIPTION";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 11 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = CTRL_DEFAULT_H;
      onSetFocus = "_this call ENH_fnc_3DENCam_onSetFocus";
      onKillFocus = "_this call ENH_fnc_3DENCam_onKillFocus";
    };
    class Save: ctrlButtonOK
    {
      idc = -1;
      text = "$STR_ENH_3DENCAM_SAVE";
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 52 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this # 0 call ENH_fnc_3DENCam_get3DENCameraParameters";
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 26 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};