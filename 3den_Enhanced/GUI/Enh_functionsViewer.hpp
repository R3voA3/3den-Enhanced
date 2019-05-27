class Enh_FunctionsViewer
{
	idd = ENH_FUNCTIONSVIEWER;
	movingEnable = true;
	onLoad = "_this call  Enh_fnc_functionsViewer_onLoad";
	onUnload = "'showinterface' call BIS_fnc_3DENInterface";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: Enh_Background
		{
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.97125 * safezoneW;
			h = 0.924 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = $STR_ENH_functionsViewer_header;
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.951562 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class List: ctrlTree
		{
			idc = 1500;
			idcSearch = 1400;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.854 * safezoneH;
			onTreeSelChanged = "_this call Enh_fnc_functionsViewer_selectionChanged";
		};
		class Search: Enh_Edit
		{
			idc = 1400;
			tooltip = $STR_ENH_functionsViewer_search_tooltip;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			tooltip = $STR_ENH_functionsViewer_search_tooltip;
			x = 0.185 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class RecompileSelected: Enh_Button
		{
			idc = 1600;
			text = $STR_ENH_functionsViewer_recompileSeletected_text;
			tooltip = $STR_ENH_functionsViewer_recompileSeletected_tooltip;
			x = 0.723125 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.124687 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_functionsViewer_recompileSelected";
		};
		class RecompileAll: Enh_Button
		{
			idc = 1601;
			text = $STR_ENH_functionsViewer_recompileAll_text;
			tooltip = $STR_ENH_functionsViewer_recompileAll_tooltip;
			x = 0.854375 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.124687 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "1 call BIS_fnc_recompile; playSound 'FD_Finish_F'";
		};
		class Close: Enh_Button
		{
			text = "X";
			idc = 1;
			x = 0.965937 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Copy: Enh_Button
		{
			text = $STR_ENH_functionsViewer_copyFunction_text;
			tooltip = $STR_ENH_functionsViewer_copyFunction_tooltip;
			x = 0.591875 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.124687 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "call Enh_fnc_functionsViewer_copy";
		};
		class Collapse: Enh_Button
		{
			tooltip = $STR_ENH_functionsViewer_collapseAll_text;
			style = "0x02 + 0x30 + 0x800";
			colorBackground[] = {0,0,0,0};
			x = 0.204688 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
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
			x = 0.217813 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			text = "\a3\3DEN\Data\Displays\Display3DEN\tree_expand_ca.paa";
			onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Preview: Enh_ControlsGroup
		{
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.741562 * safezoneW;
			h = 0.812 * safezoneH;
			class Controls
			{
				class Lines: Enh_StructuredText
				{
					idc = 1404;
					canModify = false;
					x = 0;
					y = 0;
					w = 0.070;
					h = 2;
					font = "EtelkaMonospacePro";
					shadow = 0;
					colorBackground[] = {COLOR_OVERLAY_RGBA};
				};
				class Code: Enh_Edit
				{
					idc = 1401;
					canModify = false;
					x = 0.075;
					w = 4;
					font = "EtelkaMonospacePro";
					shadow = 0;
				};
			};
		};
		class Name: Enh_Edit
		{
			idc = 1402;
			tooltip = $STR_ENH_functionsViewer_functionName_tooltip;
			canModify = false;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.347813 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Path: Enh_Edit
		{
			idc = 1403;
			tooltip = $STR_ENH_functionsViewer_functionPath_tooltip;
			canModify = false;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.108 * safezoneH + safezoneY;
			w = 0.741562 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};

/* #Nekyjo
$[
	1.063,
	["FunctionViewer",[[0,0,1,1],0.025,0.04,"GUI_GRID"],2,0,0],
	[-2200,"Background",[1,"",["0.014375 * safezoneW + safezoneX","0.052 * safezoneH + safezoneY","0.97125 * safezoneW","0.924 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"Code",[1,"",["0.2375 * safezoneW + safezoneX","0.15 * safezoneH + safezoneY","0.741562 * safezoneW","0.812 * safezoneH"],[-1,-1,-1,-1],[1,1,1,1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"Header",[1,"3den Enhanced Function Viewer",["0.014375 * safezoneW + safezoneX","0.024 * safezoneH + safezoneY","0.951562 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.403922,0.545098,0.607843,1],[-1,-1,-1,-1],"","-1"],[]],
	[1500,"List",[1,"",["0.0209375 * safezoneW + safezoneX","0.066 * safezoneH + safezoneY","0.21 * safezoneW","0.854 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"Search",[1,"Search...",["0.0209375 * safezoneW + safezoneX","0.934 * safezoneH + safezoneY","0.164062 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"RecompileSelected",[1,"Recompile Selected",["0.723125 * safezoneW + safezoneX","0.066 * safezoneH + safezoneY","0.124687 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[0.403922,0.545098,0.607843,1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"RecompileAll",[1,"Recompile All",["0.854375 * safezoneW + safezoneX","0.066 * safezoneH + safezoneY","0.124687 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[0.403922,0.545098,0.607843,1],"","-1"],[]],
	[1402,"Name",[1,"BIS_fnc_displayName",["0.2375 * safezoneW + safezoneX","0.066 * safezoneH + safezoneY","0.347813 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1403,"Path",[1,"\A3\ui_f\hpp\defineResinclDesign.inc",["0.2375 * safezoneW + safezoneX","0.108 * safezoneH + safezoneY","0.741562 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1200,"",[1,"#(argb,8,8,3)color(1,1,1,1)",["0.185 * safezoneW + safezoneX","0.934 * safezoneH + safezoneY","0.0196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1603,"Copy",[1,"Copy",["0.591875 * safezoneW + safezoneX","0.066 * safezoneH + safezoneY","0.124687 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[0.403922,0.545098,0.607843,1],"","-1"],[]],
	[1604,"Collapse",[1,"",["0.204688 * safezoneW + safezoneX","0.934 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1605,"Expand",[1,"",["0.217813 * safezoneW + safezoneX","0.934 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1606,"Close",[1,"X",["0.965937 * safezoneW + safezoneX","0.024 * safezoneH + safezoneY","0.0196875 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/