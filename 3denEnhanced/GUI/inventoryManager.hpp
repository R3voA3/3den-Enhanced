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
			text = "3den Enhanced Inventory Manager"; //--- ToDo: Localize;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class AvailableItems: ctrlStatic
		{
			idc = 1000;
			text = "Available Items"; //--- ToDo: Localize;
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + 4 * CTRL_DEFAULT_H + GRID_H;
			w = 40 * GRID_W;
			h = CTRL_DEFAULT_H;
			font = FONT_BOLD;
			sizeEx = SIZEEX_PURISTA(SIZEEX_L);
		};
		class InventoryItems: AvailableItems
		{
			text = "Items in Inventory"; //--- ToDo: Localize;
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
			idc = 1500;
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
			w = DIALOG_W * GRID_W  / 2 - 7 * GRID_W;
			h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
			colorBackground[] = {1,0,0,0};
			onLBDblClick = "_this call ENH_fnc_IM_previewItem";
		};
		class InventoryItemsList: ctrlListNBox
		{
			idc = 1501;
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W + 6 * GRID_W;
			y = DIALOG_TOP + 5 * CTRL_DEFAULT_H + GRID_H;
			w = DIALOG_W * GRID_W  / 2 - 8 * GRID_W;
			h = DIALOG_H * GRID_H - 6 * CTRL_DEFAULT_H + 2 * GRID_H;
			columns[] = {0,0.061,0.8,0.88};	
			onLBDblClick = "_this call ENH_fnc_IM_previewItem";	
		};
		class AddOne: ctrlButton
		{
			idc = 100;
			text = ">";
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W - 5 * GRID_W;
			y = DIALOG_TOP + 10 * CTRL_DEFAULT_H;
			w = 10 * GRID_W;
			h = 2 * CTRL_DEFAULT_H;
			onButtonClick = "[_this # 0,1] call ENH_fnc_IM_AddItem";
		};
		class AddTen: AddOne
		{
			idc = 110;
			text = ">>";
			y = DIALOG_TOP + 12 * CTRL_DEFAULT_H + GRID_W;
			onButtonClick = "[_this # 0,10] call ENH_fnc_IM_AddItem";
		};
		class RemoveOne: AddOne
		{
			idc = 120;
			text = "<";
			y = DIALOG_TOP + 14 * CTRL_DEFAULT_H + 2 * GRID_W;
			onButtonClick = "[_this # 0,1] call ENH_fnc_IM_RemoveItem";
		};
		class RemoveTen: AddOne
		{
			idc = 130;
			text = "<<";
			y = DIALOG_TOP + 16 * CTRL_DEFAULT_H + 3 * GRID_W;
			onButtonClick = "[_this # 0,10] call ENH_fnc_IM_RemoveItem";
		};
		class RemoveAll: ctrlButton
		{
			idc = 140;
			text = "<<<";
			x = CENTERED_X(DIALOG_W) + DIALOG_W / 2 * GRID_W - 5 * GRID_W;
			y = DIALOG_TOP + 18 * CTRL_DEFAULT_H + 4 * GRID_W;
			w = 10 * GRID_W;
			h = 2 * CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_IM_clearInventory";
		};
		class ShowTemplates: ctrlButton
		{
			idc = 1800;
			text = "Show Templates"; //--- ToDo: Localize;
			x = CENTERED_X(DIALOG_W) + GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_IM_showTemplates";
		};
		class CreateTemplate: ShowTemplates
		{
			idc = 1900;
			text = "Create Template";
			x = CENTERED_X(DIALOG_W) + GRID_W + 31 * GRID_W;
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_InventoryManager_TemplateData'";
		};
		class DeleteTemplate: ctrlButtonPictureKeepAspect
		{
			idc = 150;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
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
			idc = 2200;
			text = "Apply Template";
			x = CENTERED_X(DIALOG_W) + GRID_W + 68 * GRID_W;
			onButtonClick = "_this call ENH_fnc_IM_applyTemplate";
		};
		class IsVirtualText: ctrlStatic
		{
			text = "Is Virtual?"; //--- ToDo: Localize;
			x = CENTERED_X(DIALOG_W) + GRID_W + 120 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 20 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class IsVirtualCheckbox: ctrlCheckbox
		{
			idc = 2800;
			x = CENTERED_X(DIALOG_W) + GRID_W + 138 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 5 * GRID_W;
			h = 5 * GRID_H;
			onCheckedChanged = "_this call ENH_fnc_IM_toggleVirtual";
		};
		class Search: ctrlEdit
		{
			idc = 5000;
			x = CENTERED_X(DIALOG_W) + GRID_W + 145 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 25 * GRID_W;
			h = 5 * GRID_H;
			onKeyUp = "_this call ENH_fnc_IM_Search";
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = CENTERED_X(DIALOG_W) + GRID_W + 170 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			colorBackground[] = {1,1,1,1};
		};
		class ApplyLoadout: ctrlButton
		{
			text = "Apply Loadout"; //--- ToDo: Localize;
			x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 63 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_IM_ApplyAttribute";
		};
		class Cancel: ctrlButtonCancel
		{
			x = CENTERED_X(DIALOG_W) + GRID_W + DIALOG_W * GRID_W - 32 * GRID_W;
			y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};