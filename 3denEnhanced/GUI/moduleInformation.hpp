#define DIALOG_W 100
#define DIALOG_H 87

class ENH_ModuleInformation
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this call ENH_fnc_moduleInformation_onLoad";
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
			text = $STR_ENH_MODULEINFORMATION;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Description: ctrlStatic
		{
			text = $STR_ENH_MODULEINFORMATION_DESCRIPTION;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 6 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class DescriptionValue: ctrlEditMulti
		{
			idc = 1400;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 12 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = 22 * GRID_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Position: ctrlStatic
		{
			text = $STR_ENH_MODULEINFORMATION_POSITION;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 35 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class PositionValue: ctrlEditMulti
		{
			idc = 1401;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 41 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Duplicate: ctrlStatic
		{
			text = $STR_ENH_MODULEINFORMATION_DUPLICATE;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 47 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class DuplicateValue: ctrlEditMulti
		{
			idc = 1402;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 53 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Direction: ctrlStatic
		{
			text = $STR_ENH_MODULEINFORMATION_DIRECTION;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 59 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class DirectionValue: ctrlEditMulti
		{
			idc = 1403;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 65 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Sync : ctrlStatic
		{
			text = $STR_ENH_MODULEINFORMATION_SYNC;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 71 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SyncValue: ctrlEditMulti
		{
			idc = 1404;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 77 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = 10 * GRID_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 76 * GRID_W;
			y = DIALOG_TOP + 88 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};