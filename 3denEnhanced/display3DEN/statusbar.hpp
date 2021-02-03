class StatusBar: ctrlControlsGroupNoScrollbars
{
  class Controls
  {
    class Version;//EditBox
    class TextZ;//Icon
    class ENH_SessionTime: Version
    {
      idc = IDC_STATUSBAR_SESSIONTIMER;
      tooltip = "$STR_ENH_STATUSBAR_SESSIONTIMER_TOOLTIP";
      x = ORIGIN_X_STATUSBAR - 49 * GRID_W - SPACE_X;
      onLoad = "(_this # 0) ctrlEnable false";
      style = ST_CENTER + ST_NO_RECT;
    };
    //Selected entities counter, controls are hidden by default and managed by ENH_fnc_statusbar_entityCounter
    class ENH_NumberMarkers: Version
    {
      idc = IDC_STATUSBAR_NUMMARKERS;
      x = ORIGIN_X_STATUSBAR - 56 * GRID_W - 2 * SPACE_X;
      w = 7 * GRID_W;
      onLoad = "(_this # 0) ctrlShow false; (_this # 0) ctrlEnable false";
      style = ST_CENTER + ST_NO_RECT;
    };
    class ENH_IconMarkers: TextZ
    {
      idc = IDC_STATUSBAR_ICONMARKERS;
      x = ORIGIN_X_STATUSBAR - 59 * GRID_W - 2 * SPACE_X;
      onLoad = "(_this # 0) ctrlShow false";
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa";
    };
    class ENH_NumberSystems: ENH_NumberMarkers
    {
      idc = IDC_STATUSBAR_NUMSYSTEMS;
      x = ORIGIN_X_STATUSBAR - 66 * GRID_W - 2 * SPACE_X;
    };
    class ENH_IconSystems: TextZ
    {
      idc = IDC_STATUSBAR_ICONSYSTEMS;
      x = ORIGIN_X_STATUSBAR - 69 * GRID_W - 2 * SPACE_X;
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
    };
    class ENH_NumberWaypoints: ENH_NumberMarkers
    {
      idc = IDC_STATUSBAR_NUMWAYPOINTS;
      x = ORIGIN_X_STATUSBAR - 76 * GRID_W - 2 * SPACE_X;
    };
    class ENH_IconWaypoints: TextZ
    {
      idc = IDC_STATUSBAR_ICONWAYPOINTS;
      x = ORIGIN_X_STATUSBAR - 79 * GRID_W - 2 * SPACE_X;
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa";
    };
    class ENH_NumberTriggers: ENH_NumberMarkers
    {
      idc = IDC_STATUSBAR_NUMTRIGGERS;
      x = ORIGIN_X_STATUSBAR - 86 * GRID_W - 2 * SPACE_X;
    };
    class ENH_IconTriggers: TextZ
    {
      idc = IDC_STATUSBAR_ICONTRIGGERS;
      x = ORIGIN_X_STATUSBAR - 89 * GRID_W - 2 * SPACE_X;
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa";
    };
    class ENH_NumberGroups: ENH_NumberMarkers
    {
      idc = IDC_STATUSBAR_NUMGROUPS;
      x = ORIGIN_X_STATUSBAR - 96 * GRID_W - 2 * SPACE_X;
    };
    class ENH_IconGroups: TextZ
    {
      idc = IDC_STATUSBAR_ICONGROUPS;
      x = ORIGIN_X_STATUSBAR - 99 * GRID_W - 2 * SPACE_X;
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
    };
    class ENH_NumberObjects: ENH_NumberMarkers
    {
      idc = IDC_STATUSBAR_NUMOBJECTS;
      x = ORIGIN_X_STATUSBAR - 106 * GRID_W - 2 * SPACE_X;
    };
    class ENH_IconObjects: TextZ
    {
      idc = IDC_STATUSBAR_ICONOBJECTS;
      x = ORIGIN_X_STATUSBAR - 109 * GRID_W - 2 * SPACE_X;
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
    };
  };
};