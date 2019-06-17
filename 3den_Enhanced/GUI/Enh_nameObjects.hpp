#define DIALOG_W 70
#define DIALOG_H 30

class Enh_NameObjects
{
	idd = ENH_IDD_NAMEOBJECTS;
	onLoad = "call Enh_fnc_nameObjects_onLoad";
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_nameObjects_header;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VariableName: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_variableName_displayName;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 6 * GRID_H;
			w = DIALOG_W * GRID_W - 4 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VariableNameValue: ctrlEdit
		{
			idc = 1000;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 12 * GRID_H;
			w = DIALOG_W * GRID_W - 2 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class IndexStart: ctrlStatic
		{
			text = $STR_ENH_nameObjects_startIndex;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 17 * GRID_H;
			w = DIALOG_W * GRID_W - 4 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class IndexStartValue: ctrlEdit
		{
			idc = 1100;
			text = "0";
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 23 * GRID_H;
			w = DIALOG_W * GRID_W - 2 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class RemoveNames: ctrlButton
		{
			text = $STR_ENH_nameObjects_removeName;
			x = CENTERED_X(DIALOG_W) + 42 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = 27 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "'UNNAME' call Enh_fnc_nameObjects_name";
		};
		class OK: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the dialog
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 29 * GRID_H;
			w = 27 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "call Enh_fnc_nameObjects_name";
		};
		class Cancel: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 42 * GRID_W;
			y = DIALOG_TOP + 29 * GRID_H;
			w = 27 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};

/*class Enh_NameObjects
{
	idd = ENH_IDD_NAMEOBJECTS;
	onLoad = "call Enh_fnc_nameObjects_onLoad";
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.375313 * safezoneW + safezoneX;
			y = 0.353 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.224 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_nameObjects_header;
			x = 0.375313 * safezoneW + safezoneX;
			y = 0.325 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RemoveNames: ctrlButton
		{
			text = $STR_ENH_nameObjects_removeName;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.535 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'UNNAME' call Enh_fnc_nameObjects_name";
		};
		class OK: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the dialog
			x = 0.539375 * safezoneW + safezoneX;
			y = 0.535 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_nameObjects_name";
		};
		class VariableName: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_variableName_displayName;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.367 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class IndexStart: ctrlStatic
		{
			text = $STR_ENH_nameObjects_startIndex;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.451 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class VariableNameValue: ctrlEdit
		{
			idc = 1000;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.395 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class IndexStartValue: ctrlEdit
		{
			idc = 1100;
			text = "0";
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.479 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};