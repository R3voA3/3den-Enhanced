class ENH_3denShortcuts
{
    idd = -1;
    onLoad = "_this call ENH_fnc_3DENShortcuts_init";
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_3DENSHORTCUTS_DISPLAYNAME";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(WINDOW_PREVIEW_HAbs);
        };
        class BackgroundFilter: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            colorBackground[] = {0, 0, 0, 1};
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 2 * GRID_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(7 * GRID_H);
        };
    };
    class Controls
    {
        class ContentFilter: ctrlListNBox
        {
                idc = IDC_SHORTCUTS_FILTER;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            columns[] = {QUOTE(0), QUOTE(10 * GRID_W), QUOTE(80 * GRID_W)};
        };
        class Content: ctrlListNBox
        {
            idc = IDC_SHORTCUTS_CONTENT;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H);
            w = QUOTE((WINDOW_W_ATTRIBUTES - 2) * GRID_W);
            h = QUOTE(WINDOW_PREVIEW_HAbs - 2 * CTRL_DEFAULT_H - 3 * GRID_H);
            colorBackground[] = {COLOR_OVERLAY_RGBA};
            columns[] = {QUOTE(0), QUOTE(10 * GRID_W), QUOTE(80 * GRID_W)};
            disableOverflow = 1;
        };
        class Search: ctrlEdit
        {
            idc = IDC_SHORTCUTS_SEARCH;
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - GRID_H);
            w = QUOTE(35 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonSearch: ctrlButtonSearch
        {
            idc = IDC_SHORTCUTS_BUTTONSEARCH;
            text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
            tooltip = "";
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W + 36 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Close: ctrlButtonClose
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES - 26) * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
