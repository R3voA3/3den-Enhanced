#include "\3denEnhanced\defines\ENH_defineCommon.hpp"
#define DIALOG_W 60
#define DIALOG_H 80

class ENH_Garrison_New: ctrlControlsGroupNoScrollbars
{
  idc = IDC_GARRISON_GROUP;
  onLoad = "call ENH_fnc_garrison_onLoad";
  x = safezoneX + 61 * GRID_W;
  y = DIALOG_TOP;
  w = DIALOG_W * GRID_W;
  h = DIALOG_H * GRID_H;
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_GARRISON_HEADER";
      x = 0;
      y = 0;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = 0;
      y = CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H - CTRL_DEFAULT_H;
    };
    class BlacklistToggle: ctrlToolbox
    {
      idc = IDC_GARRISON_BLACKLIST_TOGGLE;
      x = GRID_W;
      y = CTRL_DEFAULT_H + GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 2;
      strings[] = {"$STR_ENH_GARRISON_BLACKLIST", "$STR_ENH_GARRISON_WHITELIST"};
      values[] = {0, 1};
    };
    class Blacklist: ctrlStatic
    {
      idc = -1;
      text = "$STR_ENH_AIRDROP_CLASSES_DISPLAYNAME";
      y = 2 * (CTRL_DEFAULT_H + GRID_H);
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class BlacklistValue: ctrlEditMulti
    {
      idc = IDC_GARRISON_BLACKLIST_VALUE;
      x = GRID_W;
      y = 3 * (CTRL_DEFAULT_H + GRID_H);
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = 14 * GRID_H;
    };
    class Coverage: Blacklist
    {
      text = "$STR_ENH_GARRISON_COVERAGE";
      y = 6 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
    };
    class CoverageValue: ctrlToolbox
    {
      idc = IDC_GARRISON_COVERAGE;
      x = 16 * GRID_W;
      y = 6 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 4;
      strings[] =
      {
        "$STR_ENH_GARRISON_10PERCENT",
        "$STR_ENH_GARRISON_25PERCENT",
        "$STR_ENH_GARRISON_50PERCENT",
        "$STR_ENH_GARRISON_100PERCENT"
      };
    };
    class Stance: Blacklist
    {
      text = "$STR_ENH_GARRISON_STANCE";
      y = 7 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
    };
    class StanceValue: ctrlToolbox
    {
      idc = IDC_GARRISON_STANCE;
      x = 16 * GRID_W;
      y = 7 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 5;
      strings[] =
      {
        "\a3\3DEN\Data\Attributes\Stance\up_ca.paa",
        "\a3\3DEN\Data\Attributes\Stance\middle_ca.paa",
        "\a3\3DEN\Data\Attributes\Stance\down_ca.paa",
        "\a3\3DEN\Data\Attributes\default_ca.paa",
        "\a3\ui_f\data\igui\cfg\simpletasks\types\unknown_ca.paa"
      };
      tooltips[] =
      {
        "$STR_3DEN_ATTRIBUTES_STANCE_UP",
        "$STR_3DEN_ATTRIBUTES_STANCE_MIDDLE",
        "$STR_3DEN_ATTRIBUTES_STANCE_DOWN",
        "$STR_3DEN_ATTRIBUTES_STANCE_DEFAULT",
        "$STR_A3_RSCDISPLAYARSENAL_BUTTONRANDOM"
      };
      style = "0x02 + 0x30 + 0x800";
    };
    class Mode: Blacklist
    {
      text = "$STR_ENH_GARRISON_MODE";
      y = 8 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
    };
    class ModeValue: ctrlCombo
    {
      idc = IDC_GARRISON_MODE;
      x = 16 * GRID_W;
      y = 8 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class PathFinding: Blacklist
    {
      text = "$STR_ENH_DISABLEAI_PATH_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_PATH_TOOLTIP";
      y = 9 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = 25 * GRID_W;
    };
    class PathFindingValue: ctrlToolbox
    {
      idc = IDC_GARRISON_PATH;
      x = 16 * GRID_W;
      y = 9 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 2;
      strings[] =
      {
        "$STR_DISABLED",
        "$STR_ENABLED"
      };
    };
    class Info: ctrlStructuredText
    {
      idc = IDC_GARRISON_INFO;
      y = 10 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = DIALOG_W * GRID_W - GRID_W;
      h = 2 * CTRL_DEFAULT_H;
    };
    class BackgroundButton: ctrlStaticFooter
    {
      y = DIALOG_H * GRID_H - CTRL_DEFAULT_H - 2 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class BackgroundButtonCenter: ctrlStaticFooter
    {
      x = DIALOG_W / 2 * GRID_W - 21 * GRID_W;
      y = 12 * (CTRL_DEFAULT_H + GRID_H) - 6 * GRID_H;
      w = 42 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class UpdateSelection: ctrlButton
    {
      idc = IDC_GARRISON_UPDATE_SELECTION;
      text = "$STR_ENH_GARRISON_UPDATESELECTION";
      x = DIALOG_W / 2 * GRID_W - 20 * GRID_W;
      y = 12 * (CTRL_DEFAULT_H + GRID_H) - 5 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Cancel: ctrlButtonCancel
    {
      idc = IDC_GARRISON_CANCEL;
      x = DIALOG_W * GRID_W - 26 * GRID_W;
      y = DIALOG_H * GRID_H - CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Ok: ctrlButtonOK
    {
      idc = IDC_GARRISON_OK;//We don't want it to close the GUI. The function does that.
      x = GRID_W;
      y = DIALOG_H * GRID_H - CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};

/* #define DIALOG_W 60

class ENH_Garrison
{
  idd = IDD_GARRISON;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_garrison_onLoad";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = 25 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_GARRISON_HEADER";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Radius: ctrlStatic
    {
      text = "$STR_ENH_PLACEMENTTOOLS_RADIUS";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 6 * GRID_H;
      w = 15 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class RadiusEdit: ctrlEdit
    {
      idc = IDC_GARRISON_RADIUS;
      x = CENTERED_X(DIALOG_W) + 16 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Coverage: ctrlStatic
    {
      text = "$STR_ENH_GARRISON_COVERAGE";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 12 * GRID_H;
      w = 15 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class CoverageValue: ctrlToolbox
    {
      idc = IDC_GARRISON_COVERAGE;
      x = CENTERED_X(DIALOG_W) + 16 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 4;
      strings[] =
      {
        "$STR_ENH_GARRISON_10PERCENT",
        "$STR_ENH_GARRISON_25PERCENT",
        "$STR_ENH_GARRISON_50PERCENT",
        "$STR_ENH_GARRISON_100PERCENT"
      };
      values[] = {10, 4, 2, 1};
    };
    class Stance: ctrlStatic
    {
      text = "$STR_ENH_GARRISON_STANCE";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 18 * GRID_H;
      w = 15 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class StanceValue: ctrlToolbox
    {
      idc = IDC_GARRISON_STANCE;
      x = CENTERED_X(DIALOG_W) + 16 * GRID_W;
      y = DIALOG_TOP + 18 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 3;
      strings[] =
      {
        "$STR_ENH_GARRISON_STANCE_AUTO",
        "$STR_ENH_GARRISON_STANCE_CROUCH",
        "$STR_ENH_GARRISON_STANCE_STAND"
      };
      values[] = {0, 1, 2, 3};
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(DIALOG_W) + 34 * GRID_W;
      y = DIALOG_TOP + 24 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Ok: ctrlButtonOK
    {
      idc = -1;//We don't want it to close the GUI. The function does that.
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 24 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_garrison_garrison";
    };
  };
}; */