// Disabled background
#define DISABLE_BACKGROUND class BackgroundDisable: ctrlStaticBackgroundDisable {};\
                                                    class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles {};

class RscEdit;
class RscText;
class RscTree;

// Eden base controls
class ctrlActivePictureKeepAspect;
class ctrlButton;
class ctrlButtonCancel;
class ctrlButtonClose;
class ctrlButtonCollapseAll;
class ctrlButtonExpandAll;
class ctrlButtonOK;
class ctrlButtonPictureKeepAspect;
class ctrlButtonSearch;
class ctrlButtonToolbar;
class ctrlCheckbox;
class ctrlCheckboxToolbar;
class ctrlCombo;
class ctrlControlsGroup;
class ctrlControlsGroupNoScrollbars;
class ctrlEdit;
class ctrlEditMulti;
class ctrlListbox;
class ctrlListNBox;
class ctrlMap;
class ctrlMenu;
class ctrlMenuStrip;
class ctrlProgress;
class ctrlShortcutButtonSteam;
class ctrlStatic;
class ctrlStaticBackground;
class ctrlStaticBackgroundDisable;
class ctrlStaticBackgroundDisableTiles;
class ctrlStaticFooter;
class ctrlStaticFrame;
class ctrlStaticMulti;
class ctrlStaticOverlay;
class ctrlStaticPicture;
class ctrlStaticPictureKeepAspect;
class ctrlStaticTitle;
class ctrlStructuredText;
class ctrlToolbox;
class ctrlToolboxPictureKeepAspect;
class ctrlTree;
class ctrlXSliderH;
class scrollbar;

