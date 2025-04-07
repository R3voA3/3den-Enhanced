class ENH_SliderMulti120: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_slider_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_slider_onAttributeSave";
    class Controls: Controls
    {
        class Title: Title {};
        class Value: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderPosition = 1;
            sliderRange[] = {0.1, 120};
            sliderStep = 0.1;
        };
        class Edit: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            w = QUOTE(EDIT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
