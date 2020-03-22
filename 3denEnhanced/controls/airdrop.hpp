class ENH_Airdrop: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_airdrop_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_airdrop_onAttributeSave";
	h = 17.5 * SIZE_M * GRID_H + 40 * pixelH;//We make it 5 * pixelH larger to prevent scrolling issues
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_AIRDROP_DESCRIPTION,3);
		class ClassesTitle: Title
		{
			text = $STR_ENH_AIRDROP_CLASSES_DISPLAYNAME;
			tooltip = $STR_ENH_AIRDROP_CLASSES_TOOLTIP;
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
			text = $STR_ENH_AIRDROP_CENTER_DISPLAYNAME;
			tooltip = $STR_ENH_AIRDROP_CENTER_TOOLTIP;
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
			text = $STR_ENH_AIRDROP_CONDITION_DISPLAYNAME;
			tooltip = $STR_ENH_AIRDROP_CONDITION_TOOLTIP;
		};
		class ConditionValue: CenterValue
		{
			idc = 102;
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class AltitudeTitle: Title
		{
			y = 12.5 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_ALTITUDE_DISPLAYNAME;
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
			lineSize = 50;
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
			text = $STR_ENH_AIRDROP_RADIUS_DISPLAYNAME;
			tooltip = $STR_ENH_AIRDROP_RADIUS_TOOLTIP;
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
			lineSize = 50;
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
			y = 14.5 * SIZE_M * GRID_H + 30 * pixelH;
			text = $STR_ENH_SIDE_DISPLAYNAME;
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
			onButtonDown  = "_this call ENH_fnc_airdrop_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};