class Enh_TextureFinder
{
	idd = ENH_TEXTUREFINDER;
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
		class Header: Enh_Text
		{
			text = $STR_ENH_textureFinder_header;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class ShowAll: Enh_Button
		{
			text = $STR_ENH_textureFinder_showAll;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.028 * safezoneH;
			action = "[] spawn Enh_fnc_textureFinder_fillTextureLB";
		};
		class TextureList: Enh_ListBox
		{
			idc = 1500;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.42 * safezoneH;
			onLBSelChanged = "((findDisplay 140000) displayCtrl 1200 ) ctrlsetText ((_this select 0) lbText (lbCurSel (_this select 0)))";
			onKeyDown = "_this spawn Enh_fnc_textureFinder_exportTexturePath";
		};
		class TexturePreview: Enh_Picture
		{
			idc = 1200;
			x = 0.26375 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.459375 * safezoneW;
			h = 0.168 * safezoneH;
			text = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
		};
		class Close: Enh_Button
		{
			idc = 1;
			text = $STR_ENH_textureFinder_close;
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.1575 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Search: Enh_Button
		{
			text = $STR_ENH_textureFinder_searchTextures;
			x = 0.604999 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.13125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "if (call Enh_fnc_textureFinder_searchState) then {Enh_findTextures_handle = [] spawn Enh_fnc_textureFinder_findTextures}";
		};
		class ProgessText: Enh_Text
		{
			idc = 1002;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.906 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RscProgress
		{
			idc = 1001;
			type = 8;
			style = 0;
			colorFrame[] = {0.2,0.2,0.2,0.8};
			colorBar[] = COLOUR_USER_PRESET;
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.878 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};

/* #Kypafa
$[
	1.063,
	["test",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[-2200,"",[1,"",["0.250625 * safezoneW + safezoneX","0.178 * safezoneH + safezoneY","0.485625 * safezoneW","0.644 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"Header",[1,"Texture Finder",["0.250625 * safezoneW + safezoneX","0.15 * safezoneH + safezoneY","0.485625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"ShowAll",[1,"Show All",["0.250625 * safezoneW + safezoneX","0.822 * safezoneH + safezoneY","0.144375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1500,"",[1,"",["0.250625 * safezoneW + safezoneX","0.178 * safezoneH + safezoneY","0.485625 * safezoneW","0.42 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1200,"",[1,"#(argb,8,8,3)color(1,1,1,1)",["0.26375 * safezoneW + safezoneX","0.626 * safezoneH + safezoneY","0.459375 * safezoneW","0.168 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1603,"",[1,"Close",["0.42125 * safezoneW + safezoneX","0.822 * safezoneH + safezoneY","0.1575 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1604,"HidePreviews",[1,"Hide Editor Previews",["0.604999 * safezoneW + safezoneX","0.822 * safezoneH + safezoneY","0.13125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/