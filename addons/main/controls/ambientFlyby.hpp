class ENH_AmbientFlyby: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_ambientFlyby_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_ambientFlyby_onAttributeSave";
    h = QUOTE(16 * CTRL_DEFAULT_H + 55 * pixelH);
    class Controls: Controls
    {
        class ClassesTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_CLASSES_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AMBIENTFLYBY_CLASSES_TOOLTIP";
        };
        class ClassesValue: ctrlEditMulti
        {
            idc = 100;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(4 * CTRL_DEFAULT_H);
        };
        class StartTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_STARTPOSITION_DISPLAYNAME";
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
        };
        class StartValue: ctrlEdit
        {
            idc = 101;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(4 * CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class StartRndOffsetTitle: Title
        {
            text = "Random Start Offset";
            y = QUOTE(5 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class StartRndOffsetValue: ctrlEdit
        {
            idc = 109;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(5 * CTRL_DEFAULT_H + 10 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class EndTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_ENDPOSITION_DISPLAYNAME";
            y = QUOTE(6 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndValue: StartValue
        {
            idc = 102;
            y = QUOTE(6 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class EndRndOffsetTitle: Title
        {
            text = "Random End Offset";
            y = QUOTE(7 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class EndRndOffsetValue: ctrlEdit
        {
            idc = 110;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(7 * CTRL_DEFAULT_H + 20 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class AltitudeTitle: Title
        {
            y = QUOTE(8 * CTRL_DEFAULT_H + 25 * pixelH);
            text = "$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
        };
        class AltitudeValue: ctrlXSliderH
        {
            idc = 103;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(8 * CTRL_DEFAULT_H + 25 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderPosition = 500;
            sliderRange[] = {50, 3000};
            sliderStep = 50;
            lineSize = 50;
        };
        class AltitudeEdit: StartValue
        {
            idc = 104;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            y = QUOTE(8 * CTRL_DEFAULT_H + 25 * pixelH);
            w = QUOTE(EDIT_W_WIDE * GRID_W);
        };
        class SpeedTitle: Title
        {
            y = QUOTE(9 * CTRL_DEFAULT_H + 30 * pixelH);
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_SPEED_DISPLAYNAME";
        };
        class SpeedValue: ctrlToolboxPictureKeepAspect
        {
            idc = 105;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(9 * CTRL_DEFAULT_H + 30 * pixelH);
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
            y = QUOTE(11 * CTRL_DEFAULT_H + 35 * pixelH);
            text = "$STR_ENH_MAIN_SIDE_DISPLAYNAME";
        };
        class SideValue: ENH_SideToolbox_Base
        {
            idc = 106;
            y = QUOTE(11 * CTRL_DEFAULT_H + 35 * pixelH);
        };
        class DelayTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTFLYBY_DELAY_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AMBIENTFLYBY_DELAY_TOOLTIP";
            y = QUOTE(13 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayValue: AltitudeValue
        {
            idc = 107;
            y = QUOTE(13 * CTRL_DEFAULT_H + 40 * pixelH);
            sliderPosition = 300;
            sliderRange[] = {60, 3600};
            sliderStep = 5;
        };
        class DelayEdit: AltitudeEdit
        {
            idc = 108;
            y = QUOTE(13 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class DelayRndOffsetTitle: Title
        {
            text = "Random Start Offset";
            y = QUOTE(14 * CTRL_DEFAULT_H + 45 * pixelH);
        };
        class DelayRndOffsetValue: ctrlEdit
        {
            idc = 111;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(14 * CTRL_DEFAULT_H + 45 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Reset: ENH_ResetButton_Base
        {
            y = QUOTE(15 * CTRL_DEFAULT_H + 50 * pixelH);
        };
    };
};
