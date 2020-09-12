#define DIALOG_W 240
#define DIALOG_H 140

class ENH_InventoryManager
{
	idd = 80000;
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
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_IM_HEADER;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class AvailableItems: ctrlStatic
		{
			idc = 1000;
			text = $STR_ENH_IM_AVAILABLEITEMS;
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + 4 * CTRL_DEFAULT_H + GRID_H;
			w = 40 * GRID_W;
			h = CTRL_DEFAULT_H;
			font = FONT_BOLD;
			sizeEx = SIZEEX_PURISTA(SIZEEX_L);
		};
		class InventoryItems: AvailableItems
		{
			text = $STR_ENH_IM_ITEMSININVENTORY;
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
		};
		class InventoryListBackground: ctrlStaticPictureKeepAspect
		{
			idc = 2000;
			text = "";
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
			y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
			w = DIALOG_W * GRID_W  / 2 - 8 * GRID_W;
			h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
			colorText[] = {0.1,0.1,0.1,0.9};
		};
	};
	class Controls
	{
		class Filter: ctrlToolbox
		{
			idc = 2100;
			columns = 7;
			rows = 3;
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + GRID_H;
			w = DIALOG_W * GRID_W - 2 * GRID_W;
			h = 3 * CTRL_DEFAULT_H;
			strings[] = {"Assault Rifles","Machine Guns","Sniper Rifles","Shotguns","Submachine Guns","Launchers","Handguns","Grenades","Magazines","Mines","Bipods","Muzzles","Pointer","Scopes","Uniforms","Vests","Backpacks","Headgear","Glasses","NVGs","Items"};
			onToolBoxSelChanged = "_this call ENH_fnc_IM_filterList";
		};
		class AvailableItemsList: ctrlListbox
		{
			idc = 2200;
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
			w = DIALOG_W * GRID_W  / 2 - 7 * GRID_W;
			h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
			colorBackground[] = {1,0,0,0};
			onLBDblClick = "_this call ENH_fnc_IM_previewItem";
		};
		class InventoryItemsList: ctrlListNBox
		{
			idc = 2300;
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
			y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
			w = DIALOG_W * GRID_W  / 2 - 8 * GRID_W;
			h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
			columns[] = {0,0.08,0.8,0.88};
			onLBDblClick = "_this call ENH_fnc_IM_previewItem";
		};
		class AddOne: ctrlButton
		{
			idc = 2400;
			text = ">";
			tooltip = "+1";
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W - 5 * GRID_W;
			y = DIALOG_TOP + 10 * CTRL_DEFAULT_H;
			w = 10 * GRID_W;
			h = 2 * CTRL_DEFAULT_H;
			onButtonClick = "1 call ENH_fnc_IM_AddItem";
		};
		class AddTen: AddOne
		{
			idc = 2500;
			text = ">>";
			tooltip = "+10";
			y = DIALOG_TOP + 12 * CTRL_DEFAULT_H + GRID_W;
			onButtonClick = "10 call ENH_fnc_IM_AddItem";
		};
		class RemoveOne: AddOne
		{
			idc = 2600;
			text = "<";
			tooltip = "-1";
			y = DIALOG_TOP + 14 * CTRL_DEFAULT_H + 2 * GRID_W;
			onButtonClick = "1 call ENH_fnc_IM_RemoveItem";
		};
		class RemoveTen: AddOne
		{
			idc = 2700;
			text = "<<";
			tooltip = "-10";
			y = DIALOG_TOP + 16 * CTRL_DEFAULT_H + 3 * GRID_W;
			onButtonClick = "10 call ENH_fnc_IM_RemoveItem";
		};
		class RemoveAll: ctrlButton
		{
			idc = 2800;
			text = "<<<";
			tooltip = $STR_ENH_IM_REMOVESELECTED_TOOLTIP;
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W - 5 * GRID_W;
			y = DIALOG_TOP + 18 * CTRL_DEFAULT_H + 4 * GRID_W;
			w = 10 * GRID_W;
			h = 2 * CTRL_DEFAULT_H;
			onButtonClick = "call ENH_fnc_IM_clearInventory";
		};
		class ShowTemplates: ctrlButton
		{
			text = $STR_ENH_IM_SHOWTEMPLATES;
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_IM_showTemplates";
		};
		class CreateTemplate: ShowTemplates
		{
			idc = 2900;
			text = $STR_ENH_IM_CREATETEMPLATE;
			x = CENTERED_X(DIALOG_W) + GRID_W + 31 * GRID_W;
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_InventoryManager_TemplateData'";
		};
		class DeleteTemplate: ctrlButtonPictureKeepAspect
		{
			idc = 3000;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
			tooltip = $STR_ENH_IM_DELETETEMPLATE;
			x = CENTERED_X(DIALOG_W) + GRID_W + 62 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_IM_deleteTemplate";
			colorBackground[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
		};
		class ApplyTemplate: ShowTemplates
		{
			idc = 3100;
			text = $STR_ENH_IM_APPLYTEMPLATE;
			x = CENTERED_X(DIALOG_W) + GRID_W + 68 * GRID_W;
			onButtonClick = "_this call ENH_fnc_IM_applyTemplate";
		};
		class IsVirtualCheckbox: ctrlCheckbox
		{
			idc = 3200;
			x = CENTERED_X(DIALOG_W) + GRID_W + 112 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onCheckedChanged = "_this call ENH_fnc_IM_toggleVirtual";
		};
    class IsVirtualText: ctrlStatic
		{
			text = $STR_ENH_IM_ISVIRTUAL;
			x = CENTERED_X(DIALOG_W) + GRID_W + 116 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
    class Reset: ctrlButtonPictureKeepAspect
		{
			text = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
      tooltip = $STR_ENH_IM_RESET_TOOLTIP;
			x = CENTERED_X(DIALOG_W) + GRID_W + 135 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
      action = "call ENH_fnc_IM_resetStorage";
    };
		class FilterSearch: ctrlCombo
		{
			idc = 3300;
			x = CENTERED_X(DIALOG_W) + GRID_W + 141 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 5 * GRID_W;
		  h = CTRL_DEFAULT_H;
			onLBSelChanged = "_this call ENH_fnc_IM_onModFilterChanged";
		};
		class Search: ctrlEdit
		{
			idc = 3400;
			x = CENTERED_X(DIALOG_W) + GRID_W + 146 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 25 * GRID_W;
			h = CTRL_DEFAULT_H;
			onKeyUp = "_this call ENH_fnc_IM_Search";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc = 3500;
			x = CENTERED_X(DIALOG_W) + GRID_W + 171 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_IM_resetSearch";
		};
		class Ok: ctrlButtonOK
		{
			idc = -1;
			x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 63 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "[] call ENH_fnc_IM_ApplyAttribute";
		};
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 32 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};