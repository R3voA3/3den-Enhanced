class Enh_ModuleInformation
{
	idd = 130000;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_moduleInformation";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_Background
		{
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.206 * safezoneH + safezoneY;
			w = 0.354375 * safezoneW;
			h = 0.6165 * safezoneH;
		};
	};
	class Controls
	{
		class Headline: Enh_Text
		{
			text = $STR_ENH_moduleInformation_header;
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.354375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class DescriptionText: Enh_Text
		{
			text = $STR_ENH_moduleInformation_description;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DescriptionValue: Enh_StructuredText
		{
			idc = 1400;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.168 * safezoneH;
		};
		class PositionText: Enh_Text
		{
			text = $STR_ENH_moduleInformation_position;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.542 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PositionValue: Enh_StructuredText
		{
			idc = 1401;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DuplicateText: Enh_Text
		{
			text = $STR_ENH_moduleInformation_duplicate;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DuplicateValue: Enh_StructuredText
		{
			idc = 1402;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DirectionText: Enh_Text
		{
			text = $STR_ENH_moduleInformation_direction;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DirectionValue: Enh_StructuredText
		{
			idc = 1403;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SyncText : Enh_Text
		{
			text = $STR_ENH_moduleInformation_sync;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.71 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SyncValue: Enh_StructuredText
		{
			idc = 1404;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Close: Enh_Button
		{
			idc = 1;
			text = $STR_ENH_moduleInformation_close;
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.794 * safezoneH + safezoneY;
			w = 0.354375 * safezoneW;
			h = 0.028 * safezoneH;
			default = 1;
		};
	};
};

/* #Fyloga
$[
	1.063,
	["test",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[2200,"Background",[1,"",["0.36875 * safezoneW + safezoneX","0.234 * safezoneH + safezoneY","0.23625 * safezoneW","0.588 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"DescriptionValue",[1,"",["0.381875 * safezoneW + safezoneX","0.29 * safezoneH + safezoneY","0.21 * safezoneW","0.168 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"DescriptionText",[1,"Description:",["0.381875 * safezoneW + safezoneX","0.262 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"PositionValue",[1,"",["0.381875 * safezoneW + safezoneX","0.598 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"PositionText",[1,"Position:",["0.381875 * safezoneW + safezoneX","0.57 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"DuplicateText",[1,"Duplicate:",["0.381875 * safezoneW + safezoneX","0.654 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1402,"DuplicateValue",[1,"",["0.381875 * safezoneW + safezoneX","0.682 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"DirectionText",[1,"Direction:",["0.381875 * safezoneW + safezoneX","0.486 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1403,"DirectionValue",[1,"",["0.381875 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1004,"SyncText ",[1,"Can be synced with:",["0.381875 * safezoneW + safezoneX","0.738 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1404,"SyncValue",[1,"",["0.381875 * safezoneW + safezoneX","0.766 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1005,"Headline",[1,"Module Information",["0.36875 * safezoneW + safezoneX","0.206 * safezoneH + safezoneY","0.23625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"Close",[1,"Close",["0.36875 * safezoneW + safezoneX","0.822 * safezoneH + safezoneY","0.23625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/