class Enh_GarrisonBuildings
{
	idd = 90000;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_IGUIBack
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.252 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_RscText
		{
			text = $STR_ENH_garrison_header;
			x = 0.395 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class RadiusText: Enh_RscText
		{
			text = $STR_ENH_garrison_radius;
			x = 0.408125 * safezoneW + safezoneX;
			y = 0.29 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RadiusValue: Enh_RscEdit
		{
			idc = 1000;
			x = 0.408125 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			onLoad = "(_this select 0) ctrlSetText (profileNamespace getVariable ['Enh_garrisonBuildings_lastRadius','500'])";
		};
		class CoverageText: Enh_RscText
		{
			text = $STR_ENH_garrison_coverage;
			x = 0.408125 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class CoverageValue: Enh_RscCombo
		{
			idc = 1100;
			x = 0.408125 * safezoneW + safezoneX;
			y = 0.402 * safezoneH + safezoneY;
			w = 0.18375 * safezoneW;
			h = 0.028 * safezoneH;
			onLoad = "{(_this select 0) lbAdd _x} forEach ['100%','75%','30%','25%']; {(_this select 0) lbSetValue [_forEachIndex,_x]} forEach [1,2,3,5];\
			(_this select 0) lbSetCurSel (profileNamespace getVariable ['Enh_garrisonBuildings_lastCoverage',1])";
		};
		class Close: Enh_RscButton
		{
			text = $STR_ENH_garrison_close;
			x = 0.408125 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "(findDisplay 90000) closeDisplay 0";
		};
		class Confirm: Enh_RscButton
		{
			text = $STR_ENH_nameObjects_OK;
			x = 0.52625 * safezoneW + safezoneX;
			y = 0.458 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_garrisonNearest";
		};
	};
};