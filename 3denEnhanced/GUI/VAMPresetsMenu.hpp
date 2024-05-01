class ENH_VAM_PresetMenu
{
  idd = IDD_VAM_Presets;
  class ControlsBackground
  {
    DISABLE_BACKGROUND;
    class Header: ctrlStaticTitle
    {
      text = "Virtual Arsenal Manager Presets";
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
      h = WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class BackgroundFilter: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {0, 0, 0, 1};
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Filter: ctrlListNBox
    {
      idc = IDC_VAM_PRESET_LISTNBOXFILTER;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Content: ctrlListNBox
    {
      idc = IDC_VAM_PRESET_LISTNBOXCONTENT;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_PREVIEW_HAbs - 5 * CTRL_DEFAULT_H;
      disableOverflow = 1;
    };
    class DeleteButton: ctrlButton
    {
      idc = IDC_VAM_PRESET_DELETEBUTTON;
      text = "Delete";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class LoadButton: DeleteButton
    {
      idc = IDC_VAM_PRESET_LOADBUTTON;
      text = "Load";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 27 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SaveButton: DeleteButton
    {
      idc = IDC_VAM_PRESET_SAVEBUTTON;
      text = "Save";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 53 * GRID_W;
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};