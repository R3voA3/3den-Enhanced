#define DIALOG_W 50
#define DIALOG_H 70

class Enh_Credits
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this call Enh_fnc_credits_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H + 7 * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_about_credits;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class List: ctrlListbox
		{
			idc = 1000;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = DIALOG_W * GRID_W - 2 * GRID_W;
			h = DIALOG_H * GRID_H - 1 * GRID_H;
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 29 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};

/*class Enh_Credits
{
	idd = -1;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.504 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_credits_header;
			x = 0.395 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class List: ctrlListbox
		{
			idc = 1000;
			x = 0.408125 * safezoneW + safezoneX;
			y = 0.29 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.448 * safezoneH;
		};
		class Close: ctrlButtonClose
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};

/* #define PIXEL_GRID_X	(safezoneX)
#define PIXEL_GRID_Y	(safezoneY)
#define PIXEL_GRID_W	(pixelGrid * pixelW * 0.5)
#define PIXEL_GRID_H	(pixelGrid * pixelH * 0.5)

class Enh_Credits
{
	idd = -1;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 126 * PIXEL_GRID_W + PIXEL_GRID_X;
			y = 45 * PIXEL_GRID_H + PIXEL_GRID_Y;
			w = 72 * PIXEL_GRID_W;
			h = 86 * PIXEL_GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_credits_header;
			x = 126 * PIXEL_GRID_W + PIXEL_GRID_X;
			y = 40 * PIXEL_GRID_H + PIXEL_GRID_Y;
			w = 72 * PIXEL_GRID_W;
			h = 5 * PIXEL_GRID_H;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class List: ctrlListbox
		{
			idc = 1000;
			x = 128 * PIXEL_GRID_W + PIXEL_GRID_X;
			y = 47 * PIXEL_GRID_H + PIXEL_GRID_Y;
			w = 68 * PIXEL_GRID_W;
			h = 82 * PIXEL_GRID_H;
		};
		class Close: ctrlButtonClose
		{
			x = 126 * PIXEL_GRID_W + PIXEL_GRID_X;
			y = 131 * PIXEL_GRID_H + PIXEL_GRID_Y;
			w = 72 * PIXEL_GRID_W;
			h = 5 * PIXEL_GRID_H;
		};
	};
};
 */