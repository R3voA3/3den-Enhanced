#define DIALOG_W 60
#define DIALOG_H 68

class ENH_Garrison: ctrlControlsGroupNoScrollbars
{
  idc = IDC_GARRISON_GROUP;
  onLoad = "call ENH_fnc_garrison_onLoad";
  x = 0.5 - 0.5 * DIALOG_W * GRID_W;
  y = WINDOW_TOPAbs;
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
      x = 16 * GRID_W;
      y = 2 * (CTRL_DEFAULT_H + GRID_H);
      w = 43 * GRID_W;
      h = 14 * GRID_H;
    };
    class Coverage: Blacklist
    {
      text = "$STR_ENH_GARRISON_COVERAGE";
      y = 5 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
    };
    class CoverageValue: ctrlToolbox
    {
      idc = IDC_GARRISON_COVERAGE;
      x = 16 * GRID_W;
      y = 5 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
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
      y = 6 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
    };
    class StanceValue: ctrlToolbox
    {
      idc = IDC_GARRISON_STANCE;
      x = 16 * GRID_W;
      y = 6 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
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
      y = 7 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
    };
    class ModeValue: ctrlCombo
    {
      idc = IDC_GARRISON_MODE;
      x = 16 * GRID_W;
      y = 7 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = 43 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class PathFinding: Blacklist
    {
      text = "$STR_ENH_DISABLEAI_PATH_DISPLAYNAME";
      tooltip = "$STR_ENH_DISABLEAI_PATH_TOOLTIP";
      y = 8 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = 25 * GRID_W;
    };
    class PathFindingValue: ctrlToolbox
    {
      idc = IDC_GARRISON_PATH;
      x = 16 * GRID_W;
      y = 8 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
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
      y = 9 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H;
      w = DIALOG_W * GRID_W - GRID_W;
      h = 2 * CTRL_DEFAULT_H;
    };
    class BackgroundButton: ctrlStaticFooter
    {
      y = DIALOG_H * GRID_H - CTRL_DEFAULT_H - 2 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
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