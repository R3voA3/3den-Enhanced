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
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.812 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_tools_placementTools;
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.177187 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Close: ctrlButton
		{
			idc = 1;
			text = "X";
			x = 0.191563 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class CircularHeader: ctrlStatic
		{
			text = $STR_ENH_placementTools_circular_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Radius: ctrlStatic
		{
			text = $STR_ENH_placementTools_radius;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RadiusValue: ctrlXSliderH
		{
			idc = 10;	
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderPosition = 20;
			sliderRange[] = {0,200};
			onSliderPosChanged = "_this call Enh_fnc_placementTools_radius";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class InitialAngle: ctrlStatic
		{
			text = $STR_ENH_placementTools_initialAngle;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class InitialAngleValue: ctrlXSliderH
		{
			idc = 20;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,359};
			sliderPosition = 0;
			onSliderPosChanged = "call Enh_fnc_placementTools_initialAngle";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class CentralAngle: ctrlStatic
		{
			text = $STR_ENH_placementTools_centralAngle;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.304 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CentralAngleValue: ctrlXSliderH
		{
			idc = 30;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.304 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,360};
			sliderPosition = 360;
			onSliderPosChanged = "call Enh_fnc_placementTools_centralAngle";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class LineHeader: ctrlStatic
		{
			text = $STR_ENH_placementTools_linePattern_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Spacing: ctrlStatic
		{
			text = $STR_ENH_patternTool_spacing;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpacingValue: ctrlXSliderH
		{
			idc = 40;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,50};
			sliderPosition = 5;
			onSliderPosChanged = "call Enh_fnc_placementTools_spacing";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class GridHeader: ctrlStatic
		{
			text = $STR_ENH_placementTools_grid_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class NumColumns: ctrlStatic
		{
			text = $STR_ENH_placementTools_numColumns;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumColumsValue: ctrlXSliderH
		{
			idc = 50;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {1,20};
			sliderPosition = 2;
			onSliderPosChanged = "Enh_PlacementTools_NumColumns = round (_this # 1); call Enh_fnc_placementTools_grid";
		};
		class SpaceX: ctrlStatic
		{
			text = $STR_ENH_placementTools_spacingX;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpaceXValue: ctrlXSliderH
		{
			idc = 60;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,50};
			sliderPosition = 5;
			onSliderPosChanged = "Enh_PlacementTools_SpaceX = _this # 1; call Enh_fnc_placementTools_grid";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class SpaceY: ctrlStatic
		{
			text = $STR_ENH_placementTools_spacingY;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpaceYValue: ctrlXSliderH
		{
			idc = 70;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,50};
			sliderPosition = 5;
			onSliderPosChanged = "Enh_PlacementTools_SpaceY = _this # 1; call Enh_fnc_placementTools_grid";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class FillAreaHeader: ctrlStatic
		{
			text = $STR_ENH_placementTools_fillArea_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class A: ctrlStatic
		{
			text = $STR_ENH_placementTools_A;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AValue: ctrlXSliderH
		{
			idc = 80;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {1,500};
			sliderPosition = 50;
			onSliderPosChanged = "Enh_PlacementTools_A = _this # 1; call Enh_fnc_placementTools_fillArea";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class B: ctrlStatic
		{
			text = $STR_ENH_placementTools_B;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.682 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class BValue: ctrlXSliderH
		{
			idc = 90;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.682 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {1,500};
			sliderPosition = 50;
			onSliderPosChanged = "Enh_PlacementTools_B = _this # 1; call Enh_fnc_placementTools_fillArea";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class GarrisonHeader: ctrlStatic
		{
			text = $STR_ENH_placementTools_garrison_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.724 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class AreaSize: ctrlStatic
		{
			text = $STR_ENH_placementTools_areaSize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AreaDiaValue: ctrlXSliderH
		{
			idc = 100;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,500};
			sliderPosition = 50;
			onSliderPosChanged = "Enh_PlacementTools_AreaDia = _this # 1; call Enh_fnc_placementTools_garrison";
			onMouseZChanged = "_this call Enh_fnc_placementTools_slowScrolling";
		};
		class Coverage: ctrlStatic
		{
			text = $STR_ENH_placementTools_coverage;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CoverageValue: ctrlXSliderH
		{
			idc = 110;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {1,10};
			sliderPosition = 2;
			onSliderPosChanged = "Enh_PlacementTools_Coverage = round (_this # 1); call Enh_fnc_placementTools_garrison";
		}; 
		class CurrentValueText: ctrlStatic
		{
			text = $STR_ENH_placementTools_currentValue;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.858 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CurrentValue: ctrlStatic
		{
			idc = 120;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.858 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};
};