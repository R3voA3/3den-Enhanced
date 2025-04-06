class ENH_AmbientFlyby: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_ambientFlyby_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_ambientFlyby_onAttributeSave";
    h = QUOTE(22 * CTRL_DEFAULT_H + 50 * pixelH);
    class Controls: Controls
    {
        class Search: ctrlEdit
        {
            idc = 501; // These idcs make it so that the search button is handled by the engine, why? Magic!
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE((ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            text = "";
        };
        class SearchButton: ctrlButtonSearch
        {
            idc = 502; // These idcs make it so that the search button is handled by the engine, why? Magic!
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
            idc = 500;
            idcSearch = 501;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(1 * CTRL_DEFAULT_H);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(10 * CTRL_DEFAULT_H);
        };
        class StartTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_STARTPOSITION_DISPLAYNAME";
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartTitleX: ENH_3DEN_Attribute_Control_TitleX
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartValueX: ENH_3DEN_Attribute_Control_ValueX
        {
            idc = 101;
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartTitleY: ENH_3DEN_Attribute_Control_TitleY
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartValueY: ENH_3DEN_Attribute_Control_ValueY
        {
            idc = 102;
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartTitleZ: ENH_3DEN_Attribute_Control_TitleZ
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartValueZ: ENH_3DEN_Attribute_Control_ValueZ
        {
            idc = 103;
            y = QUOTE(11 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 5 - 5) * GRID_W);
        };
        class PasteStartValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
        {
            idc = 115;
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
            idc = 104;
            y = QUOTE(12 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class EndTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_ENDPOSITION_DISPLAYNAME";
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndTitleX: ENH_3DEN_Attribute_Control_TitleX
        {
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndValueX: ENH_3DEN_Attribute_Control_ValueX
        {
            idc = 105;
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndTitleY: ENH_3DEN_Attribute_Control_TitleY
        {
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndValueY: ENH_3DEN_Attribute_Control_ValueY
        {
            idc = 106;
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndTitleZ: ENH_3DEN_Attribute_Control_TitleZ
        {
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class PasteEndValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
        {
            idc = 116;
            y = QUOTE(13 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndValueZ: StartValueZ
        {
            idc = 107;
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
            idc = 108;
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
            idc = 109;
            y = QUOTE(15 * CTRL_DEFAULT_H + 25 * pixelH);
        };
        class SpeedTitle: Title
        {
            y = QUOTE(16 * CTRL_DEFAULT_H + 30 * pixelH);
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_SPEED_DISPLAYNAME";
        };
        class SpeedValue: ctrlToolboxPictureKeepAspect
        {
            idc = 110;
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
            text = "$STR_ENH_MAIN_SIDE_DISPLAYNAME";
        };
        class SideValue: ENH_3DEN_Attribute_Control_SideToolbox
        {
            idc = 111;
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
            idc = 112;
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayTitleMid: ENH_3DEN_Attribute_Control_TitleMid
        {
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayValueMid: ENH_3DEN_Attribute_Control_ValueMid
        {
            idc = 113;
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayTitleMax: ENH_3DEN_Attribute_Control_TitleMax
        {
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayValueMax: ENH_3DEN_Attribute_Control_ValueMax
        {
            idc = 114;
            y = QUOTE(20 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(21 * CTRL_DEFAULT_H + 45 * pixelH);
        };
    };
};
