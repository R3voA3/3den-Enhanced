class ENH_TaskPatrol: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_taskPatrol_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_taskPatrol_onAttributeSave";
	class Controls: Controls
	{
		class Title: Title {};
		class Value: ctrlXSliderH
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_ULTRA_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 0;
			sliderRange[] = {0,2500};
			sliderStep = 100;
			lineSize = 100;
		};
		class Edit: ctrlEdit
		{
			idc = 101;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_ULTRA_WIDE) * GRID_W;
			w = EDIT_W_ULTRA_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
	};
};