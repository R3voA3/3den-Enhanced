#define DIALOG_W 80
#define DIALOG_H 42

class ENH_BatchReplace
{
	idd = ENH_IDD_BATCHREPLACE;
	movingEnable = true;
	onLoad = "((_this # 0) displayCtrl 1400) ctrlSetText (profileNameSpace getVariable ['ENH_batchReplace_lastUsed','']); ctrlSetFocus ((_this # 0) displayCtrl 1400)";
	onUnload = "profileNameSpace setVariable ['ENH_batchReplace_lastUsed',ctrlText ((_this # 0) displayCtrl 1400)]";
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
			text = $STR_ENH_BATCHREPLACE;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Description: ctrlStructuredText
		{
			text = $STR_ENH_BATCHREPLACE_DESCRIPTION;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 7 * GRID_H;
			w = DIALOG_W * GRID_W;
			h = 10 * GRID_H;
		};
		class ReplaceWithText: ctrlStatic
		{
			text = $STR_ENH_BATCHREPLACE_REPLACEWITH;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 19 * GRID_H;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ReplaceWithValue: ctrlEditMulti
		{
			idc = 1400;
			tooltip = $STR_ENH_BATCHREPLACE_REPLACEWITH_TOOLTIP;
			x = CENTERED_X(DIALOG_W) + 29 * GRID_W;
			y = DIALOG_TOP + 20 * GRID_H;
			w = 50 * GRID_W;
			h = 20 * GRID_H;
		};
		class Replace: ctrlButton
		{
			text = $STR_ENH_BATCHREPLACE_REPLACE;
			x = CENTERED_X(DIALOG_W) + 29 * GRID_W;
			y = DIALOG_TOP + 41 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "call ENH_fnc_batchreplace";
		};
		class Close: ctrlButtonCancel
		{
			x = CENTERED_X(DIALOG_W) + 56 * GRID_W;
			y = DIALOG_TOP + 41 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};