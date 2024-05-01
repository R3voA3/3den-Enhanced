#define DIALOG_W 60
#define DIALOG_H 68

class ENH_Garrison: ctrlControlsGroupNoScrollbars
{
  idc = IDC_GARRISON_GROUP;
  onLoad = "call ENH_fnc_garrison_onLoad";
  x = QUOTE(0.5 - 0.5 * DIALOG_W * GRID_W);
  y = QUOTE(WINDOW_TOPAbs);
  w = QUOTE(DIALOG_W * GRID_W);
  h = QUOTE(DIALOG_H * GRID_H);
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_MAIN_GARRISON_HEADER";
      x = QUOTE(0);
      y = QUOTE(0);
      w = QUOTE(DIALOG_W * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Background: ctrlStaticBackground
    {
      x = QUOTE(0);
      y = QUOTE(CTRL_DEFAULT_H);
      w = QUOTE(DIALOG_W * GRID_W);
      h = QUOTE(DIALOG_H * GRID_H - CTRL_DEFAULT_H);
    };
    class BlacklistToggle: ctrlToolbox
    {
      idc = IDC_GARRISON_BLACKLIST_TOGGLE;
      x = QUOTE(GRID_W);
      y = QUOTE(CTRL_DEFAULT_H + GRID_H);
      w = QUOTE(DIALOG_W * GRID_W - 2 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
      rows = 1;
      columns = 2;
      strings[] = {"$STR_ENH_MAIN_GARRISON_BLACKLIST", "$STR_ENH_MAIN_GARRISON_WHITELIST"};
      values[] = {0, 1};
    };
    class Blacklist: ctrlStatic
    {
      idc = -1;
      text = "$STR_ENH_MAIN_AIRDROP_CLASSES_DISPLAYNAME";
      y = QUOTE(2 * (CTRL_DEFAULT_H + GRID_H));
      w = QUOTE(20 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class BlacklistValue: ctrlEditMulti
    {
      idc = IDC_GARRISON_BLACKLIST_VALUE;
      x = QUOTE(16 * GRID_W);
      y = QUOTE(2 * (CTRL_DEFAULT_H + GRID_H));
      w = QUOTE(43 * GRID_W);
      h = QUOTE(14 * GRID_H);
    };
    class Coverage: Blacklist
    {
      text = "$STR_ENH_MAIN_GARRISON_COVERAGE";
      y = QUOTE(5 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
    };
    class CoverageValue: ctrlToolbox
    {
      idc = IDC_GARRISON_COVERAGE;
      x = QUOTE(16 * GRID_W);
      y = QUOTE(5 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
      w = QUOTE(43 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
      rows = 1;
      columns = 4;
      strings[] =
      {
        "$STR_ENH_MAIN_GARRISON_10PERCENT",
        "$STR_ENH_MAIN_GARRISON_25PERCENT",
        "$STR_ENH_MAIN_GARRISON_50PERCENT",
        "$STR_ENH_MAIN_GARRISON_100PERCENT"
      };
    };
    class Stance: Blacklist
    {
      text = "$STR_ENH_MAIN_GARRISON_STANCE";
      y = QUOTE(6 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
    };
    class StanceValue: ctrlToolbox
    {
      idc = IDC_GARRISON_STANCE;
      x = QUOTE(16 * GRID_W);
      y = QUOTE(6 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
      w = QUOTE(43 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
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
      text = "$STR_ENH_MAIN_GARRISON_MODE";
      y = QUOTE(7 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
    };
    class ModeValue: ctrlCombo
    {
      idc = IDC_GARRISON_MODE;
      x = QUOTE(16 * GRID_W);
      y = QUOTE(7 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
      w = QUOTE(43 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class PathFinding: Blacklist
    {
      text = "$STR_ENH_MAIN_DISABLEAI_PATH_DISPLAYNAME";
      tooltip = "$STR_ENH_MAIN_DISABLEAI_PATH_TOOLTIP";
      y = QUOTE(8 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
      w = QUOTE(25 * GRID_W);
    };
    class PathFindingValue: ctrlToolbox
    {
      idc = IDC_GARRISON_PATH;
      x = QUOTE(16 * GRID_W);
      y = QUOTE(8 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
      w = QUOTE(43 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
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
      y = QUOTE(9 * (CTRL_DEFAULT_H + GRID_H) - 3 * GRID_H);
      w = QUOTE(DIALOG_W * GRID_W - GRID_W);
      h = QUOTE(2 * CTRL_DEFAULT_H);
    };
    class BackgroundButton: ctrlStaticFooter
    {
      y = QUOTE(DIALOG_H * GRID_H - CTRL_DEFAULT_H - 2 * GRID_H);
      w = QUOTE(DIALOG_W * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
    };
    class Cancel: ctrlButtonCancel
    {
      idc = IDC_GARRISON_CANCEL;
      x = QUOTE(DIALOG_W * GRID_W - 26 * GRID_W);
      y = QUOTE(DIALOG_H * GRID_H - CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Ok: ctrlButtonOK
    {
      idc = IDC_GARRISON_OK;//We don't want it to close the GUI. The function does that.
      x = QUOTE(GRID_W);
      y = QUOTE(DIALOG_H * GRID_H - CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
  };
};

#undef DIALOG_W
#undef DIALOG_H