class ENH_MissionEnding_Casualties: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_missionEndingCasualties_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_missionEndingCasualties_onAttributeSave";
	h = 11.5 * SIZE_M * GRID_H + 30 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_MISSIONENDING_CASUALTIES_DESCRIPTION,4);
		class ThresholdTitle: Title
		{
			y = 5.5 * SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_MISSIONENDING_CASUALTIES_THRESHOLD_DISPLAYNAME;
			tooltip = $STR_ENH_MISSIONENDING_CASUALTIES_THRESHOLD_TOOLTIP;
		};
		class ThresholdValue: ctrlXSliderH
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 5.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 5;
			sliderRange[] = {1,100};
			sliderStep = 1;
			lineSize = 1;
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
			text = $STR_ENH_MISSIONENDING_ENDING_DISPLAYNAME;
			tooltip = $STR_ENH_MISSIONENDING_ENDING_TOOLTIP;
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Ending: ctrlCombo
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			wholeHeight = 6 * SIZE_M * GRID_H;
		};
		class IsWinTitle: Title 
		{
			text = $STR_ENH_MISSIONENDING_WIN_DISPLAYNAME;
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
			text = $STR_ENH_SIDE_DISPLAYNAME;
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
			onButtonDown  = "_this call ENH_fnc_missionEndingCasualties_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};