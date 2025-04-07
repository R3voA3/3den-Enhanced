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
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = 0;
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SliderRed: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderRange[] = {0, 1};
            color[] = {COLOR_RED_RGBA};
            colorActive[] = {COLOR_RED_RGBA};
        };
        class EditRed: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(EDIT_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SliderGreen: SliderRed
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
            color[] = {COLOR_GREEN_RGBA};
            colorActive[] = {COLOR_GREEN_RGBA};
        };
        class EditGreen: EditRed
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class SliderBlue: SliderRed
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
            color[] = {COLOR_BLUE_RGBA};
            colorActive[] = {COLOR_BLUE_RGBA};
        };
        class EditBlue: EditRed
        {
            idc = IDC_ATTRIBUTE_CONTROL_06;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class Preview: ctrlStatic
        {
            idc = IDC_ATTRIBUTE_CONTROL_07;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            colorBackground[] = {1, 1, 1, 1};
        };
        class ComboHistory: ctrlCombo
        {
            idc = IDC_ATTRIBUTE_CONTROL_08;
            onLoad = "_this call ENH_fnc_markerColor_onAttributeLoad";
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 25 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
