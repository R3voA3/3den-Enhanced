//Config macros like __eval and __excec
#include "\a3\3DEN\UI\macroexecs.inc"

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
class ctrlButtonPicture;
class ctrlButtonPictureKeepAspect;
class ctrlButtonSearch;
class ctrlCheckbox;
class ctrlCombo;
class ctrlControlsGroup;
class ctrlControlsGroupNoScrollbars;
class ctrlEdit;
class ctrlEditMulti;
class ctrlListNBox;
class ctrlListbox;
class ctrlMenu;
class ctrlMenuStrip;
class ctrlProgress;
class ctrlStatic;
class ctrlStaticBackground;
class ctrlStaticBackgroundDisable;
class ctrlStaticBackgroundDisableTiles;
class ctrlStaticFooter;
class ctrlStaticFrame;
class ctrlStaticLine;
class ctrlStaticMulti;
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
  x = ATTRIBUTE_TITLE_W * GRID_W;
  w = ATTRIBUTE_CONTENT_W * GRID_W;
  h = 2 * CTRL_DEFAULT_H;
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
  x = ATTRIBUTE_TITLE_W * GRID_W;
  w = ATTRIBUTE_CONTENT_W * GRID_W;
  h = CTRL_DEFAULT_H;
  text = "$STR_ENH_RESETANDDISABLE";
};

//Used for Advanced Damage attribute
class ENH_AttributeTitle: ctrlStatic
{
  style = ST_RIGHT;
};