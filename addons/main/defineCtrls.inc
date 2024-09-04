//Disabled background
#define DISABLE_BACKGROUND class BackgroundDisable: ctrlStaticBackgroundDisable {};\
                                                     class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles {};

//Eden base controls
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

//Attribute controls
class ENH_SideToolbox_Base: ctrlToolboxPictureKeepAspect
{
    idc = -1;
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

class ENH_ResetButton_Base: ctrlButton
{
    idc = 5;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    text = "$STR_ENH_MAIN_RESETANDDISABLE";
};

//Used for Advanced Damage attribute
class ENH_AttributeTitle: ctrlStatic
{
    style = ST_RIGHT;
};
