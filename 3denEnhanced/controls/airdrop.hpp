class Enh_Airdrop: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_airdrop_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_airdrop_onAttributeSave";
	h = 17.5 * SIZE_M * GRID_H + 35 * pixelH;
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
					text = $STR_ENH_airdrop_description;
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
		class ClassesTitle: Title
		{
			text = $STR_ENH_airdrop_classes_displayName;
			tooltip = $STR_ENH_airdrop_classes_tooltip;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class ClassesValue: ctrlEditMulti
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 6 * SIZE_M * GRID_H;
		};
		class CenterTitle: Title
		{
			text = $STR_ENH_airdrop_center_displayName;
			tooltip = $STR_ENH_airdrop_center_tooltip;
			y = 10.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class CenterValue: ctrlEdit
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 10.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ConditionTitle: Title
		{
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_airdrop_condition_displayName;
			tooltip = $STR_ENH_airdrop_condition_tooltip;
		};
		class ConditionValue: CenterValue
		{
			idc = 102;
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class AltitudeTitle: Title
		{
			y = 12.5 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_altitude_displayName;
		};
		class AltitudeValue: ctrlXSliderH
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 500;
			sliderRange[] = {200,5000};
			sliderStep = 50;
		};
		class AltitudeEdit: ctrlEdit
		{
			idc = 104;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class RadiusTitle: Title
		{
			y = 13.5 * SIZE_M * GRID_H + 25 * pixelH;
			text = $STR_ENH_airdrop_radius_displayName;
			tooltip = $STR_ENH_airdrop_radius_tooltip;
		};
		class RadiusValue: ctrlXSliderH
		{
			idc = 105;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 13.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 200;
			sliderRange[] = {50,2000};
			sliderStep = 50;
		};
		class RadiusEdit: ctrlEdit
		{
			idc = 106;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 13.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class SideTitle: Title
		{
			y = 14 * SIZE_M * GRID_H + 30 * pixelH;
			text = $STR_ENH_side_displayName;
		};
		class SideValue: ctrlToolboxPictureKeepAspect
        {
            idc = 107;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 14.5 * SIZE_M * GRID_H + 30 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 2 * SIZE_M * GRID_H;
            rows = 1; 
            columns = 4;
            strings[] = 
            {
				"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa",
				"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa",
				"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa",
				"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa"
            };
            values[] = {0,1,2,3};
        };
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 16.5 * SIZE_M * GRID_H + 35 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call Enh_fnc_airdrop_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};