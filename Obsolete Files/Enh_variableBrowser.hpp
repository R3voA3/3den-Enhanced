class Enh_VariableBrowser
{
	idd = 180000;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
        class Background: Enh_Background
        {
            idc = 2200;
            x = 1 * GUI_GRID_W + GUI_GRID_X;
            y = 2 * GUI_GRID_H + GUI_GRID_Y;
            w = 38 * GUI_GRID_W;
            h = 22 * GUI_GRID_H;
        };
		class Header: Enh_Text
        {
            idc = 1000;
            text = "Variable Browser"; //--- ToDo: Localize;
            x = 0.250625 * safezoneW + safezoneX;
            y = 0.178 * safezoneH + safezoneY;
            w = 0.49875 * safezoneW;
            h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
        };
		class Warning: Enh_StructuredText
        {
            text = "WARNING: Deleting variables can cause scripts, missions and other content to not work properly. Always backup your profile before manipulating profilnamespace variables."; //--- ToDo: Localize;
            x = 0.26375 * safezoneW + safezoneX;
            y = 0.514 * safezoneH + safezoneY;
            w = 0.4725 * safezoneW;
            h = 0.056 * safezoneH;
			colorBackground[] = {0.946,0.121,0,1};
        };
		class Value: Enh_StructuredText
        {
            idc = 1100;
            x = 0.26375 * safezoneW + safezoneX;
            y = 0.598 * safezoneH + safezoneY;
            w = 0.4725 * safezoneW;
            h = 0.14 * safezoneH;
        };
		class Controls 
		{
			class List: Enh_ListBox
			{
				idc = 1500;
				x = 0.26375 * safezoneW + safezoneX;
				y = 0.234 * safezoneH + safezoneY;
				w = 0.4725 * safezoneW;
				h = 0.252 * safezoneH;
			};
			class Copy: Enh_Button
			{
				idc = 1600;
				text = "Copy Value"; //--- ToDo: Localize;
				x = 0.26375 * safezoneW + safezoneX;
				y = 0.766 * safezoneH + safezoneY;
				w = 0.091875 * safezoneW;
				h = 0.028 * safezoneH;
			};
			class Close: Enh_Button
			{
				idc = 0;
				text = "Close"; //--- ToDo: Localize;
				x = 0.644375 * safezoneW + safezoneX;
				y = 0.766 * safezoneH + safezoneY;
				w = 0.091875 * safezoneW;
				h = 0.028 * safezoneH;
			};
		};
    };
};