class Enh_NameObjects
{
	idd = ENH_IDD_NAMEOBJECTS;
	onLoad = "call Enh_fnc_nameObjects_onLoad";
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
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_nameObjects_header;
			x = 0.375313 * safezoneW + safezoneX;
			y = 0.325 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RemoveNames: ctrlButton
		{
			text = $STR_ENH_nameObjects_removeName;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.535 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'UNNAME' call Enh_fnc_nameObjects_name";
		};
		class OK: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the dialog
			x = 0.539375 * safezoneW + safezoneX;
			y = 0.535 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_nameObjects_name";
		};
		class VariableName: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_variableName_displayName;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.367 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class IndexStart: ctrlStatic
		{
			text = $STR_ENH_nameObjects_startIndex;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.451 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class VariableNameValue: ctrlEdit
		{
			idc = 1000;
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.395 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class IndexStartValue: ctrlEdit
		{
			idc = 1100;
			text = "0";
			x = 0.381875 * safezoneW + safezoneX;
			y = 0.479 * safezoneH + safezoneY;
			w = 0.23625 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};