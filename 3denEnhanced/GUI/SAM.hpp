class ENH_SAM
{
  idd = IDD_SAM;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_SAM";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TOOLS_SAM";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Templates: ctrlStatic
    {
      text = "$STR_ENH_SAM_TEMPLATES";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + 6 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Attributes: ctrlStatic
    {
      text = "$STR_ENH_SAM_ATTRIBUTES";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 51 * GRID_W;
      y = WINDOW_TOPAbs + 6 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TemplateList: ctrlListbox
    {
      idc = IDC_SAM_TEMPLATES;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 12 * GRID_H;
      w = 50 * GRID_W;
      h = WINDOW_HAbs - 11 * CTRL_DEFAULT_H + GRID_H;
      onLBSelChanged = "[nil, 'loadTemplate'] call ENH_fnc_SAM";
    };
    class AttributeList: ctrlTree
    {
      idc = IDC_SAM_ATTRIBUTES;
      idcSearch = 1400;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 52 * GRID_W;
      y = WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 2 * GRID_H;
      w = (WINDOW_W_ATTRIBUTES - 53) * GRID_W;
      h = WINDOW_HAbs - 6 * CTRL_DEFAULT_H;
      borderSize = 0;
      colorBorder[] = {0, 0, 0, 0};
      colorBackground[] = {COLOR_TAB_RGBA};
    };
    class Search: ctrlEdit
    {
      idc = IDC_SAM_SEARCH;
      tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 52 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_SAM_BUTTONSEARCH;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 87 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Collapse: ctrlButtonCollapseAll
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 92 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
    };
    class Expand: ctrlButtonExpandAll
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 97 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
    };
    class CreateTemplate: ctrlButton
    {
      text = "$STR_ENH_ESE_CREATETEMPLATE";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 7 * CTRL_DEFAULT_H - 6 * GRID_H;
      w = 50 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[nil, 'createTemplate'] call ENH_fnc_SAM";
    };
    class DeleteTemplate: CreateTemplate
    {
      text = "$STR_ENH_SAM_DELETETEMPLATE";
      y = WINDOW_TOPAbs + WINDOW_HAbs - 6 * CTRL_DEFAULT_H - 5 * GRID_H;
      onButtonClick = "[nil, 'deleteTemplate'] call ENH_fnc_SAM";
    };
    class ApplyTemplate: CreateTemplate
    {
      text = "$STR_ENH_SAM_APPLYTEMPLATE";
      y = WINDOW_TOPAbs + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 4 * GRID_H;
      onButtonClick = "[nil, 'applyTemplate'] call ENH_fnc_SAM";
    };
    class ApplyAttribute: CreateTemplate
    {
      text = "$STR_ENH_SAM_APPLYATTRIBUTE";
      y = WINDOW_TOPAbs + WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H;
      onButtonClick = "[nil, 'applyAttribute'] call ENH_fnc_SAM";
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};