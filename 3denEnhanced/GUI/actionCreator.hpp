#define DIALOG_W 110
#define DIALOG_H 82

class ENH_ActionCreator//Do not localize. Text should be identical to wiki page
{
  idd = IDD_ACTIONCREATOR;
  movingEnable = true;
  onLoad = "[_this # 0, 'onLoad'] call ENH_fnc_actionCreator_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = """AddAction"" Creator";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W - 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Help: ctrlButton
    {
      text = "?";
      url = "https://community.bistudio.com/wiki/addAction";
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 5) * GRID_W;
      y = DIALOG_TOP;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {COLOR_ACTIVE_RGBA};
    };
    class Title: ctrlStatic
    {
      text = "Title";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 6 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TitleValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_TITLE;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Script: ctrlStatic
    {
      text = "Script";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 12 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ScriptValue: ctrlEditMulti
    {
      idc = IDC_ACTIONCREATOR_SCRIPT;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = 85 * GRID_W;
      h = 20 * GRID_H;
    };
    class Arguments: ctrlStatic
    {
      text = "Arguments";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 33 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ArgumentsValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_ARGUMENTS;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 33 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Priority: ctrlStatic
    {
      text = "Priority";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 39 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class PriorityValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_PRIORITY;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 39 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Shortcut: ctrlStatic
    {
      text = "Shortcut";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 45 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ShortcutValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_SHORTCUT;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 45 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Condition: ctrlStatic
    {
      text = "Condition";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 51 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ConditionValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_CONDITION;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 51 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Radius: ctrlStatic
    {
      text = "Radius";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 57 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class RadiusValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_RADIUS;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 57 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Selection: ctrlStatic
    {
      text = "Selection";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 63 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SelectionValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_SELECTION;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 63 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class MemoryPoint: ctrlStatic
    {
      text = "Memory Point";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 69 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class MemoryPointValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_MEMORYPOINT;
      x = CENTERED_X(DIALOG_W) + 24 * GRID_W;
      y = DIALOG_TOP + 69 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Toolbox: ctrlToolbox
    {
      idc = IDC_ACTIONCREATOR_TOOLBOX;
      type = 7;
      style = 2;

      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + 75 * GRID_H;
      w = (DIALOG_W - 2) * GRID_W;
      h = CTRL_DEFAULT_H;

      columns = 3;
      rows = 1;
      strings[] = {"Show Unconscious?", "Show Window?", "Hide on Use?"};
      checked_strings[] = {"Show Unconscious? Yes", "Show Window? Yes", "Hide on Use? Yes"};
      values[] = {0, 0, 0};
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(DIALOG_W) + 86 * GRID_W;
      y = DIALOG_TOP + 81 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Ok: ctrlButtonOK
    {
      idc = IDC_ACTIONCREATOR_OK;//We don't want it to close the GUI
      action = "call ENH_fnc_actionCreator_export";
      x = CENTERED_X(DIALOG_W) + 61 * GRID_W;
      y = DIALOG_TOP + 81 * GRID_H;
      w = 23 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};