#include "\3denEnhanced\defines\defineCommon.inc"
#define DIALOG_W 120
#define DIALOG_H 100

class RscButton;

class ENH_VAM_PresetMenu {
	idd = 12345;
	
	class ControlsBackground {
		class Background: ctrlStaticBackground
		{
			x = GUI_GRID_CENTER_X + 0 * GUI_GRID_CENTER_W;
			y = GUI_GRID_CENTER_Y + 0 * GUI_GRID_CENTER_H;
			w = 40 * GUI_GRID_CENTER_W;
			h = 25 * GUI_GRID_CENTER_H;
		};
		class Header: ctrlStaticTitle
		{
			text = "Virtual Arsenal Manager Presets";
			x = GUI_GRID_CENTER_X + 0 * GUI_GRID_CENTER_W;
			y = GUI_GRID_CENTER_Y + 0 * GUI_GRID_CENTER_H;
			w = 40 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
	};

	class Controls {
		class Filter: ctrlListNBox
		{
			idc = IDC_VAM_PRESET_LISTNBOXFILTER;
			x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 38 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
		class Content: ctrlListNBox
		{
			idc = IDC_VAM_PRESET_LISTNBOXCONTENT;
			x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 2 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 38 * GUI_GRID_CENTER_W;
			h = 20 * GUI_GRID_CENTER_H;
		};
		class LoadButton: RscButton
		{
			idc = IDC_VAM_PRESET_LOADBUTTON;
			text = "Load Preset";
			x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 22.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 5 * GUI_GRID_CENTER_W;
			h = 1.5 * GUI_GRID_CENTER_H;
		};
		class SaveButton: RscButton
		{
			idc = IDC_VAM_PRESET_SAVEBUTTON;
			text = "Save Preset";
			x = 7 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 22.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 5 * GUI_GRID_CENTER_W;
			h = 1.5 * GUI_GRID_CENTER_H;
		};
		class Close: ctrlButtonClose
		{
			x = 34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 22.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 5 * GUI_GRID_CENTER_W;
			h = 1.5 * GUI_GRID_CENTER_H;
		};

		//...
	};
};