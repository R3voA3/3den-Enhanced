#define DIALOG_W 53

class ENH_ExportGUIDefines
{
  idd = -1;
  movingEnable = true;
  onLoad = "";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = 20 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "Export GUI Defines Settings";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Target: ctrlStatic
    {
      text = "Target";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 6 * GRID_H;
      w = 15 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TargetValue: ctrlCombo
    {
      idc = 10;
      x = CENTERED_X(DIALOG_W) + 12 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = (DIALOG_W - 13) * GRID_W;
      h = CTRL_DEFAULT_H;
      class Items
      {
        class Mod
        {
          text = "Global Config";
          tooltip = "Uses 'class' keyword for use in global config.cpp (mod)."
          data = "mod"
          default = 1;
        };
        class Mission
        {
          text = "Mission Config";
          tooltip = "Uses 'import' keyword for use in mission config (description.ext)."
          data = "mission"
        };
      };
    };
    class Types: Target
    {
      text = "Types";
      y = DIALOG_TOP + 13 * GRID_H;
    };
    class TypesValue: TargetValue
    {
      idc = 20;
      y = DIALOG_TOP + 13 * GRID_H;
      class Items
      {
        class Classic
        {
          text = "Classic";
          tooltip = "Exports classic base classes like RscText or RscPicture."
          data = "classic"
          default = 1;
        };
        class Eden
        {
          text = "Eden Editor";
          tooltip = "Exports Eden Editor base classes like ctrlStatic or ctrlStaticPicture."
          data = "3DEN"
        };
        class All
        {
          text = "All";
          tooltip = "Exports all GUI base classes, including more exotic ones."
          data = ""
        };
      };
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 26) * GRID_W;
      y = DIALOG_TOP + 19 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Ok: ctrlButtonOK
    {
      idc = -1;//We don't want it to close the GUI. The function does that.
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 52) * GRID_W;
      y = DIALOG_TOP + 19 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_display = ctrlParent (_this # 0);\
      [(_display displayCtrl 10) lbData (lbCurSel (_display displayCtrl 10)),(_display displayCtrl 20) lbData (lbCurSel (_display displayCtrl 20))]\
      call ENH_fnc_exportGUIDefines; _display closeDisplay 0";
    };
  };
};