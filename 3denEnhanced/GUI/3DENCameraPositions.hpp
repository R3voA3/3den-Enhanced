#define DIALOG_W 90
#define DIALOG_H 70

class ENH_3DENCamPositions
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this call ENH_fnc_3DENCam_updateList";
	class ControlsBackground
	{
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
			text = $STR_ENH_3DENCAM_HEADER;
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
			h = DIALOG_H * GRID_H - 7 * GRID_H;
			onLBDblClick = "_this call ENH_fnc_3DENCam_set3DENCameraParameters";
			onKeyDown = "_this call ENH_fnc_3DENCam_deleteEntry";
		};
		class Description: ctrlEdit
		{
			idc = 2000;
			text = $STR_ENH_3DENCAM_DESCRIPTION;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H) * GRID_H;
			w = DIALOG_W * GRID_W - 2 * GRID_W;
			h = CTRL_DEFAULT_H;
			onSetFocus = "_this call ENH_fnc_3DENCam_onSetFocus";
			onKillFocus = "_this call ENH_fnc_3DENCam_onKillFocus";
		};
		class Save: ctrlButton
		{
			text = $STR_ENH_3DENCAM_SAVE;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this # 0 call ENH_fnc_3DENCam_get3DENCameraParameters";
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 21 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};