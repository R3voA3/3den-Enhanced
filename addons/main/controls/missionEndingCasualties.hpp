class ENH_MissionEnding_Casualties: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_missionEndingCasualties_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_missionEndingCasualties_onAttributeSave";
    h = QUOTE(6 * CTRL_DEFAULT_H + 25 * pixelH);
    class Controls: Controls
    {
        class ThresholdTitle: Title
        {
            text = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_THRESHOLD_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_THRESHOLD_TOOLTIP";
        };
        class ThresholdValue: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
             sliderPosition = 5;
            sliderRange[] = {1, 100};
            sliderStep = 1;
            lineSize = 1;
        };
        class ThresholdEdit: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            w = QUOTE(EDIT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class EndingTitle: Title
        {
            text = "$STR_ENH_MAIN_MISSIONENDING_ENDING_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_MISSIONENDING_ENDING_TOOLTIP";
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
        };
        class Ending: ctrlCombo
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            holeHeight = "6 * CTRL_DEFAULT_H";
        };
        class IsWinTitle: Title
        {
            text = "$STR_ENH_MAIN_MISSIONENDING_WIN_DISPLAYNAME";
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class IsWin: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SideTitle: Title
        {
            text = "$STR_ENH_MAIN_SIDE_DISPLAYNAME";
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
            h = QUOTE(2 * CTRL_DEFAULT_H);
        };
        class SideValue: ENH_3DEN_Attribute_Control_SideToolbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(5 * CTRL_DEFAULT_H + 20 * pixelH);
        };
    };
};
