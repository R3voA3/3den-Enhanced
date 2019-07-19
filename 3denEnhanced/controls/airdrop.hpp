class Enh_Airdrop: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_airdrop_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_airdrop_onAttributeSave";
	h = 12 * SIZE_M * GRID_H + 30 * pixelH;
	class Controls: Controls
	{
		class ClassesTitle: Title
		{
			text = $STR_ENH_airdrop_classes_displayName;
			tooltip = $STR_ENH_airdrop_classes_tooltip;
		};
		class ClassesValue: ctrlEditMulti
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 5 * SIZE_M * GRID_H;
		};
		class CenterTitle: Title
		{
			text = $STR_ENH_airdrop_center_displayName;
			tooltip = $STR_ENH_airdrop_center_tooltip;
			y = 5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class CenterValue: ctrlEdit
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ConditionTitle: Title
		{
			y = 6 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_airdrop_condition_displayName;
			tooltip = $STR_ENH_airdrop_condition_tooltip;
		};
		class ConditionValue: CenterValue
		{
			idc = 102;
			y = 6 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class AltitudeTitle: Title
		{
			y = 7 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_altitude_displayName;
		};
		class AltitudeValue: ctrlXSliderH
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7 * SIZE_M * GRID_H + 15 * pixelH;
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
			y = 7 * SIZE_M * GRID_H + 15 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class RadiusTitle: Title
		{
			y = 8 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_airdrop_radius_displayName;
			tooltip = $STR_ENH_airdrop_radius_tooltip;
		};
		class RadiusValue: ctrlXSliderH
		{
			idc = 105;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 8 * SIZE_M * GRID_H + 20 * pixelH;
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
			y = 8 * SIZE_M * GRID_H + 20 * pixelH;
			w = EDIT_W_WIDE * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class SideTitle: Title
		{
			y = 9 * SIZE_M * GRID_H + 25 * pixelH;
			text = $STR_ENH_side_displayName;
		};
		class SideValue: ctrlToolboxPictureKeepAspect
        {
            idc = 107;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 9 * SIZE_M * GRID_H + 25 * pixelH;
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
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			y = 11 * SIZE_M * GRID_H + 30 * pixelH;
			onButtonDown  = "_this call Enh_fnc_airdrop_onButtonDown";
			text = $STR_ENH_resetAndDisable;
		};
	};
};