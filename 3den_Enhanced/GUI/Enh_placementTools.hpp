#define POS_X_TEXT 1 * GRID_W
#define POS_X_VALUE 25 * GRID_W
#define WIDTH_TEXT 23 * GRID_W
#define WIDTH_VALUE 35 * GRID_W
#define WIDTH_HEADER 59 * GRID_W
#define COLOUR_GREY 0.231,0.254,0.236,1

#define ORIGIN_X  safeZoneX + 6 * GRID_W
#define ORIGIN_Y  safezoneY	+ 18 * GRID_H

class Enh_PlacementTools
{
	idd = -1;
	onLoad = "call Enh_fnc_placementTools_onLoad";
	onUnload = "call Enh_fnc_placementTools_onUnload";
	movingEnable = true;
	class ControlsBackground
	{ 
 		class Background: ctrlStaticBackground
		{
			x = ORIGIN_X;
			y = ORIGIN_Y + 5 * GRID_H;
			w = 64 * GRID_W;
			h = 90 * GRID_H;
		};
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_tools_placementTools;
			x = ORIGIN_X;
			y = ORIGIN_Y;
			w = 64 * GRID_W;
			h = 5 * GRID_H;
		};
		class CurrentValue: ctrlEdit
		{
			idc = 120;
			x = ORIGIN_X + 2 * GRID_W;
			y = ORIGIN_Y + 88 * GRID_H;
			w = 30 * GRID_W;
			h = 5 * GRID_H;
			canModify = false;
		};
		class Close: ctrlButtonClose
		{
			x = ORIGIN_X + 37 * GRID_W;
			y = ORIGIN_Y + 88 * GRID_H;
			w = WIDTH_TEXT;
			h = 5 * GRID_H;
		};
	};

	class Controls
	{
		class ControlGroup: ctrlControlsGroup
		{
			x = ORIGIN_X;
			y = ORIGIN_Y +  7 * GRID_H;
			w = 64 * GRID_W;
			h = 80 * GRID_H;
			class Controls 
			{
				class CircularHeader: ctrlStatic
				{
					text = $STR_ENH_placementTools_circular_header;
					x = POS_X_TEXT;
					y = 2 * GRID_W;
					w = WIDTH_HEADER;
					h = 5 * GRID_H;
					colorBackground[] = {COLOUR_GREY};
				};
				class Radius: ctrlStatic
				{
					text = $STR_ENH_placementTools_radius;
					x = POS_X_TEXT;
					y = 12 * GRID_H;
					w = WIDTH_TEXT
					h = 5 * GRID_H;
				};
				class RadiusValue: ctrlXSliderH
				{
					idc = 10;
					x = POS_X_VALUE;
					y = 12 * GRID_H;
					w = WIDTH_VALUE
					h = 5 * GRID_H;
					sliderPosition = 20;
					sliderRange[] = {0,200};
					onSliderPosChanged = "_this call Enh_fnc_placementTools_radius";
				};
				class InitialAngle: ctrlStatic
				{
					text = $STR_ENH_placementTools_initialAngle;
					x = POS_X_TEXT;
					y = 22 * GRID_H;
					w = WIDTH_TEXT
					h = 5 * GRID_H;
				};
				class InitialAngleValue: ctrlXSliderH
				{
					idc = 20;
					x = POS_X_VALUE;
					y = 22 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {0,359};
					sliderPosition = 0;
					onSliderPosChanged = "call Enh_fnc_placementTools_initialAngle";
				};
				class CentralAngle: ctrlStatic
				{
					text = $STR_ENH_placementTools_centralAngle;
					x = POS_X_TEXT;
					y = 32 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class CentralAngleValue: ctrlXSliderH
				{
					idc = 30;
					x = POS_X_VALUE;
					y = 32 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {0,360};
					sliderPosition = 360;
					onSliderPosChanged = "call Enh_fnc_placementTools_centralAngle";	
				};
				class LineHeader: ctrlStatic
				{
					text = $STR_ENH_placementTools_linePattern_header;
					x = POS_X_TEXT;
					y = 42 * GRID_H;
					W = WIDTH_HEADER;
					h = 5 * GRID_H;
					colorBackground[] = {COLOUR_GREY};
				};
				class Spacing: ctrlStatic
				{
					text = $STR_ENH_patternTool_spacing;
					x = POS_X_TEXT;
					y = 52 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class SpacingValue: ctrlXSliderH
				{
					idc = 40;
					x = POS_X_VALUE;
					y = 52 * GRID_H;
					w = WIDTH_VALUE
					h = 5 * GRID_H;
					sliderRange[] = {0,50};
					sliderPosition = 5;
				    onSliderPosChanged = "call Enh_fnc_placementTools_spacing"; 
				};
				class GridHeader: ctrlStatic
				{
					text = $STR_ENH_placementTools_grid_header;
					x = POS_X_TEXT;
					y = 62 * GRID_H;
					W = WIDTH_HEADER;
					h = 5 * GRID_H;
					colorBackground[] = {COLOUR_GREY};
				};
				class NumColumns: ctrlStatic
				{
					text = $STR_ENH_placementTools_numColumns;
					x = POS_X_TEXT;
					y = 72 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class NumColumsValue: ctrlXSliderH
				{
					idc = 50;
					x = POS_X_VALUE;
					y = 72 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {1,20};
					sliderPosition = 2;
					onSliderPosChanged = "Enh_PlacementTools_NumColumns = round (_this # 1); call Enh_fnc_placementTools_grid";
				};
				class SpaceX: ctrlStatic
				{
					text = $STR_ENH_placementTools_spacingX;
					x = POS_X_TEXT;
					y = 82 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class SpaceXValue: ctrlXSliderH
				{
					idc = 60;
					x = POS_X_VALUE;
					y = 82 * GRID_H;
					w = WIDTH_VALUE
					h = 5 * GRID_H;
					sliderRange[] = {0,50};
					sliderPosition = 5;
				    onSliderPosChanged = "Enh_PlacementTools_SpaceX = _this # 1; call Enh_fnc_placementTools_grid";
				};
				class SpaceY: ctrlStatic
				{
					text = $STR_ENH_placementTools_spacingY;
					x = POS_X_TEXT;
					y = 92 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class SpaceYValue: ctrlXSliderH
				{
					idc = 70;
					x = POS_X_VALUE;
					y = 92 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {0,50};
					sliderPosition = 5;
					onSliderPosChanged = "Enh_PlacementTools_SpaceY = _this # 1; call Enh_fnc_placementTools_grid";
				};
				class FillAreaHeader: ctrlStatic
				{
					text = $STR_ENH_placementTools_fillArea_header;
					x = POS_X_TEXT;
					y = 102 * GRID_H;
					W = WIDTH_HEADER;
					h = 5 * GRID_H;
					colorBackground[] = {COLOUR_GREY};
				};
				class A: ctrlStatic
				{
					text = $STR_ENH_placementTools_A;
					x = POS_X_TEXT;
					y = 112 * GRID_H;
					w = WIDTH_TEXT
					h = 5 * GRID_H;
				};
				class AValue: ctrlXSliderH
				{
					idc = 80;
					x = POS_X_VALUE;
					y = 112 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {1,500};
					sliderPosition = 50;
				    onSliderPosChanged = "Enh_PlacementTools_A = _this # 1; call Enh_fnc_placementTools_fillArea";
				};
				class B: ctrlStatic
				{
					text = $STR_ENH_placementTools_B;
					x = POS_X_TEXT;
					y = 122 * GRID_H;
					w = WIDTH_TEXT
					h = 5 * GRID_H;
				};
				class BValue: ctrlXSliderH
				{
					idc = 90;
					x = POS_X_VALUE;
					y = 122 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {1,500};
					sliderPosition = 50;
				    onSliderPosChanged = "Enh_PlacementTools_B = _this # 1; call Enh_fnc_placementTools_fillArea";
				};
				class GarrisonHeader: ctrlStatic
				{
					text = $STR_ENH_placementTools_garrison_header;
					x = POS_X_TEXT;
					y = 132 * GRID_H;
					W = WIDTH_HEADER;
					h = 5 * GRID_H;
					colorBackground[] = {COLOUR_GREY};
				};
				class AreaSize: ctrlStatic
				{
					text = $STR_ENH_placementTools_areaSize;
					x = POS_X_TEXT;
					y = 142 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class AreaSizeValue: ctrlXSliderH
				{
					idc = 100;
					x = POS_X_VALUE;
					y = 142 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {0,500};
					sliderPosition = 50;
				    onSliderPosChanged = "Enh_PlacementTools_AreaDia = _this # 1; call Enh_fnc_placementTools_garrison";
				};
				class Coverage: ctrlStatic
				{
					text = $STR_ENH_placementTools_coverage;
					x = POS_X_TEXT;
					y = 152 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class CoverageValue: ctrlToolbox
				{
					x = POS_X_VALUE;
					y = 152 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					rows = 1;
					columns = 4;
					strings[] = 
					{
						"10 %",
						"25 %",
						"50 %",
						"100 %"
					};
					values[] = {10,4,2,1};
				    onToolBoxSelChanged  = "params ['_ctrl','_index']; Enh_PlacementTools_Coverage = (_ctrl lbValue _index); call Enh_fnc_placementTools_garrison";
				};
				class RectangleHeader: ctrlStatic
				{
					text = "Rectangle Header";
					x = POS_X_TEXT;
					y = 162 * GRID_H;
					W = WIDTH_HEADER;
					h = 5 * GRID_H;
					colorBackground[] = {COLOUR_GREY};
				};
				class RectangleA: ctrlStatic
				{
					text = "L1";
					x = POS_X_TEXT;
					y = 172 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class RectangleAValue: ctrlXSliderH
				{
					idc = 130;
					x = POS_X_VALUE;
					y = 172 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {1,200};
					sliderPosition = 50;
				    onSliderPosChanged = "Enh_PlacementTools_RectangleA = round (_this # 1); call Enh_fnc_placementTools_rectangle";
				};
				class RectangleB: ctrlStatic
				{
					text = "L2";
					x = POS_X_TEXT;
					y = 182 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class RectangleBValue: ctrlXSliderH
				{
					idc = 140;
					x = POS_X_VALUE;
					y = 182 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {1,200};
					sliderPosition = 50;
				    onSliderPosChanged = "Enh_PlacementTools_RectangleB = round (_this # 1); call Enh_fnc_placementTools_rectangle";
				};
				class RectangleSpacing: ctrlStatic
				{
					text = $STR_ENH_patternTool_spacing;
					x = POS_X_TEXT;
					y = 192 * GRID_H;
					w = WIDTH_TEXT;
					h = 5 * GRID_H;
				};
				class RectangleSpacingValue: ctrlXSliderH
				{
					idc = 150;
					x = POS_X_VALUE;
					y = 192 * GRID_H;
					w = WIDTH_VALUE;
					h = 5 * GRID_H;
					sliderRange[] = {1,20};
					sliderPosition = 5;
				    onSliderPosChanged = "Enh_PlacementTools_RectangleSpacing = round (_this # 1); call Enh_fnc_placementTools_rectangle";
				    
				};
			};
		};
	};
};





/*class Enh_PlacementTools
{
	idd = -1;
	onLoad = "call Enh_fnc_placementTools_onLoad";
	onUnload = "call Enh_fnc_placementTools_onUnload";
	movingEnable = true;
	class ControlsBackground
	{
 		class Background: ctrlStaticBackground
		{
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.094 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.882 * safezoneH;
		};
	};
	class Controls
	{
			class Header: ctrlStaticTitle
			{
				text = $STR_ENH_tools_placementTools;
				x = 0.0209375 * safezoneW + safezoneX;
				y = 0.068 * safezoneH + safezoneY;
				w = 0.177187 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class Close: ctrlButton
			{
				idc = 1;
				text = "X";
				x = 0.198125 * safezoneW + safezoneX;
				y = 0.068 * safezoneH + safezoneY;
				w = 0.0196875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class CircularHeader: ctrlStatic
			{
				text = $STR_ENH_placementTools_circular_header;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.108 * safezoneH + safezoneY;
				w = 0.18375 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class Radius: ctrlStatic
			{
				text = $STR_ENH_placementTools_radius;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.15 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class RadiusValue: ctrlXSliderH
			{
				idc = 10;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.15 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderPosition = 20;
				sliderRange[] = {0,200};
				onSliderPosChanged = "_this call Enh_fnc_placementTools_radius";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class InitialAngle: ctrlStatic
			{
				text = $STR_ENH_placementTools_initialAngle;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.192 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class InitialAngleValue: ctrlXSliderH
			{
				idc = 20;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.192 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {0,359};
				sliderPosition = 0;
				onSliderPosChanged = "call Enh_fnc_placementTools_initialAngle";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class CentralAngle: ctrlStatic
			{
				text = $STR_ENH_placementTools_centralAngle;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.234 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class CentralAngleValue: ctrlXSliderH
			{
				idc = 30;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.234 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {0,360};
				sliderPosition = 360;
				onSliderPosChanged = "call Enh_fnc_placementTools_centralAngle";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class LineHeader: ctrlStatic
			{
				text = $STR_ENH_placementTools_linePattern_header;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.276 * safezoneH + safezoneY;
				w = 0.18375 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class Spacing: ctrlStatic
			{
				text = $STR_ENH_patternTool_spacing;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.318 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class SpacingValue: ctrlXSliderH
			{
				idc = 40;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.318 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {0,50};
				sliderPosition = 5;
				onSliderPosChanged = "call Enh_fnc_placementTools_spacing";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class GridHeader: ctrlStatic
			{
				text = $STR_ENH_placementTools_grid_header;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.36 * safezoneH + safezoneY;
				w = 0.18375 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class NumColumns: ctrlStatic
			{
				text = $STR_ENH_placementTools_numColumns;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.402 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class NumColumsValue: ctrlXSliderH
			{
				idc = 50;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.402 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {1,20};
				sliderPosition = 2;
				onSliderPosChanged = "Enh_PlacementTools_NumColumns = round (_this # 1); call Enh_fnc_placementTools_grid";
			};
			class SpaceX: ctrlStatic
			{
				text = $STR_ENH_placementTools_spacingX;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.444 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class SpaceXValue: ctrlXSliderH
			{
				idc = 60;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.444 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {0,50};
				sliderPosition = 5;
				onSliderPosChanged = "Enh_PlacementTools_SpaceX = _this # 1; call Enh_fnc_placementTools_grid";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class SpaceY: ctrlStatic
			{
				text = $STR_ENH_placementTools_spacingY;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.486 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class SpaceYValue: ctrlXSliderH
			{
				idc = 70;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.486 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {0,50};
				sliderPosition = 5;
				onSliderPosChanged = "Enh_PlacementTools_SpaceY = _this # 1; call Enh_fnc_placementTools_grid";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class FillAreaHeader: ctrlStatic
			{
				text = $STR_ENH_placementTools_fillArea_header;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.528 * safezoneH + safezoneY;
				w = 0.18375 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class A: ctrlStatic
			{
				text = $STR_ENH_placementTools_A;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.57 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class AValue: ctrlXSliderH
			{
				idc = 80;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.57 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {1,500};
				sliderPosition = 50;
				onSliderPosChanged = "Enh_PlacementTools_A = _this # 1; call Enh_fnc_placementTools_fillArea";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class B: ctrlStatic
			{
				text = $STR_ENH_placementTools_B;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.612 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class BValue: ctrlXSliderH
			{
				idc = 90;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.612 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {1,500};
				sliderPosition = 50;
				onSliderPosChanged = "Enh_PlacementTools_B = _this # 1; call Enh_fnc_placementTools_fillArea";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class GarrisonHeader: ctrlStatic
			{
				text = $STR_ENH_placementTools_garrison_header;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.654 * safezoneH + safezoneY;
				w = 0.18375 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class AreaSize: ctrlStatic
			{
				text = $STR_ENH_placementTools_areaSize;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.696 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class AreaDiaValue: ctrlXSliderH
			{
				idc = 100;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.696 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				sliderRange[] = {0,500};
				sliderPosition = 50;
				onSliderPosChanged = "Enh_PlacementTools_AreaDia = _this # 1; call Enh_fnc_placementTools_garrison";
				onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
			};
			class Coverage: ctrlStatic
			{
				text = $STR_ENH_placementTools_coverage;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.738 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class CoverageValue: ctrlToolbox
			{
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.738 * safezoneH + safezoneY;
				w = 0.105 * safezoneW;
				h = 0.028 * safezoneH;
				rows = 1;
				columns = 4;
				strings[] = 
				{
					"100 %",
					"50 %",
					"25 %",
					"10 %"
				};
				values[] = {1,2,4,10};
				onToolBoxSelChanged  = "params ['_ctrl','_index']; Enh_PlacementTools_Coverage = (_ctrl lbValue _index); call Enh_fnc_placementTools_garrison";
			};
			class CurrentValueText: ctrlStatic
			{
				text = $STR_ENH_placementTools_currentValue;
				x = 0.0275 * safezoneW + safezoneX;
				y = 0.9 * safezoneH + safezoneY;
				w = 0.0721875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class CurrentValue: ctrlStatic
			{
				idc = 120;
				x = 0.10625 * safezoneW + safezoneX;
				y = 0.9 * safezoneH + safezoneY;
				w = 0.0984375 * safezoneW;
				h = 0.028 * safezoneH;
				colorBackground[] = {0.1,0.1,0.1,1};
			};
	};
};