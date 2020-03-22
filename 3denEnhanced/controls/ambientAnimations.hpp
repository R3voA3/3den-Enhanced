class ENH_AmbientAnimations: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_ambientAnimations_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_ambientAnimations_onAttributeSave";
	h = 13.5 * SIZE_M * GRID_H + 25 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_AMBIENTANIMATIONS_DESCRIPTION,1);
		class AnimText: Title
		{
			text = $STR_ENH_AMBIENTANIMATIONS_ANIMATION_DISPLAYNAME;
			y = 2.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Anim: ctrlListbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 2.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 8 * SIZE_M * GRID_H;
		};
		class CanExitTitle: Title 
		{
			text = $STR_ENH_AMBIENTANIMATIONS_CANEDIT_DISPLAYNAME;
			tooltip = $STR_ENH_AMBIENTANIMATIONS_CANEDIT_TOOLTIP;
			y = 10.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class CanExit: ctrlCheckbox
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 10.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class AttachTitle: Title 
		{
			text = $STR_ENH_AMBIENTANIMATIONS_ATTACH_DISPLAYNAME;
			tooltip = $STR_ENH_AMBIENTANIMATIONS_ATTACH_TOOLTIP;
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class Attach: ctrlCheckbox
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_ambientAnimations_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};