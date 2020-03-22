class ENH_DynamicSkill: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_dynamicSkill_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_dynamicSkill_onAttributeSave";
	h = 21.5 * SIZE_M * GRID_H + 90 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_DYNAMICSKILL_DESCRIPTION,3);
		class EnableTitle: Title 
		{
			text = $STR_ENH_ENABLE;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Enable: ctrlCheckbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class BLUFORDescriptionDeco: ctrlStatic
		{
			x = 5 * GRID_W;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = 5 * pixelW;
			h = SIZE_M * GRID_H;
			colorBackground[] = {1,1,1,0.05};
		};
		class BLUFORDescriptionHeader: ctrlStatic
		{
			text = $STR_ENH_DYNAMICSKILL_BLUFORSKILL_DISPLAYNAME;
			x = 5 * GRID_W + 7 * pixelW;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
			h = SIZE_M * GRID_H;
			colorText[] = {1,1,1,0.4};
			colorBackground[] = {1,1,1,0.05};
			colorShadow[] = {0,0,0,0};
		};
		class SkillMinBLUFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLMIN_DISPLAYNAME;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class SkillMinBLUFORValue: ctrlXSliderH
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillMinBLUFOREdit: ctrlEdit
		{
			idc = 102;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class SkillAimMinBLUFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
		class SkillAimMinBLUFORValue: ctrlXSliderH
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillAimMinBLUFOREdit: ctrlEdit
		{
			idc = 104;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};

		class SkillMaxBLUFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLMAX_DISPLAYNAME;
			y = 8.5 * SIZE_M * GRID_H + 25 * pixelH;
		};
		class SkillMaxBLUFORValue: ctrlXSliderH
		{
			idc = 105;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillMaxBLUFOREdit: ctrlEdit
		{
			idc = 106;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};

		class SkillAimMaxBLUFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME;
			y = 9.5 * SIZE_M * GRID_H + 30 * pixelH;
		};
		class SkillAimMaxBLUFORValue: ctrlXSliderH
		{
			idc = 107;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 9.5 * SIZE_M * GRID_H + 30 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillAimMaxBLUFOREdit: ctrlEdit
		{
			idc = 108;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 9.5 * SIZE_M * GRID_H + 30 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		//OPFOR
		class OPFORDescriptionDeco: ctrlStatic
		{
			x = 5 * GRID_W;
			y = 10.5 * SIZE_M * GRID_H + 35 * pixelH;
			w = 5 * pixelW;
			h = SIZE_M * GRID_H;
			colorBackground[] = {1,1,1,0.05};
		};
		class OPFORDescriptionHeader: ctrlStatic
		{
			text = $STR_ENH_DYNAMICSKILL_OPFORSKILL_DISPLAYNAME;
			x = 5 * GRID_W + 7 * pixelW;
			y = 10.5 * SIZE_M * GRID_H + 35 * pixelH;
			w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
			h = SIZE_M * GRID_H;
			colorText[] = {1,1,1,0.4};
			colorBackground[] = {1,1,1,0.05};
			colorShadow[] = {0,0,0,0};
		};
		class SkillMinOPFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLMIN_DISPLAYNAME;
			y = 11.5 * SIZE_M * GRID_H + 40 * pixelH;
		};
		class SkillMinOPFORValue: ctrlXSliderH
		{
			idc = 109;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 11.5 * SIZE_M * GRID_H + 40 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillMinOPFOREdit: ctrlEdit
		{
			idc = 110;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 11.5 * SIZE_M * GRID_H + 40 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class SkillAimMinOPFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME;
			y = 12.5 * SIZE_M * GRID_H + 45 * pixelH;
		};
		class SkillAimMinOPFORValue: ctrlXSliderH
		{
			idc = 111;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 45 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillAimMinOPFOREdit: ctrlEdit
		{
			idc = 112;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 45 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};

		class SkillMaxOPFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLMAX_DISPLAYNAME;
			y = 13.5 * SIZE_M * GRID_H + 50 * pixelH;
		};
		class SkillMaxOPFORValue: ctrlXSliderH
		{
			idc = 113;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 13.5 * SIZE_M * GRID_H + 50 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillMaxOPFOREdit: ctrlEdit
		{
			idc = 114;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 13.5 * SIZE_M * GRID_H + 50 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};

		class SkillAimMaxOPFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME;
			y = 14.5 * SIZE_M * GRID_H + 55 * pixelH;
		};
		class SkillAimMaxOPFORValue: ctrlXSliderH
		{
			idc = 115;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 14.5 * SIZE_M * GRID_H + 55 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillAimMaxOPFOREdit: ctrlEdit
		{
			idc = 116;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 14.5 * SIZE_M * GRID_H + 55 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		//INDFOR
		class INDFORDescriptionDeco: ctrlStatic
		{
			x = 5 * GRID_W;
			y = 15.5 * SIZE_M * GRID_H + 60 * pixelH;
			w = 5 * pixelW;
			h = SIZE_M * GRID_H;
			colorBackground[] = {1,1,1,0.05};
		};
		class INDFORDescriptionHeader: ctrlStatic
		{
			text = $STR_ENH_DYNAMICSKILL_INDFORSKILL_DISPLAYNAME;
			x = 5 * GRID_W + 7 * pixelW;
			y = 15.5 * SIZE_M * GRID_H + 60 * pixelH;
			w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
			h = SIZE_M * GRID_H;
			colorText[] = {1,1,1,0.4};
			colorBackground[] = {1,1,1,0.05};
			colorShadow[] = {0,0,0,0};
		};
		class SkillMinINDFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLMIN_DISPLAYNAME;
			y = 16.5 * SIZE_M * GRID_H + 65 * pixelH;
		};
		class SkillMinINDFORValue: ctrlXSliderH
		{
			idc = 117;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 16.5 * SIZE_M * GRID_H + 65 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillMinINDFOREdit: ctrlEdit
		{
			idc = 118;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 16.5 * SIZE_M * GRID_H + 65 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class SkillAimMinINDFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME;
			y = 17.5 * SIZE_M * GRID_H + 70 * pixelH;
		};
		class SkillAimMinINDFORValue: ctrlXSliderH
		{
			idc = 119;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 17.5 * SIZE_M * GRID_H + 70 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillAimMinINDFOREdit: ctrlEdit
		{
			idc = 120;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 17.5 * SIZE_M * GRID_H + 70 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};

		class SkillMaxINDFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLMAX_DISPLAYNAME;
			y = 18.5 * SIZE_M * GRID_H + 75 * pixelH;
		};
		class SkillMaxINDFORValue: ctrlXSliderH
		{
			idc = 121;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 18.5 * SIZE_M * GRID_H + 75 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillMaxINDFOREdit: ctrlEdit
		{
			idc = 122;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 18.5 * SIZE_M * GRID_H + 75 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};

		class SkillAimMaxINDFORTitle: Title
		{
			text = $STR_ENH_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME;
			y = 19.5 * SIZE_M * GRID_H + 80 * pixelH;
		};
		class SkillAimMaxINDFORValue: ctrlXSliderH
		{
			idc = 123;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 19.5 * SIZE_M * GRID_H + 80 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0.2,1};
		};
		class SkillAimMaxINDFOREdit: ctrlEdit
		{
			idc = 124;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 19.5 * SIZE_M * GRID_H + 80 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			y = 20.5 * SIZE_M * GRID_H + 85 * pixelH;
			onButtonDown  = "_this call ENH_fnc_dynamicSkill_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};