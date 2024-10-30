class ENH_RPTViewer
{
    idd = IDD_NONE;
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Header: ctrlStaticTitle
        {
            idc = IDC_RPTVIEWER_TITLE;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(WINDOW_HAbs - 3 * CTRL_DEFAULT_H);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
    };
    class Controls
    {
        class Group: ctrlControlsGroup
        {
            idc = IDC_RPTVIEWER_GROUP;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
            h = QUOTE(WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H);
            class Controls
            {
                class Edit: ctrlEditMulti
                {
                    idc = IDC_RPTVIEWER_EDIT;
                    w = QUOTE(400 * GRID_W);
                    h = QUOTE(400 * GRID_H);
                    sizeEx = QUOTE(2.945 * SIZEEX_BASE);
                    font = FONT_MONO;
                    canModify = 0;
                };
            };
        };
        class LinesText: ctrlStatic
        {
            text = "$STR_ENH_MAIN_RPTVIEWER_NUMBEROFLINES";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Lines: ctrlEdit
        {
            idc = IDC_RPTVIEWER_LINES;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W + 27 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(12 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            maxChars = 4;
        };
        class ButtonHelp: ctrlButton
        {
            text = "?";
            x = QUOTE(CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 58 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            url = "https://community.bistudio.com/wiki/Crash_Files";
        };
        class ButtonUpdate: ctrlButton
        {
            text = "$STR_A3_RSCDISPLAYPUBLISHMISSION_BUTTONDOUPDATE";
            x = QUOTE(CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 52 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "'update' call ENH_fnc_RPTViewer";
            url = "";
        };
        class ButtonClose: ctrlButtonClose
        {
            x = QUOTE(CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 26 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
