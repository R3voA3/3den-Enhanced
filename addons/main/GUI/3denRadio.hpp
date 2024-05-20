class ENH_3DENRadio
{
	idd = IDD_3DENRADIO;
	onLoad = "_this spawn ENH_fnc_3DENRadio_onLoad";
	onUnload = "";
	class ControlsBackground
	{
	DISABLE_BACKGROUND
	class Header: ctrlStaticTitle
		{
			text = "3DEN Radio";
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs);
			w = QUOTE(WINDOW_W_WIDE * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class Background: ctrlStaticBackground
		{
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H);
			w = QUOTE(WINDOW_W_WIDE * GRID_W);
			h = QUOTE(WINDOW_HAbs - 4 * CTRL_DEFAULT_H);
		};
		class Footer: ctrlStaticFooter
		{
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
			w = QUOTE(WINDOW_W_WIDE * GRID_W);
			h = QUOTE(7 * GRID_H);
		};
		class BackgroundFilter: Background//Background used for filter buttons
		{
			y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
			h = QUOTE(CTRL_DEFAULT_H);
			colorBackground[] = {0, 0, 0, 1};
		};
		class CurrentSongText: ctrlStaticFooter
		{
			text = "$STR_ENH_MAIN_3DENRADIO_SONG";
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H);
			w = QUOTE(10 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class CurrentSong: CurrentSongText
		{
			idc = IDC_3DENRADIO_CURRENTSONG;
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + 10 * GRID_W);
			w = QUOTE((WINDOW_W_WIDE - 10) * GRID_W);
		};
	};
	class Controls
	{
		class Filter: ctrlListNBox //Used by BIS_fnc_initListBoxSorting as filter
		{
			idc = IDC_3DENRADIO_FILTER;
			idcLeft = -1;
			idcRight = -1;
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
			w = QUOTE(WINDOW_W_WIDE * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class Songlist: Filter
		{
			idc = IDC_3DENRADIO_SONGLIST;
			y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H);
			h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H);
			disableOverflow = 1;
			onLBDblClick = "params ['_ctrl', '_row']; [[_ctrl lnbText [_row, 0], _ctrl lnbData [_row, 0], _ctrl lnbData [_row, 1]]] call ENH_fnc_3DENRadio_playNewSong";
			onKeyDown = "_this call ENH_fnc_3DENRadio_handlePlaylist; _this call ENH_fnc_3DENRadio_exportClassname";
		};
		class ToggleRadio: ctrlButtonPictureKeepAspect
		{
			idc = IDC_3DENRADIO_TOGGLERADIO;
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
			w = QUOTE(5 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
			onButtonClick = "false call ENH_fnc_3DENRadio_toggleRadio";
		};
		class VolumeIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\Modules_F_Curator\Data\portraitSound_ca.paa";
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + 7 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
			w = QUOTE(5 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class Volume: ctrlXSliderH
		{
			idc = IDC_3DENRADIO_VOLUME;
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + 13 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
			w = QUOTE(30 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
			sliderRange[] = {0, 1.5};
			onSliderPosChanged = "0 fadeMusic (sliderPosition (_this # 0)); profileNamespace setVariable ['ENH_3DENRadio_MusicVolume', musicVolume]";
		};
		class Help: VolumeIcon
		{
			text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa";
			tooltip = "$STR_ENH_MAIN_3DENRADIO_HELP_DESCRIPTION";
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + 44 * GRID_W);
			tooltipMaxWidth = 1;
		};
		class SearchEdit: ctrlEdit
		{
			idc = IDC_3DENRADIO_SEARCH;
			tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + 50 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
			w = QUOTE(30 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc = IDC_3DENRADIO_BUTTONSEARCH;
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + 80 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
			w = QUOTE(5 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class Group: ctrlControlsGroup
		{
			x = QUOTE(CENTER_X - WINDOW_W_WIDE * 0.5 * GRID_W + 86 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
			w = QUOTE(80 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
			class Controls
			{
				class Time: ctrlStatic
				{
					idc = IDC_3DENRADIO_TIME;
					text = "00:00";
					x = QUOTE(24 * GRID_W);
					y = QUOTE(0);
					w = QUOTE(10 * GRID_W);
					h = QUOTE(CTRL_DEFAULT_H);
				};
				class Position: ctrlXSliderH
				{
					idc = IDC_3DENRADIO_POSITION;
					x = QUOTE(0 * GRID_W);
					y = QUOTE(0);
					w = QUOTE(58 * GRID_W);
					h = QUOTE(CTRL_DEFAULT_H);
					sliderRange[] = {0, 1.5};
					colorActive[] = {1, 1, 1, 0.6};
					onSliderPosChanged = "playMusic [uiNamespace getVariable ['ENH_3DENRadio_CurrentSongClass', ''], sliderPosition (_this # 0)]";
				};
			};
		};
		class Close: ctrlButtonClose
		{
			x = QUOTE(CENTER_X + 0.5 * WINDOW_W_WIDE * GRID_W - 26 * GRID_W);
			y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
			w = QUOTE(25 * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
	};
};