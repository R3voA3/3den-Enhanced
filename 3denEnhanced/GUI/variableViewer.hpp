#define DIALOG_W 170
#define DIALOG_H 120

class ENH_VariableViewer
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this call ENH_fnc_variableViewer_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H + 7 * GRID_H;
		};
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_VARIABLEVIEWER_HEADER;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VariableNameHeader: ctrlStaticFooter
		{
			text = $STR_ENH_VARIABLEVIEWER_VARIABLENAME;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 5 * GRID_H;
			w = 69 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VariableValueHeader: ctrlStaticFooter
		{
			text = $STR_ENH_VARIABLEVIEWER_VARIABLEVALUE;
			x = CENTERED_X(DIALOG_W) + 69 * GRID_W;
			y = DIALOG_TOP + 5 * GRID_H;
			w = 76 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VariableTypeHeader: ctrlStaticFooter
		{
			text = $STR_ENH_VARIABLEVIEWER_VARIABLETYPE;
			x = CENTERED_X(DIALOG_W) + 145 * GRID_W;
			y = DIALOG_TOP + 5 * GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
	class Controls
	{
		class List: ctrlListNBox
		{
			idc = 1000;
			style = LB_MULTI + LB_TEXTURES;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 12 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = (DIALOG_H - 15) * GRID_H;
			disableOverflow = true;
			columns[] = {-0.008,0.4,0.85};//Create columns and move first column a tat to the left
			onLBSelChanged = "_this call ENH_fnc_variableViewer_onLNBSelChanged";
		};
		class Progress: ctrlProgress
		{
			idc = 7000;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = (DIALOG_TOP + DIALOG_H - 12) * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = GRID_H;
			colorFrame[] = {0,0,0,0};
		};
		class Namespace: ctrlCombo
		{
			idc = 4000;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 35 * GRID_W;
			h = CTRL_DEFAULT_H;
			onLBSelChanged = "_this call ENH_fnc_variableViewer_onFilterChanged";
		};
		class VariableCount: ctrlStatic
		{
			idc = 3000;
			x = CENTERED_X(DIALOG_W) + 37 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SearchEdit: ctrlEdit
		{
			idc = 2000;
			x = CENTERED_X(DIALOG_W) + 47 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SearchButton: ctrlButtonSearch
		{
			idc = 6000;
			x = CENTERED_X(DIALOG_W) + 67 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_variableViewer_onSearch";
		};
		class HideFunctionsText: ctrlStatic
		{
			text = $STR_ENH_VARIABLEVIEWER_HIDEFUNCTIONS;
			x = CENTERED_X(DIALOG_W) + 73 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 28 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class HideFunctions: ctrlCheckbox
		{
			idc = 9000;
			x = CENTERED_X(DIALOG_W) + 100 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 5 * GRID_W;
			h = 5 * GRID_H;
			onCheckedChanged = "_this call ENH_fnc_variableViewer_hideFunctions";
		};
		class VariableName: ctrlEdit
		{
			idc = 8000;
			text = $STR_ENH_VARIABLEVIEWER_VARIABLENAME;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H) * GRID_H;
			w = 45 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VariableValue: ctrlEdit
		{
			idc = 5000;
			text = $STR_ENH_VARIABLEVIEWER_VARIABLEVALUE;
			x = CENTERED_X(DIALOG_W) + 47 * GRID_W;
			y = DIALOG_TOP + (DIALOG_H) * GRID_H;
			w = 122 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Delete: ctrlButton
		{
			text = $STR_ENH_VARIABLEVIEWER_DELETE;
			x = CENTERED_X(DIALOG_W) + (DIALOG_W - 63) * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this spawn ENH_fnc_variableViewer_delete";
		};
		class Set: ctrlButton
		{
			idc = 10000;
			text = $STR_ENH_VARIABLEVIEWER_SET_NEW;
			x = CENTERED_X(DIALOG_W) + (DIALOG_W - 42) * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this spawn ENH_fnc_variableViewer_setOrCreate";
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + (DIALOG_W - 21) * GRID_W;
			y = DIALOG_TOP + (DIALOG_H + 6) * GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};