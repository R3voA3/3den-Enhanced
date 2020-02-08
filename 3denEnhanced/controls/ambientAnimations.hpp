class ENH_AmbientAnimations: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_ambientAnimations_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_ambientAnimations_onAttributeSave";
	h = 13.5 * SIZE_M * GRID_H + 25 * pixelH;
	class Controls: Controls
	{
		class DescriptionGroup: ctrlControlsGroup
		{
			x = 5 * GRID_W;
			y = 0.5 * SIZE_M * GRID_H;
			h = 2 * SIZE_M * GRID_H;
			w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W) * GRID_W;
			class Controls
			{
				class DescriptionDeco: ctrlStatic
				{
					w = 5 * pixelW;
					h = SIZE_M * GRID_H;
					colorBackground[] = {1,1,1,0.05};
				};
				class DescriptionHeader: ctrlStatic
				{
					text = $STR_ENH_DESCRIPTION;
					x = 7 * pixelW;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0.05};
					colorShadow[] = {0,0,0,0}; 
				};
				class Description: ctrlStructuredText
				{
					text = $STR_ENH_AMBIENTANIMATIONS_DESCRIPTION;
					x = 7 * pixelW;
					y = SIZE_M * GRID_H;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0};
					shadow = 0;
					class Attributes
					{
						align = "left";
						color = "#999999";
						colorLink = "";
						font = "RobotoCondensedLight";
						size = 1;
					};
				};
			};
		};
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