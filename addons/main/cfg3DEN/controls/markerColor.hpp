class MarkerColor2: Title
{
    h = QUOTE(6 * CTRL_DEFAULT_H + 30 * pixelH);
    onLoad = "_this call ENH_fnc_markerColor_onAttributeLoad";
    class Controls
    {
        class Value;
        class SliderRed: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W  * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderRange[] = {0, 1};
            color[] = {COLOR_RED_RGBA};
            colorActive[] = {COLOR_RED_RGBA};
        };
        class SliderGreen: SliderRed
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
            color[] = {COLOR_GREEN_RGBA};
            colorActive[] = {COLOR_GREEN_RGBA};
        };
        class SliderBlue: SliderRed
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
            color[] = {COLOR_BLUE_RGBA};
            colorActive[] = {COLOR_BLUE_RGBA};
        };
        class SliderAlpha: SliderRed
        {
            idc = IDC_ATTRIBUTE_CONTROL_07;
            y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
            color[] = {1, 1, 1, 0.6};
            colorActive[] = {1, 1, 1, 1};
        };
        class Preview: Title
        {
            idc = IDC_ATTRIBUTE_CONTROL_09;
            text = "Color Preview";
            x = QUOTE((ATTRIBUTE_TITLE_W - 20) * GRID_W - GRID_W);
            y = QUOTE(CTRL_DEFAULT_H);
            w = QUOTE(20 * GRID_W);
            h = QUOTE(4 * CTRL_DEFAULT_H + 15 * pixelH);
            colorBackground[] = {1, 1, 1, 1};
        };
        class ComboHistory: ctrlCombo
        {
            idc = IDC_ATTRIBUTE_CONTROL_10;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 30 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - 10) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class HistoryAdd: ctrlButtonToolbar
        {
            idc = IDC_ATTRIBUTE_CONTROL_11;
            text = "x\enh\addons\main\data\plus_ca.paa";
            tooltip = "Add current color to color palette.";
            // TODO: LOCALIZE 2026-03-19 R3vo
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 10) * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 30 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class HistoryRemove: HistoryAdd
        {
            idc = IDC_ATTRIBUTE_CONTROL_12;
            text = "x\enh\addons\main\data\minus_ca.paa";
            tooltip = "Remove selected color from color palette.";
            // TODO: LOCALIZE 2026-03-19 R3vo
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
        };
    };
};
