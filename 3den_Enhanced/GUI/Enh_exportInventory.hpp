class Enh_ExportInventory
{
	idd = 170000;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_IGUIBack
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.308 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_RscText
		{
			text = $STR_ENH_exportLoadout_header;
			x = 0.395 * safezoneW + safezoneX;
			y = 0.29 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Class: Enh_RscText
		{
			text = $STR_ENH_exportLoadout_className;
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DisplayName: Enh_RscText
		{
			text = $STR_ENH_exportLoadout_displayName;
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.402 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Icon: Enh_RscText
		{
			text = $STR_ENH_exportLoadout_icon;
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Role: Enh_RscText
		{
			text = $STR_ENH_exportLoadout_role;
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Condition: Enh_RscText
		{
			text = $STR_ENH_exportLoadout_condition;
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ClassValue: Enh_RscEdit
		{
			idc = 1400;
			text = "WEST1";
			x = 0.480312 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DisplayNameValue: Enh_RscEdit
		{
			idc = 1401;
			text = "Soldier";
			x = 0.480312 * safezoneW + safezoneX;
			y = 0.402 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class IconValue: Enh_RscEdit
		{
			idc = 1402;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa";
			x = 0.480312 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RoleValue: Enh_RscEdit
		{
			idc = 1403;
			text = "Default";
			x = 0.480312 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ConditionValue: Enh_RscEdit
		{
			idc = 1404;
			text = "true";
			x = 0.480312 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.118125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Ok: Enh_RscButton
		{
			text = "Ok";
			x = 0.395 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_exportInventoryConfig";
		};
	};
};

/* #Jebeva
$[
	1.063,
	["e",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[2200,"Background",[1,"",["0.395 * safezoneW + safezoneX","0.318 * safezoneH + safezoneY","0.21 * safezoneW","0.308 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"Header",[1,"Export Loadout to Respawn Inventory",["0.395 * safezoneW + safezoneX","0.29 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"Class",[1,"Class Name",["0.401563 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"DisplayName",[1,"Display Name",["0.401563 * safezoneW + safezoneX","0.402 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"Icon",[1,"Icon",["0.401563 * safezoneW + safezoneX","0.458 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1004,"Role",[1,"Role",["0.401563 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1005,"Condition",[1,"Condition",["0.401563 * safezoneW + safezoneX","0.57 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"ClassValue",[1,"WEST1",["0.480312 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"DisplayNameValue",[1,"Soldier",["0.480312 * safezoneW + safezoneX","0.402 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1402,"IconValue",[1,"\A3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa",["0.480312 * safezoneW + safezoneX","0.458 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1403,"RoleValue",[1,"Default",["0.480312 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1404,"ConditionValue",[1,"true",["0.480312 * safezoneW + safezoneX","0.57 * safezoneH + safezoneY","0.118125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"Ok",[1,"Ok",["0.395 * safezoneW + safezoneX","0.626 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/