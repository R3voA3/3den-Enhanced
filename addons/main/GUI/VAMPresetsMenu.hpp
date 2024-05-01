//#include "..\script_component.hpp"
#define DIALOG_W 120
#define DIALOG_H 100

class RscButton;

class ENH_VAM_PresetMenu {
  idd = 12345;

  class ControlsBackground {
    class Background: ctrlStaticBackground
    {
      x = QUOTE(GUI_GRID_CENTER_X + 0 * GUI_GRID_CENTER_W);
      y = QUOTE(GUI_GRID_CENTER_Y + 0 * GUI_GRID_CENTER_H);
      w = QUOTE(40 * GUI_GRID_CENTER_W);
      h = QUOTE(25 * GUI_GRID_CENTER_H);
    };
    class Header: ctrlStaticTitle
    {
      text = "Virtual Arsenal Manager Presets";
      x = QUOTE(GUI_GRID_CENTER_X + 0 * GUI_GRID_CENTER_W);
      y = QUOTE(GUI_GRID_CENTER_Y + 0 * GUI_GRID_CENTER_H);
      w = QUOTE(40 * GUI_GRID_CENTER_W);
      h = QUOTE(1 * GUI_GRID_CENTER_H);
    };
  };

  class Controls {
    class Filter: ctrlListNBox
    {
      idc = IDC_VAM_PRESET_LISTNBOXFILTER;
      x = QUOTE(1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
      y = QUOTE(1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
      w = QUOTE(38 * GUI_GRID_CENTER_W);
      h = QUOTE(1 * GUI_GRID_CENTER_H);
    };
    class Content: ctrlListNBox
    {
      idc = IDC_VAM_PRESET_LISTNBOXCONTENT;
      x = QUOTE(1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
      y = QUOTE(2 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
      w = QUOTE(38 * GUI_GRID_CENTER_W);
      h = QUOTE(20 * GUI_GRID_CENTER_H);
    };
    class LoadButton: RscButton
    {
      idc = IDC_VAM_PRESET_LOADBUTTON;
      text = "Load Preset";
      x = QUOTE(1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
      y = QUOTE(22.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
      w = QUOTE(5 * GUI_GRID_CENTER_W);
      h = QUOTE(1.5 * GUI_GRID_CENTER_H);
    };
    class SaveButton: RscButton
    {
      idc = IDC_VAM_PRESET_SAVEBUTTON;
      text = "Save Preset";
      x = QUOTE(7 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
      y = QUOTE(22.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
      w = QUOTE(5 * GUI_GRID_CENTER_W);
      h = QUOTE(1.5 * GUI_GRID_CENTER_H);
    };
    class DeleteButton: RscButton
    {
      idc = IDC_VAM_PRESET_DELETEBUTTON;
      text = "Delete Preset";
      x = QUOTE(13 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
      y = QUOTE(22.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
      w = QUOTE(5 * GUI_GRID_CENTER_W);
      h = QUOTE(1.5 * GUI_GRID_CENTER_H);
    };
    class Close: ctrlButtonClose
    {
      x = QUOTE(34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
      y = QUOTE(22.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
      w = QUOTE(5 * GUI_GRID_CENTER_W);
      h = QUOTE(1.5 * GUI_GRID_CENTER_H);
    };

    //...
  };
};

#undef DIALOG_W
#undef DIALOG_H