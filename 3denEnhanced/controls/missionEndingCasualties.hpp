class ENH_MissionEnding_Casualties: Title
{
    attributeLoad = "[_this,_value] call ENH_fnc_missionEndingCasualties_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_missionEndingCasualties_onAttributeSave";
    h = 6 * SIZE_M * GRID_H + 25 * pixelH;
    class Controls: Controls
    {
        class ThresholdTitle: Title
        {
            text = $STR_ENH_MISSIONENDING_CASUALTIES_THRESHOLD_DISPLAYNAME;
            tooltip = $STR_ENH_MISSIONENDING_CASUALTIES_THRESHOLD_TOOLTIP;
        };
        class ThresholdValue: ctrlXSliderH
        {
            idc = 100;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            w = (ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
            h = SIZE_M * GRID_H;
             sliderPosition = 5;
            sliderRange[] = {1,100};
            sliderStep = 1;
            lineSize = 1;
        };
        class ThresholdEdit: ctrlEdit
        {
            idc = 101;
            x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
            w = EDIT_W * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class EndingTitle: Title
        {
            text = $STR_ENH_MISSIONENDING_ENDING_DISPLAYNAME;
            tooltip = $STR_ENH_MISSIONENDING_ENDING_TOOLTIP;
            y = 1 * SIZE_M * GRID_H + 5 * pixelH;
        };
        class Ending: ctrlCombo
        {
            idc = 102;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 1 * SIZE_M * GRID_H + 5 * pixelH;
            w = ATTRIBUTE_CONTENT_W * GRID_W;
            h = SIZE_M * GRID_H;
            wholeHeight = 6 * SIZE_M * GRID_H;
        };
        class IsWinTitle: Title
        {
            text = $STR_ENH_MISSIONENDING_WIN_DISPLAYNAME;
            y = 2 * SIZE_M * GRID_H + 10 * pixelH;
        };
        class IsWin: ctrlCheckbox
        {
            idc = 103;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 2 * SIZE_M * GRID_H + 10 * pixelH;
            w = 5 * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class SideTitle: Title
        {
            y = 3 * SIZE_M * GRID_H + 15 * pixelH;
            text = $STR_ENH_SIDE_DISPLAYNAME;
        };
        class SideValue: ENH_SideToolbox_Base
        {
            idc = 104;
            y = 3 * SIZE_M * GRID_H + 15 * pixelH;
        };
        class Reset: ENH_ResetButton_Base
        {
            y = 5 * SIZE_M * GRID_H + 20 * pixelH;
            onButtonDown  = "_this call ENH_fnc_missionEndingCasualties_onButtonDown";
        };
    };
};