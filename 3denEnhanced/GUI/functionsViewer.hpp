class ENH_FunctionsViewer
{
	idd = -1;
	movingEnable = false;
	onLoad = "_this call  ENH_fnc_functionsViewer_onLoad";
	onUnload = "'showinterface' call BIS_fnc_3DENInterface";
	class ControlsBackground
	{
		class Background: ctrlStaticBackground
		{
			x = safezoneX;
			y = safezoneY + 5 * GRID_H;
			w = safezoneW;
			h = safezoneH - 5 * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_FUNCTIONSVIEWER_HEADER;
			x = safezoneX;
			y = safezoneY;
			w = safezoneW;
			h = 5 * GRID_H;
			colorBackground[] = {COLOUR_USER_PRESET};
			moving = false;
		};
		class FilterConfig: ctrlToolbox
		{
			idc = 1700;
			x = safezoneX + GRID_W;
			y = safezoneY + 6 * GRID_H;
			w = 70 * GRID_W;
			h = 5 * GRID_H;
            rows = 1;
            columns = 3;
            strings[] = //Do not localize
            {
           		"configFile",
           		"missionConfig",
				"campaignConfig"
            };
            values[] = {0,1,2};
			onToolBoxSelChanged  = "_this call ENH_fnc_functionsViewer_fillCtrlTV";
        };
		class FilterMode: FilterConfig
		{
			idc = 1800;
			x = safezoneX + GRID_W;
			y = safezoneY + 12 * GRID_H;
            rows = 1;
            columns = 3;
            strings[] = 
            {
           		$STR_ENH_FUNCTIONSVIEWER_FULL,
           		$STR_ENH_FUNCTIONSVIEWER_CATEGORIES,
				$STR_ENH_FUNCTIONSVIEWER_FUNCTIONS
            };
            values[] = {0,1,2};
			onToolBoxSelChanged  = "_this call ENH_fnc_functionsViewer_fillCtrlTV";
        };
		class List: ctrlTree
		{
			idc = 1500;
			idcSearch = 1400;
			x = safezoneX + GRID_W;
			y = safezoneY + 18 * GRID_H;
			w = 70 * GRID_W;
			h = safezoneH - 25 * GRID_H;
			onTreeSelChanged = "_this call ENH_fnc_functionsViewer_onTreeSelChanged";
		};
		class NumFunctions: ctrlStatic
		{
			idc = 1405;
			tooltip = $STR_ENH_FUNCTIONSVIEWER_NUMFUNCTIONS_TOOLTIP;
			x = safezoneX + GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 10 * GRID_W;
			h = 5 * GRID_H;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class Search: ctrlEdit
		{
			idc = 1400;
			tooltip = $STR_ENH_FUNCTIONSVIEWER_SEARCH_TOOLTIP;
			x = safezoneX + 12 * GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 44 * GRID_W;
			h = 5 * GRID_H;
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			tooltip = $STR_ENH_FUNCTIONSVIEWER_SEARCH_TOOLTIP;
			x = safezoneX + 56 * GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 5 * GRID_W;
			h = 5 * GRID_H;
		};
		class Collapse: ctrlButtonCollapseAll
		{
			x = safezoneX + 61 * GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 5 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Expand: ctrlButtonExpandAll
		{
			x = safezoneX + 66 * GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 5 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Name: ctrlEdit
		{
			idc = 1402;
			tooltip = $STR_ENH_FUNCTIONSVIEWER_FUNCTIONNAME_TOOLTIP;
			canModify = false;
			x = safezoneX + 72 * GRID_W;
			y = safezoneY + 6 * GRID_H;
			w = safezoneW - 155 * GRID_W;
			h = 5 * GRID_H;
		};
		class Path: ctrlEdit
		{
			idc = 1403;
			tooltip = $STR_ENH_FUNCTIONSVIEWER_FUNCTIONPATH_TOOLTIP;
			canModify = false;
			x = safezoneX + 72 * GRID_W;
			y = safezoneY + 12 * GRID_H;
			w = safezoneW - 155 * GRID_W;
			h = 5 * GRID_H;
		};
		class RecompileSelected: ctrlButton
		{
			idc = 1600;
			text = $STR_ENH_FUNCTIONSVIEWER_RECOMPILESELETECTED_TEXT;
			tooltip = $STR_ENH_FUNCTIONSVIEWER_RECOMPILESELETECTED_TOOLTIP;
			x = safezoneX + safezoneW - 82 * GRID_W;
			y = safezoneY + 6 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick = "_this call ENH_fnc_functionsViewer_recompileSelected";
		};
		class Copy: ctrlButton
		{
			text = $STR_ENH_FUNCTIONSVIEWER_COPYFUNCTION_TEXT;
			tooltip = $STR_ENH_FUNCTIONSVIEWER_COPYFUNCTION_TOOLTIP;
			x = safezoneX + safezoneW - 82 * GRID_W;
			y = safezoneY + 12 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick = "_this call ENH_fnc_functionsViewer_copy";
		};
		class RecompileAll: ctrlButton
		{
			idc = 1601;
			text = $STR_ENH_FUNCTIONSVIEWER_RECOMPILEALL_TEXT;
			tooltip = $STR_ENH_FUNCTIONSVIEWER_RECOMPILEALL_TOOLTIP;
			x = safezoneX + safezoneW - 41 * GRID_W;
			y = safezoneY + 6 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick = "1 call BIS_fnc_recompile; playSound 'FD_Finish_F'";
		};
		class Biki: ctrlStructuredText
		{
			idc = 1900;
			text = $STR_ENH_FUNCTIONSVIEWER_BIKI;
			x = safezoneX + safezoneW - 41 * GRID_W;
			y = safezoneY + 12 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
			colorBackground[] = {0,0,0,1};
			class Attributes
			{
				align = "center";
				font = "PuristaLight";
				size = 1;
			};
		};
		class Preview: ctrlControlsGroup
		{
			x = safezoneX + 72 * GRID_W;
			y = safezoneY + 18 * GRID_H;
			w = safezoneW - 73 * GRID_W;
			h = safeZoneH - 25 * GRID_H;
			class Controls
			{
				class Lines: ctrlStructuredText
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
				class Code: ctrlEditMulti
				{
					idc = 1401;
					canModify = false;
					x = 0.075;
					w = 4;
					h = 2;
					font = "EtelkaMonospacePro";
					shadow = 0;
					style = ST_NO_RECT + ST_MULTI;
				};
			};
		};
		class Close: ctrlButtonClose
		{
			x = safezoneX + safezoneW - 41 * GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
		};
	};
};