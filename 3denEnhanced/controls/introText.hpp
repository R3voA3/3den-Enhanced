class Enh_IntroText: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_introText_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_introText_onAttributeSave";
	h = 6 * SIZE_M * GRID_H + 25 * pixelH;
	class Controls: Controls
	{
		class DelayTitle: Title
		{
			text = $STR_ENH_introText_introDelay_displayName;
			tooltip = $STR_ENH_introText_introDelay_tooltip;
		};
		class DelayValue: ctrlXSliderH
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 0;
			sliderRange[] = {0,360};
			sliderStep = 1;
		};
		class DelayEdit: ctrlEdit
		{
			idc = 101;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Line1Title: DelayTitle
		{
			y = SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_introText_line1_displayName;
			tooltip = "";
		};
		class Line1Value: ctrlEdit
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			y = SIZE_M * GRID_H + 5 * pixelH;
			h = SIZE_M * GRID_H;
		};
		class Line2Title: DelayTitle
		{
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_introText_line2_displayName;
			tooltip = "";
		};
		class Line2Value: Line1Value
		{
			idc = 103;
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Line3Title: DelayTitle
		{
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_introText_line3_displayName;
			tooltip = "";
		};
		class Line3Value: Line1Value
		{
			idc = 104;
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class IntroTypeTitle: DelayTitle
		{
			y = 4 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_introText_introType_displayName;
			tooltip = "";
		};
		class IntroTypeValue: ctrlCheckbox
		{
			idc = 105;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4 * SIZE_M * GRID_H + 20 * pixelH;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			y = 5 * SIZE_M * GRID_H + 25 * pixelH;
			onButtonDown  = "_this call Enh_fnc_introText_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};