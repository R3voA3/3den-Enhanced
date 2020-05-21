class ENH_HoldAction: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_holdAction_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_holdAction_onAttributeSave";
	h = 32.5 * SIZE_M * GRID_H + 75 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_HOLDACTION_DESCRIPTION,5);
		class NameTitle: Title
		{
			text = $STR_ENH_HOLDACTION_NAME_DISPLAYNAME;
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
			text = $STR_ENH_HOLDACTION_ICONIDLE_DISPLAYNAME;
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
			text = $STR_ENH_HOLDACTION_ICONPROGRESS_DISPLAYNAME;
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
			text = $STR_ENH_HOLDACTION_CONDITIONSHOW_DISPLAYNAME;
			tooltip = $STR_ENH_HOLDACTION_CONDITIONSHOW_TOOLTIP;
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
			text = $STR_ENH_HOLDACTION_CONDITIONPROGRESS_DISPLAYNAME;
			tooltip = $STR_ENH_HOLDACTION_CONDITIONPROGRESS_TOOLTIP;
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
			text = $STR_ENH_HOLDACTION_CODESTART_DISPLAYNAME;
			tooltip = $STR_ENH_HOLDACTION_CODESTART_TOOLTIP;
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
			text = $STR_ENH_HOLDACTION_CODEPROGRESS_DISPLAYNAME;
			tooltip = $STR_ENH_HOLDACTION_CODEPROGRESS_TOOLTIP;
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
			text = $STR_ENH_HOLDACTION_CODECOMPLETE_DISPLAYNAME;
			tooltip = $STR_ENH_HOLDACTION_CODECOMPLETE_TOOLTIP;
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
			text = $STR_ENH_HOLDACTION_CODEINTERRUPT_DISPLAYNAME;
			tooltip = $STR_ENH_HOLDACTION_CODEINTERRUPT_TOOLTIP;
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
			text = $STR_ENH_HOLDACTION_DURATION_DISPLAYNAME;
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
			lineSize = 1;
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
			text = $STR_ENH_HOLDACTION_PRIORITY_DISPLAYNAME;
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
			lineSize = 1;
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
			text = $STR_ENH_HOLDACTION_SHOWUNCONSCIOUSY_DISPLAYNAME;
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
			text = $STR_ENH_HOLDACTION_SHOWWINDOW_DISPLAYNAME;
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
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 31.5 * SIZE_M * GRID_H + 70 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_holdAction_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};