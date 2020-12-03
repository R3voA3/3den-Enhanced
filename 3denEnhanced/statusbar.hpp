class StatusBar: ctrlControlsGroupNoScrollbars
{
  class Controls
  {
    class Version;//EditBox
    class TextZ;//Icon
    class ENH_SessionTime: Version
    {
      idc = IDC_STATUSBAR_SESSIONTIMER;
      tooltip = $STR_ENH_STATUSBAR_SESSIONTIMER_TOOLTIP;
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

/*
#pragma region
add3DENEventHandler ["onSelectionChange",
{
  toFixed 3;
  private _display3DEN = findDisplay 313;
  private _varNames = [];
  {
    private _entities = (([[""]] call ENH_fnc_all3DENSelected) # 0);
    private _varName = (_x get3DENAttribute "Name") # 0;//Doesn't work with markers
    if (_varName != "") then
    {
      if (_forEachIndex == 0) then
      {

      };
       _varNames append [_varName];
    };
  } forEach (([[""]] call ENH_fnc_all3DENSelected) # 0);
  _display3DEN displayCtrl 684 ctrlSetText str _varNames;

  //Update position controls
  _pos = ((_entities # 0) get3DENAttribute "Position") # 0;
  _display3DEN displayCtrl 681 ctrlSetText str (_pos # 0);
  _display3DEN displayCtrl 682 ctrlSetText str (_pos # 1);
  _display3DEN displayCtrl 684 ctrlSetText str (_pos # 2);
}];

class StatusBarCustom: ctrlControlsGroupNoScrollbars
{
	idc = -1;
	x = safezoneX + 60 * GRID_W;
	y = safezoneY + safezoneH - 9 * GRID_H;
	w = safezoneW - 120 * GRID_W;
	h = CTRL_DEFAULT_H;
	class Controls
  {
    class StatusBarBackground: ctrlStatic
    {
      idc = -1;
      x = 0;
      y = 0;
      w = safezoneW - 120 * GRID_W;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {0.2,0.2,0.2,1};
    };
    class TextX: ctrlStaticPicture
    {
      y = "(2 * pixelH)";
      w = "3 * (pixelW * pixelGrid * 	0.50)";
      h = "3 * (pixelH * pixelGrid * 	0.50)";
      sizeEx = "2.88 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
      text = "\a3\3DEN\Data\Displays\Display3DEN\StatusBar\x_ca.paa";
      colorBackground[] = {0,0,0,0};
      shadow = 0;
    };
    class ValueX: ctrlEdit
    {
      idc = 681;
      style = "0x01 + 0x200";
      x = "3 * (pixelW * pixelGrid * 	0.50)";
      y = "(2 * pixelH)";
      w = "16 * (pixelW * pixelGrid * 	0.50)";
      h = "4 * (pixelH * pixelGrid * 	0.50) - 2 * (2 * pixelH)";
      font = "EtelkaMonospacePro";
      sizeEx = "2.945 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
      shadow = 0;
      colorDisabled[] = {1,1,1,0.5};
      onLoad = "(_this select 0) ctrlenable false;";
    };
    class TextY: TextX
    {
      x = "(	3 + 	16 + 	4) * (pixelW * pixelGrid * 	0.50)";
      text = "\a3\3DEN\Data\Displays\Display3DEN\StatusBar\y_ca.paa";
      colorBackground[] = {0,0,0,0};
    };
    class ValueY: ValueX
    {
      idc = 682;
      x = "((	3 + 	16 + 	4) + 	3) * (pixelW * pixelGrid * 	0.50)";
    };
    class TextZ: TextX
    {
      x = "2 * (	3 + 	16 + 	4) * (pixelW * pixelGrid * 	0.50)";
      text = "\a3\3DEN\Data\Displays\Display3DEN\StatusBar\z_ca.paa";
      colorBackground[] = {0,0,0,0};
    };
    class ValueZ: ValueX
    {
      idc = 683;
      x = "(2 * (	3 + 	16 + 	4) + 	3) * (pixelW * pixelGrid * 	0.50)";
    };
    class Copy: ctrlButtonPictureKeepAspect
    {
      idc = -1;
      text = "\3denEnhanced\data\icon_clipboard.paa";
      x = "(2 * (	3 + 	16 + 	4) + 19) * (pixelW * pixelGrid * 	0.50)";
      y = 2 * pixelH;
      w = 4 * (pixelH * pixelGrid * 	0.50) - 2 * (2 * pixelH);
      h = "4 * (pixelH * pixelGrid * 	0.50) - 2 * (2 * pixelH)";
      colorBackground[] = {0,0,0,0};
    };
    class VariableNames: ValueX
    {
      idc = 684;
      onLoad = "";
      x = "(2 * (	3 + 	16 + 	4) + 26) * (pixelW * pixelGrid * 	0.50)";
      w = "safeZoneW - (60 + 60 + 72 + 1) * (pixelW * pixelGrid * 	0.50)";
      canModify = 0;
      style = ST_LEFT + ST_NO_RECT;
      onSetFocus = "copyToClipboard (ctrlText (_this # 0)); ['ENH_DataCopied'] call BIS_fnc_3DENNotification";
      text = "[""R3vo_Target_0"", ""R3vo_Target_0"", ""R3vo_Target_0""]";
    };
  };
};
#pragma endregion
*/