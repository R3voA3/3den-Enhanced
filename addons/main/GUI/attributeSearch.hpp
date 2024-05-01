class ENH_AttributeSearch
{
  idd = IDD_ATTRIBUTESEARCH;
  onLoad = "_this call ENH_fnc_attributeSearch_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
      h = QUOTE(WINDOW_HAbs - 3 * CTRL_DEFAULT_H);
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_MAIN_SEARCHATTRIBUTES_HEADER";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
      y = QUOTE(WINDOW_TOPAbs);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Footer: ctrlStaticFooter
    {
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
    };
    class Counter: ctrlStatic
    {
      idc = IDC_ATTRIBUTESEARCH_COUNTER;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 46 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
  };
  class Controls
  {
    class TreeView: ctrlTree
    {
      idc = IDC_ATTRIBUTESEARCH_TREE;
      idcSearch = IDC_ATTRIBUTESEARCH_SEARCH;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W);
      h = QUOTE(WINDOW_HAbs - 5 * CTRL_DEFAULT_H + GRID_H);
      borderSize = 0;
      colorBorder[] = {0, 0, 0, 0};
      colorBackground[] = {COLOR_TAB_RGBA};
    };
    class Search: ctrlEdit
    {
      idc = IDC_ATTRIBUTESEARCH_SEARCH;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(40 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_ATTRIBUTESEARCH_BUTTONSEARCH;
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 41 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class EditAttributes: ctrlButton
    {
      idc = IDC_ATTRIBUTESEARCH_EDITATTRIBUTES;
      x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - (36 + 26) * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(35 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class ButtonClose: ctrlButtonClose
    {
      x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
  };
};