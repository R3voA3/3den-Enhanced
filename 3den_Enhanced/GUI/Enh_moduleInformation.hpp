class Enh_ModuleInformation
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
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class DescriptionText: ctrlStatic
		{
			text = $STR_ENH_moduleInformation_description;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DescriptionValue: Enh_StructuredText
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
		class PositionValue: Enh_StructuredText
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
		class DuplicateValue: Enh_StructuredText
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
		class DirectionValue: Enh_StructuredText
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
		class SyncValue: Enh_StructuredText
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
	};
};