#define POS_X_TEXT 1 * GRID_W
#define POS_X_VALUE 27 * GRID_W
#define WIDTH_TEXT 23 * GRID_W
#define WIDTH_VALUE 36 * GRID_W
#define WIDTH_HEADER 62 * GRID_W

#define ORIGIN_X safeZoneX + 6 * GRID_W
#define ORIGIN_Y safezoneY + 18 * GRID_H

class ENH_PlacementTools
{
  idd = IDD_PLACEMENTTOOLS;
  onLoad = "_this call ENH_fnc_placementTools_onLoad";
  onUnload = "_this call ENH_fnc_placementTools_onUnload";
  movingEnable = true;
  class ControlsBackground
  {
     class Background: ctrlStaticBackground
    {
      x = ORIGIN_X;
      y = ORIGIN_Y + CTRL_DEFAULT_H;
      w = 64 * GRID_W;
      h = 120 * GRID_H;
    };
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_FOLDER_PLACEMENTTOOLS";
      x = ORIGIN_X;
      y = ORIGIN_Y;
      w = 64 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = ORIGIN_X;
      y = ORIGIN_Y + 118 * GRID_H;
      w = 64 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class SelectCenter: ctrlButtonPictureKeepAspect
    {
      text = "\A3\ui_f\data\igui\cfg\weaponcursors\rocket_gs.paa";
      tooltip = "$STR_ENH_PLACEMENTTOOLS_RESETCENTER_TOOLTIP";
      x = ORIGIN_X + 32 * GRID_W;
      y = ORIGIN_Y + 119 * GRID_H;
      w = CTRL_DEFAULT_H;
      h = CTRL_DEFAULT_H;
      onButtonClick = "ENH_PlacementTools_Center = screenToWorld [0.5, 0.5]";
    };
    class Close: ctrlButtonClose
    {
      x = ORIGIN_X + 40 * GRID_W;
      y = ORIGIN_Y + 119 * GRID_H;
      w = WIDTH_TEXT;
      h = CTRL_DEFAULT_H;
    };
  };
  class Controls
  {
    class ControlGroup: ctrlControlsGroup
    {
      x = ORIGIN_X;
      y = ORIGIN_Y +  6 * GRID_H;
      w = 64 * GRID_W;
      h = 105 * GRID_H;
      class Controls
      {
        class CircularHeader: ctrlStaticFooter
        {
          text = "$STR_ENH_PLACEMENTTOOLS_CIRCULAR_HEADER";
          x = POS_X_TEXT;
          y = 1 * GRID_W;
          w = WIDTH_HEADER;
          h = CTRL_DEFAULT_H;
        };
        class Radius: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_RADIUS";
          x = POS_X_TEXT;
          y = 7 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class RadiusValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_RADIUS;
          x = POS_X_VALUE;
          y = 7 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class InitialAngle: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_INITIALANGLE";
          x = POS_X_TEXT;
          y = 13 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class InitialAngleValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_INITIALANGLE;
          x = POS_X_VALUE;
          y = 13 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class CentralAngle: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_CENTRALANGLE";
          x = POS_X_TEXT;
          y = 19 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class CentralAngleValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_CENTRALANGLE;
          x = POS_X_VALUE;
          y = 19 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class LineHeader: ctrlStaticFooter
        {
          text = "$STR_ENH_PLACEMENTTOOLS_LINEPATTERN_HEADER";
          x = POS_X_TEXT;
          y = 25 * GRID_H;
          W = WIDTH_HEADER;
          h = CTRL_DEFAULT_H;
        };
        class Spacing: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_SPACING";
          x = POS_X_TEXT;
          y = 31 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class SpacingValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_SPACING;
          x = POS_X_VALUE;
          y = 31 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class GridHeader: ctrlStaticFooter
        {
          text = "$STR_ENH_PLACEMENTTOOLS_GRID_HEADER";
          x = POS_X_TEXT;
          y = 37 * GRID_H;
          W = WIDTH_HEADER;
          h = CTRL_DEFAULT_H;
        };
        class NumColumns: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_NUMCOLUMNS";
          x = POS_X_TEXT;
          y = 43 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class NumColumsValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_NUMCOLUMNS;
          x = POS_X_VALUE;
          y = 43 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class SpaceX: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_SPACINGX";
          x = POS_X_TEXT;
          y = 49 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class SpaceXValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_SPACEX;
          x = POS_X_VALUE;
          y = 49 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class SpaceY: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_SPACINGY";
          x = POS_X_TEXT;
          y = 55 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class SpaceYValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_SPACEY;
          x = POS_X_VALUE;
          y = 55 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class FillAreaHeader: ctrlStaticFooter
        {
          text = "$STR_ENH_PLACEMENTTOOLS_FILLAREA_HEADER";
          x = POS_X_TEXT;
          y = 61 * GRID_H;
          W = WIDTH_HEADER;
          h = CTRL_DEFAULT_H;
        };
        class A: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_A";
          x = POS_X_TEXT;
          y = 67 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class AValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_A;
          x = POS_X_VALUE;
          y = 67 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class B: ctrlStatic
        {
          text = "$STR_ENH_PLACEMENTTOOLS_B";
          x = POS_X_TEXT;
          y = 73 * GRID_H;
          w = WIDTH_TEXT;
          h = CTRL_DEFAULT_H;
        };
        class BValue: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_B;
          x = POS_X_VALUE;
          y = 73 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class OrientationHeader: ctrlStaticFooter
        {
          text = "$STR_ENH_PLACEMENTTOOLS_ORIENTATION";
          x = POS_X_TEXT;
          y = 79 * GRID_H;
          W = WIDTH_HEADER;
          h = CTRL_DEFAULT_H;
        };
        class OrientNorth: ctrlEdit
        {
          idc = IDC_PLACEMENTTOOLS_ORIENTATION;
          x = POS_X_VALUE + 8 * GRID_W;
          y = 85 * GRID_H;
          w = CTRL_DEFAULT_H;
          h = CTRL_DEFAULT_H;
          onSliderChange = "(_this sel) call ENH_fnc_setOrientation";
        };
        /* class OrientEast: OrientNorth
        {
          text = "E";
          x = POS_X_VALUE + 16 * GRID_W;
          y = 91 * GRID_H;
          onButtonClick = "90 call ENH_fnc_setOrientation";
        };
        class OrientSouth: OrientNorth
        {
          text = "S";
          x = POS_X_VALUE + 8 * GRID_W;
          y = 97 * GRID_H;
          onButtonClick = "180 call ENH_fnc_setOrientation";
        };
        class OrientWest: OrientNorth
        {
          text = "W";
          x = POS_X_VALUE;
          y = 91 * GRID_H;
          onButtonClick = "270 call ENH_fnc_setOrientation";
        }; */
         class RandomOrientaton: ctrlButtonPictureKeepAspect
        {
          idc = IDC_PLACEMENTTOOLS_RANDOMORIENTATION;
          text = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
          x = POS_X_VALUE + 24 * GRID_W;
          y = 85 * GRID_H;
          w = CTRL_DEFAULT_H;
          h = CTRL_DEFAULT_H;
          onButtonClick = "-1 call ENH_fnc_setOrientation";
        };
        class ReverseOrientation: RandomOrientaton
        {
          idc = IDC_PLACEMENTTOOLS_REVERSEORIENTATION;
          text = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
          y = 97 * GRID_H;
          onButtonClick = "-2 call ENH_fnc_setOrientation";
        };
      };
    };
  };
};