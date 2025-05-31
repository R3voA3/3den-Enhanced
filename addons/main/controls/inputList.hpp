class ENH_InputList: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_inputList_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_inputList_onAttributeSave";
    h = QUOTE(6 * CTRL_DEFAULT_H + 10 * pixelH);
    class Controls: Controls
    {
        class Title: Title
        {
            h = QUOTE(5 * CTRL_DEFAULT_H);
        };
        class Data: ctrlListbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(5 * CTRL_DEFAULT_H);
            colorBackground[] = {COLOR_TAB_RGBA};
        };
        class InputBox: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - 10) * GRID_W - 4 * pixelW);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Remove: ctrlButtonToolbar
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            text = "\x\enh\addons\main\data\minus_ca.paa";
            tooltip = "$STR_ENH_MAIN_INPUTLIST_REMOVE_TOOLTIP";
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "_this call ENH_fnc_inputList_remove";
        };
        class Add: Remove
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            text = "\x\enh\addons\main\data\plus_ca.paa";
            tooltip = "$STR_ENH_MAIN_INPUTLIST_ADD_TOOLTIP";
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 10) * GRID_W - 2 * pixelW);
            onButtonClick = "_this call ENH_fnc_inputList_add";
        };
    };
};
