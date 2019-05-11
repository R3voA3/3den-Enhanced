class Enh_PlacementTools
{
	idd = -1;
	onLoad = "call Enh_fnc_placementTools_onLoad";
	onUnload = "delete3DENEntities [Enh_PlacementTools_AreaTrigger,Enh_PlacementTools_GarrisonTrigger]; Enh_PlacementTools_AreaTrigger = nil; Enh_PlacementTools_GarrisonTrigger = nil"
	movingEnable = true;
	class ControlsBackground
	{
 		class Background: Enh_Background
		{
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.812 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = $STR_ENH_tools_placementTools;
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.177187 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Close: Enh_Button
		{
			idc = 1;
			text = "X";
			x = 0.191563 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CircularHeader: Enh_Text
		{
			text = $STR_ENH_placementTools_circular_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Radius: Enh_Text
		{
			text = $STR_ENH_placementTools_radius;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RadiusValue: Enh_Slider
		{
			idc = 10;		
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderPosition = 20;
			sliderRange[] = {0,200};
			onSliderPosChanged = "_this call Enh_fnc_placementTools_radius";
		};
		class InitialAngle: Enh_Text
		{
			text = $STR_ENH_placementTools_initialAngle;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class InitialAngleValue: Enh_Slider
		{
			idc = 20;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,359};
			sliderPosition = 0;
			onSliderPosChanged = "call Enh_fnc_placementTools_initialAngle";
		};
		class CentralAngle: Enh_Text
		{
			text = $STR_ENH_placementTools_centralAngle;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.304 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CentralAngleValue: Enh_Slider
		{
			idc = 30;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.304 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,360};
			sliderPosition = 360;
			onSliderPosChanged = "call Enh_fnc_placementTools_centralAngle";
		};
		class LineHeader: Enh_Text
		{
			text = $STR_ENH_placementTools_linePattern_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Spacing: Enh_Text
		{
			text = $STR_ENH_patternTool_spacing;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpacingValue: Enh_Slider
		{
			idc = 40;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,50};
			sliderPosition = 5;
			onSliderPosChanged = "call Enh_fnc_placementTools_spacing";
		};
		class GridHeader: Enh_Text
		{
			text = $STR_ENH_placementTools_grid_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class NumColumns: Enh_Text
		{
			text = $STR_ENH_placementTools_numColumns;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumColumsValue: Enh_Slider
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
		class SpaceX: Enh_Text
		{
			idc = 60;
			text = $STR_ENH_placementTools_spacingX;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpaceXValue: Enh_Slider
		{
			idc = 70;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,50};
			sliderPosition = 5;
			onSliderPosChanged = "Enh_PlacementTools_SpaceX = _this # 1; call Enh_fnc_placementTools_grid";
		};
		class SpaceY: Enh_Text
		{
			text = $STR_ENH_placementTools_spacingY;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpaceYValue: Enh_Slider
		{
			idc = 80;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,50};
			sliderPosition = 5;
			onSliderPosChanged = "Enh_PlacementTools_SpaceY = _this # 1; call Enh_fnc_placementTools_grid";
		};
		class FillAreaHeader: Enh_Text
		{
			text = $STR_ENH_placementTools_fillArea_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class A: Enh_Text
		{
			text = $STR_ENH_placementTools_A;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AValue: Enh_Slider
		{
			idc = 90;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {1,500};
			sliderPosition = 50;
			onSliderPosChanged = "Enh_PlacementTools_A = _this # 1; call Enh_fnc_placementTools_fillArea";
		};
		class B: Enh_Text
		{
			text = $STR_ENH_placementTools_B;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.682 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class BValue: Enh_Slider
		{
			idc = 100;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.682 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {1,500};
			sliderPosition = 50;
			onSliderPosChanged = "Enh_PlacementTools_B = _this # 1; call Enh_fnc_placementTools_fillArea";
		};
		class GarrisonHeader: Enh_Text
		{
			text = $STR_ENH_placementTools_garrison_header;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.724 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class AreaSize: Enh_Text
		{
			text = $STR_ENH_placementTools_areaSize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AreaSizeValue: Enh_Slider
		{
			idc = 110;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,500};
			sliderPosition = 50;
			onSliderPosChanged = "Enh_PlacementTools_AreaDia = _this # 1; call Enh_fnc_placementTools_garrison";
		};
		class Coverage: Enh_Text
		{
			text = $STR_ENH_placementTools_coverage;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CoverageValue: Enh_Slider
		{
			idc = 120;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {1,10};
			sliderPosition = 2;
			onSliderPosChanged = "Enh_PlacementTools_Coverage = round (_this # 1); call Enh_fnc_placementTools_garrison";
		}; 
		class CurrentValueText: Enh_Text
		{
			text = $STR_ENH_placementTools_currentValue;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.858 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CurrentValue: Enh_Text
		{
			idc = 130;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.858 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
	};
};

/* #Tecofo
$[
	1.063,
	["d",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[1000,"Background: Enh_Background",[1,"",["0.014375 * safezoneW + safezoneX","0.15 * safezoneH + safezoneY","0.196875 * safezoneW","0.812 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 2200;"]],
	[1001,"Header: Enh_Text",[1,"Placement Tools",["0.014375 * safezoneW + safezoneX","0.122 * safezoneH + safezoneY","0.177187 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1000;"]],
	[1005,"CircularHeader: Enh_Text",[1,"Circular Pattern Settings",["0.0209375 * safezoneW + safezoneX","0.178 * safezoneH + safezoneY","0.18375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1005;"]],
	[1008,"RadiusText: Enh_Text",[1,"Radius:",["0.0209375 * safezoneW + safezoneX","0.22 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1010,"RadiusValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.22 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1901;","onSliderPosChanged = |_this call compile preprocessFileLineNumbers ^t.sqf^|;"]],
	[1022,"Close: Enh_Button",[1,"X",["0.191563 * safezoneW + safezoneX","0.122 * safezoneH + safezoneY","0.0196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1600;"]],
	[1023,"RotationValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.262 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1024,"CentralAngleValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.304 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1025,"RotationText",[1,"Rotation:",["0.0209375 * safezoneW + safezoneX","0.262 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1026,"CentralAngleText",[1,"Central Angle:",["0.0209375 * safezoneW + safezoneX","0.304 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1002,"SpacingText: Enh_Text",[1,"Spacing:",["0.0209375 * safezoneW + safezoneX","0.388 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1003,"LineHeader: Enh_Text",[1,"Line Pattern Settings",["0.0209375 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.18375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1005;"]],
	[1004,"SpacingValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.388 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1006,"GridHeader",[1,"Grid Pattern Settings",["0.0209375 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.18375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1005;"]],
	[1009,"NumColumns",[1,"#Columns:",["0.0209375 * safezoneW + safezoneX","0.472 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1011,"NumColumsValue",[1,"",["0.10625 * safezoneW + safezoneX","0.472 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1013,"SpaceX",[1,"Space X:",["0.0209375 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1014,"SpaceY",[1,"Space Y:",["0.0209375 * safezoneW + safezoneX","0.556 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1015,"SpaceXValue",[1,"",["0.10625 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1016,"SpaceYValue",[1,"",["0.10625 * safezoneW + safezoneX","0.556 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1017,"FillAreaHeader",[1,"Fill Area Settings",["0.0209375 * safezoneW + safezoneX","0.598 * safezoneH + safezoneY","0.18375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1005;"]],
	[1018,"A",[1,"A:",["0.0209375 * safezoneW + safezoneX","0.64 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1019,"",[1,"B:",["0.0209375 * safezoneW + safezoneX","0.682 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1020,"AValue",[1,"",["0.10625 * safezoneW + safezoneX","0.64 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1021,"BValue",[1,"",["0.10625 * safezoneW + safezoneX","0.682 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1007,"GarrisonHeader",[1,"Garrison Settings",["0.0209375 * safezoneW + safezoneX","0.724 * safezoneH + safezoneY","0.18375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1005;"]],
	[1012,"AreaSize",[1,"Area Size:",["0.0209375 * safezoneW + safezoneX","0.766 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1027,"Coverage",[1,"Coverage:",["0.0209375 * safezoneW + safezoneX","0.808 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1028,"AreaSizeValue",[1,"",["0.10625 * safezoneW + safezoneX","0.766 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1029,"CoverageValue",[1,"",["0.10625 * safezoneW + safezoneX","0.808 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]]
]
*/