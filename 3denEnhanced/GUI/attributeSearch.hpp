class ENH_AttributeSearch
{
  idd = IDD_ATTRIBUTESEARCH;
  onLoad = "_this call ENH_fnc_attributeSearch_onLoad";
  movingEnable = true;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_SEARCHATTRIBUTES_HEADER";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class Counter: ctrlStatic
    {
      idc = IDC_ATTRIBUTESEARCH_COUNTER;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 46 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class TreeView: ctrlTree
    {
      idc = IDC_ATTRIBUTESEARCH_TREE;
      idcSearch = IDC_ATTRIBUTESEARCH_SEARCH;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs - 5 * CTRL_DEFAULT_H + GRID_H;
    };
    class Search: ctrlEdit
    {
      idc = IDC_ATTRIBUTESEARCH_SEARCH;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_ATTRIBUTESEARCH_BUTTONSEARCH;
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 41 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class EditAttributes: ctrlButton
    {
      idc = IDC_ATTRIBUTESEARCH_EDITATTRIBUTES;
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - (36 + 26) * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonClose: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};