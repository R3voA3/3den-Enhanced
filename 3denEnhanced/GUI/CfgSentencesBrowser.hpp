#define DIALOG_W 120
#define DIALOG_H 100

class ENH_CfgSentencesBrowser
{
  idd = IDD_SENTENCES;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_CFGS_onLoad";
  onUnload = "profileNamespace setVariable ['ENH_CFGS_Favorites',ENH_CFGS_Favorites];";
  class ControlsBackground
  {
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H + 7 * GRID_H;
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TOOLS_CFGSENTENCESBROWSER";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Count: ctrlStatic
    {
      idc = IDC_SENTENCES_COUNT;
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 11 * GRID_W;
      y = DIALOG_TOP;
      w = 11 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Separator: ctrlStaticFrame
    {
      x = CENTERED_X(DIALOG_W) + 5 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 5) * GRID_H;
      w = DIALOG_W * GRID_W - 10 * GRID_W;
    };
  };
  class Controls
  {
    class Pages: ctrlToolbox
    {
      idc = IDC_SENTENCES_PAGES;
      columns = 2;
      rows = 1;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = CTRL_DEFAULT_H;
      strings[] = {"$STR_A3_WL_PARAM19_TITLE","$STR_3DEN_FAVORITE_TEXTPLURAL"};
      colorSelectedBg[] = {0.2,0.2,0.2,1};
      onToolBoxSelChanged = "_this call ENH_fnc_CFGS_changePage";
    };
    class List: ctrlTree
    {
      idc = IDC_SENTENCES_LIST;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + 11 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = DIALOG_H * GRID_H - 7 * GRID_H;
      colorBorder[] = {0,0,0,0};
      idcSearch = 10000;
      onTreeDblClick = "'play' call ENH_fnc_CFGS_playOrCopy";
    };
    class ListFavorites: ctrlTree
    {
      idc = IDC_SENTENCES_FAVORITES;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + 11 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = DIALOG_H * GRID_H - 7 * GRID_H;
      colorBorder[] = {0,0,0,0};
      idcSearch = 10000;
      onTreeDblClick = "'play' call ENH_fnc_CFGS_playOrCopy";
    };
    class Search: ctrlEdit
    {
      idc = IDC_SENTENCES_SEARCH;
      x = CENTERED_X(DIALOG_W) + 55 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Filter: ctrlCombo
    {
      idc = IDC_SENTENCES_FILTER;
      x = CENTERED_X(DIALOG_W) + 76 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 22 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBselChanged = "_this call ENH_fnc_CFGS_changeFilter";
      class Items
      {
        class All
        {
          text = "All";
          data = "ALL";
          default = 1;
        };
        class A
        {
          text = "Episode A";
          data = "A_";
        };
        class B
        {
          text = "Episode B";
          data = "B_";
        };
        class C
        {
          text = "Episode C";
          data = "C_";
        };
        class Boot
        {
          text = "Bootcamp";
          data = "BOOT_";
        };
        class Apex
        {
          text = "Apex Protocol";
          data = "EXP_";
        };
        class Faction
        {
          text = "Factions";
          data = "FACTION_";
        };
        class Orange
        {
          text = "Laws of War";
          data = "ORANGE_";
        };
        class Showcases
        {
          text = "Showcases";
          data = "SHOWCASE_";
        };
        class Tanks
        {
          text = "Tanks";
          data = "TA_";
        };
        class TacOps
        {
          text = "Tac Ops";
          data = "TO_";
        };
      };
    };
    class Play: ctrlButton
    {
      text = "$STR_A3_RSCDISPLAYWELCOME_PARD_LIST4_TITLE";
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "'play' call ENH_fnc_CFGS_playOrCopy";
    };
    class Copy: ctrlButton
    {
      text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_ENTITYCOPY_TEXT";
      x = CENTERED_X(DIALOG_W) + 22 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "'copy' call ENH_fnc_CFGS_playOrCopy";
    };
    class HandleFavorite: ctrlButtonPictureKeepAspect
    {
      text = "\a3\3den\data\displays\display3den\panelright\modefavorites_ca.paa";
      tooltip = "$STR_ENH_CFGS_HANDLEFAVORITES_TOOLTIP";
      x = CENTERED_X(DIALOG_W) + 43 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "'' call ENH_fnc_CFGS_handleFavorites";
    };
    class Biki: ctrlButton
    {
      text = "?";
      url = "https://community.bistudio.com/wiki/Conversations";
      x = CENTERED_X(DIALOG_W) + 49 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 21 * GRID_W;
      y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
      w = 20 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};