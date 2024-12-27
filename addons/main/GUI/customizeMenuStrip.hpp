class ENH_CustomizeMenuStrip
{
    idd = IDD_CUSTOMIZE_MENU_STRIP;
    onLoad = "_this call ENH_fnc_menuStrip_customize";
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(WINDOW_HAbs - 3 * CTRL_DEFAULT_H);
        };
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_MENUSTRIPENTRIES";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
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
        // We want this group so that MouseMoving event handlers reports x coords from 0 to 1
        class Group: ctrlControlsGroupNoScrollbars
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W);
            h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H + GRID_H);
            class Controls
            {
                class TreeView: ctrlTree
                {
                    idc = IDC_CUSTOMIZE_MENU_STRIP_TREE;
                    idcSearch = IDC_CUSTOMIZE_MENU_STRIP_SEARCH;
                    w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W);
                    h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H);
                    borderSize = 0;
                    colorBorder[] = {0, 0, 0, 0};
                    colorBackground[] = {COLOR_TAB_RGBA};
                    colorLines[] = {1, 1, 1, 1};
                };
            };
        };
        class Hint: ctrlStructuredText
        {
            idc = IDC_CUSTOMIZE_MENU_STRIP_SEARCH;
            text = "$STR_ENH_MAIN_MENUSTRIPENTRIES_TOOLTIP";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 5 * CTRL_DEFAULT_H - 3 * GRID_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W);
            h = QUOTE(2 * CTRL_DEFAULT_H);
            colorBackground[] = {COLOR_TAB_RGBA};
        };
        class Search: ctrlEdit
        {
            idc = IDC_CUSTOMIZE_MENU_STRIP_SEARCH;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(40 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonSearch: ctrlButtonSearch
        {
            idc = IDC_CUSTOMIZE_MENU_STRIP_BUTTON_SEARCH;
            TEXT = TEXTURE_SEARCH_START;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 41 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonCollapseAll: ctrlButtonCollapseAll
        {
            idc = IDC_CUSTOMIZE_MENU_STRIP_BUTTON_COLLAPSE_ALL;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 46 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonExpandAll: ctrlButtonExpandAll
        {
            idc = IDC_CUSTOMIZE_MENU_STRIP_BUTTON_EXPAND_ALL;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 51 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonSave: ctrlButtonClose
        {
            text = "$STR_EDITOR_MENU_FILE_SAVE";
            x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
