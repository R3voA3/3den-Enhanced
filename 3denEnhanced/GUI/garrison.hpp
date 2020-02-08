#define DIALOG_W 60

class ENH_Garrison
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this call ENH_fnc_garrison_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = 25 * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_GARRISON_HEADER;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Radius: ctrlStatic
		{
			text = $STR_ENH_PLACEMENTTOOLS_RADIUS;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 6 * GRID_H;
			w = 15 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class RadiusEdit: ctrlEdit
		{
			idc = 100;
			x = CENTERED_X(DIALOG_W) + 16 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = 43 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Coverage: ctrlStatic
		{
			text = $STR_ENH_GARRISON_COVERAGE;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 12 * GRID_H;
			w = 15 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class CoverageValue: ctrlToolbox
		{
			idc = 200;
			x = CENTERED_X(DIALOG_W) + 16 * GRID_W;
			y = DIALOG_TOP + 12 * GRID_H;
			w = 43 * GRID_W;
			h = CTRL_DEFAULT_H;
			rows = 1;
			columns = 4;
			strings[] = 
			{
				$STR_ENH_GARRISON_10PERCENT,
				$STR_ENH_GARRISON_25PERCENT,
				$STR_ENH_GARRISON_50PERCENT,
				$STR_ENH_GARRISON_100PERCENT
			};
			values[] = {10,4,2,1};
		};
		class Stance: ctrlStatic
		{
			text = $STR_ENH_GARRISON_STANCE;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 18 * GRID_H;
			w = 15 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class StanceValue: ctrlToolbox
		{
			idc = 300;
			x = CENTERED_X(DIALOG_W) + 16 * GRID_W;
			y = DIALOG_TOP + 18 * GRID_H;
			w = 43 * GRID_W;
			h = CTRL_DEFAULT_H;
			rows = 1;
			columns = 3;
			strings[] = 
			{
				$STR_ENH_GARRISON_STANCE_AUTO,
				$STR_ENH_GARRISON_STANCE_CROUCH,
				$STR_ENH_GARRISON_STANCE_STAND
			};
			values[] = {0,1,2,3};
		};
		class Cancel: ctrlButtonCancel
		{
			x = CENTERED_X(DIALOG_W) + 34 * GRID_W;
			y = DIALOG_TOP + 24 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Ok: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the GUI. The function does that.
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + 24 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_garrison_garrison";
		};
	};
};