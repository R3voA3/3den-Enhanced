#define POS_X_TEXT 1 * GRID_W
#define POS_X_VALUE 25 * GRID_W
#define WIDTH_TEXT 23 * GRID_W
#define WIDTH_VALUE 36 * GRID_W
#define WIDTH_HEADER 60 * GRID_W

#define ORIGIN_X  safeZoneX + 6 * GRID_W
#define ORIGIN_Y  safezoneY	+ 18 * GRID_H

class Enh_PlacementTools
{
	idd = -1;
	onLoad = "_this call Enh_fnc_placementTools_onLoad";
	onUnload = "_this call Enh_fnc_placementTools_onUnload";
	movingEnable = true;
	class ControlsBackground
	{ 
 		class Background: ctrlStaticBackground
		{
			x = ORIGIN_X;
			y = ORIGIN_Y + CTRL_DEFAULT_H;
			w = 64 * GRID_W;
			h = 94 * GRID_H;
		};
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_tools_placementTools;
			x = ORIGIN_X;
			y = ORIGIN_Y;
			w = 64 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class FineControlStep: ctrlToolbox
		{
			idc = 250;
			x = ORIGIN_X + 1 * GRID_W;
			y = ORIGIN_Y + 87 * GRID_H;
			w = 62 * GRID_W;
			h = CTRL_DEFAULT_H;
			rows = 1;
			columns = 7;
			strings[] = 
			{
				".0001",
				".001",
				".01",
				".1",
				"1",
				"10",
				"100"
			};
			tooltips[] =
			{
				"Sets the size of the increment when clicking the arrows next to the sliders.",
				"Sets the size of the increment when clicking the arrows next to the sliders.",
				"Sets the size of the increment when clicking the arrows next to the sliders.",
				"Sets the size of the increment when clicking the arrows next to the sliders.",
				"Sets the size of the increment when clicking the arrows next to the sliders.",
				"Sets the size of the increment when clicking the arrows next to the sliders.",
				"Sets the size of the increment when clicking the arrows next to the sliders."
			};
			values[] = {0.0001,0.001,0.01,0.1,1,10,100};
			onToolBoxSelChanged  = "_this call Enh_fnc_placementTools_onToolBoxSelChanged";
		};
		class CurrentValue: ctrlEdit
		{
			idc = 120;
			x = ORIGIN_X + 1 * GRID_W;
			y = ORIGIN_Y + 93 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			canModify = false;
		};
 		class SelectCenter: ctrlButtonPictureKeepAspect
		{
			text = "\A3\ui_f\data\igui\cfg\weaponcursors\rocket_gs.paa";
			tooltip = "Reset Center";
			x = ORIGIN_X + 32 * GRID_W;
			y = ORIGIN_Y + 93 * GRID_H;
			w = CTRL_DEFAULT_H;
			h = CTRL_DEFAULT_H;
			onButtonClick = "Enh_PlacementTools_Center = screenToWorld [0.5,0.5]";
		};
		class Close: ctrlButtonClose
		{
			x = ORIGIN_X + 40 * GRID_W;
			y = ORIGIN_Y + 93 * GRID_H;
			w = WIDTH_TEXT;
			h = CTRL_DEFAULT_H;
		};
	};
	class Controls
	{
		class ControlGroup: ctrlControlsGroup
		{
			x = ORIGIN_X;
			y = ORIGIN_Y +  6 * GRID_H;
			w = 64 * GRID_W;
			h = 80 * GRID_H;
			class Controls 
			{
				class CircularHeader: ctrlStaticFooter
				{
					text = $STR_ENH_placementTools_circular_header;
					x = POS_X_TEXT;
					y = 1 * GRID_W;
					w = WIDTH_HEADER;
					h = CTRL_DEFAULT_H;
				};
				class Radius: ctrlStatic
				{
					text = $STR_ENH_placementTools_radius;
					x = POS_X_TEXT;
					y = 7 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class RadiusValue: ctrlXSliderH
				{
					idc = 10;
					x = POS_X_VALUE;
					y = 7 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {0,200};
					onSliderPosChanged = "_this call Enh_fnc_placementTools_radius";
				};
				class InitialAngle: ctrlStatic
				{
					text = $STR_ENH_placementTools_initialAngle;
					x = POS_X_TEXT;
					y = 13 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class InitialAngleValue: ctrlXSliderH
				{
					idc = 20;
					x = POS_X_VALUE;
					y = 13 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {0,359};
					onSliderPosChanged = "call Enh_fnc_placementTools_initialAngle";
				};
				class CentralAngle: ctrlStatic
				{
					text = $STR_ENH_placementTools_centralAngle;
					x = POS_X_TEXT;
					y = 19 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class CentralAngleValue: ctrlXSliderH
				{
					idc = 30;
					x = POS_X_VALUE;
					y = 19 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {0,360};
					onSliderPosChanged = "call Enh_fnc_placementTools_centralAngle";	
				};
				class LineHeader: ctrlStaticFooter
				{
					text = $STR_ENH_placementTools_linePattern_header;
					x = POS_X_TEXT;
					y = 25 * GRID_H;
					W = WIDTH_HEADER;
					h = CTRL_DEFAULT_H;
				};
				class Spacing: ctrlStatic
				{
					text = $STR_ENH_placementTools_spacing;
					x = POS_X_TEXT;
					y = 31 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class SpacingValue: ctrlXSliderH
				{
					idc = 40;
					x = POS_X_VALUE;
					y = 31 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {0,50};
				    onSliderPosChanged = "call Enh_fnc_placementTools_spacing"; 
				};
				class GridHeader: ctrlStaticFooter
				{
					text = $STR_ENH_placementTools_grid_header;
					x = POS_X_TEXT;
					y = 37 * GRID_H;
					W = WIDTH_HEADER;
					h = CTRL_DEFAULT_H;
				};
				class NumColumns: ctrlStatic
				{
					text = $STR_ENH_placementTools_numColumns;
					x = POS_X_TEXT;
					y = 43 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class NumColumsValue: ctrlXSliderH
				{
					idc = 50;
					x = POS_X_VALUE;
					y = 43 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {1,20};
					sliderStep = 1;
					onSliderPosChanged = "Enh_PlacementTools_NumColumns = _this # 1; call Enh_fnc_placementTools_grid";
				};
				class SpaceX: ctrlStatic
				{
					text = $STR_ENH_placementTools_spacingX;
					x = POS_X_TEXT;
					y = 49 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class SpaceXValue: ctrlXSliderH
				{
					idc = 60;
					x = POS_X_VALUE;
					y = 49 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {0,50};
				    onSliderPosChanged = "Enh_PlacementTools_SpaceX = _this # 1; call Enh_fnc_placementTools_grid";
				};
				class SpaceY: ctrlStatic
				{
					text = $STR_ENH_placementTools_spacingY;
					x = POS_X_TEXT;
					y = 55 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class SpaceYValue: ctrlXSliderH
				{
					idc = 70;
					x = POS_X_VALUE;
					y = 55 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {0,50};
					onSliderPosChanged = "Enh_PlacementTools_SpaceY = _this # 1; call Enh_fnc_placementTools_grid";
				};
				class FillAreaHeader: ctrlStaticFooter
				{
					text = $STR_ENH_placementTools_fillArea_header;
					x = POS_X_TEXT;
					y = 61 * GRID_H;
					W = WIDTH_HEADER;
					h = CTRL_DEFAULT_H;
				};
				class A: ctrlStatic
				{
					text = $STR_ENH_placementTools_A;
					x = POS_X_TEXT;
					y = 67 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class AValue: ctrlXSliderH
				{
					idc = 80;
					x = POS_X_VALUE;
					y = 67 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {1,500};
					sliderStep = 1;
				    onSliderPosChanged = "Enh_PlacementTools_A = _this # 1; call Enh_fnc_placementTools_fillArea";
				};
				class B: ctrlStatic
				{
					text = $STR_ENH_placementTools_B;
					x = POS_X_TEXT;
					y = 73 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class BValue: ctrlXSliderH
				{
					idc = 90;
					x = POS_X_VALUE;
					y = 73 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {1,500};
					sliderStep = 1;
				    onSliderPosChanged = "Enh_PlacementTools_B = _this # 1; call Enh_fnc_placementTools_fillArea";
				};
				class GarrisonHeader: ctrlStaticFooter
				{
					text = $STR_ENH_placementTools_garrison_header;
					x = POS_X_TEXT;
					y = 79 * GRID_H;
					W = WIDTH_HEADER;
					h = CTRL_DEFAULT_H;
				};
				class AreaSize: ctrlStatic
				{
					text = $STR_ENH_placementTools_radius
					x = POS_X_TEXT;
					y = 85 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class AreaSizeValue: ctrlXSliderH
				{
					idc = 100;
					x = POS_X_VALUE;
					y = 85 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					sliderRange[] = {0,500};
				    onSliderPosChanged = "Enh_PlacementTools_AreaDia = _this # 1; call Enh_fnc_placementTools_garrison";
				};
				class Coverage: ctrlStatic
				{
					text = $STR_ENH_placementTools_coverage;
					x = POS_X_TEXT;
					y = 91 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class CoverageValue: ctrlToolbox
				{
					x = POS_X_VALUE;
					y = 91 * GRID_H;
					w = WIDTH_VALUE;
					h = CTRL_DEFAULT_H;
					rows = 1;
					columns = 4;
					strings[] = 
					{
						$STR_ENH_placementTools_10percent,
						$STR_ENH_placementTools_25percent,
						$STR_ENH_placementTools_50percent,
						$STR_ENH_placementTools_100percent
					};
					values[] = {10,4,2,1};
				    onToolBoxSelChanged  = "params ['_ctrl','_index']; Enh_PlacementTools_Coverage = (_ctrl lbValue _index); call Enh_fnc_placementTools_garrison";
				};
				class Orientation: ctrlStatic
				{
					text = "Orientation";
					x = POS_X_TEXT;
					y = 103 * GRID_H;
					w = WIDTH_TEXT;
					h = CTRL_DEFAULT_H;
				};
				class OrientNorth: ctrlButton
				{
					text = "N";
					x = POS_X_VALUE + 8 * GRID_W;
					y = 97 * GRID_H;
					w = CTRL_DEFAULT_H;
					h = CTRL_DEFAULT_H;
					onButtonClick = "0 call Enh_fnc_setOrientation";
				};
				class OrientEast: ctrlButton
				{
					text = "E";
					x = POS_X_VALUE + 16 * GRID_W;
					y = 103 * GRID_H;
					w = CTRL_DEFAULT_H;
					h = CTRL_DEFAULT_H;
					onButtonClick = "90 call Enh_fnc_setOrientation";
				};
				class OrientSouth: ctrlButton
				{
					text = "S";
					x = POS_X_VALUE + 8 * GRID_W;
					y = 109 * GRID_H;
					w = CTRL_DEFAULT_H;
					h = CTRL_DEFAULT_H;
					onButtonClick = "180 call Enh_fnc_setOrientation";
				};
				class OrientWest: ctrlButton
				{
					text = "W";
					x = POS_X_VALUE;
					y = 103 * GRID_H;
					w = CTRL_DEFAULT_H;
					h = CTRL_DEFAULT_H;
					onButtonClick = "270 call Enh_fnc_setOrientation";
				};
	 			class OrientRandom: ctrlButtonPictureKeepAspect
				{
					text = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
					x = POS_X_VALUE + 24 * GRID_W;
					y = 97 * GRID_H;
					w = CTRL_DEFAULT_H;
					h = CTRL_DEFAULT_H;
					onButtonClick = "call Enh_fnc_setRandomOrientation";
				};
				class ReverseOrientation: ctrlButtonPictureKeepAspect
				{
					text = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
					x = POS_X_VALUE + 24 * GRID_W;
					y = 109 * GRID_H;
					w = CTRL_DEFAULT_H;
					h = CTRL_DEFAULT_H;
					onButtonClick = "call Enh_fnc_reverseOrientation";
				};
			};
		};
	};
};