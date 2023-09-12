class ENH_3DENRadio
{
  idd = IDD_3DENRADIO;
  movingEnable = true;
  onLoad = "_this spawn ENH_fnc_3DENRadio_onLoad";
  onUnload = "";
  class ControlsBackground
  {
  DISABLE_BACKGROUND
  class Header: ctrlStaticTitle
    {
      text = "3DEN Radio";
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP;
      w = WINDOW_WAbs * GRID_W;
      h = 5 * GRID_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + 2 * 5 * GRID_H;
      w = WINDOW_WAbs * GRID_W;
      h = WINDOW_HAbs - 30 * GRID_H;
    };
  class Footer: ctrlStaticFooter
    {
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 27 * GRID_H;
      w = WINDOW_WAbs * GRID_W;
      h = 7 * GRID_H;
    };
    class BackgroundFilter: Background//Background used for filter buttons
    {
      y = WINDOW_TOP + 5 * GRID_H;
      h = 5 * GRID_H;
      colorBackground[] = {0, 0, 0, 1};
    };
    class CurrentSongText: ctrlStaticFooter
    {
      text = "$STR_ENH_3DENRADIO_SONG";
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 33 * GRID_H;
      w = 10 * GRID_W;
      h = 5 * GRID_H;
    };
    class CurrentSong: CurrentSongText
    {
      idc = IDC_3DENRADIO_CURRENTSONG;
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + 10 * GRID_W;
      w = (WINDOW_WAbs - 10) * GRID_W;
    };
  };
  class Controls
  {
    class Filter: ctrlListNBox //Used by BIS_fnc_initListBoxSorting as filter
    {
      idc = IDC_3DENRADIO_FILTER;
      idcLeft = -1;
      idcRight = -1;
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W;
      y = WINDOW_TOP + 5 * GRID_H;
      w = WINDOW_WAbs * GRID_W;
      h = 5 * GRID_H;
    };
    class Songlist: Filter
    {
      idc = IDC_3DENRADIO_SONGLIST;
      y = WINDOW_TOP + 2 * 5 * GRID_H;
      h = WINDOW_HAbs - 45 * GRID_H;
      disableOverflow = 1;
      onLBDblClick = "params ['_ctrl', '_row']; [[_ctrl lnbText [_row, 0], _ctrl lnbData [_row, 0], _ctrl lnbData [_row, 1]]] call ENH_fnc_3DENRadio_playNewSong";
      onKeyDown = "_this call ENH_fnc_3DENRadio_handlePlaylist; _this call ENH_fnc_3DENRadio_exportClassname";
    };
    class ToggleRadio: ctrlButtonPictureKeepAspect
    {
      idc = IDC_3DENRADIO_TOGGLERADIO;
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 26 * GRID_H;
      w = 5 * GRID_W;
      h = 5 * GRID_H;
      onButtonClick = "false call ENH_fnc_3DENRadio_toggleRadio";
    };
    class VolumeIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\Modules_F_Curator\Data\portraitSound_ca.paa";
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + 7 * GRID_W;
    y = WINDOW_TOP + WINDOW_HAbs - 26 * GRID_H;
      w = 5 * GRID_W;
      h = 5 * GRID_H;
    };
    class Volume: ctrlXSliderH
    {
      idc = IDC_3DENRADIO_VOLUME;
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + 13 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 26 * GRID_H;
      w = 30 * GRID_W;
      h = 5 * GRID_H;
      sliderRange[] = {0, 1.5};
      onSliderPosChanged = "0 fadeMusic (sliderPosition (_this # 0)); profileNamespace setVariable ['ENH_3DENRadio_MusicVolume', musicVolume]";
    };
    class Help: VolumeIcon
    {
      text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa";
      tooltip = "$STR_ENH_3DENRADIO_HELP_DESCRIPTION";
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + 44 * GRID_W;
      tooltipMaxWidth = 1;
    };
    class SearchEdit: ctrlEdit
    {
      idc = IDC_3DENRADIO_SEARCH;
      tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + 50 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 26 * GRID_H;
      w = 30 * GRID_W;
      h = 5 * GRID_H;
      onKeyUp = "call ENH_fnc_3DENRadio_searchList;";//onKeyUp to give the control time to update
    };
    class SearchIcon: VolumeIcon
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      tooltip = "";
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + 80 * GRID_W;
    };
    class Group: ctrlControlsGroup
    {
      x = CENTER_X - WINDOW_WAbs * 0.5 * GRID_W + 86 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 26 * GRID_H;
      w = 80 * GRID_W;
      h = 5 * GRID_H;
      class Controls
      {
        class Time: ctrlStatic
        {
          idc = IDC_3DENRADIO_TIME;
          text = "00:00";
          x = 24 * GRID_W;
          y = 0;
          w = 10 * GRID_W;
          h = 5 * GRID_H;
        };
        class Position: ctrlXSliderH
        {
          idc = IDC_3DENRADIO_POSITION;
          x = 0 * GRID_W;
          y = 0;
          w = 58 * GRID_W;
          h = 5 * GRID_H;
          sliderRange[] = {0, 1.5};
          colorActive[] = {1, 1, 1, 0.6};
          onSliderPosChanged = "playMusic [uiNamespace getVariable ['ENH_3DENRadio_CurrentSongClass', ''], sliderPosition (_this # 0)]";
        };
      };
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_WAbs * GRID_W - 26 * GRID_W;
      y = WINDOW_TOP + WINDOW_HAbs - 26 * GRID_H;
      w = 25 * GRID_W;
      h = 5 * GRID_H;
    };
  };
};