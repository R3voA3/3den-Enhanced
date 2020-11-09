class ENH_HoldAction: Title
{
    attributeLoad = "[_this,_value] call ENH_fnc_holdAction_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_holdAction_onAttributeSave";
    h = 26 * SIZE_M * GRID_H + 70 * pixelH;
    class Controls: Controls
    {
        class NameTitle: Title
        {
            text = $STR_ENH_HOLDACTION_NAME_DISPLAYNAME;
        };
        class Name: ctrlEdit
        {
            idc = 100;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            w = ATTRIBUTE_CONTENT_W * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class IdleIconTitle: Title
        {
            text = $STR_ENH_HOLDACTION_ICONIDLE_DISPLAYNAME;
            y = SIZE_M * GRID_H + 5 * pixelH;
        };
        class IdleIcon: ctrlCombo
        {
            idc = 101;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = SIZE_M * GRID_H + 5 * pixelH;
            w = ATTRIBUTE_CONTENT_W * GRID_W;
            h = SIZE_M * GRID_H;
        };        
        class ProgressIconTitle: Title
        {
            text = $STR_ENH_HOLDACTION_ICONPROGRESS_DISPLAYNAME;
            y = 2 * SIZE_M * GRID_H + 10 * pixelH;
        };
        class ProgressIcon: IdleIcon
        {
            idc = 102;
            y = 2 * SIZE_M * GRID_H + 10 * pixelH;
        };
        class ConditionShowTitle: Title
        {
            text = $STR_ENH_HOLDACTION_CONDITIONSHOW_DISPLAYNAME;
            tooltip = $STR_ENH_HOLDACTION_CONDITIONSHOW_TOOLTIP;
            y = 3 * SIZE_M * GRID_H + 15 * pixelH;
        };
        class ConditionShow: ctrlEditMulti
        {
            idc = 103;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 3 * SIZE_M * GRID_H + 15 * pixelH;
            w = ATTRIBUTE_CONTENT_W * GRID_W;
            h = 3 * SIZE_M * GRID_H;
        };
        class ConditionProgressTitle: Title
        {
            text = $STR_ENH_HOLDACTION_CONDITIONPROGRESS_DISPLAYNAME;
            tooltip = $STR_ENH_HOLDACTION_CONDITIONPROGRESS_TOOLTIP;
            y = 6 * SIZE_M * GRID_H + 20 * pixelH;
        };
        class ConditionProgress: ConditionShow
        {
            idc = 104;
            y = 6 * SIZE_M * GRID_H + 20 * pixelH;
        };
        class CodeStartTitle: Title
        {
            text = $STR_ENH_HOLDACTION_CODESTART_DISPLAYNAME;
            tooltip = $STR_ENH_HOLDACTION_CODESTART_TOOLTIP;
            y = 9 * SIZE_M * GRID_H + 25 * pixelH;
        };
        class CodeStart: ConditionShow
        {
            idc = 105;
            y = 9 * SIZE_M * GRID_H + 25 * pixelH;
        };
        class CodeProgressTitle: Title
        {
            text = $STR_ENH_HOLDACTION_CODEPROGRESS_DISPLAYNAME;
            tooltip = $STR_ENH_HOLDACTION_CODEPROGRESS_TOOLTIP;
            y = 12 * SIZE_M * GRID_H + 30 * pixelH;
        };
        class CodeProgress: ConditionShow
        {
            idc = 106;
            y = 12 * SIZE_M * GRID_H + 30 * pixelH;
        };
        class CodeCompletionTitle: Title
        {
            text = $STR_ENH_HOLDACTION_CODECOMPLETE_DISPLAYNAME;
            tooltip = $STR_ENH_HOLDACTION_CODECOMPLETE_TOOLTIP;
            y = 15 * SIZE_M * GRID_H + 35 * pixelH;
        };
        class CodeCompletion: ConditionShow
        {
            idc = 107;
            y = 15 * SIZE_M * GRID_H + 35 * pixelH;
        };
        class CodeInterruptTitle: Title
        {
            text = $STR_ENH_HOLDACTION_CODEINTERRUPT_DISPLAYNAME;
            tooltip = $STR_ENH_HOLDACTION_CODEINTERRUPT_TOOLTIP;
            y = 18 * SIZE_M * GRID_H + 40 * pixelH;
        };
        class CodeInterrupt: ConditionShow
        {
            idc = 108;
            y = 18 * SIZE_M * GRID_H + 40 * pixelH;
        };
        class DurationTitle: Title
        {
            text = $STR_ENH_HOLDACTION_DURATION_DISPLAYNAME;
            y = 21 * SIZE_M * GRID_H + 45 * pixelH;
        };
        class DurationValue: ctrlXSliderH
        {
            idc = 109;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 21 * SIZE_M * GRID_H + 45 * pixelH;
            w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            h = SIZE_M * GRID_H;
            sliderRange[] = {1,60};
            sliderStep = 1;
            lineSize = 1;
        };
        class DurationEdit: ctrlEdit
        {
            idc = 110;
            x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            y = 21 * SIZE_M * GRID_H + 45 * pixelH;
            w = EDIT_W_WIDE * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class PriorityTitle: Title
        {
            text = $STR_ENH_HOLDACTION_PRIORITY_DISPLAYNAME;
            y = 22 * SIZE_M * GRID_H + 50 * pixelH;
        };
        class PriorityValue: DurationValue
        {
            idc = 111;
            y = 22 * SIZE_M * GRID_H + 50 * pixelH;
            sliderRange[] = {1,1000};
        };
        class PriorityEdit: DurationEdit
        {
            idc = 112;
            y = 22 * SIZE_M * GRID_H + 50 * pixelH;
        };
        class ShowUnconsciousTitle: Title
        {
            text = $STR_ENH_HOLDACTION_SHOWUNCONSCIOUSY_DISPLAYNAME;
            y = 23 * SIZE_M * GRID_H + 55 * pixelH;
        };
        class ShowUnconscious: ctrlCheckbox
        {
            idc = 113;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 23 * SIZE_M * GRID_H + 55 * pixelH;
            w = 5 * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class ShowWindowTitle: Title
        {
            text = $STR_ENH_HOLDACTION_SHOWWINDOW_DISPLAYNAME;
            y = 24 * SIZE_M * GRID_H + 60 * pixelH;
        };
        class ShowWindow: ShowUnconscious
        {
            idc = 114;
            y = 24 * SIZE_M * GRID_H + 60 * pixelH;
        };
        class Reset: ENH_ResetButton_Base
        {
            y = 25 * SIZE_M * GRID_H + 65 * pixelH;
            onButtonDown  = "_this call ENH_fnc_holdAction_onButtonDown";
        };
    };
};