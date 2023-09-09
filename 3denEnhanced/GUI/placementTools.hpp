#define POS_X_TEXT GRID_W
#define POS_X_VALUE 38 * GRID_W
#define WIDTH_TEXT 23 * GRID_W
#define WIDTH_VALUE 25 * GRID_W
#define WIDTH_HEADER 62 * GRID_W

#define ORIGIN_X safeZoneX + 6 * GRID_W
#define ORIGIN_Y safezoneY + 18 * GRID_H

#define IDC_PLACEMENTTOOLS_ORIENTATION 100
#define IDC_PLACEMENTTOOLS_REVERSEORIENTATION 110
#define IDC_PLACEMENTTOOLS_RANDOMORIENTATION 120
#define IDC_PLACEMENTTOOLS_SPACINGDIRECTION 130
#define IDC_PLACEMENTTOOLS_CENTERX WINDOW_WAbs
#define IDC_PLACEMENTTOOLS_CENTERY 150

class ENH_PlacementTools
{
  idd = -1;//IDD_PLACEMENTTOOLS;
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
      h = 129 * GRID_H;
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
      y = ORIGIN_Y + 127 * GRID_H;
      w = 64 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
    class Close: ctrlButtonClose
    {
      x = ORIGIN_X + 40 * GRID_W;
      y = ORIGIN_Y + 128 * GRID_H;
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
      h = 120 * GRID_H;
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
        class InitialAngle: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_INITIALANGLE";
          y = 13 * GRID_H;
        };
        class InitialAngleValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_INITIALANGLE;
          y = 13 * GRID_H;
        };
        class CentralAngle: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_CENTRALANGLE";
          y = 19 * GRID_H;
        };
        class CentralAngleValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_CENTRALANGLE;
          y = 19 * GRID_H;
        };
        class LineHeader: CircularHeader
        {
          text = "$STR_ENH_PLACEMENTTOOLS_LINEPATTERN_HEADER";
          y = 25 * GRID_H;
        };
        class Spacing: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_SPACING";
          y = 31 * GRID_H;
        };
        class SpacingValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_SPACING;
          y = 31 * GRID_H;
        };
        class SpacingDirection: Radius
        {
          text = "STR_ENH_PLACEMENTTOOLS_DIRECTION";
          y = 37 * GRID_H;
        };
        class SpacingDirectionValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_SPACINGDIRECTION;
          y = 37 * GRID_H;
        };
        class GridHeader: CircularHeader
        {
          text = "$STR_ENH_PLACEMENTTOOLS_GRID_HEADER";
          y = 43 * GRID_H;
        };
        class NumColumns: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_NUMCOLUMNS";
          y = 49 * GRID_H;
        };
        class NumColumsValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_NUMCOLUMNS;
          y = 49 * GRID_H;
        };
        class SpaceX: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_SPACINGX";
          y = 55 * GRID_H;
        };
        class SpaceXValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_SPACEX;
          y = 55 * GRID_H;
        };
        class SpaceY: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_SPACINGY";
          y = 61 * GRID_H;
        };
        class SpaceYValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_SPACEY;
          y = 61 * GRID_H;
        };
        class FillAreaHeader: CircularHeader
        {
          text = "$STR_ENH_PLACEMENTTOOLS_FILLAREA_HEADER";
          y = 67 * GRID_H;
        };
        class A: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_A";
          y = 73 * GRID_H;
        };
        class AValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_A;
          y = 73 * GRID_H;
        };
        class B: Radius
        {
          text = "$STR_ENH_PLACEMENTTOOLS_B";
          y = 79 * GRID_H;
        };
        class BValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_B;
          y = 79 * GRID_H;
        };
        class OrientationHeader: CircularHeader
        {
          text = "$STR_ENH_PLACEMENTTOOLS_ORIENTATION";
          y = 85 * GRID_H;
        };
        class Direction: Radius
        {
          text = "STR_ENH_PLACEMENTTOOLS_DIRECTION";
          y = 91 * GRID_H;
        };
        class DirectionValue: RadiusValue
        {
          idc = IDC_PLACEMENTTOOLS_ORIENTATION;
          y = 91 * GRID_H;
        };
         class RandomOrientaton: ctrlButton
        {
          idc = IDC_PLACEMENTTOOLS_RANDOMORIENTATION;
          text = "RANDOM";
          x = POS_X_VALUE;
          y = 97 * GRID_H;
          w = WIDTH_VALUE;
          h = CTRL_DEFAULT_H;
        };
        class ReverseOrientation: RandomOrientaton
        {
          idc = IDC_PLACEMENTTOOLS_REVERSEORIENTATION;
          text = "REVERSE";
          y = 103 * GRID_H;
        };
        class CenterHeader: CircularHeader
        {
          text = "STR_ENH_PLACEMENTTOOLS_CENTER";
          y = 109 * GRID_H;
        };
        class EditXY: ctrlControlsGroupNoScrollbars
        {
          idc = 100;
          x = POS_X_TEXT;
          y = 115 * GRID_H;
          w = WIDTH_HEADER;
          h = CTRL_DEFAULT_H;
          class Controls
          {
            class TitleX: ctrlStatic
            {
              text = "X";
              style = 2;
              shadow = 0;
              x = 0;
              y = 0;
              w = 5 * GRID_W;
              h = CTRL_DEFAULT_H;
              colorBackground[] = {COLOR_POSX_RGBA};
            };
            class ValueX: ctrlEdit
            {
              idc = IDC_PLACEMENTTOOLS_CENTERX;
              text = "0";
              x = 5 * GRID_W;
              w = 26 * GRID_W;
              h = CTRL_DEFAULT_H;
            };
            class TitleY: TitleX
            {
              text = "Y";
              x = 31 * GRID_W;
              colorBackground[] = {COLOR_POSY_RGBA};
            };
            class ValueY: ValueX
            {
              idc = IDC_PLACEMENTTOOLS_CENTERY;
              x = 36 * GRID_W;
            };
          };
        };
      };
    };
  };
};