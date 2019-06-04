class Enh_BatchReplace
{
	idd = ENH_IDD_BATCHREPLACE;
	movingEnable = true;
	onLoad = "((_this # 0) displayCtrl 1400) ctrlSetText (profileNameSpace getVariable ['Enh_batchReplace_lastUsed','']); ctrlSetFocus ((_this # 0) displayCtrl 1400)";
	onUnload = "profileNameSpace setVariable ['Enh_batchReplace_lastUsed',ctrlText ((_this # 0) displayCtrl 1400)]";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.36 * safezoneH + safezoneY;
			w = 0.315 * safezoneW;
			h = 0.28 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_batchReplace_header;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.332 * safezoneH + safezoneY;
			w = 0.315 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Replace: ctrlButton
		{
			text = $STR_ENH_batchReplace_replace;
			x = 0.52625 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.124687 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_batchreplace";
		};
		class ReplaceWithValue: ctrlEditMulti
		{
			idc = 1400;
			tooltip = $STR_ENH_batchReplace_replaceWith_tooltip;
			x = 0.434375 * safezoneW + safezoneX;
			y = 0.444 * safezoneH + safezoneY;
			w = 0.216562 * safezoneW;
			h = 0.14 * safezoneH;
		};
		class ReplaceWithText: ctrlStatic
		{
			text = $STR_ENH_batchReplace_replaceWith;
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.444 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Description: ctrlStructuredText
		{
			text = $STR_ENH_batchReplace_description;
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.301875 * safezoneW;
			h = 0.056 * safezoneH;
		};
		class Close: ctrlButtonClose
		{
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.598 * safezoneH + safezoneY;
			w = 0.124687 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};