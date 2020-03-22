class ENH_AmbientFlyby: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_ambientFlyby_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_ambientFlyby_onAttributeSave";
	h = 19.5 * SIZE_M * GRID_H + 45 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_AMBIENTFLYBY_DESCRIPTION,3);
		class ClassesTitle: Title
		{
			text = $STR_ENH_AMBIENTFLYBY_CLASSES_DISPLAYNAME;
			tooltip = $STR_ENH_AMBIENTFLYBY_CLASSES_TOOLTIP;
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
		class StartTitle: Title
		{
			text = $STR_ENH_AMBIENTFLYBY_STARTPOSITION_DISPLAYNAME;
			y = 10.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class StartValue: ctrlEdit
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 10.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class EndTitle: Title
		{
			text = $STR_ENH_AMBIENTFLYBY_ENDPOSITION_DISPLAYNAME;
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class EndValue: ctrlEdit
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
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
			sliderRange[] = {50,3000};
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
		class SpeedTitle: Title
		{
			y = 13.5 * SIZE_M * GRID_H + 25 * pixelH;
			text = $STR_ENH_AMBIENTFLYBY_SPEED_DISPLAYNAME;
		};
		class SpeedValue: ctrlToolboxPictureKeepAspect
        {
            idc = 105;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 13.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 2 * SIZE_M * GRID_H;
            rows = 1; 
            columns = 3;
 			strings[] = 
			{
				"\a3\3DEN\Data\Attributes\SpeedMode\limited_ca.paa",
				"\a3\3DEN\Data\Attributes\SpeedMode\normal_ca.paa",
				"\a3\3DEN\Data\Attributes\SpeedMode\full_ca.paa"
			};
			tooltips[] = 
			{
				$STR_ENH_SPEED_LIMITED,
				$STR_ENH_SPEED_NORMAL,
				$STR_ENH_SPEED_FULL
			};
            values[] = {0,1,2};
        };
		class SideTitle: Title
		{
			y = 15.5 * SIZE_M * GRID_H + 30 * pixelH;
			text = $STR_ENH_SIDE_DISPLAYNAME;
		};
		class SideValue: ctrlToolboxPictureKeepAspect
        {
            idc = 106;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 15.5 * SIZE_M * GRID_H + 30 * pixelH;
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
		class DelayTitle: Title
		{
			text = $STR_ENH_AMBIENTFLYBY_DELAY_DISPLAYNAME;
			tooltip = $STR_ENH_AMBIENTFLYBY_DELAY_TOOLTIP;
			y = 17.5 * SIZE_M * GRID_H + 35 * pixelH;
		};
		class DelayValue: ctrlXSliderH
		{
			idc = 107;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 17.5 * SIZE_M * GRID_H + 35 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 300;
			sliderRange[] = {60,3600};
			sliderStep = 5;
		};
		class DelayEdit: ctrlEdit
		{
			idc = 108;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
			y = 17.5 * SIZE_M * GRID_H + 35 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 18.5 * SIZE_M * GRID_H + 40 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_ambientFlyby_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};