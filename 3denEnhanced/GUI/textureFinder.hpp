#define DIALOG_W 160
#define DIALOG_H 110

class ENH_TextureFinder
{
	idd = ENH_IDD_TEXTUREFINDER;
	movingEnable = true;
	onLoad = "[] spawn ENH_fnc_textureFinder_findTextures";
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
			text = $STR_ENH_TEXTUREFINDER;
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
			onLBSelChanged = "_this call ENH_fnc_textureFinder_showTexture";
			onKeyDown = "_this call ENH_fnc_textureFinder_exportTexturePath";
		};
		class ProgressList: ctrlProgress
		{
			idc = 1800;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H + 52 * GRID_H;
			w = (DIALOG_W) * GRID_W;
			h = GRID_H;
			colorFrame[] = {0,0,0,0};
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
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Progress: ctrlProgress
		{
			idc = 1001;
			x = CENTERED_X(DIALOG_W - 2);
			y = DIALOG_TOP + 103 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
			colorFrame[] = {0,0,0,0};
		};
		class UpdateList: ctrlButton
		{
			idc = 1900;
			text = $STR_ENH_TEXTUREFINDER_UPDATELIST;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 109 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "[] spawn ENH_fnc_textureFinder_fillTextureLB";
		};
		class SearchTextBox: ctrlEdit
		{
			idc = 1600;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 59 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SearchButton: ctrlButtonSearch
		{
			idc = 1700;
			x = CENTERED_X(DIALOG_W) + 31 * GRID_W;
			y = DIALOG_TOP + 59 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_textureFinder_search";
		};
		class Filter: ctrlToolbox
		{
			idc = 2000;
			x = CENTERED_X(DIALOG_W) + 63 * GRID_W;
			y = DIALOG_TOP + 109 * GRID_H;
			w = 65 * GRID_W;
			h = CTRL_DEFAULT_H;
            rows = 1;
            columns = 3;
            strings[] = 
            {
                $STR_ENH_TEXTUREFINDER_FILTERALL,
                $STR_ENH_TEXTUREFINDER_FILTERJPG,
				$STR_ENH_TEXTUREFINDER_FILTERPAA
            };
            values[] = {0,1,2};
			onLoad = "params ['_ctrl']; _ctrl lbSetCurSel 0; ENH_TextureFinder_Filter = 0";//Default value
			onToolBoxSelChanged  = "params ['_ctrl']; ENH_TextureFinder_Filter = lbCurSel _ctrl; [] spawn ENH_fnc_textureFinder_fillTextureLB";
        };
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 129 * GRID_W;
			y = DIALOG_TOP + 109 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};