class ENH_AmbientFlyby: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_ambientFlyby_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_ambientFlyby_onAttributeSave";
    h = QUOTE(22 * CTRL_DEFAULT_H + 50 * pixelH);
    class Controls: Controls
    {
        class Search: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_15;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE((ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            text = "";
        };
        class SearchButton: ctrlButtonSearch
        {
            idc = IDC_ATTRIBUTE_CONTROL_16;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ClassesTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_CLASSES_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AMBIENTFLYBY_CLASSES_TOOLTIP";
            y = QUOTE(1 * CTRL_DEFAULT_H + 5 * pixelH);
            h = QUOTE(10 * CTRL_DEFAULT_H);
        };
        class ClassesValue: ctrlTree
        {
            idc = IDC_ATTRIBUTE_CONTROL_17;
            idcSearch = IDC_ATTRIBUTE_CONTROL_15;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(10 * CTRL_DEFAULT_H);
        };
        class StartTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_STARTPOSITION_DISPLAYNAME";
            tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartTitleX: ENH_3DEN_Attribute_Control_TitleX
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartValueX: ENH_3DEN_Attribute_Control_ValueX
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartTitleY: ENH_3DEN_Attribute_Control_TitleY
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartValueY: ENH_3DEN_Attribute_Control_ValueY
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartTitleZ: ENH_3DEN_Attribute_Control_TitleZ
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartValueZ: ENH_3DEN_Attribute_Control_ValueZ
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 5 - 5) * GRID_W);
        };
        class PasteStartValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
        {
            idc = IDC_ATTRIBUTE_CONTROL_15;
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartRndOffsetTitle: Title
        {
            text = "$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_DISPLAYNAME";
            tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_TOOLTIP";
            y = QUOTE(12 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class StartRndOffsetTitleA: ENH_3DEN_Attribute_Control_TitleR
        {
            y = QUOTE(12 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class StartRndOffsetValueA: ENH_3DEN_Attribute_Control_ValueA
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            y = QUOTE(12 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class EndTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_ENDPOSITION_DISPLAYNAME";
            tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndTitleX: ENH_3DEN_Attribute_Control_TitleX
        {
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndValueX: ENH_3DEN_Attribute_Control_ValueX
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndTitleY: ENH_3DEN_Attribute_Control_TitleY
        {
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndValueY: ENH_3DEN_Attribute_Control_ValueY
        {
            idc = IDC_ATTRIBUTE_CONTROL_06;
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndTitleZ: ENH_3DEN_Attribute_Control_TitleZ
        {
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class PasteEndValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
        {
            idc = IDC_ATTRIBUTE_CONTROL_16;
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndValueZ: StartValueZ
        {
            idc = IDC_ATTRIBUTE_CONTROL_07;
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndRndOffsetTitle: StartRndOffsetTitle
        {
            y = QUOTE(14 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class EndRndOffsetTitleA: ENH_3DEN_Attribute_Control_TitleR
        {
            y = QUOTE(14 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class EndRndOffsetValueA: ENH_3DEN_Attribute_Control_ValueA
        {
            idc = IDC_ATTRIBUTE_CONTROL_08;
            y = QUOTE(14 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class AltitudeTitle: Title
        {
            y = QUOTE(15 * CTRL_DEFAULT_H + 25 * pixelH);
            text = "$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
        };
        class AltitudeTitleA: ENH_3DEN_Attribute_Control_TitleAltitude
        {
            y = QUOTE(15 * CTRL_DEFAULT_H + 25 * pixelH);
        };
        class AltitudeValueZ: ENH_3DEN_Attribute_Control_ValueZ_Front
        {
            idc = IDC_ATTRIBUTE_CONTROL_09;
            y = QUOTE(15 * CTRL_DEFAULT_H + 25 * pixelH);
        };
        class SpeedTitle: Title
        {
            y = QUOTE(16 * CTRL_DEFAULT_H + 30 * pixelH);
            h = QUOTE(2 * CTRL_DEFAULT_H);
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_SPEED_DISPLAYNAME";
        };
        class SpeedValue: ctrlToolboxPictureKeepAspect
        {
            idc = IDC_ATTRIBUTE_CONTROL_10;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(16 * CTRL_DEFAULT_H + 30 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(2 * CTRL_DEFAULT_H);
            rows = 1;
            columns = 3;
            strings[] =
            {
                "\a3\3DEN\Data\Attributes\SpeedMode\limited_ca.paa",
                "\a3\3DEN\Data\Attributes\SpeedMode\normal_ca.paa",
                "\a3\3DEN\Data\Attributes\SpeedMode\full_ca.paa"
            };
            tooltips[] =
            {
                "$STR_ENH_MAIN_SPEED_LIMITED",
                "$STR_ENH_MAIN_SPEED_NORMAL",
                "$STR_ENH_MAIN_SPEED_FULL"
            };
            values[] = {0, 1, 2};
        };
        class SideTitle: Title
        {
            y = QUOTE(18 * CTRL_DEFAULT_H + 35 * pixelH);
            h = QUOTE(2 * CTRL_DEFAULT_H);
            text = "$STR_ENH_MAIN_SIDE_DISPLAYNAME";
        };
        class SideValue: ENH_3DEN_Attribute_Control_SideToolbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_11;
            y = QUOTE(18 * CTRL_DEFAULT_H + 35 * pixelH);
        };
        class DelayTitle: Title
        {
            text = "$STR_3DEN_TRIGGER_ATTRIBUTE_TIMEOUT_DISPLAYNAME";
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayTitleMin: ENH_3DEN_Attribute_Control_TitleMin
        {
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayValueMin: ENH_3DEN_Attribute_Control_ValueMin
        {
            idc = IDC_ATTRIBUTE_CONTROL_12;
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayTitleMid: ENH_3DEN_Attribute_Control_TitleMid
        {
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayValueMid: ENH_3DEN_Attribute_Control_ValueMid
        {
            idc = IDC_ATTRIBUTE_CONTROL_13;
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayTitleMax: ENH_3DEN_Attribute_Control_TitleMax
        {
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayValueMax: ENH_3DEN_Attribute_Control_ValueMax
        {
            idc = IDC_ATTRIBUTE_CONTROL_14;
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(21 * CTRL_DEFAULT_H + 45 * pixelH);
        };
    };
};
