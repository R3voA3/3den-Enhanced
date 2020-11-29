#include "\3denEnhanced\defineCommon.hpp"
#define DIALOG_W 170
#define DIALOG_H 120

class ENH_VariableViewer
{
  idd = IDD_VARIABLEVIEWER;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_variableViewer_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H + 7 * GRID_H;
    };
    class BackgroundFilter: Background//Background used for filter buttons
    {
      h = CTRL_DEFAULT_H;
      colorBackground[] = {0,0,0,1};
    };
    class Header: ctrlStaticTitle
    {
      text = $STR_ENH_VARIABLEVIEWER_HEADER;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class List: ctrlListNBox
    {
      idc = IDC_VARIABLEVIEWER_LIST;
      style = LB_MULTI + LB_TEXTURES;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = (DIALOG_W - 2) * GRID_W;
      h = (DIALOG_H - 15) * GRID_H;
      disableOverflow = true;
      columns[] = {-0.008,0.4,0.85};//Create columns and move first column a tat to the left
      onLBSelChanged = "_this call ENH_fnc_variableViewer_onLNBSelChanged";
    };
    class Filter: List
    {
      idc = IDC_VARIABLEVIEWER_FILTER;
      y = DIALOG_TOP + 5 * GRID_H;
      h = CTRL_DEFAULT_H;
    };
    class Namespace: ctrlCombo
    {
      idc = IDC_VARIABLEVIEWER_NAMESPACE;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "_this call ENH_fnc_variableViewer_onFilterChanged";
    };
    class VariableCount: ctrlStatic
    {
      idc = IDC_VARIABLEVIEWER_VARIABLECOUNT;
      x = CENTERED_X(DIALOG_W) + 37 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchEdit: ctrlEdit
    {
      idc = IDC_VARIABLEVIEWER_SEARCH;
      x = CENTERED_X(DIALOG_W) + 47 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchButton: ctrlButtonSearch
    {
      idc = IDC_VARIABLEVIEWER_SEARCHBUTTON;
      x = CENTERED_X(DIALOG_W) + 67 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_variableViewer_onSearch";
    };
    class HideFunctionsText: ctrlStatic
    {
      text = $STR_ENH_VARIABLEVIEWER_HIDEFUNCTIONS;
      x = CENTERED_X(DIALOG_W) + 73 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 28 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class HideFunctions: ctrlCheckbox
    {
      idc = IDC_VARIABLEVIEWER_HIDEFUNCTIONS;
      x = CENTERED_X(DIALOG_W) + 100 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 5 * GRID_W;
      h = 5 * GRID_H;
      onCheckedChanged = "_this call ENH_fnc_variableViewer_hideFunctions";
    };
    class VariableName: ctrlEdit
    {
      idc = IDC_VARIABLEVIEWER_VARIABLENAME;
      text = $STR_ENH_VARIABLEVIEWER_VARIABLENAME;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H) * GRID_H;
      w = 45 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class VariableValue: ctrlEdit
    {
      idc = IDC_VARIABLEVIEWER_VARIABLEVALUE;
      text = $STR_ENH_VARIABLEVIEWER_VARIABLEVALUE;
      x = CENTERED_X(DIALOG_W) + 47 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H) * GRID_H;
      w = 122 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Delete: ctrlButton
    {
      text = $STR_ENH_VARIABLEVIEWER_DELETE;
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 63) * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this spawn ENH_fnc_variableViewer_delete";
    };
    class Set: ctrlButton
    {
      idc = IDC_VARIABLEVIEWER_SET;
      text = $STR_ENH_VARIABLEVIEWER_SET_NEW;
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 42) * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this spawn ENH_fnc_variableViewer_setOrCreate";
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 21) * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};