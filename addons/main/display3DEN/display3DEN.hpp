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
        // Preview controls. BI ones are bugged and it's easier to create new ones than fixing
        class ENH_FavoritesPreviewBackground: ctrlStatic
        {
            idc = IDC_DISPLAY3DEN_FAVORITES_PREVIEW_BG;
            colorBackground[] = {0.2, 0.2, 0.2, 0.87};
        };
        class ENH_FavoritesPreviewPicture: ctrlStaticPictureKeepAspect
        {
            idc = IDC_DISPLAY3DEN_FAVORITES_PREVIEW_PICTURE;
        };
        class StatusBar: ctrlControlsGroupNoScrollbars
        {
            class Controls
            {
                class TextX: ctrlStaticPicture
                {
                    colorText[] = {COLOR_POSX_RGBA};
                };
                class ValueX: ctrlEdit
                {
                    w = QUOTE(19 * GRID_W);
                };
                // Manually re-config version info into a button to save screen space
                class Version: ctrlButton
                {
                    idc = IDC_NONE;
                    text = "V";
                    x = QUOTE(ORIGIN_X_STATUSBAR - 15 * GRID_W - SPACE_X);
                    y = QUOTE(2 * pixelH);
                    w = QUOTE(4 * GRID_W - 4 * pixelW);
                    h = QUOTE(4 * GRID_H - 4 * pixelH);
                    onLoad = "_this # 0 ctrlSetToolTip format ['%1.%2', (productVersion select 2) * 0.01 toFixed 2, productVersion select 3]";
                    onButtonClick = "call ENH_fnc_productInfo";
                    colorBackground[] = {0, 0, 0, 0.5};
                    style = QUOTE(ST_CENTER + ST_UPPERCASE);
                };
                class TextY: TextX
                {
                    x = QUOTE(22 * GRID_W);
                    colorText[] = {COLOR_POSY_RGBA};
                };
                class ValueY: ValueX
                {
                    x = QUOTE(25 * GRID_W);
                };
                class TextZ: TextX
                {
                    x = QUOTE(44 * GRID_W);
                    colorText[] = {COLOR_POSZ_RGBA};
                };
                class ValueZ: ValueX
                {
                    x = QUOTE(47 * GRID_W);
                };
                class TextDis: TextX
                {
                    x = QUOTE(66 * GRID_W);
                    colorText[] = {1, 1, 1, 1};
                };
                class ValueDis: ValueX
                {
                    x = QUOTE(69 * GRID_W);
                };
                class ENH_TextDir: TextX
                {
                    idc = IDC_STATUSBAR_CAMDIR_ICON;
                    x = QUOTE(99 * GRID_W);
                    text = "\a3\3den\data\attributes\loiterdirection\ccw_ca.paa";
                    colorText[] = {1, 1, 1, 1};
                };
                class ENH_ValueDir: ValueX
                {
                    idc = IDC_STATUSBAR_CAMDIR;
                    x = QUOTE(102 * GRID_W);
                    w = QUOTE(9 * GRID_W);
                    onLoad = "(_this # 0) ctrlEnable false";
                    style = ST_CENTER + ST_NO_RECT;
                };
                class ENH_SessionTime: ENH_TextDir
                {
                    idc = IDC_STATUSBAR_SESSIONTIMER;
                    text = "a3\modules_f_curator\data\portraitskiptime_ca.paa";
                    x = QUOTE(ORIGIN_X_STATUSBAR - 11 * GRID_W - 2 * SPACE_X);
                    y = QUOTE(2 * pixelH);
                };
                class ENH_NumberMarkers: ValueY
                {
                    idc = IDC_STATUSBAR_NUMMARKERS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 22 * GRID_W - 2 * SPACE_X);
                    w = QUOTE(7 * GRID_W);
                    onLoad = "(_this # 0) ctrlShow false; (_this # 0) ctrlEnable false";
                    style = ST_CENTER + ST_NO_RECT;
                };
                class ENH_IconMarkers: ENH_TextDir
                {
                    idc = IDC_STATUSBAR_ICONMARKERS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 25 * GRID_W - 2 * SPACE_X);
                    onLoad = "(_this # 0) ctrlShow false";
                    text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa";
                };
                class ENH_NumberSystems: ENH_NumberMarkers
                {
                    idc = IDC_STATUSBAR_NUMSYSTEMS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 32 * GRID_W - 2 * SPACE_X);
                };
                class ENH_IconSystems: ENH_IconMarkers
                {
                    idc = IDC_STATUSBAR_ICONSYSTEMS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 35 * GRID_W - 2 * SPACE_X);
                    text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
                };
                class ENH_NumberWaypoints: ENH_NumberMarkers
                {
                    idc = IDC_STATUSBAR_NUMWAYPOINTS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 42 * GRID_W - 2 * SPACE_X);
                };
                class ENH_IconWaypoints: ENH_IconMarkers
                {
                    idc = IDC_STATUSBAR_ICONWAYPOINTS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 45 * GRID_W - 2 * SPACE_X);
                    text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa";
                };
                class ENH_NumberTriggers: ENH_NumberMarkers
                {
                    idc = IDC_STATUSBAR_NUMTRIGGERS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 52 * GRID_W - 2 * SPACE_X);
                };
                class ENH_IconTriggers: ENH_IconMarkers
                {
                    idc = IDC_STATUSBAR_ICONTRIGGERS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 55 * GRID_W - 2 * SPACE_X);
                    text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa";
                };
                class ENH_NumberGroups: ENH_NumberMarkers
                {
                    idc = IDC_STATUSBAR_NUMGROUPS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 62 * GRID_W - 2 * SPACE_X);
                };
                class ENH_IconGroups: ENH_IconMarkers
                {
                    idc = IDC_STATUSBAR_ICONGROUPS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 65 * GRID_W - 2 * SPACE_X);
                    text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
                };
                class ENH_NumberObjects: ENH_NumberMarkers
                {
                    idc = IDC_STATUSBAR_NUMOBJECTS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 72 * GRID_W - 2 * SPACE_X);
                };
                class ENH_IconObjects: ENH_IconMarkers
                {
                    idc = IDC_STATUSBAR_ICONOBJECTS;
                    x = QUOTE(ORIGIN_X_STATUSBAR - 75 * GRID_W - 2 * SPACE_X);
                    text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
                };
            };
        };
        class MenuStrip: ctrlMenuStrip
        {
            class Items
            {
                items[] += {"ENH_About"};

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
                class ENH_PanelRightFavorites: PanelRightHistory
                {
                    idc = IDC_DISPLAY3DEN_FAVORITES;
                    class Controls
                    {
                        class ENH_Footer: ctrlStaticFooter
                        {
                            y = QUOTE(safeZoneH - (28 + 7) * GRID_H);
                            w = QUOTE(60 * GRID_W);
                            h = QUOTE(7 * GRID_H);
                        };
                        class ENH_PanelRightFavorites_Search: ctrlEdit
                        {
                            idc = IDC_DISPLAY3DEN_FAVORITES_SEARCH;
                            x = QUOTE(GRID_W);
                            y = QUOTE(GRID_H);
                            w = QUOTE(43 * GRID_W);
                            h = QUOTE(CTRL_DEFAULT_H);
                        };
                        class ENH_PanelRightFavorites_SearchButton: ctrlButtonSearch
                        {
                            idc = IDC_DISPLAY3DEN_FAVORITES_BUTTON_SEARCH;
                            x = QUOTE(44 * GRID_W);
                            y = QUOTE(GRID_H);
                            w = QUOTE(5 * GRID_W);
                            h = QUOTE(CTRL_DEFAULT_H);
                        };
                        class ENH_PanelRightFavorites_CollapseButton: ctrlButtonCollapseAll
                        {
                            idc = IDC_DISPLAY3DEN_FAVORITES_BUTTON_COLLAPSE;
                            x = QUOTE(49 * GRID_W);
                            y = QUOTE(GRID_H);
                            w = QUOTE(5 * GRID_W);
                            h = QUOTE(CTRL_DEFAULT_H);
                        };
                        class ENH_PanelRightFavorites_ExpandButton: ctrlButtonExpandAll
                        {
                            idc = IDC_DISPLAY3DEN_FAVORITES_BUTTON_EXPAND;
                            x = QUOTE(54 * GRID_W);
                            y = QUOTE(GRID_H);
                            w = QUOTE(5 * GRID_W);
                            h = QUOTE(CTRL_DEFAULT_H);
                        };
                        class ENH_PanelRightFavorites_Tree: ctrlTree
                        {
                            idc = IDC_DISPLAY3DEN_FAVORITES_TREE;
                            idcSearch = IDC_DISPLAY3DEN_FAVORITES_SEARCH;
                            x = QUOTE(0);
                            y = QUOTE(7 * GRID_H);
                            w = QUOTE(60 * GRID_W);
                            h = QUOTE(safeZoneH - (28 + 21) * GRID_H);
                            borderSize = 0;
                            colorBorder[] = {0, 0, 0, 0};
                            multiselectEnabled = 1;
                        };
                        class ENH_PanelRightFavorites_Delete: ctrlButton
                        {
                            idc = IDC_DISPLAY3DEN_FAVORITES_BUTTON_DELETE;
                            text = "$STR_DISP_DELETE";
                            x = QUOTE(GRID_W);
                            y = QUOTE(safeZoneH - (28 + 6) * GRID_H);
                            w = QUOTE(58 * GRID_W);
                            h = QUOTE(CTRL_DEFAULT_H);
                        };
                    };
                };
                class TabRightSections: ctrlToolbox
                {
                    columns = 3;
                    strings[] = {"$STR_3DEN_DISPLAY3DEN_ASSETS", "$STR_3DEN_DISPLAY3DEN_HISTORY", "$STR_3DEN_FAVORITE_TEXTPLURAL"};
                    values[] = {IDC_DISPLAY3DEN_PANELRIGHT_CREATE, IDC_DISPLAY3DEN_PANELRIGHT_HISTORY, IDC_DISPLAY3DEN_FAVORITES};
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
                                    idc = IDC_NONE;
                                    text = "x\enh\addons\main\data\trash_ca.paa";
                                    x = QUOTE(7 * GRID_W);
                                    tooltip = "$STR_ENH_MAIN_TOOLS_DELETEEMPTYLAYERS";
                                    onButtonClick = "call ENH_fnc_deleteEmptyLayers";
                                };
                                class ENH_SelectLayers: Delete
                                {
                                    idc = IDC_NONE;
                                    text = "x\enh\addons\main\data\selectAllLayers_ca.paa";
                                    x = QUOTE(29 * GRID_W);
                                    tooltip = "$STR_ENH_MAIN_TOOLS_SELECTALLLAYERS";
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
                            x = QUOTE(0);
                            y = QUOTE(7 * GRID_H);
                            w = QUOTE(60 * GRID_W);
                            h = QUOTE(safeZoneH - 35 * GRID_H);
                            onTreeDblClick = "['select', _this] call bis_fnc_3DENListLocations; ['view'] call ENH_fnc_locationList_enhanced";
                            disableKeyboardSearch = 1;
                            expandOnDoubleclick = 0;
                            idcSearch = 800;
                        };
                        class EditPanel: ctrlControlsGroupNoScrollbars
                        {
                            y = QUOTE(safeZoneH - 29 * GRID_H);
                            w = QUOTE(60 * GRID_W);
                            h = QUOTE(7 * GRID_H);
                            class Controls
                            {
                                class EditPanelBackground: ctrlStatic
                                {
                                    w = QUOTE(60 * GRID_W);
                                    h = QUOTE(7 * GRID_H);
                                    colorBackground[] = {0.2, 0.2, 0.2, 1};
                                };
                                class Delete: ctrlButtonToolbar
                                {
                                    idc = IDC_DISPLAY3DEN_PANEL_LEFT_LOCATION_DELETE;
                                    text = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
                                    x = QUOTE(GRID_W);
                                    y = QUOTE(GRID_H);
                                    w = QUOTE(5 * GRID_W);
                                    h = QUOTE(5 * GRID_H);
                                    tooltip = "$STR_DISP_DELETE";
                                    onButtonClick = "['delete'] call ENH_fnc_locationList_enhanced";
                                };
                                class Add: Delete
                                {
                                    idc = IDC_DISPLAY3DEN_PANEL_LEFT_LOCATION_ADD;
                                    text = "x\enh\addons\main\data\plus_ca.paa";
                                    x = QUOTE(54 * GRID_W);
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
