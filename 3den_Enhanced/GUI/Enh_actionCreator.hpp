class Enh_ActionCreator
{
	idd = ENH_ACTIONCREATOR;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_actionCreator_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_Background
		{
			idc = 2200;
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.164 * safezoneH + safezoneY;
			w = 0.34125 * safezoneW;
			h = 0.616 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = "Action Creator";
			colorBackground[] = COLOUR_USER_PRESET;
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.136 * safezoneH + safezoneY;
			w = 0.321562 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Help: Enh_Button
		{
			text = "?";
			tooltip = $STR_ENH_actionCreator_help;
			url = "https://community.bistudio.com/wiki/addAction";
			x = 0.650637 * safezoneW + safezoneX;
			y = 0.136 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Title: Enh_Text
		{
			text = "Title";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Script: Enh_Text
		{
			text = "Script";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Arguments: Enh_Text
		{
			text = "Arguments";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Priority: Enh_Text
		{
			text = "Priority";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Window: Enh_Text
		{
			text = "Show Window?";
			x = 0.4475 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class HideOneUse: Enh_Text
		{
			text = "Hide on Use";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Shortcut: Enh_Text
		{
			text = "Shortcut";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Condition: Enh_Text
		{
			text = "Condition";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Radius: Enh_Text
		{
			text = "Radius";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Unconscious: Enh_Text
		{
			text = "Unconscious";
			x = 0.559062 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Selection: Enh_Text
		{
			text = "Selection";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class MemoryPoint: Enh_Text
		{
			text = "Memory Point";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ScriptValue: Enh_Edit
		{
			idc = 1400;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.154 * safezoneH;
		};
		class ArgumentsValue: Enh_Edit
		{
			idc = 1401;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PriorityValue: Enh_Edit
		{
			idc = 1402;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ConditionValue: Enh_Edit
		{
			idc = 1403;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RadiusValue: Enh_Edit
		{
			idc = 1404;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ShortcutValue: Enh_Edit
		{
			idc = 1405;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SelectionValue: Enh_Edit
		{
			idc = 1406;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class MemoryPointValue: Enh_Edit
		{
			idc = 1407;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TitleValue: Enh_Edit
		{
			idc = 1408;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class WindowValue: ctrlCheckbox
		{
			idc = 1409;
			x = 0.532812 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class HideOnUseValue: ctrlCheckbox
		{
			idc = 1410;
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class UnconsciousValue: ctrlCheckbox
		{
			idc = 1411;
			x = 0.644375 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Cancel: Enh_Button
		{
			idc = 2;
			text = $STR_ENH_actionCreator_cancel;
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.1575 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Ok: Enh_Button
		{
			text = $STR_ENH_actionCreator_ok;
			action = "call Enh_fnc_actionCreator_export";
			x = 0.506562 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.1575 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};

/* #Zibufo
$[
	1.063,
	["etst",[[0,0,1,1],0.025,0.04,"GUI_GRID"],2,0,0],
	[2200,"Background",[1,"",["0.329375 * safezoneW + safezoneX","0.164 * safezoneH + safezoneY","0.34125 * safezoneW","0.616 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"Header",[1,"AddAction Creator",["0.329375 * safezoneW + safezoneX","0.136 * safezoneH + safezoneY","0.321562 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"Title",[1,"Title",["0.335938 * safezoneW + safezoneX","0.178 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"Script",[1,"Script",["0.335938 * safezoneW + safezoneX","0.22 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"ScriptValue",[1,"",["0.414687 * safezoneW + safezoneX","0.22 * safezoneH + safezoneY","0.249375 * safezoneW","0.154 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"Arguments",[1,"Arguments",["0.335938 * safezoneW + safezoneX","0.388 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1004,"Priority",[1,"Priority",["0.335938 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1005,"Window",[1,"Show Window?",["0.4475 * safezoneW + safezoneX","0.696 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1006,"HideOneUse",[1,"Hide on Use",["0.335938 * safezoneW + safezoneX","0.696 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1008,"Shortcut",[1,"Shortcut",["0.335938 * safezoneW + safezoneX","0.556 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1009,"Condition",[1,"Condition",["0.335938 * safezoneW + safezoneX","0.472 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1010,"Radius",[1,"Radius",["0.335938 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1011,"Unconscious",[1,"Unconscious",["0.559062 * safezoneW + safezoneX","0.696 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1012,"Selection",[1,"Selection",["0.335938 * safezoneW + safezoneX","0.598 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1013,"MemoryPoint",[1,"Memory Point",["0.335938 * safezoneW + safezoneX","0.64 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"ArgumentsValue",[1,"",["0.414687 * safezoneW + safezoneX","0.388 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1402,"PriorityValue",[1,"",["0.414687 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1406,"ConditionValue",[1,"",["0.414687 * safezoneW + safezoneX","0.472 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1407,"RadiusValue",[1,"",["0.414687 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1408,"ShortcutValue",[1,"",["0.414687 * safezoneW + safezoneX","0.556 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1409,"SelectionValue",[1,"",["0.414687 * safezoneW + safezoneX","0.598 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1410,"MemoryPointValue",[1,"",["0.414687 * safezoneW + safezoneX","0.64 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1411,"TitleValue",[1,"",["0.414687 * safezoneW + safezoneX","0.178 * safezoneH + safezoneY","0.249375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[2800,"WindowValue",[1,"",["0.532812 * safezoneW + safezoneX","0.696 * safezoneH + safezoneY","0.0196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[2801,"HideOnUseValue",[1,"",["0.42125 * safezoneW + safezoneX","0.696 * safezoneH + safezoneY","0.0196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[2802,"UnconsciousValue",[1,"",["0.644375 * safezoneW + safezoneX","0.696 * safezoneH + safezoneY","0.0196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"Cancel",[1,"Cancel",["0.335938 * safezoneW + safezoneX","0.738 * safezoneH + safezoneY","0.1575 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"Ok",[1,"Ok",["0.506562 * safezoneW + safezoneX","0.738 * safezoneH + safezoneY","0.1575 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1602,"Help",[1,"?",["0.650637 * safezoneW + safezoneX","0.136 * safezoneH + safezoneY","0.0196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Get help.","-1"],[]]
]
*/