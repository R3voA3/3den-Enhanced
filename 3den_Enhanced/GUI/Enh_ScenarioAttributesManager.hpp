/* #Wocaxa
$[
	1.063,
	["t",[[0,0,1,1],0.025,0.04,"GUI_GRID"],2,0,0],
	[2200,"",[1,"",["0.2375 * safezoneW + safezoneX","0.178 * safezoneH + safezoneY","0.525 * safezoneW","0.672 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"",[1,"",["0.2375 * safezoneW + safezoneX","0.15 * safezoneH + safezoneY","0.511875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"",[1,"X",["0.749375 * safezoneW + safezoneX","0.15 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1500,"",[1,"",["0.414686 * safezoneW + safezoneX","0.234 * safezoneH + safezoneY","0.34125 * safezoneW","0.56 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1501,"",[1,"",["0.244062 * safezoneW + safezoneX","0.234 * safezoneH + safezoneY","0.164062 * safezoneW","0.56 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"",[1,"Templates",["0.244062 * safezoneW + safezoneX","0.192 * safezoneH + safezoneY","0.07875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"",[1,"Attributes",["0.414687 * safezoneW + safezoneX","0.192 * safezoneH + safezoneY","0.0590625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"",[1,"Delete Template",["0.244062 * safezoneW + safezoneX","0.808 * safezoneH + safezoneY","0.164062 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1602,"",[1,"Create Template from Mission Attributes",["0.414687 * safezoneW + safezoneX","0.808 * safezoneH + safezoneY","0.223125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1603,"",[1,"Copy to Clipboard",["0.644375 * safezoneW + safezoneX","0.808 * safezoneH + safezoneY","0.111562 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"",[1,"",["0.690312 * safezoneW + safezoneX","0.192 * safezoneH + safezoneY","0.065625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1200,"",[1,"#(argb,8,8,3)color(1,1,1,1)",["0.677188 * safezoneW + safezoneX","0.192 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

class Enh_ScenarioAttributesManager
{
	idd = ENH_SCENARIOATTRIBUTESMANAGER;
	movingEnable = true;
	enableSimulation = true;
	onLoad = "_this call Enh_fnc_scenarioAttributesManager_onLoad";
	onUnload = "_this call Enh_fnc_scenarioAttributesManager_onUnload";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_Background
		{
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.525 * safezoneW;
			h = 0.714 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = "3den Enhanced Scenario Attributes Manager";
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.511875 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Close: Enh_Button
		{
			idc = 1;
			text = "X";
			x = 0.749375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TemplateList: Enh_Listbox
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
		class Templates: Enh_Text
		{
			text = "Templates";
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.07875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Attributes: Enh_Text
		{
			text = "Attributes";
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.0590625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class DeleteTemplate: Enh_Button
		{
			text = "Delete Template";
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_deleteTemplate";
		};
		class CreateTemplate: Enh_Button
		{
			text = "Create Template from Mission Attributes";
			x = 0.414687 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'Enh_ScenarioAttributesManager_TemplateData'";
		};
		class ApplyTemplate: Enh_Button
		{
			text = "Apply Template";
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.85 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.028 * safezoneH;
			tooltip = "Applies currently selected Template to this mission. Action can be undone with the Eden undo button.";
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_applyTemplate";
		};
		class Export: Enh_Button
		{
			text = "Export to Clipboard";
			x = 0.644375 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_exportToClipboard";
		};
		class Search: Enh_Edit
		{
			idc = 1400;
			x = 0.690312 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SearchIcon: Enh_Picture
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = 0.677188 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Collapse: Enh_Button
		{
			tooltip = $STR_ENH_functionsViewer_collapseAll_text;
			style = "0x02 + 0x30 + 0x800";
			colorBackground[] = {0,0,0,0};
			x = 0.651688 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			text = "\a3\3DEN\Data\Displays\Display3DEN\tree_collapse_ca.paa";
			onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Expand: Enh_Button
		{
			tooltip = $STR_ENH_functionsViewer_expandAll_text;
			style = "0x02 + 0x30 + 0x800";
			colorBackground[] = {0,0,0,0};
			x = 0.664813 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			text = "\a3\3DEN\Data\Displays\Display3DEN\tree_expand_ca.paa";
			onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
	};
};