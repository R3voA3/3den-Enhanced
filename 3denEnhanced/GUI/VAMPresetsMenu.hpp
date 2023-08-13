#include "\3denEnhanced\defines\defineCommon.inc"
#define DIALOG_W 120
#define DIALOG_H 100

class ENH_VAM_PresetMenu {
	idd = 12345;
	
	class ControlsBackground {
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H + 7 * GRID_H;
		};
		class Header: ctrlStaticTitle
		{
			text = "$STR_ENH_TOOLS_CFGSENTENCESBROWSER";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Footer: ctrlStaticFooter
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + (DIALOG_H + 5) * GRID_H;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H + 2 * GRID_H;
		};
	};

	class Controls {
		class Filter: ctrlListNBox {
			idc = IDC_VAM_PRESET_ListNBoxFilter;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = 0.04 * GRID_H;
		};

		class Content: ctrlListNBox {
			idc = IDC_VAM_PRESET_ListNBoxContent;
			disableOverflow = 1;
			tooltipPerColumn = 1;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H + 7 * GRID_H;
		};

		//...
	};
};