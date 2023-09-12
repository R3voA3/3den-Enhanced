class ENH_VariableViewer
{
  idd = IDD_VARIABLEVIEWER;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_variableViewer_onLoad";
  class ControlsBackground
  {
    //DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_VARIABLEVIEWER_HEADER";
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP;
      w = WINDOW_WAbs * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + CTRL_DEFAULT_H;
      w = WINDOW_WAbs * GRID_W;
      h = WINDOW_HAbs - 5 * CTRL_DEFAULT_H;
    };
    class BackgroundFilter: Background//Background used for filter buttons
    {
      h = CTRL_DEFAULT_H;
      colorBackground[] = {0, 0, 0, 1};
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_WAbs * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class FooterInputFields: Footer
    {
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 6 * CTRL_DEFAULT_H - 4  * GRID_H;
      w = 127 * GRID_W;
    };
    class HideFunctionsText: ctrlStatic
    {
      text = "$STR_ENH_VARIABLEVIEWER_HIDEFUNCTIONS";
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 35 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 1 * GRID_H;
      w = 28 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class VariableNameText: ctrlStatic
    {
      text = "$STR_ENH_VARIABLEVIEWER_VARIABLENAME";
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 6 * CTRL_DEFAULT_H - 3 * GRID_H;
      w = 10 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class VariableValueText: VariableNameText
    {
      text = "$STR_ENH_VARIABLEVIEWER_VARIABLEVALUE";
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 57 * GRID_W;
    };
    class VariableCount: ctrlStatic
    {
      idc = IDC_VARIABLEVIEWER_VARIABLECOUNT;
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 100 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 1 * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class List: ctrlListNBox
    {
      idc = IDC_VARIABLEVIEWER_LIST;
      style = LB_MULTI + LB_TEXTURES;
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + 2 * CTRL_DEFAULT_H;
      w = WINDOW_WAbs * GRID_W;
      h = WINDOW_HAbs - 9 * CTRL_DEFAULT_H;
      disableOverflow = true;
      columns[] = {0, 0.4, 0.85};
    };
    class Filter: List
    {
      idc = IDC_VARIABLEVIEWER_FILTER;
      y = WINDOW_TOP + CTRL_DEFAULT_H;
      h = CTRL_DEFAULT_H;
    };
    class Namespace: ctrlCombo
    {
      idc = IDC_VARIABLEVIEWER_NAMESPACE;
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 55 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 1 * GRID_H;
      w = 45 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchEdit: ctrlEdit
    {
      idc = IDC_VARIABLEVIEWER_SEARCH;
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 1 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchButton: ctrlButtonSearch
    {
      idc = IDC_VARIABLEVIEWER_SEARCHBUTTON;
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 26 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 1 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class HideFunctions: ctrlCheckbox
    {
      idc = IDC_VARIABLEVIEWER_HIDEFUNCTIONS;
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 31 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 1 * GRID_H;
      w = 5 * GRID_W;
      h = 5 * GRID_H;
    };
    class VariableName: ctrlEdit
    {
      idc = IDC_VARIABLEVIEWER_VARIABLENAME;
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 12 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 6 * CTRL_DEFAULT_H - 3 * GRID_H;
      w = 45 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class VariableValue: VariableName
    {
      idc = IDC_VARIABLEVIEWER_VARIABLEVALUE;
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 69 * GRID_W;
    };
    class Delete: ctrlButtonPictureKeepAspect
    {
      idc = IDC_VARIABLEVIEWER_DELETE;
      text = "a3\3den\data\displays\display3den\panelright\customcomposition_edit_ca.paa";
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 115 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 6 * CTRL_DEFAULT_H - 3 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this spawn ENH_fnc_variableViewer_delete";
    };
    class Set: Delete
    {
      idc = IDC_VARIABLEVIEWER_SET;
      text = "a3\3den\data\displays\display3den\toolbar\save_ca.paa";
      x = CENTER_X - 0.5 * WINDOW_WAbs * GRID_W + 121 * GRID_W;
      onButtonClick = "_this spawn ENH_fnc_variableViewer_setOrCreate";
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_WAbs * GRID_W - 26 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 1 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};