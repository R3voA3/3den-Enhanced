#define DIALOG_W WINDOW_WAbs
#define DIALOG_H 120

class ENH_MoveToLayer
{
  idd = -1;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_moveToLayer_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
	  class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_SELECTLAYER_MOVETOLAYER";
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
    class LayerList: ctrlTree
    {
      idc = 100;
	    idcSearch = 101;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 11 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs - 23 * GRID_H;
      borderSize = 0;
      colorBorder[] = {0,0,0,0};
      colorLines[] = {1,1,1,1};
    };
	class Search: ctrlEdit
    {
      idc = 101;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 44 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_moveToLayer_move";
    };
	class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      tooltip = "";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + 45 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Move: ctrlButtonOK
    {
      idc = -1;
      text = "$STR_A3_BOOT_M02_BIS_SIGN_MARKER";
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 52 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_moveToLayer_move";
    };
    class Cancel: ctrlButtonClose
    {
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 26 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};