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
            idc = 100;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            colorBackground[] = {COLOR_TAB_RGBA};
            onLoad = "_this spawn ENH_fnc_groupMarker_onLoad";
        };
        class ColourTitle: Title
        {
            text = "$STR_ENH_MAIN_GROUPMARKER_COLOUR";
            tooltip = "$STR_3DEN_MARKER_ATTRIBUTE_COLOR_TOOLTIP";
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
        };
        class Colour: Type
        {
            idc = 101;
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
            idc = 102;
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
            idc = 103;
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
            idc = 104;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(4 * CTRL_DEFAULT_H + 15 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Reset: ENH_ResetButton_Base
        {
            y = QUOTE(5 * CTRL_DEFAULT_H + 20 * pixelH);
        };
    };
};