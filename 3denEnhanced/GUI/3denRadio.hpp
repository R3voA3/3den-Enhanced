#define DIALOG_W 200
#define DIALOG_H 106

class ENH_3DENRadio
{
	idd = ENH_IDD_3DENRADIO;
	movingEnable = true;
	onLoad = "_this spawn ENH_fnc_3DENRadio_onLoad";
	onUnload = "_this call ENH_fnc_3DENRadio_onUnload";
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
		class TitleHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3DENRADIO_HEADLINE_TITLE;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = 90 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class DurationHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3DENRADIO_HEADLINE_DURATION;
			x = CENTERED_X(DIALOG_W) + 90 * GRID_W;
			y = DIALOG_TOP;
			w = 16 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
 		class ThemeHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3DENRADIO_HEADLINE_THEME;
			x = CENTERED_X(DIALOG_W) + 106 * GRID_W;
			y = DIALOG_TOP;
			w = 29 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ModHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3DENRADIO_HEADLINE_MOD;
			x = CENTERED_X(DIALOG_W) + 135 * GRID_W;
			y = DIALOG_TOP;
			w = 17 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class PlaylistHeader:  ctrlStaticTitle
		{
			text = $STR_ENH_3DENRADIO_PLAYLIST_TEXT;
			x = CENTERED_X(DIALOG_W) + 152 * GRID_W;
			y = DIALOG_TOP;
			w = (DIALOG_W - 152) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
	class Controls
	{
		class Songlist: ctrlListNBox
		{
			idc = 1500;
			idcLeft = -1;
			idcRight = -1;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = (DIALOG_W - 50) * GRID_W;
			h = (DIALOG_H - 7) * GRID_H;
			type = CT_LISTNBOX;
			onLBDblClick  = "_this call ENH_fnc_3DENRadio_playMusic";
			onKeyDown = "['ADDSONG',_this # 1] call ENH_fnc_3DENRadio_handlePlaylist; _this call ENH_fnc_3DENRadio_exportClassname";
		};
		class Playlist: ctrlListbox
		{
			idc = 2000;
			x = CENTERED_X(DIALOG_W) + 150 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = (DIALOG_W - 150) * GRID_W;
			h = (DIALOG_H - 7) * GRID_H;
			onLBDblClick  = "call ENH_fnc_3DENRadio_playMusic";
			onKeyDown = "['REMOVESONG',_this # 1] call ENH_fnc_3DENRadio_handlePlaylist";
		};
		class ToggleRadio: ctrlButtonPictureKeepAspect
		{
			idc = 2300;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "['BUTTON'] call ENH_fnc_3DENRadio_toggleRadio";
		};
		class VolumeIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\Modules_F_Curator\Data\portraitSound_ca.paa";
			x = CENTERED_X(DIALOG_W) + 7 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Volume: ctrlXSliderH
		{
			idc = 1900;
			x = CENTERED_X(DIALOG_W) + 13 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			sliderRange[] = {0,1.5};
			onSliderPosChanged = "0 fadeMusic (sliderPosition (_this # 0))";
		};
		class Sort: ctrlCombo
  		{
			idc = 1600;
			x = CENTERED_X(DIALOG_W) + 44 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 35 * GRID_W;
			h = CTRL_DEFAULT_H;
			onLBSelChanged = "params ['','_index']; (['TITLE','DURATION','THEME'] select _index) call ENH_fnc_3DENRadio_sortBy";
		};
		class Help: ctrlStaticPictureKeepAspect
		{
			text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa";
			tooltip = $STR_ENH_3DENRADIO_HELP_DESCRIPTION;
			x = CENTERED_X(DIALOG_W) + 79 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SearchEdit: ctrlEdit
		{
			idc = 1400;
			x = CENTERED_X(DIALOG_W) + 85 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			onKeyUp = "call ENH_fnc_3DENRadio_searchList;";//onKeyUp to give the control time to update
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = CENTERED_X(DIALOG_W) + 115 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Import: ctrlButton
		{
			text = $STR_ENH_3DENRADIO_IMPORTPLAYLIST_TEXT;
			x = CENTERED_X(DIALOG_W) + 121 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "'IMPORT'call ENH_fnc_3DENRadio_handlePlaylist";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_3DENRADIO_EXPORTPLAYLIST_TEXT;
			x = CENTERED_X(DIALOG_W) + 147 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 26 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "'EXPORT'call ENH_fnc_3DENRadio_handlePlaylist";
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 174 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class CurrentSongText: ctrlStaticFooter
		{
			text = $STR_ENH_3DENRADIO_SONG;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H;
			w = 10 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class CurrentSong: ctrlStaticFooter
		{
			idc = 2200;
			x = CENTERED_X(DIALOG_W) + 10 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H + CTRL_DEFAULT_H;
			w = (DIALOG_W - 10) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};