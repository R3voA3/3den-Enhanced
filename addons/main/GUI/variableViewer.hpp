class ENH_VariableViewer
{
  idd = IDD_VARIABLEVIEWER;
  onLoad = "_this call ENH_fnc_variableViewer_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_MAIN_VARIABLEVIEWER_HEADER";
      x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs);
      w = QUOTE(WINDOW_W_WIDE * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Background: ctrlStaticBackground
    {
      x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
      w = QUOTE(WINDOW_W_WIDE * GRID_W);
      h = QUOTE(WINDOW_HAbs - 3 * CTRL_DEFAULT_H);
    };
    class BackgroundFilter: Background//Background used for filter buttons
    {
      h = QUOTE(CTRL_DEFAULT_H);
      colorBackground[] = {0, 0, 0, 1};
    };
    class Footer: ctrlStaticFooter
    {
      x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
      w = QUOTE(WINDOW_W_WIDE * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
    };
    class FooterInputFields: Footer
    {
      x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 4 * GRID_H);
      w = QUOTE(127 * GRID_W);
    };
    class HideFunctionsText: ctrlStatic
    {
      text = "$STR_ENH_MAIN_VARIABLEVIEWER_HIDEFUNCTIONS";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 35 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(28 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class VariableNameText: ctrlStatic
    {
      text = "$STR_ENH_MAIN_VARIABLEVIEWER_VARIABLENAME";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H);
      w = QUOTE(10 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class VariableValueText: VariableNameText
    {
      text = "$STR_ENH_MAIN_VARIABLEVIEWER_VARIABLEVALUE";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 57 * GRID_W);
    };
    class VariableCount: ctrlStatic
    {
      idc = IDC_VARIABLEVIEWER_VARIABLECOUNT;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 100 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(20 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
  };
  class Controls
  {
    class List: ctrlListNBox
    {
      idc = IDC_VARIABLEVIEWER_LIST;
      x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H);
      w = QUOTE(WINDOW_W_WIDE * GRID_W);
      h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H - 2 * GRID_H);
      disableOverflow = 1;
      columns[] = {0, 0.4, 0.85};

    };
    class Filter: List
    {
      idc = IDC_VARIABLEVIEWER_FILTER;
      y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Namespace: ctrlCombo
    {
      idc = IDC_VARIABLEVIEWER_NAMESPACE;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 55 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(45 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class SearchEdit: ctrlEdit
    {
      idc = IDC_VARIABLEVIEWER_SEARCH;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class SearchButton: ctrlButtonSearch
    {
      idc = IDC_VARIABLEVIEWER_SEARCHBUTTON;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 26 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class HideFunctions: ctrlCheckbox
    {
      idc = IDC_VARIABLEVIEWER_HIDEFUNCTIONS;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 31 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(5 * GRID_H);
    };
    class VariableName: ctrlEdit
    {
      idc = IDC_VARIABLEVIEWER_VARIABLENAME;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 12 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H);
      w = QUOTE(45 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class VariableValue: VariableName
    {
      idc = IDC_VARIABLEVIEWER_VARIABLEVALUE;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 69 * GRID_W);
    };
    class Delete: ctrlButtonPictureKeepAspect
    {
      idc = IDC_VARIABLEVIEWER_DELETE;
      text = "a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 115 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
      onButtonClick = "_this spawn ENH_fnc_variableViewer_delete";
    };
    class Set: Delete
    {
      idc = IDC_VARIABLEVIEWER_SET;
      text = "a3\3den\data\displays\display3den\toolbar\save_ca.paa";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 121 * GRID_W);
      onButtonClick = "_this spawn ENH_fnc_variableViewer_setOrCreate";
    };
    class Close: ctrlButtonClose
    {
      x = QUOTE(CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 26 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
  };
};