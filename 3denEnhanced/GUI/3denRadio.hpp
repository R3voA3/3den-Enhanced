#define DIALOG_W 200
#define DIALOG_H 106

class ENH_3denRadio
{
	idd = ENH_IDD_3DENRADIO;
	movingEnable = true;
	onLoad = "_this spawn ENH_fnc_3denRadio_onLoad";
	onUnload = "_this call ENH_fnc_3denRadio_onUnload";
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
			text = $STR_ENH_3denRadio_headline_title;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = 90 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class DurationHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_duration;
			x = CENTERED_X(DIALOG_W) + 90 * GRID_W;
			y = DIALOG_TOP;
			w = 16 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
 		class ThemeHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_theme;
			x = CENTERED_X(DIALOG_W) + 106 * GRID_W;
			y = DIALOG_TOP;
			w = 29 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ModHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_mod;
			x = CENTERED_X(DIALOG_W) + 135 * GRID_W;
			y = DIALOG_TOP;
			w = 17 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class PlaylistHeader:  ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_playlist_text;
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
			onLBDblClick  = "_this call ENH_fnc_3denRadio_playMusic";
			onKeyDown = "['ADDSONG',_this # 1] call ENH_fnc_3denRadio_handlePlaylist; _this call ENH_fnc_3denRadio_exportClassname";
		};
		class Playlist: ctrlListbox
		{
			idc = 2000;
			x = CENTERED_X(DIALOG_W) + 150 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = (DIALOG_W - 150) * GRID_W;
			h = (DIALOG_H - 7) * GRID_H;
			onLBDblClick  = "call ENH_fnc_3denRadio_playMusic";
			onKeyDown = "['REMOVESONG',_this # 1] call ENH_fnc_3denRadio_handlePlaylist";
		};
		class ToggleRadio: ctrlButtonPictureKeepAspect
		{
			idc = 2300;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "['BUTTON'] call ENH_fnc_3denRadio_toggleRadio";
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
			onLBSelChanged = "params ['','_index']; (['TITLE','DURATION','THEME'] select _index) call ENH_fnc_3denRadio_sortBy";
		};
		class Help: ctrlStaticPictureKeepAspect
		{
			text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa";
			tooltip = $STR_ENH_3denRadio_help_description;
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
			onKeyUp = "call ENH_fnc_3denRadio_searchList;";//onKeyUp to give the control time to update
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
			text = $STR_ENH_3denRadio_importPlaylist_text;
			x = CENTERED_X(DIALOG_W) + 121 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "'IMPORT'call ENH_fnc_3denRadio_handlePlaylist";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_3denRadio_exportPlaylist_text;
			x = CENTERED_X(DIALOG_W) + 147 * GRID_W;
			y = DIALOG_TOP + 105 * GRID_H;
			w = 26 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "'EXPORT'call ENH_fnc_3denRadio_handlePlaylist";
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
			text = $STR_ENH_3denRadio_song;
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
/*class ENH_3denRadio
{
	idd = ENH_IDD_3DENRADIO;
	movingEnable = true;
	onLoad = "_this spawn ENH_fnc_3denRadio_onLoad";
	onUnload = "_this call ENH_fnc_3denRadio_onUnload";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.97125 * safezoneW;
			h = 0.924 * safezoneH;
		};
		class TitleHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_title;
			x = 0.0275 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.450312 * safezoneW;
			h = 0.028 * safezoneH;
		};
			class HeaderLeft: ctrlStaticTitle
		{
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ThemeHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_theme;
			x = 0.535375 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.170625 * safezoneW
			h = 0.028 * safezoneH;
		};
		class DurationHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_duration;
			x = 0.460625 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PlaylistHeader:  ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_playlist_text;
			x = 0.769063 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.216562 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ModHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_mod;
			x = 0.698875 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.28675 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
	class Controls
	{
		class Songlist: ctrlListNBox
		{
			idc = 1500;
			idcLeft = -1;
			idcRight = -1;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.741562 * safezoneW;
			h = 0.868 * safezoneH;
			type = CT_LISTNBOX;
			onLBDblClick  = "_this call ENH_fnc_3denRadio_playMusic";
			onKeyDown = "['ADDSONG',_this # 1] call ENH_fnc_3denRadio_handlePlaylist; _this call ENH_fnc_3denRadio_exportClassname";
		};
		class Playlist: ctrlListbox
		{
			idc = 2000;
			x = 0.769062 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.868 * safezoneH;
			onLBDblClick  = "call ENH_fnc_3denRadio_playMusic";
			onKeyDown = "['REMOVESONG',_this # 1] call ENH_fnc_3denRadio_handlePlaylist";
		};
		class Separator: ctrlStaticLine
		{
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.923704 * safezoneH + safezoneY;
			w = 0.958125 * safezoneW;
		};
		class ToggleRadio: ctrlButtonPictureKeepAspect
		{
			idc = 2300;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "['BUTTON'] call ENH_fnc_3denRadio_toggleRadio";
		};
		class VolumeIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\Modules_F_Curator\Data\portraitSound_ca.paa";
			x = 0.0471875 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Volume: ctrlXSliderH
		{
			idc = 1900;
			x = 0.0734375 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
			sliderRange[] = {0,1.5};
			onSliderPosChanged = "0 fadeMusic (sliderPosition (_this # 0))";
		};
		class CurrentSongText: ctrlStatic
		{
			text = $STR_ENH_3denRadio_song;
			x = 0.15875 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.03 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CurrentSong: ctrlStatic
		{
			idc = 2200;
			x = 0.19 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.23 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Sort: ctrlCombo
  		{
			idc = 1600;
			x = 0.5525 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
			onLBSelChanged = "params ['','_index']; (['TITLE','DURATION','THEME'] select _index) call ENH_fnc_3denRadio_sortBy";
		};
		class SearchEdit: ctrlEdit
		{
			idc = 1400;
			x = 0.690313 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0525 * safezoneW;
			h = 0.028 * safezoneH;
			onKeyUp = "call ENH_fnc_3denRadio_searchList;";//onKeyUp to give the control time to update
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = 0.742812 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Close: ctrlButtonClose
		{
			x = 0.913437 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_3denRadio_exportPlaylist_text;
			x = 0.769063 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'EXPORT'call ENH_fnc_3denRadio_handlePlaylist";
		};
		class Import: ctrlButton
		{
			text = $STR_ENH_3denRadio_importPlaylist_text;
			x = 0.84125 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'IMPORT'call ENH_fnc_3denRadio_handlePlaylist";
		};
		class ToggleHelp: ctrlStaticPictureKeepAspect
		{
			text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa";
			tooltip = $STR_ENH_3denRadio_help_description;
			x = 0.664063 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};