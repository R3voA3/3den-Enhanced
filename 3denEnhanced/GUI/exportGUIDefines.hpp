#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

#define DIALOG_W 53

class ENH_ExportGUIDefines
{
  idd = IDD_EXPORTGUIDEFINES;
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
      h = 21 * GRID_H;
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 18 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 3 * GRID_H;
    };
  };
  class Controls
  {
    class Target: ctrlStatic
    {
      text = "$STR_WATCH_TARGET";
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
          text = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES_ADDON";
          tooltip = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES_ADDON_TOOLTIP";
          default = 1;
        };
        class Scenario
        {
          text = "$STR_A3_CFGUIGRIDS_IGUI_VARIABLES_GRID_MISSION_0";
          tooltip = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES_SCENARIO_TOOLTIP";
        };
      };
    };
    class Types: Target
    {
      text = "$STR_A3_TO_BASICCIVILIANPRESENCE12";
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
          text = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES_CLASSIC";
          tooltip = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES_CLASSIC_TOOLTIP";
          data = "classic";
          default = 1;
        };
        class Eden
        {
          text = "$STR_A3_CFGMODS_APEX_FEATURE_EDEN_NAME";
          tooltip = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES_EDEN_TOOLTIP";
          data = "3DEN";
        };
        class All
        {
          text = "$STR_GEAR_ALL";
          tooltip = "$STR_ENH_TOOLS_EXPORTGUIBASECLASSES_ALL_TOOLTIP";
          data = "";
        };
      };
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 26) * GRID_W;
      y = DIALOG_TOP + 20 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Ok: ctrlButtonOK
    {
      idc = -1;//We don't want it to close the GUI. The function does that.
      x = CENTERED_X(DIALOG_W) + (DIALOG_W - 52) * GRID_W;
      y = DIALOG_TOP + 20 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "private _display = ctrlParent (_this # 0); [lbCurSel (_display displayCtrl 10), lbCurSel (_display displayCtrl 20)] call ENH_fnc_exportGUIDefines";
    };
  };
};