class Enh_GridPattern
{
	idd = 160000;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_gridPattern_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_IGUIBack
		{
			x = 0.36875 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.2625 * safezoneW;
			h = 0.252 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_RscText
		{
			text = $STR_ENH_gridPattern_header;
			x = 0.36875 * safezoneW + safezoneX;
			y = 0.29 * safezoneH + safezoneY;
			w = 0.2625 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Close: Enh_RscButton
		{
			idc = 1;
			text = $STR_ENH_gridPattern_close;
			x = 0.36875 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Ok: Enh_RscButton
		{
			text = $STR_ENH_gridPattern_ok;
			x = 0.565625 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_gridPattern";
		};
		class NumRowsText: Enh_RscText
		{
			text = $STR_ENH_gridPattern_numRows;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumColumnsText: Enh_RscText
		{
			text = $STR_ENH_gridPattern_numColumns;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.402 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpacingXText: Enh_RscText
		{
			text = $STR_ENH_gridPattern_spacingX;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumRowsValue: Enh_RscEdit
		{
			idc = 1400;
			x = 0.513125 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumColumnsValue: Enh_RscEdit
		{
			idc = 1401;
			x = 0.513125 * safezoneW + safezoneX;
			y = 0.402 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpacingXValue: Enh_RscEdit
		{
			idc = 1402;
			x = 0.513125 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpacingYText: Enh_RscText
		{
			text = $STR_ENH_gridPattern_spacingY;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SpacingYValue: Enh_RscEdit
		{
			idc = 1403;
			x = 0.513125 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};

/* #Piduxa
$[
	1.063,
	["sdf",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[2200,"Background",[1,"",["0.36875 * safezoneW + safezoneX","0.318 * safezoneH + safezoneY","0.2625 * safezoneW","0.252 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"Header",[1,"Grid Pattern",["0.36875 * safezoneW + safezoneX","0.29 * safezoneH + safezoneY","0.2625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"Close",[1,"Close",["0.36875 * safezoneW + safezoneX","0.57 * safezoneH + safezoneY","0.065625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"Ok",[1,"Ok",["0.565625 * safezoneW + safezoneX","0.57 * safezoneH + safezoneY","0.065625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"NumRowsText",[1,"Number of Rows",["0.381875 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"NumColumnsText",[1,"Number of Columns",["0.381875 * safezoneW + safezoneX","0.402 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"SpacingXText",[1,"Spacing X",["0.381875 * safezoneW + safezoneX","0.458 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"NumRowsValue",[1,"",["0.513125 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"NumColumnsValue",[1,"",["0.513125 * safezoneW + safezoneX","0.402 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1402,"SpacingXValue",[1,"",["0.513125 * safezoneW + safezoneX","0.458 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1004,"SpacingYText",[1,"Spacing Y",["0.381875 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1403,"SpacingYValue",[1,"",["0.513125 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1005,"",[1,"#5566 / #5456",["0.460625 * safezoneW + safezoneX","0.57 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/