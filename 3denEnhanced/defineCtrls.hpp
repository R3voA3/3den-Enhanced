//Config macros like __eval and __excec
#include "\a3\3DEN\UI\macroexecs.inc"

//Disabled background
#define DISABLE_BACKGROUND class BackgroundDisable: ctrlStaticBackgroundDisable {};\
                           class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles {};

//Eden base controls
class ctrlEdit;
class ctrlEditMulti;
class ctrlButton;
class ctrlButtonPicture;
class ctrlButtonClose;
class ctrlButtonCancel;
class ctrlButtonOK;
class ctrlButtonSearch;
class ctrlButtonCollapseAll;
class ctrlButtonExpandAll;
class ctrlButtonPictureKeepAspect;
class ctrlStructuredText;
class ctrlCombo;
class ctrlCheckbox;
class ctrlXSliderH;
class ctrlControlsGroup;
class ctrlControlsGroupNoScrollbars;
class ctrlMenuStrip;
class ctrlMenu;
class ctrlStaticBackground;
class ctrlStatic;
class ctrlStaticFooter;
class ctrlStaticBackgroundDisable;
class ctrlStaticBackgroundDisableTiles;
class ctrlStaticPictureKeepAspect;
class ctrlStaticPicture;
class ctrlStaticMulti;
class ctrlStaticTitle;
class ctrlStaticLine;
class ctrlTree;
class ctrlListbox;
class ctrlListNBox;
class ctrlToolbox;
class ctrlToolboxPictureKeepAspect;
class ctrlProgress;
class ctrlStaticFrame;
class scrollbar;

//Attribute controls
class ENH_SideToolbox_Base: ctrlToolboxPictureKeepAspect
{
  idc = -1;
  x = ATTRIBUTE_TITLE_W * GRID_W;
  w = ATTRIBUTE_CONTENT_W * GRID_W;
  h = 2 * SIZE_M * GRID_H;
  rows = 1;
  columns = 4;
  strings[] =
  {
    "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa",
    "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa",
    "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa",
    "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa"
  };
  tooltips[] =
  {
    "$STR_WEST",
    "$STR_EAST",
    "$STR_GUERRILA",
    "$STR_CIVILIAN"
  };
  values[] = {0,1,2,3};
};

class ENH_ResetButton_Base: ctrlButton
{
  idc = 5;
  x = ATTRIBUTE_TITLE_W * GRID_W;
  w = ATTRIBUTE_CONTENT_W * GRID_W;
  h = SIZE_M * GRID_H;
  text = "$STR_ENH_RESETANDDISABLE";
};