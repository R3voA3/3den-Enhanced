class ENH_ModuleInformation
{
	idd = IDD_MODULEINFORMATION;
	onLoad = "_this call ENH_fnc_moduleInformation_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Header: ctrlStaticTitle
		{
			text = "$STR_ENH_MAIN_MODULEINFORMATION";
			x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
			y = QUOTE(WINDOW_TOPAbs);
			w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class Background: ctrlStaticBackground
		{
			x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
			w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
			h = QUOTE(WINDOW_PREVIEW_HAbs);
		};
		class Footer: ctrlStaticFooter
		{
			x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - 2 * GRID_H);
			w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
			h = QUOTE(7 * GRID_H);
		};
	};
	class Controls
	{
		class DescriptionValue: ctrlStructuredText
		{
			idc = IDC_MODULEINFORMATION_DESCRIPTION;
			x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 1 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + 6 * GRID_H);
			w = QUOTE((WINDOW_W_ATTRIBUTES - 2) * GRID_W);
			h = QUOTE(WINDOW_PREVIEW_HAbs - 9 * GRID_H);
			colorBackground[] = {COLOR_OVERLAY_RGBA};
		};
		class Close: ctrlButtonClose
		{
			x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES - 26) * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_PREVIEW_HAbs - GRID_H);
			w = QUOTE(25 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
	};
};