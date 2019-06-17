class Enh_ScenarioAttributesManagerTemplateData
{
	idd = -1;
	movingEnable = true;
	enableSimulation = true;
	onLoad = "Enh_ScenarioAttributesManager_TemplateTitle = ''; Enh_ScenarioAttributesManager_TemplateDescription = '';";
	onUnload = "";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(60);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = 60 * GRID_W;
			h = 57 * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			x = CENTERED_X(60);
			y = DIALOG_TOP;
			w = 60 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Title: ctrlStatic
		{
			text = $STR_ENH_ScenarioAttributesManagerTemplateData_title;
			x = CENTERED_X(60);
			y = DIALOG_TOP + 7 * GRID_H;
			w = 56 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class TitleValue: ctrlEdit
		{
			idc = 1400;
			x = CENTERED_X(60) + 2 * GRID_W;
			y = DIALOG_TOP + 14 * GRID_H;
			w = 56 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Description: ctrlStatic
		{
			text = $STR_ENH_ScenarioAttributesManagerTemplateData_description;
			x = CENTERED_X(60) + 2 * GRID_W;
			y = DIALOG_TOP + 21 * GRID_H;
			w = 56 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class DescriptionValue: ctrlEditMulti
		{
			idc = 1401;
			x = CENTERED_X(60) + 2 * GRID_W;
			y = DIALOG_TOP + 28 * GRID_H;
			w = 56 * GRID_W;
			h = 2CTRL_DEFAULT_H;
		};
		class Cancel: ctrlButtonCancel
		{
			x = CENTERED_X(60) + 33 * GRID_W;
			y = DIALOG_TOP + 5CTRL_DEFAULT_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class OK: ctrlButtonOK
		{
			x = CENTERED_X(60) + 2 * GRID_W;
			y = DIALOG_TOP + 5CTRL_DEFAULT_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_createTemplate";
		};
	};
};