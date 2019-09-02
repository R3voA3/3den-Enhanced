#include "\a3\3DEN\UI\macros.inc"
#include "\a3\3DEN\UI\macroexecs.inc"
#include "\a3\ui_f\hpp\definedikcodes.inc"

//Display IDDs
#define ENH_IDD_3DENRADIO 					60000
#define ENH_IDD_NAMEOBJECTS 				80000
#define ENH_IDD_TEXTUREFINDER 				140000
#define ENH_IDD_BATCHREPLACE 				150000
#define ENH_IDD_SCENARIOATTRIBUTESMANAGER 	160000
#define ENH_IDD_ACTIONCREATOR 				190000

//Control types
#ifndef CT_COMBO
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_STRUCTURED_TEXT  13
#define CT_CONTROLS_GROUP   15
#define CT_LISTNBOX         102
#define CT_CHECKBOX         77
#endif

//Static styles
#ifndef ST_HPOS
#define ST_HPOS           		0x03
#define ST_LEFT           		0x00
#define ST_CENTER         		0x02
#define ST_MULTI         	 	0x10
#define ST_TITLE_BAR     	 	0x20
#define ST_NO_RECT       		0x200
#define ST_KEEP_ASPECT_RATIO  	0x800
#define LB_TEXTURES       		0x10
#endif

#define SHOW_IN_ROOT value = 0
#define EDIT_W 10
#define EDIT_W_WIDE 11
#define EDIT_W_ULTRA_WIDE 12
#define CENTERED_X(w) (CENTER_X - ((w) / 2 * GRID_W))
#define DIALOG_TOP (safezoneY + 17 * GRID_H)
#define CTRL_DEFAULT_H 5 * GRID_H

//Statusbar
#define SPACE_X (2 * pixelW)
#define ORIGIN_X_STATUSBAR (safezoneW - 60 * GRID_W)

#define COLOUR_USER_PRESET "profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843]","profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019]","profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862]",1

//Disabled background
#define DISABLE_BACKGROUND class BackgroundDisable: ctrlStaticBackgroundDisable {};\
						   class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles {};

//Eden base controls
class title;
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