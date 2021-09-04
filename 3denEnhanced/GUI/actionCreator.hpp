#define DIALOG_W 110
#define DIALOG_H 82

class ENH_ActionCreator//Do not localize. Text should be identical to wiki page
{
  idd = IDD_ACTIONCREATOR;
  movingEnable = true;
  onLoad = "[_this # 0, 'onLoad'] call ENH_fnc_actionCreator";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = """AddAction"" Creator";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
    class BackgroundButtons: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 80 * GRID_H;
      w = 110 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Title: ctrlStatic
    {
      text = "Title";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 6 * GRID_H;
      w = 28 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TitleValue: ctrlEdit
    {
      idc = IDC_ACTIONCREATOR_TITLE;
      x = CENTERED_X(DIALOG_W) + 30 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 79 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Script: Title
    {
      text = "Script";
      y = DIALOG_TOP + 12 * GRID_H;
      h = CTRL_DEFAULT_H;
    };
    class ScriptValue: ctrlEditMulti
    {
      idc = IDC_ACTIONCREATOR_SCRIPT;
      x = CENTERED_X(DIALOG_W) + 30 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = 79 * GRID_W;
      h = 20 * GRID_H;
      autocomplete = "Scripting";
    };
    class Arguments: Title
    {
      text = "Arguments";
      y = DIALOG_TOP + 33 * GRID_H;
    };
    class ArgumentsValue: TitleValue
    {
      idc = IDC_ACTIONCREATOR_ARGUMENTS;
      y = DIALOG_TOP + 33 * GRID_H;
    };
    class Priority: Title
    {
      text = "Priority";
      y = DIALOG_TOP + 39 * GRID_H;
    };
    class PriorityValue: ctrlXSliderH
    {
      idc = IDC_ACTIONCREATOR_PRIORITY;
      x = CENTERED_X(DIALOG_W) + 30 * GRID_W;
      y = DIALOG_TOP + 39 * GRID_H;
      w = 79 * GRID_W;
      h = CTRL_DEFAULT_H;
      sliderRange[] = {1.5,50};
      sliderStep = 0.5;
    };
    class Shortcut: Title
    {
      text = "Shortcut";
      y = DIALOG_TOP + 45 * GRID_H;
    };
    class ShortcutValue: TitleValue
    {
      idc = IDC_ACTIONCREATOR_SHORTCUT;
      y = DIALOG_TOP + 45 * GRID_H;
    };
    class Condition: Title
    {
      text = "Condition";
      y = DIALOG_TOP + 51 * GRID_H;
    };
    class ConditionValue: TitleValue
    {
      idc = IDC_ACTIONCREATOR_CONDITION;
      y = DIALOG_TOP + 51 * GRID_H;
      autocomplete = "Scripting";
    };
    class Radius: Title
    {
      text = "Radius";
      y = DIALOG_TOP + 57 * GRID_H;
    };
    class RadiusValue: PriorityValue
    {
      idc = IDC_ACTIONCREATOR_RADIUS;
      y = DIALOG_TOP + 57 * GRID_H;
      sliderRange[] = {1,200};
      sliderStep = 1;
    };
    class ShowUnconcious: Title
    {
      text = "Show unconscious";
      y = DIALOG_TOP + 63 * GRID_H;
    };
    class ShowUnconciousValue: ctrlCheckbox
    {
      idc = IDC_ACTIONCREATOR_SHOWUNCONCIOUS;
      x = CENTERED_X(DIALOG_W) + 29 * GRID_W;
      y = DIALOG_TOP + 63 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ShowWindow: Title
    {
      text = "Show window";
      y = DIALOG_TOP + 69 * GRID_H;
    };
    class ShowWindowValue: ShowUnconciousValue
    {
      idc = IDC_ACTIONCREATOR_SHOWWINDOW;
      y = DIALOG_TOP + 69 * GRID_H;
    };
    class HideOnUse: Title
    {
      text = "Hide on use";
      y = DIALOG_TOP + 75 * GRID_H;
    };
    class HideOnUseValue: ShowUnconciousValue
    {
      idc = IDC_ACTIONCREATOR_HIDEONUSE;
      y = DIALOG_TOP + 75 * GRID_H;
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(DIALOG_W) + 81 * GRID_W;
      y = DIALOG_TOP + 81 * GRID_H;
      w = 28 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Ok: ctrlButtonOK
    {
      idc = IDC_ACTIONCREATOR_OK;//We don't want it to close the GUI
      x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
      y = DIALOG_TOP + 81 * GRID_H;
      w = 28 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "[ctrlParent (_this # 0), 'export'] call ENH_fnc_actionCreator";
    };
    class Help: Ok
    {
      idc = -1;
      text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPBIKI_TEXT";
      url = "https://community.bistudio.com/wiki/addAction";
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      onButtonClick = "";
    };
  };
};