class Enh_IntroText: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_introText_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_introText_onAttributeSave";
	h = 5 * SIZE_M * GRID_H + 20 * pixelH;
	class Controls: Controls
	{
		class DelayText: Title
		{
			text = $STR_ENH_introText_introDelay_displayName;
			tooltip = $STR_ENH_introText_introDelay_tooltip;
		};
		class Line1Text: DelayText
		{
			y = SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_introText_line1_displayName;
			tooltip = "";
		};
		class Line2Text: DelayText
		{
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_introText_line2_displayName;
			tooltip = "";
		};
		class Line3Text: DelayText
		{
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_introText_line3_displayName;
			tooltip = "";
		};
		class ApexIntroText: DelayText
		{
			y = 4 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_introText_introType_displayName;
			tooltip = "";
		};
		class DelayValue: ctrlEdit
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Line1Value: DelayValue
		{
			idc = 101;
			y = SIZE_M * GRID_H + 5 * pixelH;
		};
		class Line2Value: DelayValue
		{
			idc = 102;
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Line3Value: DelayValue
		{
			idc = 103;
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class ApexIntroTextValue: ctrlCheckbox
		{
			idc = 104;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4 * SIZE_M * GRID_H + 20 * pixelH;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};