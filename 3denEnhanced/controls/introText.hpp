class Enh_IntroText: Title
{
	attributeLoad=
	"\
		_delay = _value param [0,-1,[-1]];\
		_line1 = _value param [1,missionName,['']];\
		_line2 = _value param [2,'by ' + profileName,['']];\
		_line3 = _value param [3,([daytime,'HH:MM'] call BIS_fnc_TimeToString),['']];\
		_introType = _value param [4,false,[false]];\
		\
		_ctrlDelay = _this controlsGroupCtrl 100;\
		_ctrlLine1 = _this controlsGroupCtrl 101;\
		_ctrlLine2 = _this controlsGroupCtrl 102;\
		_ctrlLine3 = _this controlsGroupCtrl 103;\
		_ctrlAPEX  = _this controlsGroupCtrl 104;\
		\
		_ctrlDelay ctrlSetText str _delay;\
		_ctrlLine1 ctrlSetText _line1;\
		_ctrlLine2 ctrlSetText _line2;\
		_ctrlLine3 ctrlSetText _line3;\
		_ctrlAPEX cbSetChecked _introType";

	attributeSave =
	"\
		_ctrlDelay = _this controlsGroupCtrl 100;\
		_ctrlLine1 = _this controlsGroupCtrl 101;\
		_ctrlLine2 = _this controlsGroupCtrl 102;\
		_ctrlLine3 = _this controlsGroupCtrl 103;\
		_ctrlAPEX  = _this controlsGroupCtrl 104;\
		[\
			parseNumber (ctrlText _ctrlDelay),\
			ctrlText _ctrlLine1,\
			ctrlText _ctrlLine2,\
			ctrlText _ctrlLine3,\
			cbChecked _ctrlAPEX\
		]";

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