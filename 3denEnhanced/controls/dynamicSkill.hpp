class Enh_DynamicSkill: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_dynamicSkill_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_dynamicSkill_onAttributeSave";
	h = 21.5 * SIZE_M * GRID_H + 90 * pixelH;
	class Controls: Controls
	{
		class DescriptionGroup: ctrlControlsGroup
		{
			x = 5 * GRID_W;
			y = 0.5 * SIZE_M * GRID_H;
			h = 4 * SIZE_M * GRID_H;
			w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W) * GRID_W;
			class Controls
			{
				class DescriptionDeco: ctrlStatic
				{
					w = 5 * pixelW;
					h = SIZE_M * GRID_H;
					colorBackground[] = {1,1,1,0.05};
				};
				class DescriptionHeader: ctrlStatic
				{
					text = $STR_ENH_description;
					x = 7 * pixelW;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0.05};
					colorShadow[] = {0,0,0,0};
				};
				class Description: ctrlStructuredText
				{
					text = $STR_ENH_dynamicSkill_description;
					x = 7 * pixelW;
					y = SIZE_M * GRID_H;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = 3 * SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0};
					shadow = 0;
					class Attributes
					{
						align = "left";
						color = "#999999";
						colorLink = "";
						font = "RobotoCondensedLight";
						size = 1;
					};
				};
			};
		};
		class EnableTitle: Title 
		{
			text = $STR_ENH_enable;
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
			text = $STR_ENH_dynamicSkill_BLUFORSkill_displayname;
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
			text = $STR_ENH_dynamicSkill_skillMin_displayname;
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
			text = $STR_ENH_dynamicSkill_skillAimMin_displayname;
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
			text = $STR_ENH_dynamicSkill_skillMax_displayname;
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
			text = $STR_ENH_dynamicSkill_skillAimMax_displayname;
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
			text = $STR_ENH_dynamicSkill_OPFORSkill_displayname;
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
			text = $STR_ENH_dynamicSkill_skillMin_displayname;
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
			text = $STR_ENH_dynamicSkill_skillAimMin_displayname;
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
			text = $STR_ENH_dynamicSkill_skillMax_displayname;
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
			text = $STR_ENH_dynamicSkill_skillAimMax_displayname;
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
			text = $STR_ENH_dynamicSkill_INDFORSkill_displayname;
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
			text = $STR_ENH_dynamicSkill_skillMin_displayname;
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
			text = $STR_ENH_dynamicSkill_skillAimMin_displayname;
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
			text = $STR_ENH_dynamicSkill_skillMax_displayname;
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
			text = $STR_ENH_dynamicSkill_skillAimMax_displayname;
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
			onButtonDown  = "_this call Enh_fnc_dynamicSkill_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};