class ENH_AttributeSearch
{
  idd = -1;
  onLoad = "_this call ENH_fnc_attributeSearch_onLoad";
  movingEnable = true;
  class ControlsBackground
  {
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_SEARCHATTRIBUTES_HEADER";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOP + 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Counter: ctrlStatic
    {
      idc = 12;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class Search: ctrlEdit
    {
      idc = 10;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W + 7 * GRID_W;
      y = WINDOW_TOP + 6 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TreeView: ctrlTree
    {
      idc = 11;
      idcSearch = 10;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W;
      y = WINDOW_TOP + 12 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs - 6 * CTRL_DEFAULT_H;
    };
    class Cancel: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class EditAttributes: ctrlButton
    {
      idc = 13;
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - (36 + 27) * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};