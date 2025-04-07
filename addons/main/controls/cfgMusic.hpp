class ENH_CfgMusic: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_cfgMusic_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_cfgMusic_onAttributeSave";
    h = QUOTE(12 * CTRL_DEFAULT_H + 10 * pixelH);
    class Controls: Controls
    {
        class Search: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_24;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE((ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            text = "";
        };
        class SearchButton: ctrlButtonSearch
        {
            idc = IDC_ATTRIBUTE_CONTROL_25;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ClassesTitle: Title
        {
            text = "$STR_ENH_MAIN_RANDOMMUSIC_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_RANDOMMUSIC_TOOLTIP";
            y = QUOTE(1 * CTRL_DEFAULT_H + 5 * pixelH);
            h = QUOTE(10 * CTRL_DEFAULT_H);
        };
        class ClassesValue: ctrlTree
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            idcSearch = IDC_ATTRIBUTE_CONTROL_24;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(10 * CTRL_DEFAULT_H);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
    };
};
