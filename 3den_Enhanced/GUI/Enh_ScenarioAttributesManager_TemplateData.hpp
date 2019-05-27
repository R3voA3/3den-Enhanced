/* #Jatexe
$[
	1.063,
	["test",[[0,0,1,1],0.025,0.04,"GUI_GRID"],2,0,0],
	[2200,"",[1,"",["0.395 * safezoneW + safezoneX","0.374 * safezoneH + safezoneY","0.21 * safezoneW","0.252 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"",[1,"Template Description ",["0.395 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.21 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"Title",[1,"Title",["0.401563 * safezoneW + safezoneX","0.388 * safezoneH + safezoneY","0.0853125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"",[2,"Description",["12.5 * GUI_GRID_W + GUI_GRID_X","11.5 * GUI_GRID_H + GUI_GRID_Y","6.5 * GUI_GRID_W","1 * GUI_GRID_H"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"TitleValue",[1,"",["0.401562 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"DescriptionValue",[1,"",["0.401562 * safezoneW + safezoneX","0.514 * safezoneH + safezoneY","0.196875 * safezoneW","0.056 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"Cancel",[1,"Cancel",["0.401563 * safezoneW + safezoneX","0.584 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"OK",[1,"OK",["0.526249 * safezoneW + safezoneX","0.584 * safezoneH + safezoneY","0.0721875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

class Enh_ScenarioAttributesManager_TemplateData
{
	idd = ENH_SCENARIOATTRIBUTESMANAGER_TEMPLATEDATA;
	movingEnable = true;
	enableSimulation = true;
	onLoad = "Enh_ScenarioAttributesManager_TemplateTitle = ''; Enh_ScenarioAttributesManager_TemplateDescription = '';";
	onUnload = "";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_Background
		{
			x = 0.395 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.252 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = "Template Description"; 
			x = 0.395 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Title: Enh_Text
		{
			text = "Title"; 
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Description: Enh_Text
		{
			text = "Description"; 
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.472 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
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
		class Cancel: Enh_Button
		{
			idc = 1;
			text = "Cancel"; 
			x = 0.401563 * safezoneW + safezoneX;
			y = 0.584 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class OK: Enh_Button
		{
			idc = 2;
			text = "OK";
			x = 0.526249 * safezoneW + safezoneX;
			y = 0.584 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_scenarioAttributesManager_createTemplate";
		};
	};
};