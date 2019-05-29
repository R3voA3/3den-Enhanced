class Enh_NameObjects
{
	idd = ENH_NAMEOBJECTS;
	movingEnable = true;
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.375313 * safezoneW + safezoneX;
			y = 0.353 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.224 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = $STR_ENH_nameObjects_header;
			x = 0.375313 * safezoneW + safezoneX;
			y = 0.325 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class RemoveNames: Enh_Button
		{
			text = $STR_ENH_nameObjects_removeName;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.535 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'UNNAME' call Enh_fnc_nameObjects";
		};
		class OK: Enh_Button
		{
			text = $STR_ENH_nameObjects_OK;
			x = 0.5525 * safezoneW + safezoneX;
			y = 0.535 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_nameObjects";
		};
		class VariableName: Enh_Text
		{
			text = $STR_ENH_briefingEditor_variableName_displayName;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.367 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class IndexStart: Enh_Text
		{
			text = $STR_ENH_nameObjects_startIndex;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.451 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class VariableNameValue: Enh_Edit
		{
			idc = 1000;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.395 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
			onLoad = "(_this # 0) ctrlSetText (profileNamespace getVariable ['Enh_nameObjects_lastVarName',profileName])";
		};
		class IndexStartValue: Enh_Edit
		{
			idc = 1100;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.479 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
			onLoad = "(_this # 0) ctrlSetText (profileNamespace getVariable ['Enh_nameObjects_lastIndex','0'])";
		};
	};
};