class ENH_DebugOptions: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_debugOptions_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_debugOptions_onAttributeSave";
	h = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_DEBUGOPTIONS_DESCRIPTION,3);
		class Title: Title
		{
			text = $STR_ENH_OPTIONS;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class DebugOptions: ctrlListbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 6 * SIZE_M * GRID_H;
			onLBSelChanged = "_this call ENH_fnc_debugOptions_onLBSelChanged";
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 10.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_debugOptions_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};