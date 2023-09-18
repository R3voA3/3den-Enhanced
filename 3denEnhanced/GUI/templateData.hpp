class ENH_ESE_TemplateData
{
  idd = IDD_TEMPLATEDATA;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
  class Header: ctrlStaticTitle
    {
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOP;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOP + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 51 * GRID_H;
    };
    class Title: ctrlStatic
    {
      text = "$STR_ENH_TEMPLATE_DATA_TITLE";
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOP + CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Description: ctrlStatic
    {
      text = "$STR_ENH_TEMPLATE_DATA_DESCRIPTION";
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOP + 3 * CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * 60 * GRID_W;
      y = WINDOW_TOP + 49 * GRID_H;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class TitleValue: ctrlEdit
    {
      idc = IDC_ESE_TEMPLATEDATA_TITLE;
      x = CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOP + 2 * CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class DescriptionValue: ctrlEditMulti
    {
      idc = IDC_ESE_TEMPLATEDATA_DESCRIPTION;
      x = CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOP + 4 * CTRL_DEFAULT_H + GRID_H;
      w = 58 * GRID_W;
      h = 25 * GRID_H;
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTER_X - 0.5 * 60 * GRID_W + 34 * GRID_W;
      y = WINDOW_TOP + 50 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class OK: ctrlButtonOk
    {
      idc = -1;
      x = CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOP + 50 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "'create' call ENH_fnc_ESE_handleTemplates";
    };
  };
};

class ENH_SAM_TemplateData: ENH_ESE_TemplateData
{
  class Controls: Controls
  {
    class OK: ctrlButtonOK
    {
      onButtonClick = "_this call ENH_fnc_SAM_createTemplate";
    };
  };
};