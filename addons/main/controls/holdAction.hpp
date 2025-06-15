class ENH_HoldAction: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_holdAction_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_holdAction_onAttributeSave";
    h = QUOTE(41 * CTRL_DEFAULT_H + 75 * pixelH);
    class Controls: Controls
    {
        class NameTitle: Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_NAME_DISPLAYNAME";
        };
        class Name: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class IdleIconTitle: Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_ICONIDLE_DISPLAYNAME";
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            h = QUOTE(2 * CTRL_DEFAULT_H);
        };
        class IdleIconBackground: ctrlStaticBackground
        {
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(10 * GRID_W);
            h = QUOTE(2 * CTRL_DEFAULT_H);
            colorBackground[] = {COLOR_OVERLAY_RGB, 0.3};
        };
        class IdleIcon: ctrlActivePictureKeepAspect
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            text = "a3\weapons_f\data\placeholder_co.paa";
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(10 * GRID_W);
            h = QUOTE(2 * CTRL_DEFAULT_H);
        };
        class ProgressIconTitle: IdleIconTitle
        {
            text = "$STR_ENH_MAIN_HOLDACTION_ICONPROGRESS_DISPLAYNAME";
            y = QUOTE(3 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class ProgressIconBackground: IdleIconBackground
        {
            y = QUOTE(3 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class ProgressIcon: IdleIcon
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            y = QUOTE(3 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        // Condition show
        class ConditionShowBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
        {
            y = QUOTE(5 * CTRL_DEFAULT_H + 2 * GRID_H + 15 * pixelH);
        };
        class ConditionShowTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_TOOLTIP";
            y = QUOTE(5 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class ConditionShow: ENH_3DEN_Attribute_Control_EditMulti5_Edit
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            y = QUOTE(5 * CTRL_DEFAULT_H + 5 * GRID_H + 15 * pixelH);
            autocomplete = "scripting";
        };
        // Condition progress
        class ConditionProgressBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
        {
            y = QUOTE(10 * CTRL_DEFAULT_H + 2 * GRID_H + 20 * pixelH);
        };
        class ConditionProgressTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_TOOLTIP";
            y = QUOTE(10 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class ConditionProgress: ENH_3DEN_Attribute_Control_EditMulti5_Edit
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            y = QUOTE(10 * CTRL_DEFAULT_H + 5 * GRID_H + 20 * pixelH);
            autocomplete = "scripting";
        };
        // Code start
        class CodeStartBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
        {
            y = QUOTE(15 * CTRL_DEFAULT_H + 2 * GRID_H + 25 * pixelH);
        };
        class CodeStartTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_CODESTART_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_CODESTART_TOOLTIP";
            y = QUOTE(15 * CTRL_DEFAULT_H + 25 * pixelH);
        };
        class CodeStart: ENH_3DEN_Attribute_Control_EditMulti5_Edit
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            y = QUOTE(15 * CTRL_DEFAULT_H + 5 * GRID_H + 25 * pixelH);
            autocomplete = "scripting";
        };
        // Code progress
        class CodeProgressBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
        {
            y = QUOTE(20 * CTRL_DEFAULT_H + 2 * GRID_H + 30 * pixelH);
        };
        class CodeProgressTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_TOOLTIP";
            y = QUOTE(20 * CTRL_DEFAULT_H + 30 * pixelH);
        };
        class CodeProgress: ENH_3DEN_Attribute_Control_EditMulti5_Edit
        {
            idc = IDC_ATTRIBUTE_CONTROL_06;
            y = QUOTE(20 * CTRL_DEFAULT_H + 5 * GRID_H + 30 * pixelH);
            autocomplete = "scripting";
        };
        // Code completion
        class CodeCompleteBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
        {
            y = QUOTE(25 * CTRL_DEFAULT_H + 2 * GRID_H + 35 * pixelH);
        };
        class CodeCompleteTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_TOOLTIP";
            y = QUOTE(25 * CTRL_DEFAULT_H + 35 * pixelH);
        };
        class CodeComplete: ENH_3DEN_Attribute_Control_EditMulti5_Edit
        {
            idc = IDC_ATTRIBUTE_CONTROL_07;
            y = QUOTE(25 * CTRL_DEFAULT_H + 5 * GRID_H + 35 * pixelH);
            autocomplete = "scripting";
        };
        // Code interrupt
        class CodeInterruptBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
        {
            y = QUOTE(30 * CTRL_DEFAULT_H + 2 * GRID_H + 40 * pixelH);
        };
        class CodeInterruptTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_TOOLTIP";
            y = QUOTE(30 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class CodeInterrupt: ENH_3DEN_Attribute_Control_EditMulti5_Edit
        {
            idc = IDC_ATTRIBUTE_CONTROL_08;
            y = QUOTE(30 * CTRL_DEFAULT_H + 5 * GRID_H + 40 * pixelH);
            autocomplete = "scripting";
        };
        class DurationTitle: Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_DURATION_DISPLAYNAME";
            y = QUOTE(35 * CTRL_DEFAULT_H + 45 * pixelH);
        };
        class DurationValue: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_09;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(35 * CTRL_DEFAULT_H + 45 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderRange[] = {1, 60};
            sliderStep = 1;
            lineSize = 1;
        };
        class DurationEdit: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_10;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            y = QUOTE(35 * CTRL_DEFAULT_H + 45 * pixelH);
            w = QUOTE(EDIT_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class PriorityTitle: Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_PRIORITY_DISPLAYNAME";
            y = QUOTE(36 * CTRL_DEFAULT_H + 50 * pixelH);
        };
        class PriorityValue: DurationValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_11;
            y = QUOTE(36 * CTRL_DEFAULT_H + 50 * pixelH);
            sliderRange[] = {1, 1000};
        };
        class PriorityEdit: DurationEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_12;
            y = QUOTE(36 * CTRL_DEFAULT_H + 50 * pixelH);
        };
        class ShowUnconsciousTitle: Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_SHOWUNCONSCIOUSY_DISPLAYNAME";
            y = QUOTE(37 * CTRL_DEFAULT_H + 55 * pixelH);
        };
        class ShowUnconscious: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_13;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(37 * CTRL_DEFAULT_H + 55 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class ShowWindowTitle: Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_SHOWWINDOW_DISPLAYNAME";
            y = QUOTE(38 * CTRL_DEFAULT_H + 60 * pixelH);
        };
        class ShowWindow: ShowUnconscious
        {
            idc = IDC_ATTRIBUTE_CONTROL_14;
            y = QUOTE(38 * CTRL_DEFAULT_H + 60 * pixelH);
        };
        class RemoveAfterUseTitle: Title
        {
            text = "$STR_ENH_MAIN_HOLDACTION_REMOVEONUSE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_REMOVEONUSE_TOOLTIP";
            y = QUOTE(39 * CTRL_DEFAULT_H + 65 * pixelH);
        };
        class RemoveAfterUse: ShowUnconscious
        {
            idc = IDC_ATTRIBUTE_CONTROL_15;
            y = QUOTE(39 * CTRL_DEFAULT_H + 65 * pixelH);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(40 * CTRL_DEFAULT_H + 70 * pixelH);
        };
    };
};
