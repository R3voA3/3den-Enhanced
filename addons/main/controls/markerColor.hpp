class ENH_MarkerColor: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_markerColor_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_markerColor_onAttributeSave";
    h = QUOTE(6 * CTRL_DEFAULT_H + 25 * pixelH);
    class Controls: Controls
    {
        class Title: Title {};
        class CheckboxEnable: ctrlCheckbox
        {
            idc = 100;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = 0;
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SliderRed: ctrlXSliderH
        {
            idc = 101;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderRange[] = {0, 1};
            color[] = {RED};
            colorActive[] = {RED};
        };
        class EditRed: ctrlEdit
        {
            idc = 102;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(EDIT_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SliderGreen: SliderRed
        {
            idc = 103;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
            color[] = {GREEN};
            colorActive[] = {GREEN};
        };
        class EditGreen: EditRed
        {
            idc = 104;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class SliderBlue: SliderRed
        {
            idc = 105;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
            color[] = {BLUE};
            colorActive[] = {BLUE};
        };
        class EditBlue: EditRed
        {
            idc = 106;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class Preview: ctrlStatic
        {
            idc = 107;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            colorBackground[] = {1, 1, 1, 1};
        };
        class ComboHistory: ctrlCombo
        {
            idc = 108;
            onLoad = "_this call ENH_fnc_markerColor_onAttributeLoad";
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 25 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
