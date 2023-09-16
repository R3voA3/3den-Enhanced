class ENH_ModuleInformation
{
  idd = IDD_MODULEINFORMATION;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_moduleInformation_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_MODULEINFORMATION";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_PREVIEW_HAbs;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOP + WINDOW_PREVIEW_HAbs - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = 7 * GRID_H;
    };
  };
  class Controls
  {
    class DescriptionValue: ctrlStructuredText
    {
      idc = IDC_MODULEINFORMATION_DESCRIPTION;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W;
      y = WINDOW_TOP + 6 * GRID_H;
      w = (WINDOW_W_ATTRIBUTES - 2) * GRID_W;
      h = WINDOW_PREVIEW_HAbs - 9 * GRID_H;
      colorBackground[] = {COLOR_OVERLAY_RGBA};
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES - 26) * GRID_W;
      y = WINDOW_TOP + WINDOW_PREVIEW_HAbs - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};