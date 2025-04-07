class ENH_EstablishingShot: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_establishingShot_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_establishingShot_onAttributeSave";
    h = QUOTE(8 * CTRL_DEFAULT_H + 35 * pixelH);
    class Controls: Controls
    {
        class CenterTitle: Title
        {
            text = "$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_DISPLAYNAME";
            tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
        };
        class CenterTitleX: ENH_3DEN_Attribute_Control_TitleX {};
        class CenterValueX: ENH_3DEN_Attribute_Control_ValueX
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
        };
        class CenterTitleY: ENH_3DEN_Attribute_Control_TitleY {};
        class CenterValueY: ENH_3DEN_Attribute_Control_ValueY
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
        };
        class CenterTitleZ: ENH_3DEN_Attribute_Control_TitleZ {};
        class CenterValueZ: ENH_3DEN_Attribute_Control_ValueZ
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 5 - 5) * GRID_W);
        };
        class PasteStartValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
        };
        class TextTitle: Title
        {
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_DISPLAYEDTEXT";
        };
        class TextValue: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class AltitudeTitle: Title
        {
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
            text = "$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
        };
        class AltitudeTitleA: ENH_3DEN_Attribute_Control_TitleAltitude
        {
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class AltitudeValueA: ENH_3DEN_Attribute_Control_ValueA
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class RadiusTitle: Title
        {
            text = "$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_DISPLAYNAME";
            tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_TOOLTIP";
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class RadiusTitleR: ENH_3DEN_Attribute_Control_TitleR
        {
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class RadiusValueR: ENH_3DEN_Attribute_Control_ValueA
        {
            idc = IDC_ATTRIBUTE_CONTROL_06;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class AngleTitle: Title
        {
            y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
            text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_VIEWINGANGLE_DISPLAYNAME";
        };
        class AngleValue: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_07;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
            h = QUOTE(CTRL_DEFAULT_H);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            sliderPosition = 45;
            sliderRange[] = {0, 360};
            sliderStep = 5;
            lineSize = 5;
        };
        class AngleEdit: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_08;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
            w = QUOTE(EDIT_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class DirectionTitle: Title
        {
            y = QUOTE(5 * CTRL_DEFAULT_H + 25 * pixelH);
            w = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            h = QUOTE(2 * CTRL_DEFAULT_H);
            text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_DIRECTION_DISPLAYNAME";
        };
        class DirectionValue: ctrlToolbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_09;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 25 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(2 * CTRL_DEFAULT_H);
            rows = 2;
            columns = 1;
            strings[] =
            {
                "$STR_ENH_MAIN_ESTABLISHINGSHOT_ANTICLOCKWISE",
                "$STR_ENH_MAIN_ESTABLISHINGSHOT_CLOCKWISE"
            };
            values[] = {0, 1};
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(7 * CTRL_DEFAULT_H + 30 * pixelH);
        };
    };
};
