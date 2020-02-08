#define DIALOG_W 50
#define DIALOG_H 70

class ENH_Credits
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this call ENH_fnc_credits_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H + 7 * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_ABOUT_CREDITS;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class List: ctrlListbox
		{
			idc = 1000;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = DIALOG_W * GRID_W - 2 * GRID_W;
			h = DIALOG_H * GRID_H - 1 * GRID_H;
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 29 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};