#define DIALOG_W 160
#define DIALOG_H 90

class ENH_ScenarioAttributesManager
{
	idd = ENH_IDD_SCENARIOATTRIBUTESMANAGER;
	movingEnable = true;
	onLoad = "_this call ENH_fnc_scenarioAttributesManager_onLoad";
	onUnload = "_this call ENH_fnc_scenarioAttributesManager_onUnload";
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
			text = $STR_ENH_TOOLS_SCENARIOATTRIBUTESMANAGER;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Templates: ctrlStatic
		{
			text = $STR_ENH_SCENARIOATTRIBUTESMANAGER_TEMPLATES;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 6 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Attributes: ctrlStatic
		{
			text = $STR_ENH_SCENARIOATTRIBUTESMANAGER_ATTRIBUTES;
			x = CENTERED_X(DIALOG_W) + 51 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class CreateTemplate: ctrlButton
		{
			text = $STR_ENH_SCENARIOATTRIBUTESMANAGER_CREATETEMPLATE;
			x = CENTERED_X(DIALOG_W) + 98 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = 61 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_ScenarioAttributesManagerTemplateData'";
		};
		class TemplateList: ctrlListbox
		{
			idc = 1501;
			x = CENTERED_X(DIALOG_W - 2);
			y = DIALOG_TOP + 12 * GRID_H;
			w = 50 * GRID_W;
			h = 70 * GRID_H;
			onLBSelChanged = "_this call ENH_fnc_scenarioAttributesManager_loadTemplate";
		};
		class AttributeList: ctrlTree
		{
			idc = 1500;
			idcSearch = 1400;
			x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
			y = DIALOG_TOP + 12 * GRID_H;
			w = 107 * GRID_W;
			h = 70 * GRID_H;
		};

		class DeleteTemplate: ctrlButton
		{
			text = $STR_ENH_SCENARIOATTRIBUTESMANAGER_DELETETEMPLATE;
			x = CENTERED_X(DIALOG_W - 2);
			y = DIALOG_TOP + 83 * GRID_H;
			w = 50 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_scenarioAttributesManager_deleteTemplate";
		};
		class ApplyTemplate: ctrlButton
		{
			text = $STR_ENH_SCENARIOATTRIBUTESMANAGER_APPLYTEMPLATE;
			x = CENTERED_X(DIALOG_W - 2);
			y = DIALOG_TOP + 89 * GRID_H;
			w = 50 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_scenarioAttributesManager_applyTemplate";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_SCENARIOATTRIBUTESMANAGER_EXPORT;
			x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
			y = DIALOG_TOP + 89 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_scenarioAttributesManager_exportToClipboard";
		};
		class Search: ctrlEdit
		{
			idc = 1400;
			x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
			y = DIALOG_TOP + 83 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = CENTERED_X(DIALOG_W) + 77 * GRID_W;
			y = DIALOG_TOP + 83 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Collapse: ctrlButtonCollapseAll
		{
			x = CENTERED_X(DIALOG_W) + 82 * GRID_W;
			y = DIALOG_TOP + 83 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Expand: ctrlButtonExpandAll
		{
			x = CENTERED_X(DIALOG_W) + 87 * GRID_W;
			y = DIALOG_TOP + 83 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class ApplyAttribute: ctrlButton
		{
			text = $STR_ENH_SCENARIOATTRIBUTESMANAGER_APPLYATTRIBUTE;
			x = CENTERED_X(DIALOG_W) + 78 * GRID_W;
			y = DIALOG_TOP + 89 * GRID_H;
			w = 40 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_scenarioAttributesManager_applyAttribute";
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 134 * GRID_W;
			y = DIALOG_TOP + 89 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};