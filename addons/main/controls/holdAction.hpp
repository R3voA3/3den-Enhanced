class ENH_HoldAction: Title
{
	attributeLoad = "[_this, _value] call ENH_fnc_holdAction_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_holdAction_onAttributeSave";
	h = QUOTE(26 * CTRL_DEFAULT_H + 70 * pixelH);
	class Controls: Controls
	{
		class NameTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_NAME_DISPLAYNAME";
		};
		class Name: ctrlEdit
		{
			idc = 100;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class IdleIconTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_ICONIDLE_DISPLAYNAME";
			y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
		};
		class IdleIcon: ctrlCombo
		{
			idc = 101;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
			w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class ProgressIconTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_ICONPROGRESS_DISPLAYNAME";
			y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
		};
		class ProgressIcon: IdleIcon
		{
			idc = 102;
			y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
		};
		class ConditionShowTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_DISPLAYNAME";
			tooltip = "$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_TOOLTIP";
			y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
		};
		class ConditionShow: ctrlEditMulti
		{
			idc = 103;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
			w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
			h = QUOTE(3 * CTRL_DEFAULT_H);
		};
		class ConditionProgressTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_DISPLAYNAME";
			tooltip = "$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_TOOLTIP";
			y = QUOTE(6 * CTRL_DEFAULT_H + 20 * pixelH);
		};
		class ConditionProgress: ConditionShow
		{
			idc = 104;
			y = QUOTE(6 * CTRL_DEFAULT_H + 20 * pixelH);
		};
		class CodeStartTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_CODESTART_DISPLAYNAME";
			tooltip = "$STR_ENH_MAIN_HOLDACTION_CODESTART_TOOLTIP";
			y = QUOTE(9 * CTRL_DEFAULT_H + 25 * pixelH);
		};
		class CodeStart: ConditionShow
		{
			idc = 105;
			y = QUOTE(9 * CTRL_DEFAULT_H + 25 * pixelH);
		};
		class CodeProgressTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_DISPLAYNAME";
			tooltip = "$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_TOOLTIP";
			y = QUOTE(12 * CTRL_DEFAULT_H + 30 * pixelH);
		};
		class CodeProgress: ConditionShow
		{
			idc = 106;
			y = QUOTE(12 * CTRL_DEFAULT_H + 30 * pixelH);
		};
		class CodeCompletionTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_DISPLAYNAME";
			tooltip = "$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_TOOLTIP";
			y = QUOTE(15 * CTRL_DEFAULT_H + 35 * pixelH);
		};
		class CodeCompletion: ConditionShow
		{
			idc = 107;
			y = QUOTE(15 * CTRL_DEFAULT_H + 35 * pixelH);
		};
		class CodeInterruptTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_DISPLAYNAME";
			tooltip = "$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_TOOLTIP";
			y = QUOTE(18 * CTRL_DEFAULT_H + 40 * pixelH);
		};
		class CodeInterrupt: ConditionShow
		{
			idc = 108;
			y = QUOTE(18 * CTRL_DEFAULT_H + 40 * pixelH);
		};
		class DurationTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_DURATION_DISPLAYNAME";
			y = QUOTE(21 * CTRL_DEFAULT_H + 45 * pixelH);
		};
		class DurationValue: ctrlXSliderH
		{
			idc = 109;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			y = QUOTE(21 * CTRL_DEFAULT_H + 45 * pixelH);
			w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
			sliderRange[] = {1, 60};
			sliderStep = 1;
			lineSize = 1;
		};
		class DurationEdit: ctrlEdit
		{
			idc = 110;
			x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
			y = QUOTE(21 * CTRL_DEFAULT_H + 45 * pixelH);
			w = QUOTE(EDIT_W_WIDE * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class PriorityTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_PRIORITY_DISPLAYNAME";
			y = QUOTE(22 * CTRL_DEFAULT_H + 50 * pixelH);
		};
		class PriorityValue: DurationValue
		{
			idc = 111;
			y = QUOTE(22 * CTRL_DEFAULT_H + 50 * pixelH);
			sliderRange[] = {1, 1000};
		};
		class PriorityEdit: DurationEdit
		{
			idc = 112;
			y = QUOTE(22 * CTRL_DEFAULT_H + 50 * pixelH);
		};
		class ShowUnconsciousTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_SHOWUNCONSCIOUSY_DISPLAYNAME";
			y = QUOTE(23 * CTRL_DEFAULT_H + 55 * pixelH);
		};
		class ShowUnconscious: ctrlCheckbox
		{
			idc = 113;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			y = QUOTE(23 * CTRL_DEFAULT_H + 55 * pixelH);
			w = QUOTE(5 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class ShowWindowTitle: Title
		{
			text = "$STR_ENH_MAIN_HOLDACTION_SHOWWINDOW_DISPLAYNAME";
			y = QUOTE(24 * CTRL_DEFAULT_H + 60 * pixelH);
		};
		class ShowWindow: ShowUnconscious
		{
			idc = 114;
			y = QUOTE(24 * CTRL_DEFAULT_H + 60 * pixelH);
		};
		class Reset: ENH_ResetButton_Base
		{
			y = QUOTE(25 * CTRL_DEFAULT_H + 65 * pixelH);
		};
	};
};