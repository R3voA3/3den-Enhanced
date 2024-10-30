class ENH_MoveToLayer
{
    idd = IDD_MOVETOLAYER;
    onLoad = "_this call ENH_fnc_moveToLayer_onLoad";
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_SELECTLAYER_MOVETOLAYER";
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(WINDOW_HAbs - 3 * CTRL_DEFAULT_H);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
    };
    class Controls
    {
        class LayerList: ctrlTree
        {
            idc = IDC_MOVETOLAYER_TREE;
            idcSearch = IDC_MOVETOLAYER_SEARCH;
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W - 2 * GRID_W);
            h = QUOTE(WINDOW_HAbs - 24 * GRID_H);
            borderSize = 0;
            colorBorder[] = {0, 0, 0, 0};
            colorBackground[] = {COLOR_TAB_RGBA};
        };
        class Search: ctrlEdit
        {
            idc = IDC_MOVETOLAYER_SEARCH;
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(35 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "_this call ENH_fnc_moveToLayer_move";
        };
        class ButtonSearch: ctrlButtonSearch
        {
            idc = IDC_MOVETOLAYER_BUTTONSEARCH;
            TEXT = TEXTURE_SEARCH_START;
            tooltip = "";
            x = QUOTE(CENTER_X - WINDOW_W_ATTRIBUTES * 0.5 * GRID_W + 36 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonMove: ctrlButtonOK
        {
            idc = IDC_NONE;
            text = "$STR_A3_BOOT_M02_BIS_SIGN_MARKER";
            x = QUOTE(CENTER_X + WINDOW_W_ATTRIBUTES * 0.5 * GRID_W - 52 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "_this call ENH_fnc_moveToLayer_move";
        };
        class ButtonClose: ctrlButtonClose
        {
            x = QUOTE(CENTER_X + WINDOW_W_ATTRIBUTES * 0.5 * GRID_W - 26 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
