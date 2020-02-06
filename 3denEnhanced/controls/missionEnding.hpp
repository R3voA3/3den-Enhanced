class Enh_MissionEnding_Casualties: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_missionEnding_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_missionEnding_onAttributeSave";
	h = 11.5 * SIZE_M * GRID_H + 30 * pixelH;
	class Controls: Controls
	{
		class DescriptionGroup: ctrlControlsGroup
		{
			x = 5 * GRID_W;
			y = 0.5 * SIZE_M * GRID_H;
			h = 5 * SIZE_M * GRID_H;
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
					text = $STR_ENH_missionEnding_casualties_description;
					x = 7 * pixelW;
					y = SIZE_M * GRID_H;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = 4 * SIZE_M * GRID_H;
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
		class ThresholdTitle: Title
		{
			y = 5.5 * SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_missionEnding_casualties_threshold_displayName;
			tooltip = $STR_ENH_missionEnding_casualties_threshold_tooltip;
		};
		class ThresholdValue: ctrlXSliderH
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 5.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 5;
			sliderRange[] = {1,100};
			sliderStep = 1;
		};
		class ThresholdEdit: ctrlEdit
		{
			idc = 101;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
			y = 5.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = EDIT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class EndingTitle: Title 
		{
			text = $STR_ENH_missionEnding_casualties_threshold_ending_displayName;
			tooltip = $STR_ENH_missionEnding_casualties_threshold_ending_tooltip;
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Ending: ctrlCombo
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class IsWinTitle: Title 
		{
			text = $STR_ENH_missionEnding_casualties_threshold_win_displayName;
			y = 7.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class IsWin: ctrlCheckbox
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class SideTitle: Title
		{
			y = 8.5 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_side_displayName;
		};
		class SideValue: ctrlToolboxPictureKeepAspect
        {
            idc = 104;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 20 * pixelH;
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
			y = 10.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call Enh_fnc_missionEnding_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};