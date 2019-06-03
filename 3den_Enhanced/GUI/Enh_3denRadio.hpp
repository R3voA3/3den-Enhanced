class Enh_3denRadio
{
	idd = ENH_IDD_3DENRADIO;
	movingEnable = true;
	onLoad = "_this spawn Enh_fnc_3denRadio_onLoad";
	onUnload = "_this call Enh_fnc_3denRadio_onUnload"
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.97125 * safezoneW;
			h = 0.9344 * safezoneH;
		};
	};
	class Controls
	{
		class ToggleRadio: ctrlButtonPictureKeepAspect
		{
			idc = 2300;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "['BUTTON'] call Enh_fnc_3denRadio_toggleRadio";
		};
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
			onLBDblClick  = "_this call Enh_fnc_3denRadio_playMusic";
			onKeyDown = "['ADDSONG',_this # 1] call Enh_fnc_3denRadio_handlePlaylist; _this call Enh_fnc_3denRadio_exportClassname";
		};
		class Playlist: ctrlListbox
		{
			idc = 2000;
			x = 0.769062 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.868 * safezoneH;
			onLBDblClick  = "call Enh_fnc_3denRadio_playMusic";
			onKeyDown = "['REMOVESONG',_this # 1] call Enh_fnc_3denRadio_handlePlaylist";
		};
		class SearchEdit: ctrlEdit
		{
			idc = 1400;
			x = 0.644375 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0984375 * safezoneW;
			h = 0.028 * safezoneH;
			onKeyUp = "call Enh_fnc_3denRadio_searchList;";//onKeyUp to give the control time to update
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = 0.742812 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TitleHeader: ctrlStaticTitle
		{
			text = $STR_ENH_3denRadio_headline_title;
			x = 0.0275 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.450312 * safezoneW;
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
			x = 0.460624 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PlaylistHeader:  ctrlStaticTitle
		{
			text = "Playlist";
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
			colorBackground[] = COLOUR_USER_PRESET;
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
			action = "'EXPORT'call Enh_fnc_3denRadio_handlePlaylist";
		};
		class Import: ctrlButton
		{
			text = $STR_ENH_3denRadio_importPlaylist_text;
			x = 0.84125 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'IMPORT'call Enh_fnc_3denRadio_handlePlaylist";
		};
		class ToggleHelp: ctrlButton
		{
			text = $STR_ENH_3denRadio_help_text;
			x = 0.572187 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_3denRadio_toggleHelp";
		};
		class HelpText: Enh_StructuredText
		{
			idc = 2400;
			text = $STR_ENH_3denRadio_help_description;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.3 * safezoneW;
			h = 0.168 * safezoneH;
			onLoad = "_this # 0 ctrlSetFade 1;  _this # 0 ctrlCommit 0";
			colorBackground[] = COLOUR_USER_PRESET;
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
			w = 0.0459375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CurrentSong: ctrlStatic
		{
			idc = 2200;
			x = 0.19125 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.2575 * safezoneW;
			h = 0.028 * safezoneH;
		};
/* 		class FastForwardIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\Modules_F_Curator\Data\portraitSound_ca.paa"; //--- ToDo: Localize;
			x = 0.375313 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		}; */
/* 		class FastForward: ctrlXSliderH
		{
			idc = 1900;
			sliderRange[] = {0,1.5};
			onSliderPosChanged = "playMusic [profileNamespace getVariable ['Enh_3denRadio_CurrentSong',''],]";
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		}; */
		//Sort buttons
		class SortTitle: ctrlButtonPicture
		{
			text = "\A3\ui_f\data\igui\cfg\actions\arrow_down_gs.paa";
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "'NAME' call Enh_fnc_3denRadio_sortBy";
		};
		class SortDuration: ctrlButtonPicture
		{
			text = "\A3\ui_f\data\igui\cfg\actions\arrow_down_gs.paa";
			x = 0.4475 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "'DURATION' call Enh_fnc_3denRadio_sortBy";
		};
		class SortTheme: ctrlButtonPicture
		{
			text = "\A3\ui_f\data\igui\cfg\actions\arrow_down_gs.paa";
			x = 0.52625 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "'THEME' call Enh_fnc_3denRadio_sortBy";
		};
	};
};