class Enh_TextureFinder
{
	idd = ENH_IDD_TEXTUREFINDER;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_textureFinder_updateProgressbar";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.644 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_textureFinder_header;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class ShowAll: ctrlButton
		{
			text = $STR_ENH_textureFinder_showAll;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.028 * safezoneH;
			action = "[] spawn Enh_fnc_textureFinder_fillTextureLB";
		};
		class TextureList: ctrlListbox
		{
			idc = 1500;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.42 * safezoneH;
			onLBSelChanged = "((findDisplay 140000) displayCtrl 1200 ) ctrlsetText ((_this # 0) lbText (lbCurSel (_this # 0)))";
			onKeyDown = "_this spawn Enh_fnc_textureFinder_exportTexturePath";
		};
		class TexturePreview: ctrlStaticPictureKeepAspect
		{
			idc = 1200;
			x = 0.26375 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.459375 * safezoneW;
			h = 0.168 * safezoneH;
		};
		class Close: ctrlButtonClose
		{
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.1575 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Search: ctrlButtonSearch
		{
			x = 0.604999 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.13125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "if (call Enh_fnc_textureFinder_searchState) then {Enh_findTextures_handle = [] spawn Enh_fnc_textureFinder_findTextures}";
		};
		class ProgessText: ctrlStatic
		{
			idc = 1002;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.906 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Progress: ctrlProgress
		{
			idc = 1001;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.878 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};