class StatusBar: ctrlControlsGroupNoScrollbars
{
	class Controls
	{
		class Version;//EditBox
		class TextZ;//Icon
		class Enh_SessionTime: Version
		{
			idc = 668;
			tooltip = $STR_ENH_statusBar_sessionTimer_tooltip;
			x = ORIGIN_X - 49 * GRID_W - SPACE_X;
			onLoad = "(_this # 0) ctrlEnable false";
			style = ST_CENTER + ST_NO_RECT;
		};
		//Selected entities counter
		class Enh_NumberMarkers: Version
		{
			idc = 669;
			x = ORIGIN_X - 56 * GRID_W - 2 * SPACE_X;
			w = 7 * GRID_W;
			onLoad = "(_this # 0) ctrlEnable false; (_this # 0) ctrlSetText '0'";
			style = ST_CENTER + ST_NO_RECT;
		};
		class Enh_IconMarkers: TextZ
		{
			x = ORIGIN_X - 59 * GRID_W  - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa";
		};
		class Enh_NumberSystems: Enh_NumberMarkers
		{
			idc = 670;
			x = ORIGIN_X - 66 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconSystems: TextZ
		{
			x = ORIGIN_X - 69 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
		};
		class Enh_NumberWaypoints: Enh_NumberMarkers
		{
			idc = 671;
			x = ORIGIN_X - 76 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconWaypoints: TextZ
		{
			x = ORIGIN_X - 79 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa";
		};
		class Enh_NumberTriggers: Enh_NumberMarkers
		{
			idc = 672;
			x = ORIGIN_X - 86 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconTriggers: TextZ
		{
			x = ORIGIN_X - 89 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa";
		};
		class Enh_NumberGroups: Enh_NumberMarkers
		{
			idc = 673;
			x = ORIGIN_X - 96 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconGroups: TextZ
		{
			x = ORIGIN_X - 99 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
		};
		class Enh_NumberObjects: Enh_NumberMarkers
		{
			idc = 674;
			x = ORIGIN_X - 106 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconObjects: TextZ
		{
			x = ORIGIN_X - 109 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
		};
	};
};