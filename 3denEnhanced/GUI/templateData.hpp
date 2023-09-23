class ENH_TemplateData
{
  idd = IDD_TEMPLATEDATA;
  onLoad = "uiNamespace setVariable ['ENH_TitleValue', nil]; uiNamespace setVariable ['ENH_DescriptionValue', nil];";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOPAbs;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 51 * GRID_H;
    };
    class Title: ctrlStatic
    {
      text = "$STR_ENH_TEMPLATE_DATA_TITLE";
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Description: ctrlStatic
    {
      text = "$STR_ENH_TEMPLATE_DATA_DESCRIPTION";
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOPAbs + 49 * GRID_H;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class TitleValue: ctrlEdit
    {
      idc = IDC_TEMPLATEDATA_TITLE;
      x = CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class DescriptionValue: ctrlEditMulti
    {
      idc = IDC_TEMPLATEDATA_DESCRIPTION;
      x = CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + 4 * CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = 25 * GRID_H;
    };
    class ButtonCancel: ctrlButtonCancel
    {
      x = CENTER_X - 0.5 * 60 * GRID_W + 34 * GRID_W;
      y = WINDOW_TOPAbs + 50 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonOK: ctrlButtonOk
    {
      x = CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + 50 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "uiNamespace setVariable ['ENH_TitleValue', ctrlText (ctrlParent (_this#0) displayCtrl 30700)]; uiNamespace setVariable ['ENH_DescriptionValue', ctrlText (ctrlParent (_this#0) displayCtrl 30800)];";
    };
  };
};