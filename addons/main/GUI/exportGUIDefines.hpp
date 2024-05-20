class ENH_ExportGUIDefines
{
	idd = IDD_EXPORTGUIDEFINES;
	onLoad = "";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = QUOTE(CENTER_X - 0.5 * 53 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
			w = QUOTE(53 * GRID_W);
			h = QUOTE(21 * GRID_H);
		};
		class Header: ctrlStaticTitle
		{
			text = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES";
			x = QUOTE(CENTER_X - 0.5 * 53 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs);
			w = QUOTE(53 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class Footer: ctrlStaticFooter
		{
			x = QUOTE(CENTER_X - 0.5 * 53 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + 19 * GRID_H);
			w = QUOTE(53 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
		};
	};
	class Controls
	{
		class Target: ctrlStatic
		{
			text = "$STR_WATCH_TARGET";
			x = QUOTE(CENTER_X - 0.5 * 53 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + 6 * GRID_H);
			w = QUOTE(15 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class TargetValue: ctrlCombo
		{
			idc = 10;
			x = QUOTE(CENTER_X - 0.5 * 53 * GRID_W + 12 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + 6 * GRID_H);
			w = QUOTE((53 - 13) * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
			class Items
			{
				class Mod
				{
					text = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_ADDON";
					tooltip = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_ADDON_TOOLTIP";
					default = 1;
				};
				class Scenario
				{
					text = "$STR_A3_CFGUIGRIDS_IGUI_VARIABLES_GRID_MISSION_0";
					tooltip = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_SCENARIO_TOOLTIP";
				};
			};
		};
		class Types: Target
		{
			text = "$STR_A3_TO_BASICCIVILIANPRESENCE12";
			y = QUOTE(WINDOW_TOPAbs + 13 * GRID_H);
		};
		class TypesValue: TargetValue
		{
			idc = 20;
			y = QUOTE(WINDOW_TOPAbs + 13 * GRID_H);
			class Items
			{
				class Classic
				{
					text = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_CLASSIC";
					tooltip = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_CLASSIC_TOOLTIP";
					data = "classic";
					default = 1;
				};
				class Eden
				{
					text = "$STR_A3_CFGMODS_APEX_FEATURE_EDEN_NAME";
					tooltip = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_EDEN_TOOLTIP";
					data = "3DEN";
				};
				class All
				{
					text = "$STR_GEAR_ALL";
					tooltip = "$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_ALL_TOOLTIP";
					data = "";
				};
			};
		};
		class Cancel: ctrlButtonCancel
		{
			x = QUOTE(CENTER_X - 0.5 * 53 * GRID_W + (53 - 26) * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + 20 * GRID_H);
			w = QUOTE(25 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class Ok: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the GUI. The function does that.
			x = QUOTE(CENTER_X - 0.5 * 53 * GRID_W + (53 - 52) * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + 20 * GRID_H);
			w = QUOTE(25 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
			onButtonClick = "private _display = ctrlParent (_this # 0); [lbCurSel (_display displayCtrl 10), lbCurSel (_display displayCtrl 20)] call ENH_fnc_exportGUIDefines";
		};
	};
};