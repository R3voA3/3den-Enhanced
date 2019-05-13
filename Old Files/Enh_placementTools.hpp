/* #Boturo
$[
	1.063,
	["d",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[1000,"Background: Enh_Background",[1,"",["0.014375 * safezoneW + safezoneX","0.15 * safezoneH + safezoneY","0.196875 * safezoneW","0.812 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 2200;"]],
	[1001,"Header: Enh_Text",[1,"Placement Tools",["0.014375 * safezoneW + safezoneX","0.122 * safezoneH + safezoneY","0.177187 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1000;"]],
	[1005,"CircularHeader: Enh_Text",[1,"Circular Pattern Settings",["0.0209375 * safezoneW + safezoneX","0.178 * safezoneH + safezoneY","0.18375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1005;"]],
	[1008,"RadiusText: Enh_Text",[2,"Radius:",["-16.5 * GUI_GRID_W + GUI_GRID_X","2.5 * GUI_GRID_H + GUI_GRID_Y","5.5 * GUI_GRID_W","1 * GUI_GRID_H"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1010,"RadiusValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.22 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1901;","onSliderPosChanged = |_this call compile preprocessFileLineNumbers ^t.sqf^|;"]],
	[1022,"Close: Enh_Button",[2,"X",["-3.5 * GUI_GRID_W + GUI_GRID_X","-1 * GUI_GRID_H + GUI_GRID_Y","1.5 * GUI_GRID_W","1 * GUI_GRID_H"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1600;"]],
	[1023,"RotationValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.262 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1024,"CentralAngleValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.304 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]],
	[1025,"RotationText",[1,"Rotation:",["0.0209375 * safezoneW + safezoneX","0.262 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1026,"CentralAngleText",[1,"Central Angle:",["0.0209375 * safezoneW + safezoneX","0.304 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1002,"SpacingText: Enh_Text",[1,"Spacing:",["0.0209375 * safezoneW + safezoneX","0.388 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1008;"]],
	[1003,"LineHeader: Enh_Text",[1,"Line Pattern Settings",["0.0209375 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.18375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.13,0.54,0.21,1],[-1,-1,-1,-1],"","-1"],["idc = 1005;"]],
	[1004,"SpacingValue: Enh_Slider",[1,"",["0.10625 * safezoneW + safezoneX","0.388 * safezoneH + safezoneY","0.0984375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1900;"]]
]
*/

class Enh_PatternTools
{
	idd = 180000;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND

		class Background: Enh_Background
		{
			idc = 2200;
			x = 0.0143745 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.91 * safezoneH;
			colorBackground[] = {0.2,0.2,0.2,0.8};
		};
	};
		class Header: Enh_Text
		{
			idc = 1000;
			text = "Placement Tools"; //--- ToDo: Localize;
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.177187 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.13,0.54,0.21,1};
		};
		class GridHeader: Enh_Text
		{
			idc = 1001;
			text = "Grid Settings"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.13,0.54,0.21,1};
		};
		class CircularPatternHeader: Enh_Text
		{
			idc = 1002;
			text = "Circular Pattern Settings"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.164 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.13,0.54,0.21,1};
		};
		class FillAreaHeader: Enh_Text
		{
			idc = 1004;
			text = "Fill Area Settings"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.13,0.54,0.21,1};
		};
		class LineHeader: Enh_Text
		{
			idc = 1005;
			text = "Line Pattern Settings"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.13,0.54,0.21,1};
		};
		class RscSlider_1900: Enh_Slider
		{
			idc = 1900;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.304 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpaceText: Enh_Text
		{
			idc = 1006;
			text = "Space:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.108 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RadiusText: Enh_Text
		{
			idc = 1008;
			text = "Radius:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.206 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AreaAText: Enh_Text
		{
			idc = 1003;
			text = "A:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.304 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RscSlider_1901: Enh_Slider//CIRCLE
		{
			idc = 1901;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.206 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			onSliderPosChanged = "execVM 't.sqf'";		};
		class RscSlider_1902: Enh_Slider
		{
			idc = 1902;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.108 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AreaBText: Enh_Text
		{
			idc = 1009;
			text = "B:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RscSlider_1903: Enh_Slider
		{
			idc = 1903;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumberRowsText: Enh_Text
		{
			idc = 1007;
			text = "#Rows:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RscSlider_1904: Enh_Slider
		{
			idc = 1904;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumberColumnsText: Enh_Text
		{
			idc = 1010;
			text = "#Columns:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RscSlider_1905: Enh_Slider
		{
			idc = 1905;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpaceXText: Enh_Text
		{
			idc = 1011;
			text = "Space X:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpaceYText: Enh_Text
		{
			idc = 1012;
			text = "Space Y:"; //--- ToDo: Localize;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RscSlider_1906: Enh_Slider
		{
			idc = 1906;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RscSlider_1907: Enh_Slider
		{
			idc = 1907;
			x = 0.10625 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Close: Enh_Button
		{
			idc = 1600;
			text = "X"; //--- ToDo: Localize;
			x = 0.191563 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0.13,0.54,0.21,1};
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

};