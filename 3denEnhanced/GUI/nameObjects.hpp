class ENH_NameObjects
{
  idd = IDD_NAMEOBJECTS;
  onLoad = "_this call ENH_fnc_nameObjects_onLoad";
  movingEnable = true;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_NAMEOBJECTS";
      x = CENTER_X - 0.5 * 53 * GRID_W;
      y = WINDOW_TOPAbs;
      w = 53 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * 53 * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = 53 * GRID_W;
      h = 37 * GRID_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * 53 * GRID_W;
      y = WINDOW_TOPAbs + 29 * GRID_H;
      w = 53 * GRID_W;
      h = 2 * CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class VariableName: ctrlStatic
    {
      text = "$STR_ENH_NAMEOBJECTS_NAME";
      x = CENTER_X - 0.5 * 53 * GRID_W;
      y = WINDOW_TOPAbs + 6 * GRID_H;
      w = 53 * GRID_W - 4 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class VariableNameValue: ctrlEdit
    {
      idc = IDC_NAMEOBJECTS_VARIABLENAME;
      x = CENTER_X - 0.5 * 53 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + 12 * GRID_H;
      w = 53 * GRID_W - 2 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class IndexStart: ctrlStatic
    {
      text = "$STR_ENH_NAMEOBJECTS_STARTINDEX";
      x = CENTER_X - 0.5 * 53 * GRID_W;
      y = WINDOW_TOPAbs + 17 * GRID_H;
      w = 53 * GRID_W - 4 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class IndexStartValue: ctrlEdit
    {
      idc = IDC_NAMEOBJECTS_INDEXSTART;
      text = "0";
      x = CENTER_X - 0.5 * 53 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + 23 * GRID_H;
      w = 53 * GRID_W - 2 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class RemoveNames: ctrlButton
    {
      text = "$STR_ENH_NAMEOBJECTS_REMOVENAMES";
      x = CENTER_X - 0.5 * 53 * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 30 * GRID_H;
      w = (53 - 2) * GRID_W;
      h = CTRL_DEFAULT_H;
      action = "'UNNAME' call ENH_fnc_nameObjects_name";
    };
    class OK: ctrlButtonOK
    {
      idc = IDC_NAMEOBJECTS_OK;//We don't want it to close the dialog
      x = CENTER_X - 0.5 * 53 * GRID_W + 1 * GRID_W;
      y = WINDOW_TOPAbs + 36 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      action = "call ENH_fnc_nameObjects_name";
    };
    class Cancel: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * 53 * GRID_W - 26 * GRID_W;
      y = WINDOW_TOPAbs + 36 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};