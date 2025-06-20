#define SIDEBAR_W 70 * GRID_W

class ENH_FunctionsViewer
{
    idd = IDD_FUNCTIONSVIEWER;
    onLoad = "_this call ENH_fnc_functionsViewer_onLoad";
    class ControlsBackground
    {
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_HEADER";
            x = QUOTE(safeZoneX);
            y = QUOTE(safeZoneY);
            w = QUOTE(safeZoneW);
            h = QUOTE(CTRL_DEFAULT_H);
            colorBackground[] = {COLOR_ACTIVE_RGBA};
            moving = 0;
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(safeZoneX);
            y = QUOTE(safeZoneY + CTRL_DEFAULT_H);
            w = QUOTE(safeZoneW);
            h = QUOTE(safeZoneH - CTRL_DEFAULT_H);
        };
        class NumFunctions: ctrlStatic
        {
            idc = IDC_FUNCTIONSVIEWER_NUMFUNCTIONS;
            tooltip = "$STR_ENH_MAIN_FUNCTIONSVIEWER_NUMFUNCTIONS_TOOLTIP";
            x = QUOTE(safeZoneX + GRID_W);
            y = QUOTE(safeZoneY + safeZoneH - 6 * GRID_H);
            w = QUOTE(10 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(safeZoneX);
            y = QUOTE(safeZoneY + safeZoneH - 7 * GRID_H);
            w = QUOTE(safeZoneW);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
    };
    class Controls
    {
        class MenuStrip: ctrlMenuStrip
        {
            idc = IDC_FUNCTIONSVIEWER_MENU;
            x = QUOTE(safeZoneX);
            y = QUOTE(safeZoneY + CTRL_DEFAULT_H);
            w = QUOTE(safeZoneW);
            h = QUOTE(CTRL_DEFAULT_H);
            class Items
            {
                items[] =
                {
                    "FolderFilter",
                    "FolderEdit",
                    "FolderHelp"
                };
                class FolderFilter
                {
                    text = "Filter";
                    items[] = {"ConfigFile", "MissionConfigFile", "CampaignConfigFile", "OtherFiles", "Separator", "Full", "Categories", "Functions", "Separator", "LoadFile", "PreprocessFile", "PreprocessFileLineNumbers"};
                };
                class FolderEdit
                {
                    text = "Edit";
                    items[] = {"ToggleSidebar", "CollapseAll", "ExpandAll", "Separator", "RecompileSelected", "RecompileAll", "Separator", "Copy", "Separator", "LegacyFunctionsViewer"};
                };
                class FolderHelp
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELP_TEXT";
                    items[] = {"Documentation", "ShowOnBiki"};
                };
               // Edit
                class ToggleSidebar
                {
                    text = "$STR_USRACT_CURATOR_COLLAPSE_PARENT";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_B};
                    action = "_this call ENH_fnc_functionsViewer_togglePanel";
                    picture = "\a3\ui_f_orange\data\igui\rscingameui\elevationarrow_ca.paa";
                };
                class CollapseAll
                {
                    text = "$STR_3DEN_CTRLBUTTONCOLLAPSEALL_TEXT";
                    shortcuts[] = {INPUT_ALT_OFFSET + DIK_UP};
                    action = QUOTE(tvCollapseAll (ctrlParent (_this # 0) displayCtrl IDC_RSCDISPLAYFUNCTIONSVIEWER_FUNCTIONS));
                    picture = "\a3\3den\data\displays\display3den\tree_expand_ca.paa";
                };
                class ExpandAll
                {
                    text = "$STR_3DEN_CTRLBUTTONEXPANDALL_TEXT";
                    shortcuts[] = {INPUT_ALT_OFFSET + DIK_DOWN};
                    action = QUOTE(tvExpandAll (ctrlParent (_this # 0) displayCtrl IDC_RSCDISPLAYFUNCTIONSVIEWER_FUNCTIONS));
                    picture = "\a3\3den\data\displays\display3den\tree_collapse_ca.paa";
                };
                class RecompileSelected
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILESELETECTED_TEXT";
                    tooltip = "$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILESELETECTED_TOOLTIP";
                    shortcuts[] = {INPUT_ALT_OFFSET + DIK_R};
                    picture = "\a3\3den\data\displays\display3den\entitymenu\functions_ca.paa";
                    action = "[] call ENH_fnc_functionsViewer_recompileSelected";
                };
                class RecompileAll: RecompileSelected
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILEALL_TEXT";
                    tooltip = "$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILEALL_TOOLTIP";
                    shortcuts[] = {INPUT_ALT_OFFSET + DIK_A};
                    action = "[1] call BIS_fnc_recompile";
                };
                class Copy
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_COPYFUNCTION_TEXT";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_C};
                    action = "_this call ENH_fnc_functionsViewer_copy";
                };
                class LegacyFunctionsViewer
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_LEGACY";
                    action = "[ctrlParent (_this # 0)] call BIS_fnc_help";
                };
               // Config
                class ConfigFile
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_GLOBALCONFIG";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 0]; profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', false]; call ENH_fnc_functionsViewer_fillCtrlTV";
                    shortcuts[] = {DIK_1};
                };
                class MissionConfigFile: ConfigFile
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_MISSIONCONFIG";
                    shortcuts[] = {DIK_2};
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 1]; profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', false]; call ENH_fnc_functionsViewer_fillCtrlTV";
                };
                class CampaignConfigFile: ConfigFile
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_CAMPAIGNCONFIG";
                    shortcuts[] = {DIK_3};
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 2]; profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', false]; call ENH_fnc_functionsViewer_fillCtrlTV";
                };
                class OtherFiles
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_OTHERFILES";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', true]; call ENH_fnc_functionsViewer_fillCtrlTV";
                    shortcuts[] = {DIK_4};
                };
               // Filter
                class Full
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_ADDONS";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 0]; call ENH_fnc_functionsViewer_fillCtrlTV";
                    shortcuts[] = {INPUT_ALT_OFFSET + DIK_1};
                };
                class Categories
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_CATEGORIES";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 1]; call ENH_fnc_functionsViewer_fillCtrlTV";
                    shortcuts[] = {INPUT_ALT_OFFSET + DIK_2};
                };
                class Functions
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_FUNCTIONS";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 2]; call ENH_fnc_functionsViewer_fillCtrlTV";
                    shortcuts[] = {INPUT_ALT_OFFSET + DIK_3};
                };
               // Loading Method
                class LoadFile
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_LOADFILE";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 0]; call ENH_fnc_functionsViewer_setUpMenuStrip; [] call ENH_fnc_functionsViewer_onTreeSelChanged";
                    shortcuts[] = {INPUT_ALT_OFFSET + INPUT_CTRL_OFFSET + DIK_1};
                };
                class PreprocessFile
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_PREPROCESSFILE";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 1]; call ENH_fnc_functionsViewer_setUpMenuStrip; [] call ENH_fnc_functionsViewer_onTreeSelChanged";
                    shortcuts[] = {INPUT_ALT_OFFSET + INPUT_CTRL_OFFSET + DIK_2};
                };
                class PreprocessFileLineNumbers
                {
                    text = "$STR_ENH_MAIN_FUNCTIONSVIEWER_PREPROCESSFILEWITHLINES";
                    action = "profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 2]; call ENH_fnc_functionsViewer_setUpMenuStrip; [] call ENH_fnc_functionsViewer_onTreeSelChanged";
                    shortcuts[] = {INPUT_ALT_OFFSET + INPUT_CTRL_OFFSET + DIK_3};
                };
               // Help
                class Documentation
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
                    picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
                    weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#functions-viewer";
                    opensNewWindow = 1;
                };
                class ShowOnBiki
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPBIKI_TEXT";
                    picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
                    opensNewWindow = 1;
                };
                class Default
                {
                    test = 0;
                };
                class Separator
                {
                    test = 0;
                };
            };
        };
        class List: ctrlTree
        {
            idc = IDC_FUNCTIONSVIEWER_LIST;
            idcSearch = 1400;
            x = QUOTE(safeZoneX + GRID_W);
            y = QUOTE(safeZoneY + 2 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(SIDEBAR_W);
            h = QUOTE(safeZoneH - 3 * CTRL_DEFAULT_H - 3 * GRID_H);
            colorLines[] = {1, 1, 1, 1};
            borderSize = 0;
            colorBorder[] = {0, 0, 0, 0};
        };
        class Search: ctrlEdit
        {
            idc = IDC_FUNCTIONSVIEWER_SEARCH;
            tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
            x = QUOTE(safeZoneX + 12 * GRID_W);
            y = QUOTE(safeZoneY + safeZoneH - 6 * GRID_H);
            w = QUOTE(53 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonSearch: ctrlButtonSearch
        {
            idc = IDC_FUNCTIONSVIEWER_BUTTONSEARCH;
            x = QUOTE(safeZoneX + 65 * GRID_W);
            y = QUOTE(safeZoneY + safeZoneH - 6 * GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Name: ctrlEdit
        {
            idc = IDC_FUNCTIONSVIEWER_NAME;
            tooltip = "$STR_ENH_MAIN_FUNCTIONSVIEWER_FUNCTIONNAME_TOOLTIP";
            canModify = 0;
            x = QUOTE(safeZoneX + 72 * GRID_W);
            y = QUOTE(safeZoneY + 2 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(70 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Path: Name
        {
            idc = IDC_FUNCTIONSVIEWER_PATH;
            tooltip = "$STR_ENH_MAIN_FUNCTIONSVIEWER_FUNCTIONPATH_TOOLTIP";
            x = QUOTE(safeZoneX + 143 * GRID_W);
            w = QUOTE(safeZoneW - (143 + 1) * GRID_W);
        };
        class SearchCode: ctrlEdit
        {
            idc = IDC_FUNCTIONSVIEWER_SEARCHCODE;
            tooltip = __EVAL(toUpper format ["%1+%2+%3", localize "STR_DIK_CONTROL", localize "STR_VK_SHIFT", "F"]);
            x = QUOTE(safeZoneX + 72 * GRID_W);
            y = QUOTE(safeZoneY + safeZoneH - 6 * GRID_H);
            w = QUOTE(40 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onKeyUp = "_this call ENH_fnc_functionsViewer_searchKey";
        };
        class SearchText: ctrlStatic
        {
            idc = IDC_FUNCTIONSVIEWER_SEARCHTEXT;
            x = QUOTE(safeZoneX + 113 * GRID_W);
            y = QUOTE(safeZoneY + safeZoneH - 6 * GRID_H);
            w = QUOTE(30 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SearchButtonUp: ctrlButtonPictureKeepAspect
        {
            text = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_up_ca.paa";
            x = QUOTE(safeZoneX + 135 * GRID_W);
            y = QUOTE(safeZoneY + safeZoneH - 6 * GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "[_this # 0, -1] call ENH_fnc_FunctionsViewer_IncrementKey";
        };
        class SearchButtonDown: SearchButtonUp
        {
            text = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_down_ca.paa";
            x = QUOTE(safeZoneX + 129 * GRID_W);
            onButtonClick = "[_this # 0, 1] call ENH_fnc_functionsViewer_incrementKey";
        };
        class Preview: ctrlControlsGroup
        {
            idc = IDC_FUNCTIONSVIEWER_GROUP;
            x = QUOTE(safeZoneX + 72 * GRID_W);
            y = QUOTE(safeZoneY + 3 * CTRL_DEFAULT_H + 2 * GRID_H);
            w = QUOTE(safeZoneW - 73 * GRID_W);
            h = QUOTE(safeZoneH - 4 * CTRL_DEFAULT_H - 4 * GRID_H);
            class Controls
            {
                class Lines: ctrlStructuredText
                {
                    idc = IDC_FUNCTIONSVIEWER_LINES;
                    canModify = 0;
                    x = QUOTE(0);
                    y = QUOTE(0);
                    w = QUOTE(0.070);
                    h = QUOTE(2);
                    font = "EtelkaMonospacePro";
                    shadow = 0;
                    colorBackground[] = {COLOR_OVERLAY_RGBA};
                };
                class Code: ctrlEditMulti
                {
                    idc = IDC_FUNCTIONSVIEWER_CODE;
                    canModify = 0;
                    x = QUOTE(0.075);
                    w = QUOTE(4);
                    h = QUOTE(2);
                    font = "EtelkaMonospacePro";
                    shadow = 0;
                    style = ST_NO_RECT + ST_MULTI;
                };
            };
        };
        class Close: ctrlButtonClose
        {
            x = QUOTE(safeZoneX + safeZoneW - 26 * GRID_W);
            y = QUOTE(safeZoneY + safeZoneH - 6 * GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
