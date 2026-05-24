class ENH_Airdrop: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_airdrop_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_airdrop_onAttributeSave";
    h = QUOTE(11 * CTRL_DEFAULT_H + 35 * pixelH);
    class Controls: Controls
    {
        class ClassesTitle: Title
        {
            text = "$STR_ENH_MAIN_AIRDROP_CLASSES_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AIRDROP_CLASSES_TOOLTIP";
            h = QUOTE(4 * CTRL_DEFAULT_H);
        };
        class ClassesValue: ctrlEditMulti
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(4 * CTRL_DEFAULT_H);
        };
        class CenterTitle: Title
        {
            text = "$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_DISPLAYNAME";
            tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class CenterTitleX: ENH_3DEN_Attribute_Control_TitleX
        {
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class CenterValueX: ENH_3DEN_Attribute_Control_ValueX
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class CenterTitleY: ENH_3DEN_Attribute_Control_TitleY
        {
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class CenterValueY: ENH_3DEN_Attribute_Control_ValueY
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class CenterTitleZ: ENH_3DEN_Attribute_Control_TitleZ
        {
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class CenterValueZ: ENH_3DEN_Attribute_Control_ValueZ
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 5 - 5) * GRID_W);
        };
        class PasteStartValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class ConditionTitle: Title
        {
            y = QUOTE(5 * CTRL_DEFAULT_H + 10 * pixelH);
            text = "$STR_ENH_MAIN_AIRDROP_CONDITION_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AIRDROP_CONDITION_TOOLTIP";
        };
        class ConditionValue: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 10 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class AltitudeTitle: Title
        {
            y = QUOTE(6 * CTRL_DEFAULT_H + 15 * pixelH);
            text = "$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
        };
        class AltitudeTitleA: ENH_3DEN_Attribute_Control_TitleAltitude
        {
            y = QUOTE(6 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class AltitudeValueA: ENH_3DEN_Attribute_Control_ValueA
        {
            idc = IDC_ATTRIBUTE_CONTROL_06;
            y = QUOTE(6 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class RadiusTitle: Title
        {
            text = "$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_DISPLAYNAME";
            tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_TOOLTIP";
            y = QUOTE(7 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class RadiusTitleR: ENH_3DEN_Attribute_Control_TitleR
        {
            y = QUOTE(7 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class RadiusValueR: ENH_3DEN_Attribute_Control_ValueA
        {
            idc = IDC_ATTRIBUTE_CONTROL_07;
            y = QUOTE(7 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class SideTitle: Title
        {
            text = "$STR_ENH_MAIN_SIDE_DISPLAYNAME";
            y = QUOTE(8 * CTRL_DEFAULT_H + 25 * pixelH);
            h = QUOTE(2 * CTRL_DEFAULT_H);
        };
        class SideValue: ENH_3DEN_Attribute_Control_SideToolbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_08;
            y = QUOTE(8 * CTRL_DEFAULT_H + 25 * pixelH);
            h = QUOTE(2 * CTRL_DEFAULT_H);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(10 * CTRL_DEFAULT_H + 30 * pixelH);
        };
    };
};
