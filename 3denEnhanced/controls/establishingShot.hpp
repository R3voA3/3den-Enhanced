class Enh_EstablishingShot: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_establishingShot_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_establishingShot_onAttributeSave";
	h = 12.5 * SIZE_M * GRID_H + 40 * pixelH;
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
					text = $STR_ENH_establishingShot_description;
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
		class CenterTitle: Title
		{
			text = $STR_ENH_establishingShot_centerPos_displayName;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class CenterValue: ctrlEdit
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class TextTitle: Title
		{
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_establishingShot_displayedText;
		};
		class TextValue: CenterValue
		{
			idc = 101;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class AltitudeTitle: Title
		{
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_altitude_displayName;
		};
		class AltitudeValue: ctrlXSliderH
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 500;
			sliderRange[] = {50,2000};
			sliderStep = 1;
		};
		class AltitudeEdit: ctrlEdit
		{
			idc = 103;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class RadiusTitle: Title
		{
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_establishingShot_radius_displayName;
		};
		class RadiusValue: ctrlXSliderH
		{
			idc = 104;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 200;
			sliderRange[] = {50,2000};
			sliderStep = 1;
		};
		class RadiusEdit: ctrlEdit
		{
			idc = 105;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class AngleTitle: Title
		{
			y = 8.5 * SIZE_M * GRID_H + 25 * pixelH;
			text = $STR_ENH_establishingShot_viewingAngle_displayName;
		};
		class AngleValue: ctrlXSliderH
		{
			idc = 106;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 45;
			sliderRange[] = {0,360};
			sliderStep = 1;
		};
		class AngleEdit: ctrlEdit
		{
			idc = 107;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class DirectionTitle: Title
		{
			y = 9.5 * SIZE_M * GRID_H + 30 * pixelH;
			text = $STR_ENH_establishingShot_direction_displayName;
		};
		class DirectionValue: ctrlToolbox
        {
            idc = 108;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 9.5 * SIZE_M * GRID_H + 30 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 2 * SIZE_M * GRID_H;
            rows = 2;
            columns = 1;
            strings[] = 
            {
				$STR_ENH_establishingShot_antiClockwise,
				$STR_ENH_establishingShot_clockwise
            };
            values[] = {0,1};
        };
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 11.5 * SIZE_M * GRID_H + 35 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call Enh_fnc_establishingShot_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};