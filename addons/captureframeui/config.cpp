#include "script_component.hpp"

#include "\x\enh\addons\main\defineCtrls.inc"
#include "cfgPatches.hpp"

class RscDisplayCapture
{
    class Controls
    {
        class Index: RscTree
        {
            idcSearch = IDC_CAPTURE_FRAME_UI_EDIT_SEARCH;
        };
        class Title: RscText
        {
            moving = 0;
        };
        class Background: RscText
        {
            moving = 0;
        };
        class SearchEditTree: RscEdit
        {
            idc = 1337;
            x = QUOTE(GUI_GRID_W + GUI_GRID_X + 4 * GUI_GRID_W);
            y = QUOTE(safeZoneY + 11.3 * GUI_GRID_H);
            w = QUOTE(10 * GUI_GRID_W);
            h = QUOTE(GUI_GRID_H);
        };
        class ButtonCollapseAll: ctrlButtonCollapseAll
        {
            x = QUOTE(GUI_GRID_W + GUI_GRID_X + 5 * GUI_GRID_W + 10 * GUI_GRID_W);
            y = QUOTE(safeZoneY + 11.3 * GUI_GRID_H);
            w = QUOTE(GUI_GRID_W);
            h = QUOTE(GUI_GRID_H);
            onButtonClick = QUOTE(tvCollapseAll (ctrlParent (_this#0) displayCtrl 101));
        };
        class ButtonExpandAll: ctrlButtonExpandAll
        {
            x = QUOTE(GUI_GRID_W + GUI_GRID_X + 5 * GUI_GRID_W + 11 * GUI_GRID_W);
            y = QUOTE(safeZoneY + 11.3 * GUI_GRID_H);
            w = QUOTE(GUI_GRID_W);
            h = QUOTE(GUI_GRID_H);
            onButtonClick = QUOTE(tvExpandAll (ctrlParent (_this#0) displayCtrl 101));
        };
        class ButtonPreviousData;
        class ButtonOpenPerfetto: ButtonPreviousData
        {
            idc = -1;
            text = "Open Perfetto...";
            x = QUOTE(39.11 * GUI_GRID_W + GUI_GRID_X);
            url = "https://ui.perfetto.dev/";
        };
    };
    class ControlsBackground
    {
        class Background: RscText
        {
            x = QUOTE(safeZoneX);
            y = QUOTE(safeZoneY);
            w = QUOTE(safeZoneW);
            h = QUOTE(safeZoneH);
            colorBackground[] = {0.1, 0.1, 0.1, 1};
        };
    };
};
