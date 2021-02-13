class ENH_DynamicSkill: Title
{
  attributeLoad = "[_this, _value] call ENH_fnc_dynamicSkill_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_dynamicSkill_onAttributeSave";
  h = 17 * SIZE_M * GRID_H + 90 * pixelH;
  class Controls: Controls
  {
    class EnableTitle: Title
    {
      text = $STR_ENH_ENABLE;
    };
    class Enable: ctrlCheckbox
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = 5 * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class BLUFORDescriptionDeco: ctrlStatic
    {
      x = 5 * GRID_W;
      y = SIZE_M * GRID_H + 10 * pixelH;
      w = 5 * pixelW;
      h = SIZE_M * GRID_H;
      colorBackground[] = {1, 1, 1, 0.05};
    };
    class BLUFORDescriptionHeader: ctrlStatic
    {
      text = $STR_ENH_DYNAMICSKILL_BLUFORSKILL_DISPLAYNAME;
      x = 5 * GRID_W + 7 * pixelW;
      y = SIZE_M * GRID_H + 10 * pixelH;
      w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
      h = SIZE_M * GRID_H;
      colorText[] = {1, 1, 1, 0.4};
      colorBackground[] = {1, 1, 1, 0.05};
      colorShadow[] = {0, 0, 0, 0};
    };
    class SkillMinBLUFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLMIN_DISPLAYNAME;
      y = 2 * SIZE_M * GRID_H + 15 * pixelH;
    };
    class SkillMinBLUFORValue: ctrlXSliderH
    {
      idc = 101;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 2 * SIZE_M * GRID_H + 15 * pixelH;
      w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
      h = SIZE_M * GRID_H;
      sliderRange[] = {0.2, 1};
    };
    class SkillMinBLUFOREdit: ctrlEdit
    {
      idc = 102;
      x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
      y = 2 * SIZE_M * GRID_H + 15 * pixelH;
      w = EDIT_W_WIDE * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class SkillAimMinBLUFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME;
      y = 3 * SIZE_M * GRID_H + 20 * pixelH;
    };
    class SkillAimMinBLUFORValue: SkillMinBLUFORValue
    {
      idc = 103;
      y = 3 * SIZE_M * GRID_H + 20 * pixelH;
    };
    class SkillAimMinBLUFOREdit: SkillMinBLUFOREdit
    {
      idc = 104;
      y = 3 * SIZE_M * GRID_H + 20 * pixelH;
    };

    class SkillMaxBLUFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLMAX_DISPLAYNAME;
      y = 4 * SIZE_M * GRID_H + 25 * pixelH;
    };
    class SkillMaxBLUFORValue: SkillMinBLUFORValue
    {
      idc = 105;
      y = 4 * SIZE_M * GRID_H + 25 * pixelH;
    };
    class SkillMaxBLUFOREdit: SkillMinBLUFOREdit
    {
      idc = 106;
      y = 4 * SIZE_M * GRID_H + 25 * pixelH;
    };
    class SkillAimMaxBLUFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME;
      y = 5 * SIZE_M * GRID_H + 30 * pixelH;
    };
    class SkillAimMaxBLUFORValue: SkillMinBLUFORValue
    {
      idc = 107;
      y = 5 * SIZE_M * GRID_H + 30 * pixelH;
    };
    class SkillAimMaxBLUFOREdit: SkillMinBLUFOREdit
    {
      idc = 108;
      y = 5 * SIZE_M * GRID_H + 30 * pixelH;
    };
    //OPFOR
    class OPFORDescriptionDeco: BLUFORDescriptionDeco
    {
      y = 6 * SIZE_M * GRID_H + 35 * pixelH;
    };
    class OPFORDescriptionHeader: BLUFORDescriptionHeader
    {
      text = $STR_ENH_DYNAMICSKILL_OPFORSKILL_DISPLAYNAME;
      y = 6 * SIZE_M * GRID_H + 35 * pixelH;
    };
    class SkillMinOPFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLMIN_DISPLAYNAME;
      y = 7 * SIZE_M * GRID_H + 40 * pixelH;
    };
    class SkillMinOPFORValue: SkillMinBLUFORValue
    {
      idc = 109;
      y = 7 * SIZE_M * GRID_H + 40 * pixelH;
    };
    class SkillMinOPFOREdit: SkillMinBLUFOREdit
    {
      idc = 110;
      y = 7 * SIZE_M * GRID_H + 40 * pixelH;
    };
    class SkillAimMinOPFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME;
      y = 8 * SIZE_M * GRID_H + 45 * pixelH;
    };
    class SkillAimMinOPFORValue: SkillMinBLUFORValue
    {
      idc = 111;
      y = 8 * SIZE_M * GRID_H + 45 * pixelH;
    };
    class SkillAimMinOPFOREdit: SkillMinBLUFOREdit
    {
      idc = 112;
      y = 8 * SIZE_M * GRID_H + 45 * pixelH;
    };
    class SkillMaxOPFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLMAX_DISPLAYNAME;
      y = 9 * SIZE_M * GRID_H + 50 * pixelH;
    };
    class SkillMaxOPFORValue: SkillMinBLUFORValue
    {
      idc = 113;
      y = 9 * SIZE_M * GRID_H + 50 * pixelH;
    };
    class SkillMaxOPFOREdit: SkillMinBLUFOREdit
    {
      idc = 114;
      y = 9 * SIZE_M * GRID_H + 50 * pixelH;
    };
    class SkillAimMaxOPFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME;
      y = 10 * SIZE_M * GRID_H + 55 * pixelH;
    };
    class SkillAimMaxOPFORValue: SkillMinBLUFORValue
    {
      idc = 115;
      y = 10 * SIZE_M * GRID_H + 55 * pixelH;
    };
    class SkillAimMaxOPFOREdit: SkillMinBLUFOREdit
    {
      idc = 116;
      y = 10 * SIZE_M * GRID_H + 55 * pixelH;
    };
    //INDFOR
    class INDFORDescriptionDeco: BLUFORDescriptionDeco
    {
      y = 11 * SIZE_M * GRID_H + 60 * pixelH;
    };
    class INDFORDescriptionHeader: BLUFORDescriptionHeader
    {
      text = $STR_ENH_DYNAMICSKILL_INDFORSKILL_DISPLAYNAME;
      y = 11 * SIZE_M * GRID_H + 60 * pixelH;
    };
    class SkillMinINDFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLMIN_DISPLAYNAME;
      y = 12 * SIZE_M * GRID_H + 65 * pixelH;
    };
    class SkillMinINDFORValue: SkillMinBLUFORValue
    {
      idc = 117;
      y = 12 * SIZE_M * GRID_H + 65 * pixelH;
    };
    class SkillMinINDFOREdit: SkillMinBLUFOREdit
    {
      idc = 118;
      y = 12 * SIZE_M * GRID_H + 65 * pixelH;
    };
    class SkillAimMinINDFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME;
      y = 13 * SIZE_M * GRID_H + 70 * pixelH;
    };
    class SkillAimMinINDFORValue: SkillMinBLUFORValue
    {
      idc = 119;
      y = 13 * SIZE_M * GRID_H + 70 * pixelH;
    };
    class SkillAimMinINDFOREdit: SkillMinBLUFOREdit
    {
      idc = 120;
      y = 13 * SIZE_M * GRID_H + 70 * pixelH;
    };
    class SkillMaxINDFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLMAX_DISPLAYNAME;
      y = 14 * SIZE_M * GRID_H + 75 * pixelH;
    };
    class SkillMaxINDFORValue: SkillMinBLUFORValue
    {
      idc = 121;
      y = 14 * SIZE_M * GRID_H + 75 * pixelH;
    };
    class SkillMaxINDFOREdit: SkillMinBLUFOREdit
    {
      idc = 122;
      y = 14 * SIZE_M * GRID_H + 75 * pixelH;
    };

    class SkillAimMaxINDFORTitle: Title
    {
      text = $STR_ENH_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME;
      y = 15 * SIZE_M * GRID_H + 80 * pixelH;
    };
    class SkillAimMaxINDFORValue: SkillMinBLUFORValue
    {
      idc = 123;
      y = 15 * SIZE_M * GRID_H + 80 * pixelH;
    };
    class SkillAimMaxINDFOREdit: SkillMinBLUFOREdit
    {
      idc = 124;
      y = 15 * SIZE_M * GRID_H + 80 * pixelH;
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 16 * SIZE_M * GRID_H + 85 * pixelH;
    };
  };
};