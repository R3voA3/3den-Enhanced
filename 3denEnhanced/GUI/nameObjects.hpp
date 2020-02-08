#define DIALOG_W 70
#define DIALOG_H 30

class ENH_NameObjects
{
	idd = ENH_IDD_NAMEOBJECTS;
	onLoad = "_this call ENH_fnc_nameObjects_onLoad";
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
			text = $STR_ENH_NAMEOBJECTS;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VariableName: ctrlStatic
		{
			text = $STR_ENH_NAMEOBJECTS_NAME;
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
			text = $STR_ENH_NAMEOBJECTS_STARTINDEX;
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
			text = $STR_ENH_NAMEOBJECTS_REMOVENAME;
			x = CENTERED_X(DIALOG_W) + 42 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = 27 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "'UNNAME' call ENH_fnc_nameObjects_name";
		};
		class OK: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the dialog
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 29 * GRID_H;
			w = 27 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "call ENH_fnc_nameObjects_name";
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