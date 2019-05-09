class Enh_BatchReplace
{
	idd = 150000;
	movingEnable = true;
	onLoad = "((_this # 0) displayCtrl 1400) ctrlSetText (profileNameSpace getVariable ['Enh_batchReplace_lastUsed','']); ctrlSetFocus ((_this # 0) displayCtrl 1400)";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_IGUIBack
		{
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.36 * safezoneH + safezoneY;
			w = 0.315 * safezoneW;
			h = 0.266 * safezoneH;
		};
	};
	class Controls
	{
		class Close: Enh_RscButton
		{
			idc = 1;
			text = $STR_ENH_batchReplace_close;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.13125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "profileNameSpace getVariable ['Enh_batchReplace_lastUsed',ctrlText ((findDisplay 150000) displayCtrl 1400)]";
		};
		class Replace: Enh_RscButton
		{
			text = $STR_ENH_batchReplace_replace;
			x = 0.52625 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.13155 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_batchreplace";
		};
		class ReplaceWithValue: Enh_RscEdit
		{
			idc = 1400;
			tooltip = $STR_ENH_batchReplace_replaceWith_tooltip;
			x = 0.447499 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.112 * safezoneH;
		};
		class ReplaceWithText: Enh_RscText
		{
			text = $STR_ENH_batchReplace_replaceWith;
			tooltip = $STR_ENH_batchReplace_replaceWith_tooltip;
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Header: Enh_RscText
		{
			text = $STR_ENH_batchReplace_header;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.332 * safezoneH + safezoneY;
			w = 0.315 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Description: Enh_RscStructuredText
		{
			text = $STR_ENH_batchReplace_description;
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.28875 * safezoneW;
			h = 0.07 * safezoneH;
		};
	};
};

/* #Kolamu
$[
	1.063,
	["test",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[1600,"Close",[1,"Close",["0.3425 * safezoneW + safezoneX","0.542 * safezoneH + safezoneY","0.13125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"Replace",[1,"Replace",["0.52625 * safezoneW + safezoneX","0.542 * safezoneH + safezoneY","0.13125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"ReplaceWithValue",[1,"Classname_1, Classname_2, Classname_n",["0.447499 * safezoneW + safezoneX","0.486 * safezoneH + safezoneY","0.196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"ReplaceWithText",[1,"Replace With:",["0.355625 * safezoneW + safezoneX","0.486 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-2200,"",[1,"",["0.3425 * safezoneW + safezoneX","0.36 * safezoneH + safezoneY","0.315 * safezoneW","0.182 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"Header",[1,"Batch Replace",["0.3425 * safezoneW + safezoneX","0.332 * safezoneH + safezoneY","0.315 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,1,1],[-1,-1,-1,-1],"","-1"],[]],
	[1100,"",[1,"All selected objects will be replaced by the object types you enter in the edit box below.",["0.355625 * safezoneW + safezoneX","0.374 * safezoneH + safezoneY","0.28875 * safezoneW","0.07 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,0],[-1,-1,-1,-1],"","-1"],[]]
]
*/