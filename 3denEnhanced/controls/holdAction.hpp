class Enh_HoldAction: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_holdAction_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_holdAction_onAttributeSave";
	h = 37.5 * SIZE_M * GRID_H + 75 * pixelH;
	class Controls: Controls
	{
		class DescriptionGroup: ctrlControlsGroup
		{
			x = 5 * GRID_W;
			y = 0.5 * SIZE_M * GRID_H;
			h = 6 * SIZE_M * GRID_H;
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
					text = "Adds a hold action to this entity. Can be a custom one, or one of the templates. Once the action was completed it's removed for all clients. For a detailed description of this attribute see: <a href='https://community.bistudio.com/wiki/BIS_fnc_holdActionAdd'>BIS_fnc_holdActionAdd</a>.";
					x = 7 * pixelW;
					y = SIZE_M * GRID_H;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = 5 * SIZE_M * GRID_H;
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
		class NameTitle: Title
		{
			text = "Name";
			y = 6.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Name: ctrlEdit
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class IdleIconTitle: Title
		{
			text = "Icon Idle";
			y = 7.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class IdleIcon: ctrlCombo
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};		
		class ProgressIconTitle: Title
		{
			text = "Icon Progress";
			y = 8.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class ProgressIcon: ctrlCombo
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ConditionShowTitle: Title
		{
			text = "Condition Show ";
			tooltip = "Condition for the action to be shown. Passed arguments are:\n_target, _this (caller).";
			y = 9.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
		class ConditionShow: ctrlEditMulti
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 9.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 3 * SIZE_M * GRID_H;
		};
		class ConditionProgressTitle: Title
		{
			text = "Condition Progress";
			tooltip = "Condition for the action to progress. Passed arguments are:\n_target, _caller, _actionID.";
			y = 12.5 * SIZE_M * GRID_H + 25 * pixelH;
		};
		class ConditionProgress: ctrlEditMulti
		{
			idc = 104;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 3 * SIZE_M * GRID_H;
		};
		class CodeStartTitle: Title
		{
			text = "Code Start";
			tooltip = "Code executed when action starts.  Passed arguments are:\n_target, _caller, _actionID.";
			y = 15.5 * SIZE_M * GRID_H + 30 * pixelH;
		};
		class CodeStart: ctrlEditMulti
		{
			idc = 105;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 15.5 * SIZE_M * GRID_H + 30 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 3 * SIZE_M * GRID_H;
		};
		class CodeProgressTitle: Title
		{
			text = "Code Progress";
			tooltip = "Code executed on every progress tick. Passed arguments are:\n_target, _caller, _actionID, _progress, _maxProgress.";
			y = 18.5 * SIZE_M * GRID_H + 35 * pixelH;
		};
		class CodeProgress: ctrlEditMulti
		{
			idc = 106;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 18.5 * SIZE_M * GRID_H + 35 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 3 * SIZE_M * GRID_H;
		};
		class CodeCompletionTitle: Title
		{
			text = "Code Complete";
			tooltip = "Code executed on completion. Passed arguments are:\n_target, _caller, _actionID.";
			y = 21.5 * SIZE_M * GRID_H + 40 * pixelH;
		};
		class CodeCompletion: ctrlEditMulti
		{
			idc = 107;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 21.5 * SIZE_M * GRID_H + 40 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 3 * SIZE_M * GRID_H;
		};
		class CodeInterruptTitle: Title
		{
			text = "Code Interrupt";
			tooltip = "Code executed when action is interrupted. Passed arguments are:\n_target, _caller, _actionID.";
			y = 24.5 * SIZE_M * GRID_H + 45 * pixelH;
		};
		class CodeInterrupt: ctrlEditMulti
		{
			idc = 108;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 24.5 * SIZE_M * GRID_H + 45 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 3 * SIZE_M * GRID_H;
		};
		class DurationTitle: Title
		{
			text = "Duration";
			y = 27.5 * SIZE_M * GRID_H + 50 * pixelH;
		};
		class DurationValue: ctrlXSliderH
		{
			idc = 109;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 27.5 * SIZE_M * GRID_H + 50 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {1,60};
			sliderStep = 1;
		};
		class DurationEdit: ctrlEdit
		{
			idc = 110;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 27.5 * SIZE_M * GRID_H + 50 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class PriorityTitle: Title
		{
			text = "Priority";
			y = 28.5 * SIZE_M * GRID_H + 55 * pixelH;
		};
		class PriorityValue: ctrlXSliderH
		{
			idc = 111;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 28.5 * SIZE_M * GRID_H + 55 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {1,1000};
			sliderStep = 1;
		};
		class PriorityEdit: ctrlEdit
		{
			idc = 112;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 28.5 * SIZE_M * GRID_H + 55 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ShowUnconsciousTitle: Title
		{
			text = "Show when Unconscious";
			y = 29.5 * SIZE_M * GRID_H + 60 * pixelH;
		};
		class ShowUnconscious: ctrlCheckbox
		{
			idc = 113;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 29.5 * SIZE_M * GRID_H + 60 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ShowWindowTitle: Title
		{
			text = "Show Window";
			y = 30.5 * SIZE_M * GRID_H + 65 * pixelH;
		};
		class ShowWindow: ctrlCheckbox
		{
			idc = 114;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 30.5 * SIZE_M * GRID_H + 65 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class TemplateTitle: Title
		{
			text = "Template";
			y = 31.5 * SIZE_M * GRID_H + 70 * pixelH;
		};
		class Template: ctrlListbox
		{
			idc = 115;
			tooltip = "Not implemented yet."
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 31.5 * SIZE_M * GRID_H + 70 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 5 * SIZE_M * GRID_H;
			//onLoad = "_this # 0 ctrlEnable false";
			onLBSelChanged = "_this call Enh_fnc_holdAction_onLBSelChanged";
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 36.5 * SIZE_M * GRID_H + 75 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call Enh_fnc_holdAction_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};