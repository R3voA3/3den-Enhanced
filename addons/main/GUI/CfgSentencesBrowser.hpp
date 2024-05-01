class ENH_CfgSentencesBrowser
{
  idd = IDD_SENTENCESBROWSER;
  onLoad = "_this call ENH_fnc_CFGS_onLoad";
  onUnload = "profileNamespace setVariable ['ENH_CFGS_Favorites', ENH_CFGS_Favorites];";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
      h = QUOTE(WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H);
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_MAIN_TOOLS_CFGSENTENCESBROWSER";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
      y = QUOTE(WINDOW_TOPAbs);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Footer: ctrlStaticFooter
    {
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
    };
    class Count: ctrlStatic
    {
      idc = IDC_SENTENCESBROWSER_COUNT;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + WINDOW_W_ATTRIBUTES * GRID_W - 11 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs);
      w = QUOTE(11 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
  };
  class Controls
  {
    class Pages: ctrlToolbox
    {
      idc = IDC_SENTENCESBROWSER_PAGES;
      columns = 2;
      rows = 1;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W);
      y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
      strings[] = {"$STR_A3_WL_PARAM19_TITLE", "$STR_3DEN_FAVORITE_TEXTPLURAL"};
      colorSelectedBg[] = {0.2, 0.2, 0.2, 1};
      onToolBoxSelChanged = "_this call ENH_fnc_CFGS_changePage";
    };
    class List: ctrlTree
    {
      idc = IDC_SENTENCESBROWSER_LIST;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + 11 * GRID_H);
      w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W);
      h = QUOTE(WINDOW_PREVIEW_HAbs - 6 * CTRL_DEFAULT_H + GRID_H);
      colorBorder[] = {0, 0, 0, 0};
      idcSearch = IDC_SENTENCESBROWSER_SEARCH;
      onTreeDblClick = "'play' call ENH_fnc_CFGS_playOrCopy";
    };
    class ListFavorites: List
    {
      idc = IDC_SENTENCESBROWSER_FAVORITES;
      onTreeDblClick = "'play' call ENH_fnc_CFGS_playOrCopy";
    };
    class Search: ctrlEdit
    {
      idc = IDC_SENTENCESBROWSER_SEARCH;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 45 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class ButtonSearch: ctrlButtonSearch
    {
      idc = IDC_SENTENCESBROWSER_BUTTONSEARCH;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 70 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Filter: ctrlCombo
    {
      idc = IDC_SENTENCESBROWSER_FILTER;
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 76 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(22 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
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
    class Play: ctrlButtonPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Attributes\ComboPreview\play_ca.paa";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
      onButtonClick = "'play' call ENH_fnc_CFGS_playOrCopy";
    };
    class Copy: ctrlButton
    {
      text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_ENTITYCOPY_TEXT";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 7 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
      onButtonClick = "'copy' call ENH_fnc_CFGS_playOrCopy";
    };
    class HandleFavorite: ctrlButtonPictureKeepAspect
    {
      text = "\a3\3den\data\displays\display3den\panelright\modefavorites_ca.paa";
      tooltip = "$STR_ENH_MAIN_CFGS_HANDLEFAVORITES_TOOLTIP";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 33 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
      onButtonClick = "'' call ENH_fnc_CFGS_handleFavorites";
    };
    class Biki: ctrlButton
    {
      text = "?";
      url = "https://community.bistudio.com/wiki/Conversations";
      x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 39 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(5 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
    class Close: ctrlButtonClose
    {
      x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W);
      y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
      w = QUOTE(25 * GRID_W);
      h = QUOTE(CTRL_DEFAULT_H);
    };
  };
};