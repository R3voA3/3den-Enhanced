class Enh_TimeMultiplier: Title
{
	attributeLoad =
	"\
		_ctrlGroup = _this;\
		_ctrlSlider = _ctrlGroup controlsgroupctrl 100;\
		_ctrlEdit = _ctrlGroup controlsgroupctrl 101;\
		_value = _value max (sliderrange _ctrlSlider # 0) min (sliderrange _ctrlSlider # 1);\
		_ctrlEdit ctrlSetText (str ((round (_value * 10)) / 10) + 'x');\
		_ctrlSlider sliderSetPosition _value;\
	";
	attributeSave =
	"\
		_value = sliderPosition (_this controlsGroupCtrl 100);\
		if (_value >= 1) then\
		{\
			round _value;\
		}\
		else\
		{\
			parseNumber (_value toFixed 1);\
		};\
	";

	class Controls: Controls
	{
		class Title: Title {};
		class Value: ctrlXSliderH
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 1;
			sliderRange[] = {0.1,120};
			onSliderPosChanged =
			"\
				_ctrlGroup = ctrlParentControlsGroup (_this # 0);\
				_ctrlEdit = _ctrlGroup controlsGroupCtrl 101;\
				_value = sliderPosition (_this # 0);\
				if (_value >= 1) then\
				{\
					_ctrlEdit ctrlSetText (str round _value + 'x');\
				}\
				else\
				{\
					_ctrlEdit ctrlSetText (str (parseNumber (_value toFixed 1)) + 'x');\
				};\
			";
		};
		class Edit: ctrlEdit
		{
			idc = 101;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
			w = EDIT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onKillFocus =
			"\
				_ctrlEdit = _this # 0;\
				_ctrlGroup = ctrlParentControlsGroup _ctrlEdit;\
				_ctrlSlider = _ctrlGroup controlsGroupctrl 100;\
				_value = parseNumber ctrlText _ctrlEdit;\
				_value = _value max (sliderRange _ctrlSlider # 0) min (sliderRange _ctrlSlider # 1);\
				_ctrlEdit ctrlSetText (str ((round (_value * 10)) / 10) + 'x');\
				_ctrlSlider sliderSetPosition _value;\
			";
		};
	};
};
