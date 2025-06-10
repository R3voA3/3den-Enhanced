class ENH_DynamicSkill: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_dynamicSkill_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_dynamicSkill_onAttributeSave";
    h = QUOTE(17 * CTRL_DEFAULT_H + 90 * pixelH);
    class Controls: Controls
    {
        class EnableTitle: Title
        {
            text = "$STR_ENH_MAIN_ENABLE";
        };
        class Enable: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class BLUFORDescriptionDeco: ctrlStatic
        {
            x = QUOTE(5 * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 10 * pixelH);
            w = QUOTE(5 * pixelW);
            h = QUOTE(CTRL_DEFAULT_H);
            colorBackground[] = {1, 1, 1, 0.05};
        };
        class BLUFORDescriptionHeader: ctrlStatic
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_BLUFORSKILL_DISPLAYNAME";
            x = QUOTE(5 * GRID_W + 7 * pixelW);
            y = QUOTE(CTRL_DEFAULT_H + 10 * pixelH);
            w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW);
            h = QUOTE(CTRL_DEFAULT_H);
            colorText[] = {1, 1, 1, 0.4};
            colorBackground[] = {1, 1, 1, 0.05};
            colorShadow[] = {0, 0, 0, 0};
        };
        class SkillMinBLUFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLMIN_DISPLAYNAME";
            y = QUOTE(2 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class SkillMinBLUFORValue: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(2 * CTRL_DEFAULT_H + 15 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderRange[] = {0.2, 1};
        };
        class SkillMinBLUFOREdit: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
            y = QUOTE(2 * CTRL_DEFAULT_H + 15 * pixelH);
            w = QUOTE(EDIT_W_WIDE * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SkillAimMinBLUFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME";
            y = QUOTE(3 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class SkillAimMinBLUFORValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            y = QUOTE(3 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class SkillAimMinBLUFOREdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            y = QUOTE(3 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class SkillMaxBLUFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLMAX_DISPLAYNAME";
            y = QUOTE(4 * CTRL_DEFAULT_H + 25 * pixelH);
        };
        class SkillMaxBLUFORValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            y = QUOTE(4 * CTRL_DEFAULT_H + 25 * pixelH);
        };
        class SkillMaxBLUFOREdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_06;
            y = QUOTE(4 * CTRL_DEFAULT_H + 25 * pixelH);
        };
        class SkillAimMaxBLUFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME";
            y = QUOTE(5 * CTRL_DEFAULT_H + 30 * pixelH);
        };
        class SkillAimMaxBLUFORValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_07;
            y = QUOTE(5 * CTRL_DEFAULT_H + 30 * pixelH);
        };
        class SkillAimMaxBLUFOREdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_08;
            y = QUOTE(5 * CTRL_DEFAULT_H + 30 * pixelH);
        };
        // OPFOR
        class OPFORDescriptionDeco: BLUFORDescriptionDeco
        {
            y = QUOTE(6 * CTRL_DEFAULT_H + 35 * pixelH);
        };
        class OPFORDescriptionHeader: BLUFORDescriptionHeader
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_OPFORSKILL_DISPLAYNAME";
            y = QUOTE(6 * CTRL_DEFAULT_H + 35 * pixelH);
        };
        class SkillMinOPFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLMIN_DISPLAYNAME";
            y = QUOTE(7 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class SkillMinOPFORValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_09;
            y = QUOTE(7 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class SkillMinOPFOREdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_10;
            y = QUOTE(7 * CTRL_DEFAULT_H + 40 * pixelH);
        };
        class SkillAimMinOPFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME";
            y = QUOTE(8 * CTRL_DEFAULT_H + 45 * pixelH);
        };
        class SkillAimMinOPFORValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_11;
            y = QUOTE(8 * CTRL_DEFAULT_H + 45 * pixelH);
        };
        class SkillAimMinOPFOREdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_12;
            y = QUOTE(8 * CTRL_DEFAULT_H + 45 * pixelH);
        };
        class SkillMaxOPFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLMAX_DISPLAYNAME";
            y = QUOTE(9 * CTRL_DEFAULT_H + 50 * pixelH);
        };
        class SkillMaxOPFORValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_13;
            y = QUOTE(9 * CTRL_DEFAULT_H + 50 * pixelH);
        };
        class SkillMaxOPFOREdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_14;
            y = QUOTE(9 * CTRL_DEFAULT_H + 50 * pixelH);
        };
        class SkillAimMaxOPFORTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME";
            y = QUOTE(10 * CTRL_DEFAULT_H + 55 * pixelH);
        };
        class SkillAimMaxOPFORValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_15;
            y = QUOTE(10 * CTRL_DEFAULT_H + 55 * pixelH);
        };
        class SkillAimMaxOPFOREdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_16;
            y = QUOTE(10 * CTRL_DEFAULT_H + 55 * pixelH);
        };
        // Independent
        class IndependentDescriptionDeco: BLUFORDescriptionDeco
        {
            y = QUOTE(11 * CTRL_DEFAULT_H + 60 * pixelH);
        };
        class IndependentDescriptionHeader: BLUFORDescriptionHeader
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_IndependentSKILL_DISPLAYNAME";
            y = QUOTE(11 * CTRL_DEFAULT_H + 60 * pixelH);
        };
        class SkillMinIndependentTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLMIN_DISPLAYNAME";
            y = QUOTE(12 * CTRL_DEFAULT_H + 65 * pixelH);
        };
        class SkillMinIndependentValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_17;
            y = QUOTE(12 * CTRL_DEFAULT_H + 65 * pixelH);
        };
        class SkillMinIndependentEdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_18;
            y = QUOTE(12 * CTRL_DEFAULT_H + 65 * pixelH);
        };
        class SkillAimMinIndependentTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME";
            y = QUOTE(13 * CTRL_DEFAULT_H + 70 * pixelH);
        };
        class SkillAimMinIndependentValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_19;
            y = QUOTE(13 * CTRL_DEFAULT_H + 70 * pixelH);
        };
        class SkillAimMinIndependentEdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_20;
            y = QUOTE(13 * CTRL_DEFAULT_H + 70 * pixelH);
        };
        class SkillMaxIndependentTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLMAX_DISPLAYNAME";
            y = QUOTE(14 * CTRL_DEFAULT_H + 75 * pixelH);
        };
        class SkillMaxIndependentValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_21;
            y = QUOTE(14 * CTRL_DEFAULT_H + 75 * pixelH);
        };
        class SkillMaxIndependentEdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_22;
            y = QUOTE(14 * CTRL_DEFAULT_H + 75 * pixelH);
        };
        class SkillAimMaxIndependentTitle: Title
        {
            text = "$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME";
            y = QUOTE(15 * CTRL_DEFAULT_H + 80 * pixelH);
        };
        class SkillAimMaxIndependentValue: SkillMinBLUFORValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_23;
            y = QUOTE(15 * CTRL_DEFAULT_H + 80 * pixelH);
        };
        class SkillAimMaxIndependentEdit: SkillMinBLUFOREdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_24;
            y = QUOTE(15 * CTRL_DEFAULT_H + 80 * pixelH);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(16 * CTRL_DEFAULT_H + 85 * pixelH);
        };
    };
};
