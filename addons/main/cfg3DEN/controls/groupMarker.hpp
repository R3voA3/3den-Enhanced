class ENH_GroupMarker: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_groupMarker_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_groupMarker_onAttributeSave";
    h = QUOTE(6 * CTRL_DEFAULT_H + 25 * pixelH);
    class Controls: Controls
    {
        class TypeTitle: Title
        {
            text = "$STR_ENH_MAIN_GROUPMARKER_TYPE";
            tooltip = "$STR_3DEN_MARKER_ATTRIBUTE_TYPE_TOOLTIP";
        };
        class Type: ctrlCombo
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            colorBackground[] = {COLOR_TAB_RGBA};
            onLoad = "_this spawn ENH_fnc_groupMarker_onLoad";
        };
        class ColorTitle: Title
        {
            text = "$STR_ENH_MAIN_GROUPMARKER_COLOR";
            tooltip = "$STR_3DEN_MARKER_ATTRIBUTE_COLOR_TOOLTIP";
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
        };
        class Color: Type
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            onload = "";
        };
        class TextTitle: Title
        {
            text = "$STR_ENH_MAIN_GROUPMARKER_TEXT";
            tooltip = "$STR_3DEN_MARKER_ATTRIBUTE_TEXT_TOOLTIP";
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class Text: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ShowGroupSizeTitle: Title
        {
            text = "$STR_ENH_MAIN_GROUPMARKER_SHOWGROUPSIZE";
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class ShowGroupSize: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ShowGroupVehicleTitle: Title
        {
            text = "$STR_ENH_MAIN_GROUPMARKER_VEHICLENAME";
            y = QUOTE(4 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class ShowGroupVehicle: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(4 * CTRL_DEFAULT_H + 15 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(5 * CTRL_DEFAULT_H + 20 * pixelH);
        };
    };
};
