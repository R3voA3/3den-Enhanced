class ENH_TimeMultiplier: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_timeMultiplier_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_timeMultiplier_onAttributeSave";
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
			sliderStep = 0.1;
		};
		class Edit: ctrlEdit
		{
			idc = 101;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
			w = EDIT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
	};
};