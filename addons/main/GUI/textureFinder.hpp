class ENH_TextureFinder
{
    idd = IDD_TEXTUREFINDER;
    onLoad = "spawn ENH_fnc_textureFinder_findTextures";
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_TEXTUREFINDER";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            moving = 0;
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(WINDOW_HAbs - 3 * CTRL_DEFAULT_H);
        };
        class BackgroundPreview: ctrlStaticBackgroundDisableTiles
        {
            idc = IDC_TEXTUREFINDER_PREVIEWBACKGROUND;
            x = QUOTE(0);
            y = QUOTE(0);
            w = QUOTE(0);
            h = QUOTE(0);
            tileH = QUOTE(4 / (32 * pixelH) * 32);
            tileW = QUOTE(8 / (32 * pixelW) * 32);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
    };
    class Controls
    {
        class TextureList: ctrlTree
        {
            idc = IDC_TEXTUREFINDER_TEXTURELIST;
            idcSearch = IDC_TEXTUREFINDER_SEARCH;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H);
            w = QUOTE((WINDOW_W_ATTRIBUTES - 2) * GRID_W);
            h = QUOTE(WINDOW_HAbs - 80 * GRID_H + CTRL_DEFAULT_H);
            borderSize = 0;
            colorBorder[] = {0, 0, 0, 0};
            colorBackground[] = {COLOR_TAB_RGBA};
        };
        class Preview: ctrlStaticPictureKeepAspect
        {
            idc = IDC_TEXTUREFINDER_PREVIEW;
            x = QUOTE(0);
            y = QUOTE(0);
            w = QUOTE(0);
            h = QUOTE(0);
            colorBackground[] = {1, 1, 1, 1};
        };
        class Search: ctrlEdit
        {
            idc = IDC_TEXTUREFINDER_SEARCH;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(30 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
        };
        class ButtonSearch: ctrlButtonSearch
        {
            idc = IDC_TEXTUREFINDER_BUTTONSEARCH;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 31 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(5 * GRID_H);
        };
        class CollapseAll: ctrlButtonCollapseAll
        {
            idc = IDC_TEXTUREFINDER_COLLAPSEALL;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 36 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(5 * GRID_H);
        };
        class ExpandAll: ctrlButtonExpandAll
        {
            idc = IDC_TEXTUREFINDER_EXPANDALL;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 41 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(5 * GRID_H);
        };
        class ProgessText: ctrlStructuredText
        {
            idc = IDC_TEXTUREFINDER_PROGRESSTEXT;
            style = ST_LEFT;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 46 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(80 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Close: ctrlButtonClose
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES - 25 - 1) * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
