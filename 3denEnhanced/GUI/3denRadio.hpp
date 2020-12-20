#define DIALOG_W 195
#define DIALOG_H 120

class ENH_3DENRadio
{
  idd = IDD_3DENRADIO;
  movingEnable = true;
  onLoad = "_this spawn ENH_fnc_3DENRadio_onLoad";
  onUnload = "";
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
    class Header:  ctrlStaticTitle
    {
      text = "3DEN Radio";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class BackgroundFilter: Background//Background used for filter buttons
    {
      h = CTRL_DEFAULT_H;
      colorBackground[] = {0,0,0,1};
    };
  };
  class Controls
  {
    class Filter: ctrlListNBox //Used by BIS_fnc_initListBoxSorting as filter
    {
      idc = IDC_3DENRADIO_FILTER;
      idcLeft = -1;
      idcRight = -1;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Songlist: Filter
    {
      idc = IDC_3DENRADIO_SONGLIST;
      y = DIALOG_TOP + 2 * CTRL_DEFAULT_H;
      h = DIALOG_H * GRID_H - 18 * GRID_H;
      disableOverflow = 1;
      onLBDblClick  = "params ['_ctrl','_row']; [[_ctrl lnbText [_row,0],_ctrl lnbData [_row,0],_ctrl lnbData [_row,1]]] call ENH_fnc_3DENRadio_playNewSong";
      onKeyDown = "_this call ENH_fnc_3DENRadio_handlePlaylist; _this call ENH_fnc_3DENRadio_exportClassname";
    };
    class CurrentSongText: ctrlStaticFooter
    {
      text = "$STR_ENH_3DENRADIO_SONG";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + DIALOG_H * GRID_H - 7 * GRID_H;
      w = 10 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class CurrentSong: CurrentSongText
    {
      idc = IDC_3DENRADIO_CURRENTSONG;
      x = CENTERED_X(DIALOG_W) + 10 * GRID_W;
      w = (DIALOG_W - 10) * GRID_W;
    };
    class ToggleRadio: ctrlButtonPictureKeepAspect
    {
      idc = IDC_3DENRADIO_TOGGLERADIO;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "false call ENH_fnc_3DENRadio_toggleRadio";
    };
    class VolumeIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\Modules_F_Curator\Data\portraitSound_ca.paa";
      x = CENTERED_X(DIALOG_W) + 7 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Volume: ctrlXSliderH
    {
      idc = IDC_3DENRADIO_VOLUME;
      x = CENTERED_X(DIALOG_W) + 13 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
      sliderRange[] = {0,1.5};
      onSliderPosChanged = "0 fadeMusic (sliderPosition (_this # 0)); profileNamespace setVariable ['ENH_3DENRadio_MusicVolume',musicVolume]";
    };
    class Help: VolumeIcon
    {
      text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa";
      tooltip = "$STR_ENH_3DENRADIO_HELP_DESCRIPTION";
      x = CENTERED_X(DIALOG_W) + 44 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      tooltipMaxWidth = 1;
    };
    class SearchEdit: ctrlEdit
    {
      idc = IDC_3DENRADIO_SEARCH;
      tooltip = __EVAL(format ["%1+%2",toUpper localize "STR_DIK_CONTROL","F"]);
      x = CENTERED_X(DIALOG_W) + 50 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
      onKeyUp = "call ENH_fnc_3DENRadio_searchList;";//onKeyUp to give the control time to update
    };
    class SearchIcon: VolumeIcon
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      tooltip = "";
      x = CENTERED_X(DIALOG_W) + 80 * GRID_W;
    };
    class Group: ctrlControlsGroup
    {
      x = CENTERED_X(DIALOG_W) + 86 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 80 * GRID_W;
      h = CTRL_DEFAULT_H;
      class Controls
      {
        class Start:  ctrlStatic
        {
          text = "$STR_A3_RSCDISPLAYINTEL_CA_TEXTSTART";
          x = 0;
          y = 0;
          w = 10 * GRID_W;
          h = CTRL_DEFAULT_H;
        };
        class Position: ctrlXSliderH
        {
          idc = IDC_3DENRADIO_POSITION;
          x = 11 * GRID_W;
          y = 0;
          w = 58 * GRID_W;
          h = CTRL_DEFAULT_H;
          sliderRange[] = {0,1.5};
          colorActive[] = {1,1,1,0.6};
          onSliderPosChanged = "playMusic [uiNamespace getVariable ['ENH_3DENRadio_CurrentSongClass',''],sliderPosition (_this # 0)]";
        };
        class Time:  Start
        {
          idc = IDC_3DENRADIO_TIME;
          text = "00:00";
          x = 35 * GRID_W;
        };
        class End:  Start
        {
          text = "$STR_ENH_3DENRADIO_END";
          x = 69 * GRID_W;
        };
      };
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 26 * GRID_W;
      y = DIALOG_TOP + DIALOG_H * GRID_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};