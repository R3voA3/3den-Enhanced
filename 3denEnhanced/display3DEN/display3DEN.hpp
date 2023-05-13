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
    class StatusBar: ctrlControlsGroupNoScrollbars
    {
      class Controls
      {
        class Version;//EditBox
        class TextZ;//Icon
        class ValueX;
        class ValueDis: ValueX
        {
          w = 18 * GRID_W;
        };
        class ENH_TextDir: TextZ
        {
          idc = -1;
          x = 92 * GRID_W + 2 * SPACE_X;
          text = "\a3\3den\data\attributes\loiterdirection\ccw_ca.paa";
        };
        class ENH_ValueDir: ValueX
        {
          idc = IDC_STATUSBAR_CAMDIR;
          x = 95 * GRID_W + 2 * SPACE_X;
          w = 12 * GRID_W;
          text = "0 °";
          onLoad = "(_this # 0) ctrlEnable false";
        };
        #ifndef ENH_HIDE_INTERFACE
        class ENH_SessionTime: Version
        {
          idc = IDC_STATUSBAR_SESSIONTIMER;
          tooltip = "$STR_ENH_STATUSBAR_SESSIONTIMER_TOOLTIP";
          x = ORIGIN_X_STATUSBAR - 49 * GRID_W - SPACE_X;
          onLoad = "(_this # 0) ctrlEnable false";
          style = ST_CENTER + ST_NO_RECT;
        };
        //Selected entities counter, controls are hidden by default and managed by ENH_fnc_statusbar_entityCounter
        class ENH_NumberMarkers: Version
        {
          idc = IDC_STATUSBAR_NUMMARKERS;
          x = ORIGIN_X_STATUSBAR - 56 * GRID_W - 2 * SPACE_X;
          w = 7 * GRID_W;
          onLoad = "(_this # 0) ctrlShow false; (_this # 0) ctrlEnable false";
          style = ST_CENTER + ST_NO_RECT;
        };
        class ENH_IconMarkers: TextZ
        {
          idc = IDC_STATUSBAR_ICONMARKERS;
          x = ORIGIN_X_STATUSBAR - 59 * GRID_W - 2 * SPACE_X;
          onLoad = "(_this # 0) ctrlShow false";
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa";
        };
        class ENH_NumberSystems: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMSYSTEMS;
          x = ORIGIN_X_STATUSBAR - 66 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconSystems: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONSYSTEMS;
          x = ORIGIN_X_STATUSBAR - 69 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
        };
        class ENH_NumberWaypoints: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMWAYPOINTS;
          x = ORIGIN_X_STATUSBAR - 76 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconWaypoints: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONWAYPOINTS;
          x = ORIGIN_X_STATUSBAR - 79 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa";
        };
        class ENH_NumberTriggers: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMTRIGGERS;
          x = ORIGIN_X_STATUSBAR - 86 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconTriggers: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONTRIGGERS;
          x = ORIGIN_X_STATUSBAR - 89 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa";
        };
        class ENH_NumberGroups: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMGROUPS;
          x = ORIGIN_X_STATUSBAR - 96 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconGroups: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONGROUPS;
          x = ORIGIN_X_STATUSBAR - 99 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
        };
        class ENH_NumberObjects: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMOBJECTS;
          x = ORIGIN_X_STATUSBAR - 106 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconObjects: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONOBJECTS;
          x = ORIGIN_X_STATUSBAR - 109 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
        };
        #endif
        #if __has_include("\userconfig\ENH_Config.hpp")
        class ENH_UserconfigWarning: TextZ
        {
          idc = -1;
          x = 108 * GRID_W + 2 * SPACE_X;
          text = "\a3\ui_f\data\map\markers\military\warning_ca.paa";
          tooltip = "$STR_ENH_STATUSBAR_USERCONFIG_WARNING_TOOLTIP";
        };
        #endif
      };
    };
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
        class PanelLeftLocations: ctrlControlsGroupNoScrollbars
        {
          class Controls
          {
            class Locations: ctrlTree
						{
							idc = IDC_DISPLAY3DEN_SEARCH_TREE;
							x = 0;
							y = 7 * GRID_H;
							w = 60 * GRID_W;
							h = safezoneH - 35 * GRID_H;
							onTreeDblClick = "['select',_this] call bis_fnc_3DENListLocations; ['view'] call ENH_fnc_locationList_enhanced";
							disableKeyboardSearch = 1;
							expandOnDoubleclick = 0;
							idcSearch = 800;
						};
            class EditPanel: ctrlControlsGroupNoScrollbars
            {
              y = safezoneH - 29 * GRID_H;
              w = 60 * GRID_W;
              h = 7 * GRID_H;
              class Controls
              {
                class EditPanelBackground: ctrlStatic
                {
                  w = 60 * GRID_W;
                  h = 7 * GRID_H;
                  colorBackground[] = {0.2,0.2,0.2,1};
                };
                class Delete: ctrlButtonToolbar
                {
                  idc = 101;
                  text = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
                  x = GRID_W;
                  y = GRID_H;
                  w = 5 * GRID_W;
                  h = 5 * GRID_H;
                  tooltip = "$STR_DISP_DELETE";
                  onButtonClick = "['delete'] call ENH_fnc_locationList_enhanced";
                };
                class Add: Delete
                {
                  idc = 102;
                  text = "\3denEnhanced\data\panelLeft_addLocation_ca.paa";
                  x = 54 * GRID_W;
                  tooltip = "$STR_A3_CFGVEHICLES_MODULECURATORADDEDITABLEOBJECTS_ARGUMENTS_ADDCREW_VALUES_YES";
                  onButtonClick = "['add'] spawn ENH_fnc_locationList_enhanced";
                };
              };
            };
          };
        };
      };
    };
  };
};