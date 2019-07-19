#define DIALOG_W 160
#define DIALOG_H 111

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
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_textureFinder_header;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class TextureList: ctrlListbox
		{
			idc = 1500;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = 52 * GRID_H;
			onLBSelChanged = "((findDisplay 140000) displayCtrl 1200 ) ctrlsetText ((_this # 0) lbText (lbCurSel (_this # 0)))";
			onKeyDown = "_this spawn Enh_fnc_textureFinder_exportTexturePath";
		};
		class TexturePreview: ctrlStaticPictureKeepAspect
		{
			idc = 1200;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 58 * GRID_H;
			w = DIALOG_W * GRID_W;
			h = 40 * GRID_H;
			colorBackground[] = {1,1,1,1};
		};
		class ProgessText: ctrlStatic
		{
			idc = 1002;
			style = ST_CENTER;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 99 * GRID_H;
			w = DIALOG_W * GRID_W
			h = CTRL_DEFAULT_H;
		};
		class Progress: ctrlProgress
		{
			idc = 1001;
			x = CENTERED_X(DIALOG_W - 2);
			y = DIALOG_TOP + 104 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class UpdateList: ctrlButton
		{
			text = $STR_ENH_textureFinder_updateList;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 110 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "[] spawn Enh_fnc_textureFinder_fillTextureLB";
		};
		class Search: ctrlButtonSearch
		{
			x = CENTERED_X(DIALOG_W) + 32 * GRID_W;
			y = DIALOG_TOP + 110 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "if (call Enh_fnc_textureFinder_searchState) then {Enh_findTextures_handle = [] spawn Enh_fnc_textureFinder_findTextures}";
		};
		class Filter: ctrlToolbox
		{
			x = CENTERED_X(DIALOG_W) + 63 * GRID_W;
			y = DIALOG_TOP + 110 * GRID_H;
			w = 65 * GRID_W;
			h = CTRL_DEFAULT_H;
            rows = 1;
            columns = 3;
            strings[] = 
            {
                $STR_ENH_textureFinder_filterAll,
                $STR_ENH_textureFinder_filterJPG,
				$STR_ENH_textureFinder_filterPAA
            };
            values[] = {0,1,2};
			onLoad = "params ['_ctrl']; _ctrl lbSetCurSel 0; Enh_TextureFinder_Filter = 0";//Default value
			onToolBoxSelChanged  = "params ['_ctrl']; Enh_TextureFinder_Filter = lbCurSel _ctrl";
        };
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 129 * GRID_W;
			y = DIALOG_TOP + 110 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};

/*
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
			w = 0.49875 * safezoneW;
			h = 0.672 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_textureFinder_header;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.49875 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class ShowAll: ctrlButton
		{
			text = $STR_ENH_textureFinder_showAll;
			x = 0.257187 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.091875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "[] spawn Enh_fnc_textureFinder_fillTextureLB";
		};
		class TextureList: ctrlListbox
		{
			idc = 1500;
			x = 0.257187 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.378 * safezoneH;
			onLBSelChanged = "((findDisplay 140000) displayCtrl 1200 ) ctrlsetText ((_this # 0) lbText (lbCurSel (_this # 0)))";
			onKeyDown = "_this spawn Enh_fnc_textureFinder_exportTexturePath";
		};
		class TexturePreview: ctrlStaticPictureKeepAspect
		{
			idc = 1200;
			x = 0.257187 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.154 * safezoneH;
		};
		class Close: ctrlButtonClose
		{
			x = 0.454062 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.091875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Filter: ctrlToolbox
		{
			x = 0.5525 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.190312 * safezoneW;
			h = 0.028 * safezoneH;
            rows = 1;
            columns = 3;
            strings[] = 
            {
                "Show all",
                "Hide JPG",
				"Hide PAA"
            };
            values[] = {0,1,2};
			onLoad = "params ['_ctrl']; _ctrl lbSetCurSel 0; Enh_TextureFinder_Filter = 0";//Default value
			onToolBoxSelChanged  = "params ['_ctrl']; Enh_TextureFinder_Filter = lbCurSel _ctrl";
        };
		class Search: ctrlButtonSearch
		{
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.091875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "if (call Enh_fnc_textureFinder_searchState) then {Enh_findTextures_handle = [] spawn Enh_fnc_textureFinder_findTextures}";
		};
		class ProgessText: ctrlStatic
		{
			idc = 1002;
			x = 0.257187 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Progress: ctrlProgress
		{
			idc = 1001;
			x = 0.257187 * safezoneW + safezoneX;
			y = 0.78 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};