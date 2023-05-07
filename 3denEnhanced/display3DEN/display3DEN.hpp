class Display3DEN
{
  class ContextMenu: ctrlMenu
  {
    class Items
    {
      #include "contextMenu.hpp"
    };
  };
  class Controls
  {
    #include "statusbar.hpp"
    class MenuStrip: ctrlMenuStrip
    {
      class Items
      {
        items[] += {"ENH_About"};//new main category
        #include "menuStrip_about.hpp"
        #include "menuStrip_tools.hpp"
        #include "menuStrip_help.hpp"
      };
    };
    class PanelRight: ctrlControlsGroupNoScrollbars
    {
      class Controls
      {
        class PanelRightHistory;
        class PanelRightFavorites: PanelRightHistory
        {
          idc = 1337;
          class Controls
          {
            class Footer: ctrlStaticFooter
            {
              y = safezoneH - (28 + 13) * GRID_H;
              w = 60 * GRID_W;
              h = 13 * GRID_H;
            };
            class Text: ctrlStatic
            {
              text = "$STR_ENH_DISPLAY3DEN_PLACEENTITY";
              y = safezoneH - (28 + 12) * GRID_H;
              w = 60 * GRID_W;
              h = CTRL_DEFAULT_H;
              style = 2;
            };
            class Search: ctrlEdit
            {
              idc = 1336;
              x = GRID_W;
              y = GRID_H;
              w = 58 * GRID_W;
              h = CTRL_DEFAULT_H;
            };
            class Favorites: ctrlTree
            {
              idc = 1338;
              idcSearch = 1336;
              x = 0;
              y = 7 * GRID_H;
              w = 60 * GRID_W;
              h = safezoneH - (28 + 21) * GRID_H;
              borderSize = 0;
              colorBorder[] = {0,0,0,0};
              multiselectEnabled = 1;
            };
            class RemoveFromList: ctrlButton
            {
              idc = 1339;
              text = "$STR_DISP_DELETE";
              x = GRID_W;
              y = safezoneH - (28 + 6) * GRID_H;
              w = 58 * GRID_W;
              h = CTRL_DEFAULT_H;
            };
          };
        };
        class TabRightSections: ctrlToolbox
        {
          columns = 3;
          strings[] = {"$STR_3DEN_DISPLAY3DEN_ASSETS", "$STR_3DEN_DISPLAY3DEN_HISTORY", "$STR_3DEN_FAVORITE_TEXTPLURAL"};
          values[] = {1039, 1040, 1337};
        };
      };
    };
    class PanelLeft: ctrlControlsGroupNoScrollbars
    {
      class Controls
      {
        class PanelLeftEdit: ctrlControlsGroupNoScrollbars
        {
          class Controls
          {
            class EditPanel: ctrlControlsGroupNoScrollbars
            {
              class Controls
              {
                class Delete;
                class ENH_DeleteEmptyLayers: Delete
                {
                  idc = -1;
                  text = "\3denEnhanced\data\entitylist_deleteEmpty_ca.paa";
                  x = 7 * GRID_W;
                  tooltip = "$STR_ENH_TOOLS_DELETEEMPTYLAYERS";
                  onButtonClick = "call ENH_fnc_deleteEmptyLayers";
                };
                class ENH_SelectLayers: Delete
                {
                  idc = -1;
                  text = "\3denEnhanced\data\selectAllLayers_ca.paa";
                  x = 29 * GRID_W;
                  tooltip = "$STR_ENH_TOOLS_SELECTALLLAYERS";
                  onButtonClick = "set3DENSelected (all3DENEntities # 6)";
                };
              };
            };
          };
        };
      };
    };
  };
};
