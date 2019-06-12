#define DIALOG_W 110
#define DIALOG_H 95

class Enh_ActionCreator
{
	idd = ENH_IDD_ACTIONCREATOR;
	movingEnable = true;
	onLoad = "_this call Enh_fnc_actionCreator_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 5 * GRID_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = "Action Creator";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W - 5 * GRID_W;
			h = 5 * GRID_H;
		};
		class Help: ctrlButton
		{
			text = "?";
			url = "https://community.bistudio.com/wiki/addAction";
			x = CENTERED_X(DIALOG_W) + (DIALOG_W - 5) * GRID_W;
			y = DIALOG_TOP;
			w = 5 * GRID_W;
			h = 5 * GRID_H;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class Title: ctrlStatic
		{
			text = "Title";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 7 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class TitleValue: ctrlEdit
		{
			idc = 1408;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 7 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class Script: ctrlStatic
		{
			text = "Script";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 14 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class ScriptValue: ctrlEditMulti
		{
			idc = 1400;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 14 * GRID_H;
			w = 82 * GRID_W;
			h = 20 * GRID_H;
		};
		class Arguments: ctrlStatic
		{
			text = "Arguments";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 36 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class ArgumentsValue: ctrlEdit
		{
			idc = 1401;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 36 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class Priority: ctrlStatic
		{
			text = "Priority";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 43 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class PriorityValue: ctrlEdit
		{
			idc = 1402;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 43 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class Shortcut: ctrlStatic
		{
			text = "Shortcut";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 50 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class ShortcutValue: ctrlEdit
		{
			idc = 1405;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 50 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class Condition: ctrlStatic
		{
			text = "Condition";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 57 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class ConditionValue: ctrlEdit
		{
			idc = 1403;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 57 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class Radius: ctrlStatic
		{
			text = "Radius";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 64 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class RadiusValue: ctrlEdit
		{
			idc = 1404;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 64 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class Selection: ctrlStatic
		{
			text = "Selection";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 71 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class SelectionValue: ctrlEdit
		{
			idc = 1406;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 71 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class MemoryPoint: ctrlStatic
		{
			text = "Memory Point";
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 78 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class MemoryPointValue: ctrlEdit
		{
			idc = 1407;
			x = CENTERED_X(DIALOG_W) + 26 * GRID_W;
			y = DIALOG_TOP + 78 * GRID_H;
			w = 82 * GRID_W;
			h = 5 * GRID_H;
		};
		class Toolbox: ctrlToolbox
		{
			idc = 1000;
			type = 7;
			style = 2;

			x = CENTERED_X(DIALOG_W) + 3 * GRID_W;
			y = DIALOG_TOP + 85 * GRID_H;
			w = (DIALOG_W - 5) * GRID_W;
			h = 5 * GRID_H;

			columns = 3;
			rows = 1;
			strings[] = {"Show Unconscious?","Show Window?","Hide on Use?"};
			checked_strings[] = {"Show Unconscious? Yes","Show Window? Yes","Hide on Use? Yes"};
			values[] = {0,0,0};
		};
		class Cancel: ctrlButtonCancel
		{
			x = CENTERED_X(DIALOG_W) + 85 * GRID_W;
			y = DIALOG_TOP + 92 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
		class Ok: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the GUI
			action = "call Enh_fnc_actionCreator_export";
			x = CENTERED_X(DIALOG_W) + 60 * GRID_W;
			y = DIALOG_TOP + 92 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
	};
};

/* class Enh_ActionCreator
{
	idd = ENH_IDD_ACTIONCREATOR;
	movingEnable = true;
	onLoad = "call Enh_fnc_actionCreator_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
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
		class Header: ctrlStaticTitle
		{
			text = "Action Creator";
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.136 * safezoneH + safezoneY;
			w = 0.321562 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Help: ctrlButton
		{
			text = "?";
			tooltip = $STR_ENH_actionCreator_help;
			url = "https://community.bistudio.com/wiki/addAction";
			x = 0.650637 * safezoneW + safezoneX;
			y = 0.136 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class Title: ctrlStatic
		{
			text = "Title";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Script: ctrlStatic
		{
			text = "Script";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Arguments: ctrlStatic
		{
			text = "Arguments";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Priority: ctrlStatic
		{
			text = "Priority";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Window: ctrlStatic
		{
			text = "Show Window?";
			x = 0.4475 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class HideOneUse: ctrlStatic
		{
			text = "Hide on Use";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Shortcut: ctrlStatic
		{
			text = "Shortcut";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Condition: ctrlStatic
		{
			text = "Condition";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Radius: ctrlStatic
		{
			text = "Radius";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Unconscious: ctrlStatic
		{
			text = "Unconscious";
			x = 0.559062 * safezoneW + safezoneX;
			y = 0.696 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Selection: ctrlStatic
		{
			text = "Selection";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class MemoryPoint: ctrlStatic
		{
			text = "Memory Point";
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ScriptValue: ctrlEditMulti
		{
			idc = 1400;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.154 * safezoneH;
		};
		class ArgumentsValue: ctrlEdit
		{
			idc = 1401;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PriorityValue: ctrlEdit
		{
			idc = 1402;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ConditionValue: ctrlEdit
		{
			idc = 1403;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RadiusValue: ctrlEdit
		{
			idc = 1404;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ShortcutValue: ctrlEdit
		{
			idc = 1405;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.556 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SelectionValue: ctrlEdit
		{
			idc = 1406;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class MemoryPointValue: ctrlEdit
		{
			idc = 1407;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TitleValue: ctrlEdit
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
		class Cancel: ctrlButtonCancel
		{
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.1575 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Ok: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the GUI
			action = "call Enh_fnc_actionCreator_export";
			x = 0.506562 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.1575 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
}; */