// Default classes needed for ctrlMenuStrip to work
#define MENU_STRIP_DEFAULT class Default\
{\
    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_DEFAULT_TEXT";\
    enable = 0;\
};

#define MENU_STRIP_SEPARATOR class Separator\
{\
    value = 0;\
};

class ENH_ctrlButtonHelp: ctrlButtonPictureKeepAspect
{
    idc = IDC_NONE;
    text = "\a3\3den\data\displays\display3den\toolbar\help_tutorial_ca.paa";
    x = 0;
    y = 0;
    w = QUOTE(5 * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    onLoad = "(_this#0) ctrlSetURLOverlayMode 1";
};

// Attribute controls
// These are not Attribute control groups but the
// Controls these are filled with
class ENH_3DEN_Attribute_Control_SideToolbox: ctrlToolboxPictureKeepAspect
{
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
    h = QUOTE(2 * CTRL_DEFAULT_H);
    rows = 1;
    columns = 4;
    strings[] =
    {
        "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa",
        "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa",
        "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa",
        "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa"
    };
    tooltips[] = {"$STR_WEST", "$STR_EAST", "$STR_GUERRILA", "$STR_CIVILIAN"};
    values[] = {0, 1, 2, 3};
};
class ENH_3DEN_Attribute_Control_ResetButton: ctrlButton
{
    idc = IDC_ATTRIBUTE_BUTTON_RESET;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    text = "$STR_ENH_MAIN_RESETANDDISABLE";
};
// Used for Advanced Damage attribute
class ENH_3DEN_Attribute_Control_AttributeTitle: ctrlStatic
{
    style = ST_RIGHT;
};
// These controls are directly used inside attribute controls
class ENH_3DEN_Attribute_Control_TitleX: ctrlStatic
{
    text = "$STR_3DEN_AXIS_X";
    style = 2;
    shadow = 0;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_H * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    colorBackground[] = {COLOR_POSX_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleY: ENH_3DEN_Attribute_Control_TitleX
{
    text = "$STR_3DEN_AXIS_Y";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3)) * GRID_W);
    colorBackground[] = {COLOR_POSY_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleZ: ENH_3DEN_Attribute_Control_TitleX
{
    text = "$STR_3DEN_AXIS_Z";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (2 / 3)) * GRID_W);
    colorBackground[] = {COLOR_POSZ_RGBA};
};
class ENH_3DEN_Attribute_Control_ValueX: ctrlEdit
{
    text = "0";
    x = QUOTE((ATTRIBUTE_TITLE_W + 5) * GRID_W);
    w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 5) * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    font = FONT_MONO;
    sizeEx = QUOTE(3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5);
};
class ENH_3DEN_Attribute_Control_ValueY: ENH_3DEN_Attribute_Control_ValueX
{
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (1 / 3) +ATTRIBUTE_CONTENT_H) * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueZ: ENH_3DEN_Attribute_Control_ValueX
{
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (2 / 3) +ATTRIBUTE_CONTENT_H) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleA: ctrlStatic
{
    text = "$STR_3DEN_AXIS_A";
    style = 2;
    shadow = 0;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_H * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    colorText[] = {COLOR_TEXT_RGBA};
    colorBackground[] = {COLOR_POSX_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleB: ENH_3DEN_Attribute_Control_TitleA
{
    text = "$STR_3DEN_AXIS_B";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3)) * GRID_W);
    colorBackground[] = {COLOR_POSY_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleR: ENH_3DEN_Attribute_Control_TitleA
{
    text = "$STR_ENH_BASE_CONTROLS_TITLE_R";
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    colorBackground[] = {COLOR_RADIUS_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleAltitude: ENH_3DEN_Attribute_Control_TitleA
{
    text = "$STR_ENH_BASE_CONTROLS_TITLE_A";
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    colorBackground[] = {COLOR_ALTITUDE_RGBA};
};
class ENH_3DEN_Attribute_Control_ValueA: ctrlEdit
{
    text = "0";
    x = QUOTE((ATTRIBUTE_TITLE_W + 5) * GRID_W);
    w = QUOTE((ATTRIBUTE_CONTENT_W / 3 -5) * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    font = FONT_MONO;
    sizeEx = QUOTE(3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5);
};
class ENH_3DEN_Attribute_Control_ValueB: ENH_3DEN_Attribute_Control_ValueA
{
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3) +ATTRIBUTE_CONTENT_H) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleZ_Front: ENH_3DEN_Attribute_Control_TitleZ
{
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueZ_Front: ENH_3DEN_Attribute_Control_ValueZ
{
    x = QUOTE((ATTRIBUTE_TITLE_W + 5) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleMin: ctrlStatic
{
    text = "$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMIN_TEXT";
    style = 1;
    shadow = 0;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_H * 2 * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    colorText[] = {COLOR_TEXT_RGBA};
    colorBackground[] = {COLOR_TEXT_RGB, 0};
};
class ENH_3DEN_Attribute_Control_TitleMid: ENH_3DEN_Attribute_Control_TitleMin
{
    text = "$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMID_TEXT";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3)) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleMax: ENH_3DEN_Attribute_Control_TitleMin
{
    text = "$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMAX_TEXT";
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (2 / 3)) * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueMin: ctrlEdit
{
    x = QUOTE((ATTRIBUTE_TITLE_W +(5 * 2)) * GRID_W);
    w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 2 * ATTRIBUTE_CONTENT_H) * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    font = FONT_MONO;
    sizeEx = QUOTE(3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5);
};
class ENH_3DEN_Attribute_Control_ValueMid: ENH_3DEN_Attribute_Control_ValueMin
{
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (1 / 3) +(ATTRIBUTE_CONTENT_H * 2)) * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueMax: ENH_3DEN_Attribute_Control_ValueMin
{
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (2 / 3) +(ATTRIBUTE_CONTENT_H * 2)) * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueFromClipboard: ctrlButtonPictureKeepAspect
{
    idc = IDC_NONE;
    text = "\x\enh\addons\main\data\clipboard_ca.paa";
    tooltip = "$STR_ENH_BUTTON_PASTE_ARRAY_FROM_CLIPBOARD";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
    y = 0;
    w = QUOTE(5 * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
};
class ENH_3DEN_Attribute_Control_EditMultiCode5_Group: ctrlControlsGroupNoScrollbars
{
    idc = IDC_NONE;
    x = QUOTE(5 * GRID_W);
    y = 0;
    w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
    h = QUOTE(5 * CTRL_DEFAULT_H + 6 * GRID_H);
    class Controls
    {
        class Background: ctrlStaticOverlay
        {
            y = QUOTE(2 * GRID_H);
            w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            h = QUOTE(5 * CTRL_DEFAULT_H - 2 * GRID_H);
        };
        class Header: ctrlStaticFrame
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            h = QUOTE(5 * CTRL_DEFAULT_H);
            colorBackground[] = {COLOR_OVERLAY_RGBA};
        };
        class Value: ctrlEditMulti
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            y = QUOTE(5 * GRID_H);
            w = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W);
            h = QUOTE(5 * CTRL_DEFAULT_H - 6 * GRID_H);
            style = QUOTE(ST_MULTI + ST_NO_RECT);
            colorBackground[] = {COLOR_OVERLAY_RGB, 0};
        };
    };
};
// Custom minimap control
class ENH_3DENMinimap: ctrlMap
{
    scaleMax = 3;
};
