#define DIALOG_W 100
#define DIALOG_H 94

class Enh_ModuleInformation
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this call Enh_fnc_moduleInformation_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 5 * GRID_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_moduleInformation_header;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = 5 * GRID_H;
		};
		class Description: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_description;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 7 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 5 * GRID_H;
		};
		class DescriptionValue: ctrlEditMulti
		{
			idc = 1400;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 12 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 20 * GRID_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Position: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_position;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 34 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 5 * GRID_H;
		};
		class PositionValue: ctrlEditMulti
		{
			idc = 1401;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 39 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 10 * GRID_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Duplicate: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_duplicate;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 51 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 5 * GRID_H;
		};
		class DuplicateValue: ctrlEditMulti
		{
			idc = 1402;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 56 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 5 * GRID_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Direction: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_direction;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 61 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 5 * GRID_H;
		};
		class DirectionValue: ctrlEditMulti
		{
			idc = 1403;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 66 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 5 * GRID_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Sync : ctrlStatic
		{
			text = $STR_ENH_moduleInformation_sync;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 73 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 5 * GRID_H;
		};
		class SyncValue: ctrlEditMulti
		{
			idc = 1404;
			x = CENTERED_X(DIALOG_W) + 2 * GRID_W;
			y = DIALOG_TOP + 80 * GRID_H;
			w = (DIALOG_W - 4) * GRID_W;
			h = 10 * GRID_H;
			ColorBackground[] = {COLOR_OVERLAY_RGBA};
			canModify = false;
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 75 * GRID_W;
			y = DIALOG_TOP + 92 * GRID_H;
			w = 23 * GRID_W;
			h = 5 * GRID_H;
		};
	};
};
/*class Enh_ModuleInformation
{
	idd = ENH_IDD_MODULEINFORMATION;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_moduleInformation";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.206 * safezoneH + safezoneY;
			w = 0.354375 * safezoneW;
			h = 0.6165 * safezoneH;
		};
	};
	class Controls
	{
		class Headline: ctrlStaticTitle
		{
			text = $STR_ENH_moduleInformation_header;
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.354375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class DescriptionText: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_description;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DescriptionValue: ctrlEditMulti
		{
			idc = 1400;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.168 * safezoneH;
		};
		class PositionText: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_position;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.542 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PositionValue: ctrlEditMulti
		{
			idc = 1401;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DuplicateText: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_duplicate;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DuplicateValue: ctrlEditMulti
		{
			idc = 1402;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DirectionText: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_direction;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DirectionValue: ctrlEditMulti
		{
			idc = 1403;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SyncText : ctrlStatic
		{
			text = $STR_ENH_moduleInformation_sync;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.71 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SyncValue: ctrlEditMulti
		{
			idc = 1404;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.738 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Close: ctrlButtonClose
		{
			x = 0.329375 * safezoneW + safezoneX;
			y = 0.794 * safezoneH + safezoneY;
			w = 0.354375 * safezoneW;
			h = 0.028 * safezoneH;
			default = 1;
		};
		class FrameDescription: ctrlStaticFrame
		{
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.196 * safezoneH;
		};
		class FrameDirection: ctrlStaticFrame
		{
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.056 * safezoneH;
		};
		class FramePosition: ctrlStaticFrame
		{
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.542 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.056 * safezoneH;
		};
		class FrameDuplication: ctrlStaticFrame
		{
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.626 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.056 * safezoneH;
		};
		class FrameSync: ctrlStaticFrame
		{
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.71 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.056 * safezoneH;
		};
	};
};