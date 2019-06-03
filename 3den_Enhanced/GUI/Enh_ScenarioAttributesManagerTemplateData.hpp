class Enh_ScenarioAttributesManagerTemplateData
{
	idd = ENH_IDD_SCENARIOATTRIBUTESMANAGERTEMPLATEDATA;
	movingEnable = true;
	enableSimulation = true;
	onLoad = "Enh_ScenarioAttributesManager_TemplateTitle = ''; Enh_ScenarioAttributesManager_TemplateDescription = '';";
	onUnload = "";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.252 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Title: ctrlStatic
		{
			text = $STR_ENH_ScenarioAttributesManagerTemplateData_title;
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.12 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Description: ctrlStatic
		{
			text = $STR_ENH_ScenarioAttributesManagerTemplateData_description;
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.12 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TitleValue: ctrlEdit
		{
			idc = 1400;
			x = 0.401562 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DescriptionValue: ctrlEdit
		{
			idc = 1401;
			x = 0.401562 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.196875 * safezoneW;
			h = 0.056 * safezoneH;
		};
		class Cancel: ctrlButtonCancel
		{
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.584 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class OK: ctrlButtonOK
		{
			x = 0.526249 * safezoneW + safezoneX;
			y = 0.584 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_createTemplate";
		};
	};
};