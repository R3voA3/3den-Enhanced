#define DIALOG_W 160
#define DIALOG_H 80

class ENH_AttributeSearch
{
  idd = -1;
  onLoad = "_this call ENH_fnc_attributeSearch_onLoad";
  movingEnable = true;
  class ControlsBackground
  {
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_SEARCHATTRIBUTES_HEADER";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + DIALOG_H * GRID_H - 2 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Counter: ctrlStatic
    {
      idc = 12;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - 1 * GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class Search: ctrlEdit
    {
      idc = 10;
      x = CENTERED_X(DIALOG_W) + GRID_W + 7 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TreeView: ctrlTree
    {
      idc = 11;
      idcSearch = 10
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = DIALOG_H * GRID_H - 15 * GRID_H;
    };
    class Cancel: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + 160 * GRID_W - 28 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - 1 * GRID_H;
      w = 27 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class EditAttributes: ctrlButton
    {
      idc = 13;
      x = CENTERED_X(DIALOG_W) + 160 * GRID_W - 64 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - 1 * GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};