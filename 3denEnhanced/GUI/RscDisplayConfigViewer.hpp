class RscDisplayConfigViewer
{
  scriptName = "RscDisplayConfigViewer";
  scriptPath = "GUI";
  onLoad = "['onLoad', _this, 'RscDisplayConfigViewer', 'GUI'] call (uinamespace getVariable 'BIS_fnc_initDisplay')";
  onUnload = "['onUnload', _this, 'RscDisplayConfigViewer', 'GUI'] call (uinamespace getVariable 'BIS_fnc_initDisplay')";
  idd = 2928;
  movingEnable = 0;
  enableSimulation = 1;
  class ControlsBackground
  {
    class TitleBackground: ctrlStaticTitle
    {
      x = safezoneX;
      y = safezoneY;
      w = safezoneW;
      h = CTRL_DEFAULT_H;
      colorBackground[] =
      {
        "(profilenamespace getVariable ['GUI_BCG_RGB_R', 0.77])",
        "(profilenamespace getVariable ['GUI_BCG_RGB_G', 0.51])",
        "(profilenamespace getVariable ['GUI_BCG_RGB_B', 0.08])",
        1
      };
      moving = 0;
    };
    class MainBackground: ctrlStaticBackground
    {
      idc = 11000;
      x = safezoneX;
      y = safezoneY + CTRL_DEFAULT_H;
      w = safezoneW;
      h = safezoneH - CTRL_DEFAULT_H;
      colorBackground[] = {0.2, 0.2, 0.2, 1};
    };
  };
  class Controls
  {
    class Title: ctrlStatic
    {
      idc = 1000;
      x = safezoneX + 5 * GRID_W;
      y = safezoneY;
      w = safezoneW;
      h = CTRL_DEFAULT_H;
      font = "EtelkaMonospacePro";
      sizeEx = SIZEEX_ETELKA(SIZEEX_S);
    };
    class TitleIcon: ctrlStaticPictureKeepAspect
    {
      idc = 1200;
      text = "\A3\ui_f\data\gui\rsc\rscdisplayarcademap\icon_config_ca.paa";
      x = safezoneX;
      y = safezoneY;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ListClasses: ctrlListbox //h is set automatically by BIS_fnc_configViewer
    {
      idc = 1500;
      x = safezoneX + GRID_W;
      y = safezoneY + 2 * CTRL_DEFAULT_H + 2 * GRID_H;
      w = 60 * GRID_W;
      font = "EtelkaMonospacePro";
      sizeEx = SIZEEX_ETELKA(SIZEEX_S);
    };
    class ListFavorites: ListClasses
    {
      idc = 1502;
      x = safezoneX + GRID_W;
      y = safezoneY + safezoneH - 41 * GRID_H;
      h = 40 * GRID_H;
      w = 60 * GRID_W;
      font = "EtelkaMonospacePro";
      sizeEx = SIZEEX_ETELKA(SIZEEX_S);
    };
    class SearchClasses: ctrlEdit
    {
      idc = 1001;
      x = safezoneX + GRID_W;
      y = safezoneY + CTRL_DEFAULT_H + GRID_H;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H;
      canModify = 0;
      font = "EtelkaMonospacePro";
      sizeEx = SIZEEX_ETELKA(SIZEEX_S);
    };
    class GroupDefault: ctrlControlsGroup
    {
      idc = 2300;
      x = safezoneX + 62 * GRID_W;
      y = safezoneY + CTRL_DEFAULT_H + GRID_H;
      w = safezoneW - 63 * GRID_W;
      h = safezoneH - 2 * CTRL_DEFAULT_H - 3 * GRID_H;
      class Controls
      {
        class SearchParams: ctrlEdit
        {
          idc = 1002;
          x = 0;
          y = 0;
          w = 60 * GRID_W;
          h = CTRL_DEFAULT_H;
          canModify = 0;
          font = "EtelkaMonospacePro";
          sizeEx = SIZEEX_ETELKA(SIZEEX_S);
        };
        class ListParams: ctrlListbox
        {
          idc = 1501;
          x = 0;
          y = CTRL_DEFAULT_H + GRID_H;
          w = 5;//safezoneW - 63 * GRID_W;
          h = safezoneH - 6 * CTRL_DEFAULT_H - 3 * GRID_H;
          font = "EtelkaMonospacePro";
          sizeEx = SIZEEX_ETELKA(SIZEEX_S);
        };
        class PathText: ctrlStatic
        {
          idc = 1003;
          x = -GRID_W;
          y = safezoneH - 3 * CTRL_DEFAULT_H - 6 * GRID_H;
          w = 17 * GRID_W;
          h = CTRL_DEFAULT_H;
          font = "EtelkaMonospacePro";
          sizeEx = SIZEEX_ETELKA(SIZEEX_S);
        };
        class ParentsText: PathText
        {
          idc = 1004;
          x = -GRID_W;
          y = safezoneH - 4 * CTRL_DEFAULT_H - 7 * GRID_H;
          w = 17 * GRID_W;
          h = CTRL_DEFAULT_H;
          font = "EtelkaMonospacePro";
          sizeEx = SIZEEX_ETELKA(SIZEEX_S);
        };
        class PathValue: ctrlEdit
        {
          idc = 1400;
          x = 18 * GRID_W;
          y = safezoneH - 3 * CTRL_DEFAULT_H - 6 * GRID_H;
          w = safezoneW - 81 * GRID_W;
          h = CTRL_DEFAULT_H;
          font = "EtelkaMonospacePro";
          sizeEx = SIZEEX_ETELKA(SIZEEX_S);
        };
        class ParentsValue: PathValue
        {
          idc = 1401;
          x = 18 * GRID_W;
          y = safezoneH - 4 * CTRL_DEFAULT_H - 7 * GRID_H;
          w = safezoneW - 81 * GRID_W;
          h = CTRL_DEFAULT_H;
          font = "EtelkaMonospacePro";
          sizeEx = SIZEEX_ETELKA(SIZEEX_S);
        };
      };
    };
    class BackgroundCustom: ctrlStaticBackground
    {
      idc = 1005;
    };
    class GroupCustom: ctrlControlsGroup
    {
      idc = 2301;
      x = safezoneX + 62 * GRID_W;
      y = safezoneY + CTRL_DEFAULT_H + GRID_H;
      w = safezoneW - 63 * GRID_W;
      h = safezoneH - 2 * CTRL_DEFAULT_H - 3 * GRID_H;
      class Controls
      {
        class CustomText: ctrlStructuredText //Used to display custom text when CV is opened via function
        {
          idc = 1100;
          x = safezoneX + 62 * GRID_W;
          y = safezoneY + CTRL_DEFAULT_H + GRID_H;
          w = safezoneW - 63 * GRID_W;
          h = 5; //So it can display a lot of text
        };
      };
    };
    class ButtonClose: ctrlButtonClose
    {
      idc = 2;
      x = safezoneX + safezoneW - 41 * GRID_W;
      y = safezoneY + safezoneH - CTRL_DEFAULT_H - GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonPreviewClass: ButtonClose
    {
      idc = 2400;
      x = safezoneX + safezoneW - 82 * GRID_W;
      y = safezoneY + safezoneH - CTRL_DEFAULT_H - GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonPreviewParam: ButtonClose
    {
      idc = 2401;
      x = safezoneX + safezoneW - 123 * GRID_W;
      y = safezoneY + safezoneH - CTRL_DEFAULT_H - GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonOK: ButtonClose
    {
      idc = 2600;
      text = "OK";
      x = safezoneX + safezoneW - 164 * GRID_W;
      y = safezoneY + safezoneH - CTRL_DEFAULT_H - GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      default = 1;
    };
  };
};