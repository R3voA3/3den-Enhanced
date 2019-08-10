class Enh_GroupMarker: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_groupMarker_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_groupMarker_onAttributeSave";
	h = 9.5 * SIZE_M * GRID_H + 30 * pixelH;
	class Controls: Controls
	{
		class DescriptionGroup: ctrlControlsGroup
		{
			x = 5 * GRID_W;
			y = 0.5 * SIZE_M * GRID_H;
			h = 4 * SIZE_M * GRID_H;
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
					text = $STR_ENH_description;
					x = 7 * pixelW;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0.05};
					colorShadow[] = {0,0,0,0};
				};
				class Description: ctrlStructuredText
				{
					text = $STR_ENH_groupMarker_description;
					x = 7 * pixelW;
					y = SIZE_M * GRID_H;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = 3 * SIZE_M * GRID_H;
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
		class TypeTitle: Title 
		{
			text = $STR_ENH_groupMarker_type;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Type: ctrlCombo
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ColourTitle: Title
		{
			text = $STR_ENH_groupMarker_colour;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Colour: ctrlCombo
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};		
		class TextTitle: Title
		{
			text = $STR_ENH_groupMarker_text;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class Text: ctrlEdit
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ShowGroupSizeTitle: Title 
		{
			text = $STR_ENH_groupMarker_showGroupSize;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
		class ShowGroupSize: ctrlCheckbox
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call Enh_fnc_groupMarker_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};