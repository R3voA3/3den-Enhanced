class Enh_Credits
{
	idd = 200000;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_Background
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.504 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = $STR_ENH_credits_header;
			x = 0.395 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Close: Enh_Button
		{
			idc = 1;
			text = $STR_ENH_briefingEditor_close_displayName;
			x = 0.395 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class List: Enh_ListBox
		{
			idc = 1000;
			x = 0.408125 * safezoneW + safezoneX;
			y = 0.29 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.448 * safezoneH;
		};
	};
};