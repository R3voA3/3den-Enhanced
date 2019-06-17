#define DIALOG_W 160
#define DIALOG_H 95

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
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_tools_ScenarioAttributesManager;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Templates: ctrlStatic
		{
			text = $STR_ENH_scenarioAttributesManager_templates;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 7 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Attributes: ctrlStatic
		{
			text = $STR_ENH_scenarioAttributesManager_attributes;
			x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
			y = DIALOG_TOP + 7 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class CreateTemplate: ctrlButton
		{
			text = $STR_ENH_scenarioAttributesManager_createTemplate;
			x = CENTERED_X(DIALOG_W) + 98 * GRID_W;
			y = DIALOG_TOP + 7 * GRID_H;
			w = 60 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'Enh_ScenarioAttributesManagerTemplateData'";
		};
		class TemplateList: ctrlListbox
		{
			idc = 1501;
			x = CENTERED_X(DIALOG_W - 4);
			y = DIALOG_TOP + 14 * GRID_H;
			w = 50 * GRID_W;
			h = 70 * GRID_H;
			onLBSelChanged = "_this call Enh_fnc_scenarioAttributesManager_loadTemplate";
		};
		class AttributeList: ctrlTree
		{
			idc = 1500;
			idcSearch = 1400;
			x = CENTERED_X(DIALOG_W) + 54 * GRID_W;
			y = DIALOG_TOP + 14 * GRID_H;
			w = 104 * GRID_W;
			h = 70 * GRID_H;
		};

		class DeleteTemplate: ctrlButton
		{
			text = $STR_ENH_scenarioAttributesManager_deleteTemplate;
			x = CENTERED_X(DIALOG_W - 4);
			y = DIALOG_TOP + 86 * GRID_H;
			w = 50 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_deleteTemplate";
		};
		class ApplyTemplate: ctrlButton
		{
			text = $STR_ENH_scenarioAttributesManager_applyTemplate;
			x = CENTERED_X(DIALOG_W - 4);
			y = DIALOG_TOP + 93 * GRID_H;
			w = 50 * GRID_W;
			h = CTRL_DEFAULT_H;
			tooltip = "Applies currently selected Template to this mission. Action can be undone with the Eden undo button.";
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_applyTemplate";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_scenarioAttributesManager_export;
			x = CENTERED_X(DIALOG_W) + 54 * GRID_W;
			y = DIALOG_TOP + 93 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_exportToClipboard";
		};
		class Search: ctrlEdit
		{
			idc = 1400;
			x = CENTERED_X(DIALOG_W) + 54 * GRID_W;
			y = DIALOG_TOP + 86 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = CENTERED_X(DIALOG_W) + 79 * GRID_W;
			y = DIALOG_TOP + 86 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Collapse: ctrlButtonCollapseAll
		{
			x = CENTERED_X(DIALOG_W) + 84 * GRID_W;
			y = DIALOG_TOP + 86 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Expand: ctrlButtonExpandAll
		{
			x = CENTERED_X(DIALOG_W) + 89* GRID_W;
			y = DIALOG_TOP + 86 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class ApplyAttribute: ctrlButton
		{
			text = $STR_ENH_scenarioAttributesManager_applyAttribute;
			x = CENTERED_X(DIALOG_W) + 81 * GRID_W;
			y = DIALOG_TOP + 93 * GRID_H;
			w = 40 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_applyAttribute";
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 133 * GRID_W;
			y = DIALOG_TOP + 93 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};

/*class Enh_ScenarioAttributesManager
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
			colorBackground[] = {COLOUR_USER_PRESET};
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
		class ApplyAttribute: ctrlButton
		{
			text = "STR_ENH_ScenarioAttributesManager_applyAttribute";
			x = 0.534995‬ * safezoneW + safezoneX;
			y = 0.85 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_applyAttribute";
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