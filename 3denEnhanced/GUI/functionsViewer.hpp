class Enh_FunctionsViewer
{
	idd = ENH_IDD_FUNCTIONSVIEWER;
	movingEnable = false;
	onLoad = "_this call  Enh_fnc_functionsViewer_onLoad";
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
			text = $STR_ENH_functionsViewer_header;
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
			onToolBoxSelChanged  = "_this call Enh_fnc_functionsViewer_fillCtrlTV";
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
           		$STR_ENH_functionsViewer_full,
           		$STR_ENH_functionsViewer_categories,
				$STR_ENH_functionsViewer_functions
            };
            values[] = {0,1,2};
			onToolBoxSelChanged  = "_this call Enh_fnc_functionsViewer_fillCtrlTV";
        };
		class List: ctrlTree
		{
			idc = 1500;
			idcSearch = 1400;
			x = safezoneX + GRID_W;
			y = safezoneY + 18 * GRID_H;
			w = 70 * GRID_W;
			h = safezoneH - 25 * GRID_H;
			onTreeSelChanged = "_this call Enh_fnc_functionsViewer_onTreeSelChanged";
		};
		class NumFunctions: ctrlStatic
		{
			idc = 1405;
			tooltip = $STR_ENH_functionsViewer_numFunctions_tooltip;
			x = safezoneX + GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 10 * GRID_W;
			h = 5 * GRID_H;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class Search: ctrlEdit
		{
			idc = 1400;
			tooltip = $STR_ENH_functionsViewer_search_tooltip;
			x = safezoneX + 12 * GRID_W;
			y = safezoneY + safezoneH - 6 * GRID_H;
			w = 44 * GRID_W;
			h = 5 * GRID_H;
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			tooltip = $STR_ENH_functionsViewer_search_tooltip;
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
			tooltip = $STR_ENH_functionsViewer_functionName_tooltip;
			canModify = false;
			x = safezoneX + 72 * GRID_W;
			y = safezoneY + 6 * GRID_H;
			w = safezoneW - 155 * GRID_W;
			h = 5 * GRID_H;
		};
		class Path: ctrlEdit
		{
			idc = 1403;
			tooltip = $STR_ENH_functionsViewer_functionPath_tooltip;
			canModify = false;
			x = safezoneX + 72 * GRID_W;
			y = safezoneY + 12 * GRID_H;
			w = safezoneW - 155 * GRID_W;
			h = 5 * GRID_H;
		};
		class RecompileSelected: ctrlButton
		{
			idc = 1600;
			text = $STR_ENH_functionsViewer_recompileSeletected_text;
			tooltip = $STR_ENH_functionsViewer_recompileSeletected_tooltip;
			x = safezoneX + safezoneW - 82 * GRID_W;
			y = safezoneY + 6 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick = "_this call Enh_fnc_functionsViewer_recompileSelected";
		};
		class Copy: ctrlButton
		{
			text = $STR_ENH_functionsViewer_copyFunction_text;
			tooltip = $STR_ENH_functionsViewer_copyFunction_tooltip;
			x = safezoneX + safezoneW - 82 * GRID_W;
			y = safezoneY + 12 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick = "_this call Enh_fnc_functionsViewer_copy";
		};
		class RecompileAll: ctrlButton
		{
			idc = 1601;
			text = $STR_ENH_functionsViewer_recompileAll_text;
			tooltip = $STR_ENH_functionsViewer_recompileAll_tooltip;
			x = safezoneX + safezoneW - 41 * GRID_W;
			y = safezoneY + 6 * GRID_H;
			w = 40 * GRID_W;
			h = 5 * GRID_H;
			onButtonClick = "1 call BIS_fnc_recompile; playSound 'FD_Finish_F'";
		};
		class Biki: ctrlStructuredText
		{
			idc = 1900;
			text = $STR_ENH_functionsViewer_biki;
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

/*class Enh_FunctionsViewer
{
	idd = ENH_IDD_FUNCTIONSVIEWER;
	movingEnable = true;
	onLoad = "_this call  Enh_fnc_functionsViewer_onLoad";
	onUnload = "'showinterface' call BIS_fnc_3DENInterface";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.97125 * safezoneW;
			h = 0.924 * safezoneH;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_functionsViewer_header;
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.951562 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class FilterConfig: ctrlToolbox
		{
			idc = 1700;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
            rows = 1;
            columns = 3;
            strings[] = //Do not localize
            {
           		"configFile",
           		"missionConfig",
				"campaignConfig"
            };
            values[] = {0,1,2};
			onToolBoxSelChanged  = "_this call Enh_fnc_functionsViewer_fillCtrlTV";
        };
		class FilterMode: ctrlToolbox
		{
			idc = 1800;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.108 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
            rows = 1;
            columns = 3;
            strings[] = 
            {
           		$STR_ENH_functionsViewer_full,
           		$STR_ENH_functionsViewer_categories,
				$STR_ENH_functionsViewer_functions
            };
            values[] = {0,1,2};
			onToolBoxSelChanged  = "_this call Enh_fnc_functionsViewer_fillCtrlTV";
        };
		class List: ctrlTree
		{
			idc = 1500;
			idcSearch = 1400;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.78 * safezoneH;
			onTreeSelChanged = "_this call Enh_fnc_functionsViewer_onTreeSelChanged";
		};
		class Search: ctrlEdit
		{
			idc = 1400;
			tooltip = $STR_ENH_functionsViewer_search_tooltip;
			x = 0.06 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class NumFunctions: ctrlStatic
		{
			idc = 1405;
			tooltip = $STR_ENH_functionsViewer_numFunctions_tooltip;
			x = 0.0209375 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.035 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {COLOUR_USER_PRESET};
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
		class RecompileSelected: ctrlButton
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
		class RecompileAll: ctrlButton
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
		class Biki: ctrlStructuredText
		{
			idc = 1900;
			x = 0.854375 * safezoneW + safezoneX;
			y = 0.108 * safezoneH + safezoneY;
			w = 0.124687 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {0,0,0,1};
			class Attributes
			{
				align = "center";
				font = "PuristaLight";
				size = 1;
			};
		};
		class Close: ctrlButton
		{
			text = "X";
			idc = 1;
			x = 0.965937 * safezoneW + safezoneX;
			y = 0.024 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class Copy: ctrlButton
		{
			text = $STR_ENH_functionsViewer_copyFunction_text;
			tooltip = $STR_ENH_functionsViewer_copyFunction_tooltip;
			x = 0.591875 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.124687 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "call Enh_fnc_functionsViewer_copy";
		};
		class Collapse: ctrlButtonCollapseAll
		{
			x = 0.204688 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Expand: ctrlButtonExpandAll
		{
			x = 0.217813 * safezoneW + safezoneX;
			y = 0.934 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Preview: ctrlControlsGroup
		{
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.741562 * safezoneW;
			h = 0.812 * safezoneH;
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
		class Name: ctrlEdit
		{
			idc = 1402;
			tooltip = $STR_ENH_functionsViewer_functionName_tooltip;
			canModify = false;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.347813 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Path: ctrlEdit
		{
			idc = 1403;
			tooltip = $STR_ENH_functionsViewer_functionPath_tooltip;
			canModify = false;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.108 * safezoneH + safezoneY;
			w = 0.61 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};