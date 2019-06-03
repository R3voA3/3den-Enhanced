class Enh_ScenarioAttributesManager
{
	idd = ENH_IDD_SCENARIOATTRIBUTESMANAGER;
	movingEnable = true;
	enableSimulation = true;
	onLoad = "_this call Enh_fnc_scenarioAttributesManager_onLoad";
	onUnload = "_this call Enh_fnc_scenarioAttributesManager_onUnload";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.525 * safezoneW;
			h = 0.714 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_ScenarioAttributesManager;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.525 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class TemplateList: ctrlListbox
		{
			idc = 1501;
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.56 * safezoneH;
			onLBSelChanged = "_this call Enh_fnc_scenarioAttributesManager_loadTemplate";
		};
		class AttributeList: ctrlTree
		{
			idc = 1500;
			idcSearch = 1400;
			x = 0.414686 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.34125 * safezoneW;
			h = 0.56 * safezoneH;
			onTreeDblClick = "_this call Enh_fnc_scenarioAttributesManager_applyAttribute";
		};
		class Templates: ctrlStatic
		{
			text = $STR_ENH_ScenarioAttributesManager_templates;
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Attributes: ctrlStatic
		{
			text = $STR_ENH_ScenarioAttributesManager_attributes;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.0590625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DeleteTemplate: ctrlButton
		{
			text = $STR_ENH_ScenarioAttributesManager_deleteTemplate;
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_deleteTemplate";
		};
		class CreateTemplate: ctrlButton
		{
			text = $STR_ENH_ScenarioAttributesManager_createTemplate;
			x = 0.5525 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.203437 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'Enh_ScenarioAttributesManagerTemplateData'";
		};
		class ApplyTemplate: ctrlButton
		{
			text = $STR_ENH_ScenarioAttributesManager_applyTemplate;
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.85 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.028 * safezoneH;
			tooltip = "Applies currently selected Template to this mission. Action can be undone with the Eden undo button.";
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_applyTemplate";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_ScenarioAttributesManager_export;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.85 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_exportToClipboard";
		};
		class Search: ctrlEdit
		{
			idc = 1400;
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = 0.486875 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Collapse: ctrlButtonCollapseAll
		{
			x = 0.513125 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Expand: ctrlButtonExpandAll
		{
			x = 0.5 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Close: ctrlButtonClose
		{
			x = 0.68375 * safezoneW + safezoneX;
			y = 0.85 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};