#define POS_X_TEXT GRID_W
#define POS_X_VALUE 32 * GRID_W
#define WIDTH_TEXT 23 * GRID_W
#define WIDTH_VALUE 25 * GRID_W
#define WIDTH_HEADER 56 * GRID_W

class ENH_PlacementToolsGroup: ctrlControlsGroup
{
    idc = IDC_PLACEMENTTOOLS;
    onLoad = "[ctrlParent (_this#0), 'onLoad'] call ENH_fnc_placementTools";
    onUnload = "[ctrlParent (_this#0), 'onUnload'] call ENH_fnc_placementTools";
    x = QUOTE(safeZoneX + 2 * GRID_W);
    y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 3 * GRID_H);
    w = QUOTE(58 * GRID_W);
    h = QUOTE(WINDOW_HAbs - 5 * CTRL_DEFAULT_H);
    class Controls
    {
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_FOLDER_PLACEMENTTOOLS";
            x = QUOTE(0);
            y = QUOTE(0);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(0);
            y = QUOTE(CTRL_DEFAULT_H);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(WINDOW_HAbs - 6 * CTRL_DEFAULT_H);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(0);
            y = QUOTE(WINDOW_HAbs - 6 * CTRL_DEFAULT_H - 2 * GRID_H);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
        class Close: ctrlButtonClose
        {
            x = QUOTE(POS_X_VALUE);
            y = QUOTE(WINDOW_HAbs - 6 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(WIDTH_VALUE);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "ctrlDelete ctrlParentControlsGroup (_this#0)";
        };
        class Tools: ctrlControlsGroup
        {
            idc = IDC_NONE;
            onLoad = "[ctrlParent (_this#0), 'onLoad'] call ENH_fnc_placementTools";
            onUnload = "[ctrlParent (_this#0), 'onUnload'] call ENH_fnc_placementTools";
            x = QUOTE(0);
            y = QUOTE(CTRL_DEFAULT_H);
            w = QUOTE(58 * GRID_W);
            h = QUOTE(WINDOW_HAbs - 7 * CTRL_DEFAULT_H - 3 * GRID_H);
            class Controls
            {
                class CircularHeader: ctrlStaticFooter
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_CIRCULAR_HEADER";
                    x = QUOTE(POS_X_TEXT);
                    y = QUOTE(GRID_H);
                    w = QUOTE(WIDTH_HEADER);
                    h = QUOTE(CTRL_DEFAULT_H);
                };
                class Radius: ctrlStatic
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_RADIUS";
                    x = QUOTE(POS_X_TEXT);
                    y = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
                    w = QUOTE(WIDTH_TEXT);
                    h = QUOTE(CTRL_DEFAULT_H);
                };
                class RadiusValue: ctrlEdit
                {
                    idc = IDC_PLACEMENTTOOLS_RADIUS;
                    x = QUOTE(POS_X_VALUE);
                    y = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
                    w = QUOTE(WIDTH_VALUE);
                    h = QUOTE(CTRL_DEFAULT_H);
                };
                class InitialAngle: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_INITIALANGLE";
                    y = QUOTE(2 * CTRL_DEFAULT_H + 3 * GRID_H);
                };
                class InitialAngleValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_INITIALANGLE;
                    y = QUOTE(2 * CTRL_DEFAULT_H + 3 * GRID_H);
                };
                class CentralAngle: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_CENTRALANGLE";
                    y = QUOTE(3 * CTRL_DEFAULT_H + 4 * GRID_H);
                };
                class CentralAngleValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_CENTRALANGLE;
                    y = QUOTE(3 * CTRL_DEFAULT_H + 4 * GRID_H);
                };
                class LineHeader: CircularHeader
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_LINEPATTERN_HEADER";
                    y = QUOTE(4 * CTRL_DEFAULT_H + 5 * GRID_H);
                };
                class Spacing: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_SPACING";
                    y = QUOTE(5 * CTRL_DEFAULT_H + 6 * GRID_H);
                };
                class SpacingValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_SPACING;
                    y = QUOTE(5 * CTRL_DEFAULT_H + 6 * GRID_H);
                };
                class SpacingDirection: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_DIRECTION";
                    y = QUOTE(6 * CTRL_DEFAULT_H + 7 * GRID_H);
                };
                class SpacingDirectionValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_SPACINGDIRECTION;
                    y = QUOTE(6 * CTRL_DEFAULT_H + 7 * GRID_H);
                };
                class GridHeader: CircularHeader
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_GRID_HEADER";
                    y = QUOTE(7 * CTRL_DEFAULT_H + 8 * GRID_H);
                };
                class NumColumns: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_NUMCOLUMNS";
                    y = QUOTE(8 * CTRL_DEFAULT_H + 9 * GRID_H);
                };
                class NumColumsValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_NUMCOLUMNS;
                    y = QUOTE(8 * CTRL_DEFAULT_H + 9 * GRID_H);
                };
                class SpaceX: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_SPACINGX";
                    y = QUOTE(9 * CTRL_DEFAULT_H + 10 * GRID_H);
                };
                class SpaceXValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_SPACEX;
                    y = QUOTE(9 * CTRL_DEFAULT_H + 10 * GRID_H);
                };
                class SpaceY: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_SPACINGY";
                    y = QUOTE(10 * CTRL_DEFAULT_H + 11 * GRID_H);
                };
                class SpaceYValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_SPACEY;
                    y = QUOTE(10 * CTRL_DEFAULT_H + 11 * GRID_H);
                };
                class FillAreaHeader: CircularHeader
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_FILLAREA_HEADER";
                    y = QUOTE(11 * CTRL_DEFAULT_H + 12 * GRID_H);
                };
                class A: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_A";
                    y = QUOTE(12 * CTRL_DEFAULT_H + 13 * GRID_H);
                };
                class AValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_A;
                    y = QUOTE(12 * CTRL_DEFAULT_H + 13 * GRID_H);
                };
                class B: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_B";
                    y = QUOTE(13 * CTRL_DEFAULT_H + 14 * GRID_H);
                };
                class BValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_B;
                    y = QUOTE(13 * CTRL_DEFAULT_H + 14 * GRID_H);
                };
                class OrientationHeader: CircularHeader
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_ORIENTATION";
                    y = QUOTE(14 * CTRL_DEFAULT_H + 15 * GRID_H);
                };
                class Direction: Radius
                {
                    text = "$STR_ENH_MAIN_PLACEMENTTOOLS_DIRECTION";
                    y = QUOTE(15 * CTRL_DEFAULT_H + 16 * GRID_H);
                };
                class DirectionValue: RadiusValue
                {
                    idc = IDC_PLACEMENTTOOLS_ORIENTATION;
                    y = QUOTE(15 * CTRL_DEFAULT_H + 16 * GRID_H);
                };
                    class RandomOrientaton: ctrlButton
                {
                    idc = IDC_PLACEMENTTOOLS_RANDOMORIENTATION;
                    text = "$STR_ENH_MAIN_TOOLS_PLACEMENTTOOLS_RANDOM";
                    x = QUOTE(POS_X_VALUE);
                    y = QUOTE(16 * CTRL_DEFAULT_H + 17 * GRID_H);
                    w = QUOTE(WIDTH_VALUE);
                    h = QUOTE(CTRL_DEFAULT_H);
                };
                class ReverseOrientation: RandomOrientaton
                {
                    idc = IDC_PLACEMENTTOOLS_REVERSEORIENTATION;
                    text = "$STR_ENH_MAIN_TOOLS_PLACEMENTTOOLS_REVERSE";
                    x = QUOTE(POS_X_TEXT);
                    y = QUOTE(16 * CTRL_DEFAULT_H + 17 * GRID_H);
                };
            };
        };
    };
};

#undef POS_X_TEXT
#undef POS_X_VALUE
#undef WIDTH_TEXT
#undef WIDTH_VALUE
#undef WIDTH_HEADER
