class RscTestControlStyles
{
  scriptName = "RscTestControlStyles";
  scriptPath = "GUI";
  onLoad = "[""onLoad"",_this,""RscTestControlStyles"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
  onUnload = "[""onUnload"",_this,""RscTestControlStyles"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
  idd = 999;
  enableSimulation = 1;
  movingEnable = 0;
  class ControlsBackground
  {
    class Background
    {
      idc = -1;
      type = 0;
      style = 0;
      x = GUI_GRID_CENTER_X;
      y = GUI_GRID_CENTER_Y;
      w = GUI_GRID_WAbs;
      h = GUI_GRID_HAbs;
      colorBackground[] = {1,1,1,1};
      colorText[] = {0,0,0,0};
      font = "RobotoCondensed";
      sizeEx = GUI_GRID_H;
      text = "";
      moving = 0;
    };
  };
  class Controls
  {
    class _ST_LEFT
    {
      type = 0;
      idc = 0;
      style = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 1 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 2 * GUI_GRID_H;
      text = "ST_LEFT";
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      lineSpacing = 1;
      colorText[] = {0,0,0,1};
      colorBackground[] = {1,0.5,0,1};
    };
    class _ST_RIGHT: _ST_LEFT
    {
      idc = 1;
      style = 1;
      text = "ST_RIGHT";
      y = 4 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_CENTER: _ST_LEFT
    {
      idc = 2;
      style = 2;
      text = "ST_CENTER";
      y = 7 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_MULTI: _ST_LEFT
    {
      idc = 16;
      style = 16;
      text = "ST_MULTI\nST_MULTI";
      y = 10 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_TITLE_BAR: _ST_LEFT
    {
      idc = 32;
      moving = 0;
      style = 32;
      text = "ST_TITLE_BAR";
      y = 13 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_PICTURE: _ST_LEFT
    {
      idc = 48;
      style = 48;
      text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
      y = 16 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_PICTURE_video: _ST_LEFT
    {
      idc = "0x30 + 1000";
      style = 48;
      text = "\A3\Missions_F_Bootcamp\video\VR_BOOT.ogv";
      colorText[] = {1,1,1,1};
      y = 19 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 8 * GUI_GRID_W;
      h = 5 * GUI_GRID_H;
      autoplay = 1;
      loops = 1;
    };
    class _ST_FRAME: _ST_LEFT
    {
      idc = 64;
      style = 64;
      text = "ST_FRAME";
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 1 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_BACKGROUND: _ST_FRAME
    {
      idc = 80;
      style = 80;
      text = "ST_BACKGROUND";
      y = 4 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_GROUP_BOX: _ST_FRAME
    {
      idc = 96;
      style = 96;
      text = "ST_GROUP_BOX";
      y = 7 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_GROUP_BOX2: _ST_FRAME
    {
      idc = 112;
      style = 112;
      text = "ST_GROUP_BOX2";
      y = 10 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_HUD_BACKGROUND: _ST_FRAME
    {
      idc = 128;
      style = 128;
      text = "ST_HUD_BACKGROUND";
      y = 13 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_TILE_PICTURE: _ST_FRAME
    {
      idc = 144;
      style = 144;
      text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
      y = 16 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      tileW = 10;
      tileH = 2;
    };
    class _ST_WITH_RECT: _ST_FRAME
    {
      idc = 160;
      style = 160;
      text = "ST_WITH_RECT";
      y = 19 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_LINE: _ST_FRAME
    {
      idc = 176;
      style = 176;
      text = "ST_LINE";
      y = 22 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_UPPERCASE
    {
      idc = 192;
      style = 192;
      type = 16;
      text = "st_UPPERCASE";
      x = 23 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 1 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 2 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      colorBackground2[] = {0,0,0,1};
      colorBackgroundFocused[] = {1,0.5,0,1};
      colorBackgroundActive[] = {0,0,0,1};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 1;
      color[] = {1,1,1,1};
      color2[] = {1,1,1,1};
      colorFocused[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
      animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
      tooltip = "CT_SHORTCUTBUTTON";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      period = 1;
      periodFocus = 1;
      periodOver = 0.5;
      shortcuts[] = {"0x00050000 + 0",28,57,156};
      textureNoShortcut = "#(argb,8,8,3)color(1,1,1,0)";
      soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
      soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
      soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
      soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
      class Attributes
      {
        align = "left";
        color = "#ffffff";
        font = "RobotoCondensed";
        shadow = 0;
      };
      class HitZone
      {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
      };
      class TextPos
      {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
      };
      class ShortcutPos
      {
        left = 0;
        top = 0;
        w = GUI_GRID_W;
        h = GUI_GRID_H;
      };
    };
    class _ST_LOWERCASE: _ST_UPPERCASE
    {
      idc = 208;
      style = 208;
      text = "st_LOWERCASE";
      y = 4 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_SHADOW: _ST_LEFT
    {
      idc = 256;
      style = 256;
      text = "ST_SHADOW";
      x = 23 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 7 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_NO_RECT: _ST_SHADOW
    {
      idc = 512;
      style = 512;
      text = "ST_NO_RECT";
      y = 10 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _ST_KEEP_ASPECT_RATIO: _ST_SHADOW
    {
      idc = 2048;
      style = "0x30 + 0x800";
      text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
      y = 13 * GUI_GRID_H + GUI_GRID_CENTER_Y;
    };
    class _SL_HORZ
    {
      type = 3;
      idc = "3 + 0x400";
      style = 1024;
      x = 23 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 16 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      color[] = {0,0,0,1};
      colorDisabled[] = {1,1,1,0.5};
      colorActive[] = {1,0.5,0,1};
      tooltip = "SL_HORZ";
    };
    class _SL_VERT: _SL_HORZ
    {
      idc = "3 + 0";
      style = 0;
      x = 35 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 14 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 1 * GUI_GRID_W;
      h = 10 * GUI_GRID_H;
      tooltip = "SL_VERT";
    };
    class _ST_HORIZONTAL
    {
      type = 8;
      idc = "8 + 0";
      style = 0;
      x = 23 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 18 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      texture = "#(argb,8,8,3)color(1,1,1,1)";
      colorBar[] = {0,0,0,1};
      colorFrame[] = {0,0,0,1};
      tooltip = "ST_HORIZONTAL";
    };
    class _ST_VERTICAL: _ST_HORIZONTAL
    {
      idc = "8 + 0x01";
      style = 1;
      x = 37 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 14 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 1 * GUI_GRID_W;
      h = 10 * GUI_GRID_H;
      tooltip = "ST_VERTICAL";
    };
  };
};
class RscText;
class RscTestControlTypes
{
  scriptName = "RscTestControlTypes";
  scriptPath = "GUI";
  onLoad = "[""onLoad"",_this,""RscTestControlTypes"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
  onUnload = "[""onUnload"",_this,""RscTestControlTypes"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
  idd = 999;
  enableSimulation = 0;
  enableDisplay = 0;
  closeOnMissionEnd = 0;
  class ControlsBackground
  {
    class Background: RscText
    {
      x = GUI_GRID_CENTER_X;
      y = GUI_GRID_CENTER_Y;
      w = GUI_GRID_WAbs;
      h = GUI_GRID_HAbs;
      colorBackground[] = {0.5,0.5,0.5,1};
      moving = 0;
    };
  };
  class Controls
  {
    class _CT_STATIC
    {
      access = 0;
      idc = 0;
      type = 0;
      style = "0x00 + 0x10";
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 1;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 1 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      text = "CT_STATIC";
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 1;
      lineSpacing = 1;
      fixedWidth = 1;
      colorText[] = {1,1,1,1};
      colorShadow[] = {0,0,0,0.5};
      tooltip = "CT_STATIC";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      moving = 0;
      autoplay = 0;
      loops = 0;
      tileW = 1;
      tileH = 1;
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onVideoStopped = "diag_log ['Log: onVideoStopped',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_BUTTON
    {
      access = 0;
      idc = 1;
      type = 1;
      style = 0;
      default = 1;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 3 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      colorBackgroundDisabled[] = {0,0,0,0.5};
      colorBackgroundActive[] = {0,0,0,1};
      colorFocused[] = {1,0.5,0,1};
      text = "CT_BUTTON";
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 1;
      colorText[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      tooltip = "CT_BUTTON";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      borderSize = 0.01;
      colorBorder[] = {1,1,1,1};
      colorShadow[] = {0,0,0,0.2};
      offsetX = 0.0075;
      offsetY = 0.01;
      offsetPressedX = 0.0075;
      offsetPressedY = 0.01;
      period = 1;
      periodFocus = 2;
      periodOver = 0.5;
      soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
      soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
      soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
      soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
      class KeyHints
      {
        class A
        {
          key = "0x00050000 + 0";
          hint = "KEY_XBOX_A";
        };
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onButtonClick = "diag_log ['Log: onButtonClick',ctrlClassname (_this select 0),_this]; false";
      onButtonDown = "diag_log ['Log: onButtonDown',ctrlClassname (_this select 0),_this]; false";
      onButtonUp = "diag_log ['Log: onButtonUp',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_EDIT
    {
      access = 0;
      idc = 2;
      type = 2;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 5 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      text = "CT_EDIT";
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {0,0,0,1};
      colorDisabled[] = {1,1,1,0.5};
      colorSelection[] = {1,0.5,0,1};
      tooltip = "CT_EDIT";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      canModify = 1;
      autocomplete = "scripting";
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
    };
    class _CT_SLIDER_Value: _CT_STATIC
    {
      idc = 1200;
      style = 2;
      blinkingPeriod = 0;
      x = 8 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 6.75 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 3 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorBackground[] = {0,0,0,0};
      fixedWidth = 0;
    };
    class _CT_SLIDER
    {
      access = 0;
      idc = 3;
      type = 3;
      style = 1024;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 7 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 7 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      color[] = {0,0,0,1};
      colorDisabled[] = {1,1,1,0.5};
      colorActive[] = {1,0.5,0,1};
      tooltip = "CT_SLIDER";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      sliderRange[] = {0,100};
      sliderPosition = 42;
      class Title
      {
        idc = -1;
        colorBase[] = {1,1,1,1};
        colorActive[] = {1,0.5,0,1};
      };
      class Value
      {
        idc = 1200;
        format = "%.f";
        type = "SPTPlain";
        colorBase[] = {1,1,1,1};
        colorActive[] = {1,0.5,0,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onSliderPosChanged = "diag_log ['Log: onSliderPosChanged',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_COMBO
    {
      access = 0;
      idc = 4;
      type = 4;
      style = "0x00 + 0x10";
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 9 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      colorSelectBackground[] = {1,0.5,0,1};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      colorSelect[] = {1,1,1,1};
      colorPicture[] = {1,0.5,0,1};
      colorPictureSelect[] = {1,1,1,1};
      colorPictureDisabled[] = {1,1,1,0.5};
      tooltip = "CT_COMBO";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
      arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
      wholeHeight = 5 * GUI_GRID_H;
      maxHistoryDelay = 1;
      soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1};
      soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1};
      soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1};
      class ComboScrollBar
      {
        width = 0;
        height = 0;
        scrollSpeed = 0.01;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onLBSelChanged = "diag_log ['Log: onLBSelChanged',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_LISTBOX
    {
      access = 0;
      idc = 5;
      type = 5;
      style = "0x00 + 0x10";
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 11 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 3 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      colorSelectBackground[] = {1,0.5,0,1};
      colorSelectBackground2[] = {0,0,0,1};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      colorSelect[] = {1,1,1,1};
      colorSelect2[] = {1,1,1,1};
      colorShadow[] = {0,0,0,0.5};
      colorPicture[] = {1,0.5,0,1};
      colorPictureSelected[] = {1,1,1,1};
      colorPictureDisabled[] = {1,1,1,0.5};
      colorPictureRight[] = {1,0.5,0,1};
      colorPictureRightSelected[] = {1,1,1,1};
      colorPictureRightDisabled[] = {1,1,1,0.5};
      tooltip = "CT_LISTBOX";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      period = 1;
      rowHeight = 1.5 * GUI_GRID_H;
      itemSpacing = 0;
      maxHistoryDelay = 1;
      canDrag = 1;
      soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
      class ListScrollBar
      {
        width = 0;
        height = 0;
        scrollSpeed = 0.01;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onLBSelChanged = "diag_log ['Log: onLBSelChanged',ctrlClassname (_this select 0),_this]; false";
      onLBDblClick = "diag_log ['Log: onLBDblClick',ctrlClassname (_this select 0),_this]; false";
      onLBDrag = "diag_log ['Log: onLBDrag',ctrlClassname (_this select 0),_this]; false";
      onLBDragging = "diag_log ['Log: onLBDragging',ctrlClassname (_this select 0),_this]; false";
      onLBDrop = "diag_log ['Log: onLBDrop',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_TOOLBOX
    {
      access = 0;
      idc = 6;
      type = 6;
      style = 2;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 15 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 2 * GUI_GRID_H;
      colorSelectedBg[] = {1,0.5,0,1};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {1,1,1,1};
      colorTextSelect[] = {1,1,1,1};
      tooltip = "CT_TOOLBOX";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      rows = 2;
      columns = 2;
      strings[] = {"Alpha","Bravo","Charlie","Delta"};
      values[] = {1,2,3,4};
      color[] = {0,0,0,0};
      colorSelect[] = {0,0,0,0};
      colorTextDisable[] = {0,0,0,0};
      colorDisable[] = {0,0,0,0};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onToolBoxSelChanged = "diag_log ['Log: onToolBoxSelChanged',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_CHECKBOXES
    {
      access = 0;
      idc = 7;
      type = 7;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 18 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 2 * GUI_GRID_H;
      colorSelectedBg[] = {1,0.5,0,1};
      text = "CT_CHECKBOXES";
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {1,1,1,0.5};
      colorTextSelect[] = {1,1,1,1};
      tooltip = "CT_CHECKBOXES";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      rows = 2;
      columns = 2;
      strings[] = {"A","B","C","D"};
      checked_strings[] = {"Alpha","Bravo","Charlie","Delta"};
      values[] = {1,2,3,4};
      color[] = {0,0,0,0};
      colorSelect[] = {0,0,0,0};
      colorTextDisable[] = {0,0,0,0};
      colorDisable[] = {0,0,0,0};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onCheckBoxesSelChanged = "diag_log ['Log: onCheckBoxesSelChanged',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_PROGRESS
    {
      access = 0;
      idc = 8;
      type = 8;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 21 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      texture = "#(argb,8,8,3)color(1,1,1,1)";
      colorBar[] = {1,1,1,1};
      colorFrame[] = {0,0,0,1};
      tooltip = "CT_PROGRESS";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_HTML
    {
      access = 0;
      idc = 9;
      type = 9;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 1 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 23 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1.5 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      colorText[] = {1,1,1,1};
      colorBold[] = {1,1,1,1};
      colorLink[] = {1,1,1,1};
      colorLinkActive[] = {1,0.5,0,1};
      colorPicture[] = {1,1,1,1};
      colorPictureBorder[] = {0,0,0,0};
      colorPictureLink[] = {1,1,1,1};
      colorPictureSelected[] = {1,1,1,1};
      prevPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
      nextPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";
      tooltip = "CT_HTML";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      filename = "a3\ui_f\data\html\RscFeedback.html";
      class P
      {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = GUI_GRID_H;
        align = "left";
      };
      class H1: P
      {
      };
      class H2: P
      {
      };
      class H3: P
      {
      };
      class H4: P
      {
      };
      class H5: P
      {
      };
      class H6: P
      {
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onHTMLLink = "diag_log ['Log: onHTMLLink',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_ACTIVETEXT
    {
      access = 0;
      idc = 11;
      type = 11;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 1 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      text = "CT_ACTIVETEXT";
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      color[] = {1,1,1,1};
      colorActive[] = {1,0.5,0,1};
      colorDisabled[] = {0.3,0.3,0.3,1};
      tooltip = "CT_ACTIVETEXT";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      soundClick[] = {"",1,1};
      soundEnter[] = {"",1,1};
      soundPush[] = {"",1,1};
      soundEscape[] = {"",1,1};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onButtonClick = "diag_log ['Log: onButtonClick',ctrlClassname (_this select 0),_this]; false";
      onButtonDown = "diag_log ['Log: onButtonDown',ctrlClassname (_this select 0),_this]; false";
      onButtonUp = "diag_log ['Log: onButtonUp',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_TREE
    {
      access = 0;
      idc = 12;
      type = 12;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 3 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 3 * GUI_GRID_H;
      colorBorder[] = {0,0,0,1};
      colorBackground[] = {0.2,0.2,0.2,1};
      colorSelect[] = {1,0.5,0,1};
      colorMarked[] = {1,0.5,0,0.5};
      colorMarkedSelected[] = {1,0.5,0,1};
      colorPicture[] = {1,1,1,1};
      colorPictureSelected[] = {0,0,0,1};
      colorPictureDisabled[] = {1,1,1,0.25};
      colorPictureRight[] = {1,1,1,1};
      colorPictureRightSelected[] = {0,0,0,1};
      colorPictureRightDisabled[] = {1,1,1,0.25};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 1;
      colorText[] = {1,1,1,1};
      colorSelectText[] = {1,1,1,1};
      colorMarkedText[] = {1,1,1,1};
      tooltip = "CT_TREE";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      multiselectEnabled = 1;
      expandOnDoubleclick = 1;
      hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa";
      expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa";
      maxHistoryDelay = 1;
      class ScrollBar
      {
        width = 0;
        height = 0;
        scrollSpeed = 0.01;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
      };
      colorDisabled[] = {0,0,0,0};
      colorArrow[] = {0,0,0,0};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onTreeSelChanged = "diag_log ['Log: onTreeSelChanged',ctrlClassname (_this select 0),_this]; false";
      onTreeLButtonDown = "diag_log ['Log: onTreeLButtonDown',ctrlClassname (_this select 0),_this]; false";
      onTreeDblClick = "diag_log ['Log: onTreeDblClick',ctrlClassname (_this select 0),_this]; false";
      onTreeExpanded = "diag_log ['Log: onTreeExpanded',ctrlClassname (_this select 0),_this]; false";
      onTreeCollapsed = "diag_log ['Log: onTreeCollapsed',ctrlClassname (_this select 0),_this]; false";
      onTreeMouseExit = "diag_log ['Log: onTreeMouseExit',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_STRUCTURED_TEXT
    {
      access = 0;
      idc = 13;
      type = 13;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 7 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      text = "<img image='\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa' size='0.5' />CT_<t size='0.8' underline='1' color='#ffff8000' font='PuristaBold' shadow='1' shadowColor='#000000'><a href='https://arma3.com'>STRUCTURED</a></t>_TEXT";
      size = GUI_GRID_H;
      tooltip = "CT_STRUCTURED_TEXT";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      class Attributes
      {
        align = "left";
        color = "#ffffff";
        colorLink = "#ff8000";
        size = 1;
        font = "RobotoCondensed";
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_CONTROLS_GROUP
    {
      access = 0;
      idc = 15;
      type = 15;
      style = 16;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 9 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 3 * GUI_GRID_H;
      class Controls
      {
        class _CT_STATIC: _CT_STATIC
        {
          idc = 1300;
          style = 48;
          blinkingPeriod = 0;
          x = 0;
          y = 0;
          w = 20 * GUI_GRID_W;
          h = 5 * GUI_GRID_H;
          text = "#(ai,512,512,1)perlinNoise(512,128,0,1)";
          tooltip = "CT_CONTROLS_GROUP";
        };
      };
      class VScrollBar
      {
        width = 0.021;
        height = 0;
        scrollSpeed = 0.01;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
        autoScrollEnabled = 1;
        autoScrollDelay = 1;
        autoScrollRewind = 1;
        autoScrollSpeed = 1;
      };
      class HScrollBar
      {
        width = 0;
        height = 0.028;
        scrollSpeed = 0.01;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
    };
    class _CT_SHORTCUTBUTTON
    {
      access = 0;
      idc = 16;
      type = 16;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 13 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorBackground[] = {0.2,0.2,0.2,1};
      colorBackground2[] = {0,0,0,1};
      colorBackgroundFocused[] = {1,0.5,0,1};
      colorBackgroundActive[] = {0,0,0,1};
      text = "CT_SHORTCUTBUTTON";
      size = GUI_GRID_H;
      sizeEx = 0;
      font = "RobotoCondensed";
      shadow = 1;
      color[] = {1,1,1,1};
      color2[] = {1,1,1,1};
      colorFocused[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
      animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
      animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
      tooltip = "CT_SHORTCUTBUTTON";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      period = 1;
      periodFocus = 1;
      periodOver = 0.5;
      shortcuts[] = {"0x00050000 + 0",28,57,156};
      textureNoShortcut = "#(argb,8,8,3)color(1,1,1,1)";
      soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
      soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
      soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
      soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
      class Attributes
      {
        align = "left";
        color = "#ffffff";
        font = "RobotoCondensed";
        shadow = 0;
      };
      class HitZone
      {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
      };
      class TextPos
      {
        left = GUI_GRID_W;
        top = 0;
        right = 0;
        bottom = 0;
      };
      class ShortcutPos
      {
        left = 0;
        top = 0;
        w = GUI_GRID_W;
        h = GUI_GRID_H;
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onButtonClick = "diag_log ['Log: onButtonClick',ctrlClassname (_this select 0),_this]; false";
      onButtonDown = "diag_log ['Log: onButtonDown',ctrlClassname (_this select 0),_this]; false";
      onButtonUp = "diag_log ['Log: onButtonUp',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_XBUTTON
    {
      access = 0;
      idc = 41;
      type = 41;
      style = 0;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 15 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorBackground[] = {0,0,0,0};
      colorActiveBackground[] = {1,0.5,0,1};
      colorActiveBackground2[] = {0,0,0,1};
      colorDisabled[] = {0,1,1,1};
      text = "CT_XBUTTON";
      size = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      color[] = {1,1,1,1};
      colorActive[] = {1,1,1,1};
      colorActive2[] = {1,1,1,1};
      tooltip = "CT_XBUTTON";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      period = 1;
      soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
      soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
      soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
      soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onButtonClick = "diag_log ['Log: onButtonClick',ctrlClassname (_this select 0),_this]; false";
      onButtonDown = "diag_log ['Log: onButtonDown',ctrlClassname (_this select 0),_this]; false";
      onButtonUp = "diag_log ['Log: onButtonUp',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_XLISTBOX
    {
      access = 0;
      idc = 42;
      type = 42;
      style = "0x400 + 0x02 + 0x10";
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 17 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      color[] = {1,1,1,1};
      colorActive[] = {1,0.5,0,1};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {1,1,1,1};
      colorSelect[] = {1,0.5,0,1};
      colorDisabled[] = {1,1,1,0.5};
      tooltip = "CT_XLISTBOX";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
      arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
      border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
      soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onLBSelChanged = "diag_log ['Log: onLBSelChanged',ctrlClassname (_this select 0),_this]; false";
      onLBDblClick = "diag_log ['Log: onLBDblClick',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_XSLIDER
    {
      access = 0;
      idc = 43;
      type = 43;
      style = 1024;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 19 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      color[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      colorActive[] = {1,0.5,0,1};
      tooltip = "CT_XSLIDER";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      sliderRange[] = {0,100};
      sliderPosition = 42;
      arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
      arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
      border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
      thumb = "#(argb,8,8,3)color(1,1,1,1)";
      class Title
      {
        idc = -1;
        colorBase[] = {1,1,1,1};
        colorActive[] = {1,0.5,0,1};
      };
      class Value
      {
        idc = -1;
        format = "%.f";
        type = "SPTPlain";
        colorBase[] = {1,1,1,1};
        colorActive[] = {1,0.5,0,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onSliderPosChanged = "diag_log ['Log: onSliderPosChanged',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_XCOMBO
    {
      access = 0;
      idc = 44;
      type = 44;
      style = "0x00 + 0x10";
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 22 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      colorSelectBackground2[] = {0,0,0,1};
      colorBorder[] = {1,0,1,1};
      colorSelectBorder[] = {1,1,1,1};
      colorDisabledBorder[] = {0,1,1,1};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {1,1,1,1};
      colorSelect[] = {1,1,1,1};
      colorSelect2[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      tooltip = "CT_XCOMBO";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1};
      soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1};
      soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1};
      class Title
      {
        text = "CT_XCOMBO";
        x = 12 * GUI_GRID_W + GUI_GRID_CENTER_X;
        y = 21 * GUI_GRID_H + GUI_GRID_CENTER_Y;
        w = 10 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        colorBackground[] = {0.2,0.2,0.2,1};
        colorSelectBackground[] = {1,0.5,0,1};
        colorBorder[] = {0,0,0,1};
        colorSelectBorder[] = {0,0,0,1};
        colorDisabledBorder[] = {1,1,1,1};
        font = "RobotoCondensed";
        size = GUI_GRID_H;
        colorText[] = {1,1,1,1};
        colorSelect[] = {1,1,1,1};
        colorDisabled[] = {1,1,1,0.5};
      };
      class List
      {
        x = 22 * GUI_GRID_W + GUI_GRID_CENTER_X;
        y = 22 * GUI_GRID_H + GUI_GRID_CENTER_Y;
        w = 10 * GUI_GRID_W;
        h = 5 * GUI_GRID_H;
        colorBackground[] = {0.2,0.2,0.2,1};
        colorSelectBackground[] = {1,0.5,0,1};
        colorBorder[] = {1,1,1,1};
        rowHeight = 1 * GUI_GRID_H;
        sizeEx = GUI_GRID_H;
        colorText[] = {1,1,1,1};
        colorSelect[] = {1,1,1,1};
      };
      class ScrollBar
      {
        width = 0;
        height = 0;
        scrollSpeed = 0.01;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onLBSelChanged = "diag_log ['Log: onLBSelChanged',ctrlClassname (_this select 0),_this]; false";
      onLBDblClick = "diag_log ['Log: onLBDblClick',ctrlClassname (_this select 0),_this]; false";
      onLBListSelChanged = "diag_log ['Log: onLBListSelChanged',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_MAP
    {
      access = 0;
      idc = 100;
      type = 101;
      style = 48;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 29 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 1 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 6 * GUI_GRID_H;
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      colorText[] = {0,0,0,1};
      tooltip = "CT_MAP";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      moveOnEdges = 1;
      ptsPerSquareSea = 5;
      ptsPerSquareTxt = 20;
      ptsPerSquareCLn = 10;
      ptsPerSquareExp = 10;
      ptsPerSquareCost = 10;
      ptsPerSquareFor = 9;
      ptsPerSquareForEdge = 9;
      ptsPerSquareRoad = 6;
      ptsPerSquareObj = 9;
      scaleMin = 0.001;
      scaleMax = 1;
      scaleDefault = 0.16;
      alphaFadeStartScale = 0.1;
      alphaFadeEndScale = 0.01;
      maxSatelliteAlpha = 0.85;
      text = "#(argb,8,8,3)color(1,1,1,1)";
      colorBackground[] = {1,1,1,1};
      colorOutside[] = {0,0,0,1};
      colorSea[] = {0.4,0.6,0.8,0.5};
      colorForest[] = {0.6,0.8,0.4,0.5};
      colorForestBorder[] = {0.6,0.8,0.4,1};
      colorRocks[] = {0,0,0,0.3};
      colorRocksBorder[] = {0,0,0,1};
      colorLevels[] = {0.3,0.2,0.1,0.5};
      colorMainCountlines[] = {0.6,0.4,0.2,0.5};
      colorCountlines[] = {0.6,0.4,0.2,0.3};
      colorMainCountlinesWater[] = {0.5,0.6,0.7,0.6};
      colorCountlinesWater[] = {0.5,0.6,0.7,0.3};
      colorPowerLines[] = {0.1,0.1,0.1,1};
      colorRailWay[] = {0.8,0.2,0,1};
      colorNames[] = {1.1,0.1,1.1,0.9};
      colorInactive[] = {1,1,0,0.5};
      colorTracks[] = {0.8,0.8,0.7,0.2};
      colorTracksFill[] = {0.8,0.7,0.7,1};
      colorRoads[] = {0.7,0.7,0.7,1};
      colorRoadsFill[] = {1,1,1,1};
      colorMainRoads[] = {0.9,0.5,0.3,1};
      colorMainRoadsFill[] = {1,0.6,0.4,1};
      colorGrid[] = {0.1,0.1,0.1,0.6};
      colorGridMap[] = {0.1,0.1,0.1,0.6};
      fontLabel = "RobotoCondensed";
      sizeExLabel = GUI_GRID_H * 0.5;
      fontGrid = "TahomaB";
      sizeExGrid = GUI_GRID_H * 0.5;
      fontUnits = "TahomaB";
      sizeExUnits = GUI_GRID_H * 0.5;
      fontNames = "RobotoCondensed";
      sizeExNames = GUI_GRID_H * 0.5;
      fontInfo = "RobotoCondensed";
      sizeExInfo = GUI_GRID_H * 0.5;
      fontLevel = "TahomaB";
      sizeExLevel = GUI_GRID_H * 0.5;
      showCountourInterval = 1;
      widthRailWay = 1;
      class LineMarker
      {
        textureComboBoxColor = "#(argb,8,8,3)color(1,1,1,1)";
        lineWidthThin = 0.008;
        lineWidthThick = 0.014;
        lineDistanceMin = 3e-005;
        lineLengthMin = 5;
      };
      class Task
      {
        icon = "#(argb,8,8,3)color(1,1,1,1)";
        color[] = {1,1,0,1};
        iconCreated = "#(argb,8,8,3)color(1,1,1,1)";
        colorCreated[] = {0,0,0,1};
        iconCanceled = "#(argb,8,8,3)color(1,1,1,1)";
        colorCanceled[] = {0,0,0,0.5};
        iconDone = "#(argb,8,8,3)color(1,1,1,1)";
        colorDone[] = {0,1,0,1};
        iconFailed = "#(argb,8,8,3)color(1,1,1,1)";
        colorFailed[] = {1,0,0,1};
        size = 8;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
      };
      class ActiveMarker
      {
        color[] = {0,0,0,1};
        size = 2;
      };
      class Waypoint
      {
        coefMax = 1;
        coefMin = 4;
        color[] = {0,0,0,1};
        icon = "#(argb,8,8,3)color(0,0,0,1)";
        importance = 1;
        size = 2;
      };
      class WaypointCompleted: Waypoint
      {
      };
      class CustomMark: Waypoint
      {
      };
      class Command: Waypoint
      {
      };
      class Bush: Waypoint
      {
      };
      class Rock: Waypoint
      {
      };
      class SmallTree: Waypoint
      {
      };
      class Tree: Waypoint
      {
      };
      class BusStop: Waypoint
      {
      };
      class FuelStation: Waypoint
      {
      };
      class Hospital: Waypoint
      {
      };
      class Church: Waypoint
      {
      };
      class Lighthouse: Waypoint
      {
      };
      class Power: Waypoint
      {
      };
      class PowerSolar: Waypoint
      {
      };
      class PowerWave: Waypoint
      {
      };
      class PowerWind: Waypoint
      {
      };
      class Quay: Waypoint
      {
      };
      class Transmitter: Waypoint
      {
      };
      class Watertower: Waypoint
      {
      };
      class Cross: Waypoint
      {
      };
      class Chapel: Waypoint
      {
      };
      class Shipwreck: Waypoint
      {
      };
      class Bunker: Waypoint
      {
      };
      class Fortress: Waypoint
      {
      };
      class Fountain: Waypoint
      {
      };
      class Ruin: Waypoint
      {
      };
      class Stack: Waypoint
      {
      };
      class Tourism: Waypoint
      {
      };
      class ViewTower: Waypoint
      {
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onDraw = "";
    };
    class _CT_MAP_MAIN: _CT_MAP
    {
      access = 0;
      idc = 101;
      type = 101;
      style = 48;
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 29 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 8 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 6 * GUI_GRID_H;
      tooltip = "CT_MAP_MAIN";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      showCountourInterval = 1;
      class Legend
      {
        x = 30 * GUI_GRID_W + GUI_GRID_CENTER_X;
        y = 9 * GUI_GRID_H + GUI_GRID_CENTER_Y;
        w = 8 * GUI_GRID_W;
        h = 4 * GUI_GRID_H;
        colorBackground[] = {1,1,1,1};
        font = "RobotoCondensed";
        sizeEx = 0.8 * GUI_GRID_H;
        color[] = {0,0,0,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onDraw = "";
    };
    class _CT_LISTNBOX
    {
      access = 0;
      idc = 102;
      type = 102;
      style = "0x00 + 0x10";
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 29 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 15 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 10 * GUI_GRID_W;
      h = 3 * GUI_GRID_H;
      colorSelectBackground[] = {1,0.5,0,1};
      colorSelectBackground2[] = {0,0,0,1};
      sizeEx = GUI_GRID_H;
      font = "RobotoCondensed";
      shadow = 0;
      colorText[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.5};
      colorSelect[] = {1,1,1,1};
      colorSelect2[] = {1,1,1,1};
      colorShadow[] = {0,0,0,0.5};
      tooltip = "CT_LISTNBOX";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      columns[] = {0.1,0.4};
      drawSideArrows = 1;
      idcLeft = 1000;
      idcRight = 1001;
      period = 1;
      rowHeight = GUI_GRID_H;
      maxHistoryDelay = 1;
      soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
      class ListScrollBar
      {
        width = 0;
        height = 0;
        scrollSpeed = 0.01;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
      };
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onLBSelChanged = "diag_log ['Log: onLBSelChanged',ctrlClassname (_this select 0),_this]; false";
      onLBDblClick = "diag_log ['Log: onLBDblClick',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_LISTNBOX_RIGHT: _CT_BUTTON
    {
      idc = 1000;
      text = "<";
      borderSize = 0;
      colorShadow[] = {0,0,0,0};
    };
    class _CT_LISTNBOX_LEFT: _CT_LISTNBOX_RIGHT
    {
      idc = 1001;
      text = ">";
    };
    class _CT_CHECKBOX
    {
      access = 0;
      idc = 77;
      type = 77;
      style = "0x00 + 0x10";
      default = 0;
      enable = 1;
      show = 1;
      fade = 0;
      blinkingPeriod = 0;
      x = 29 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 20 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      w = 1 * GUI_GRID_W;
      h = 1 * GUI_GRID_H;
      color[] = {1,1,1,0.7};
      colorFocused[] = {1,1,1,1};
      colorHover[] = {1,1,1,1};
      colorPressed[] = {1,1,1,1};
      colorDisabled[] = {1,1,1,0.2};
      colorBackground[] = {0,0,0,0};
      colorBackgroundFocused[] = {0,0,0,0};
      colorBackgroundHover[] = {0,0,0,0};
      colorBackgroundPressed[] = {0,0,0,0};
      colorBackgroundDisabled[] = {0,0,0,0};
      textureChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
      textureUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
      textureFocusedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
      textureFocusedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
      textureHoverChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
      textureHoverUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
      texturePressedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
      texturePressedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
      textureDisabledChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
      textureDisabledUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
      tooltip = "CT_CHECKBOX";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
      soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
      soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
      soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
      onCanDestroy = "diag_log ['Log: onCanDestroy',ctrlClassname (_this select 0),_this]; true";
      onDestroy = "diag_log ['Log: onDestroy',ctrlClassname (_this select 0),_this]; false";
      onMouseEnter = "diag_log ['Log: onMouseEnter',ctrlClassname (_this select 0),_this]; false";
      onMouseExit = "diag_log ['Log: onMouseExit',ctrlClassname (_this select 0),_this]; false";
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
    };
  };
  class Objects
  {
    class _CT_OBJECT
    {
      access = 0;
      idc = 80;
      type = 80;
      style = 0;
      enable = 1;
      show = 1;
      blinkingPeriod = 0;
      model = "\a3\Ui_f\objects\Watch.p3d";
      scale = 2;
      x = 26 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 4 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      z = 1;
      direction[] = {0,0,1};
      up[] = {0,1,0};
      tooltip = "CT_OBJECT";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onObjectMoved = "diag_log ['Log: onObjectMoved',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_OBJECT_ZOOM
    {
      access = 0;
      idc = 81;
      type = 81;
      style = 0;
      enable = 1;
      show = 1;
      blinkingPeriod = 0;
      model = "\a3\Ui_f\objects\Compass.p3d";
      scale = 2;
      x = 26 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 13 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      z = 1;
      xBack = 26 * GUI_GRID_W + GUI_GRID_CENTER_X;
      yBack = 13 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      zBack = 2;
      enableZoom = 1;
      zoomDuration = 0.5;
      inBack = 0;
      direction[] = {0,1,1};
      up[] = {0,1,0};
      tooltip = "CT_OBJECT_ZOOM";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      onSetFocus = "diag_log ['Log: onSetFocus',ctrlClassname (_this select 0),_this]; false";
      onKillFocus = "diag_log ['Log: onKillFocus',ctrlClassname (_this select 0),_this]; false";
      onKeyDown = "diag_log ['Log: onKeyDown',ctrlClassname (_this select 0),_this]; false";
      onKeyUp = "diag_log ['Log: onKeyUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDown = "diag_log ['Log: onMouseButtonDown',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonUp = "diag_log ['Log: onMouseButtonUp',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonClick = "diag_log ['Log: onMouseButtonClick',ctrlClassname (_this select 0),_this]; false";
      onMouseButtonDblClick = "diag_log ['Log: onMouseButtonDblClick',ctrlClassname (_this select 0),_this]; false";
      onMouseZChanged = "diag_log ['Log: onMouseZChanged',ctrlClassname (_this select 0),_this]; false";
      onMouseMoving = "";
      onMouseHolding = "";
      onObjectMoved = "diag_log ['Log: onObjectMoved',ctrlClassname (_this select 0),_this]; false";
    };
    class _CT_OBJECT_CONTAINER
    {
      access = 0;
      idc = 82;
      type = 82;
      style = 0;
      enable = 1;
      show = 1;
      blinkingPeriod = 0;
      model = "\A3\Misc_F\Helpers\UserTexture1m.p3d";
      scale = 0.2;
      x = 26 * GUI_GRID_W + GUI_GRID_CENTER_X;
      y = 21 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      z = 1;
      xBack = 25 * GUI_GRID_W + GUI_GRID_CENTER_X;
      yBack = 12 * GUI_GRID_H + GUI_GRID_CENTER_Y;
      zBack = 2;
      enableZoom = 1;
      zoomDuration = 0.5;
      inBack = 0;
      direction[] = {1,0,0.5};
      up[] = {0.5,1,0};
      tooltip = "CT_OBJECT";
      tooltipColorShade[] = {0,0,0,1};
      tooltipColorText[] = {1,1,1,1};
      tooltipColorBox[] = {1,1,1,1};
      class Areas
      {
        class UserTexture
        {
          selection = "usertexture";
          class Controls
          {
            class _CT_STATIC
            {
              idc = 1100;
              type = 0;
              style = "0x00 + 0x02 + 0x10";
              x = 0;
              y = 0;
              w = 1;
              h = 1;
              colorBackground[] = {0,0,0,1};
              text = "\nCT_OBJECT\n_CONTAINER";
              sizeEx = 6 * GUI_GRID_H;
              font = "RobotoCondensed";
              colorText[] = {1,1,1,1};
              lineSpacing = 1;
            };
          };
        };
      };
    };
  };
};