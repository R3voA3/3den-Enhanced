class ENH_TemplateData
{
    idd = IDD_TEMPLATEDATA;
    onLoad = "uiNamespace setVariable ['ENH_TitleValue', nil]; uiNamespace setVariable ['ENH_DescriptionValue', nil];";
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Header: ctrlStaticTitle
        {
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(60 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(60 * GRID_W);
            h = QUOTE(51 * GRID_H);
        };
        class Title: ctrlStatic
        {
            text = "$STR_ENH_MAIN_TEMPLATE_DATA_TITLE";
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Description: ctrlStatic
        {
            text = "$STR_ENH_MAIN_TEMPLATE_DATA_DESCRIPTION";
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 49 * GRID_H);
            w = QUOTE(60 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
    };
    class Controls
    {
        class TitleValue: ctrlEdit
        {
            idc = IDC_TEMPLATEDATA_TITLE;
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class DescriptionValue: ctrlEditMulti
        {
            idc = IDC_TEMPLATEDATA_DESCRIPTION;
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 4 * CTRL_DEFAULT_H + GRID_H);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(25 * GRID_H);
        };
        class ButtonCancel: ctrlButtonCancel
        {
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W + 34 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 50 * GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ButtonOK: ctrlButtonOK
        {
            x = QUOTE(CENTER_X - 0.5 * 60 * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 50 * GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = QUOTE(uiNamespace setVariable ARR_2(['ENH_TitleValue',ctrlText (ctrlParent (_this#0) displayCtrl IDC_TEMPLATEDATA_TITLE)]); uiNamespace setVariable ARR_2(['ENH_DescriptionValue',ctrlText (ctrlParent (_this#0) displayCtrl IDC_TEMPLATEDATA_DESCRIPTION)]));
        };
    };
};
