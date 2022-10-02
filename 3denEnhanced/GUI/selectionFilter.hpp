#define DIALOG_W 68
#define TEXTURES(NAME)\
textureChecked = NAME;\
textureUnchecked = NAME;\
textureFocusedChecked = NAME;\
textureFocusedUnchecked = NAME;\
textureHoverChecked = NAME;\
textureHoverUnchecked = NAME;\
texturePressedChecked = NAME;\
texturePressedUnchecked = NAME;\
textureDisabledChecked = NAME;\
textureDisabledUnchecked = NAME;\

class ENH_SelectionFilter
{
  idd = -1;
  onLoad = "_this call ENH_fnc_selectionFilter_init";
  class ControlsBackground
  {
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = 7 * GRID_H;
    };
    class Header: ctrlStaticTitle
    {
      text = $STR_ENH_SELECTIONFILTER;
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 6) * GRID_W;
      y = DIALOG_TOP + 5 * GRID_H;
      w = 19 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class FilterObjects: ctrlCheckboxToolbar
    {
      idc = 10;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      TEXTURES("\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa")
      checked = 1;
      onCheckedChanged = "_this call ENH_fnc_selectionFilter_onCheckedChanged";
      tooltip = $STR_3DEN_OBJECT_TEXTPLURAL;
    };
    class FilterGroups: FilterObjects
    {
      idc = 11;
      x = CENTERED_X(DIALOG_W) + (1 + 6) * GRID_W;
      TEXTURES("\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa")
      tooltip = $STR_3DEN_GROUP_TEXTPLURAL;
    };
    class FilterTriggers: FilterObjects
    {
      idc = 12;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6) * GRID_W;
      TEXTURES("\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa")
      tooltip = $STR_3DEN_TRIGGER_TEXTPLURAL;
    };
    class FilterSystems: FilterObjects
    {
      idc = 13;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6) * GRID_W;
      TEXTURES("\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa")
      tooltip = $STR_3DEN_LOGIC_TEXTPLURAL;
    };
    class FilterWaypoints: FilterObjects
    {
      idc = 14;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6) * GRID_W;
      TEXTURES("\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa")
      tooltip = $STR_3DEN_WAYPOINT_TEXTPLURAL;
    };
    class FilterMarkers: FilterObjects
    {
      idc = 15;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6 + 6) * GRID_W;
      TEXTURES("\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa")
      tooltip = $STR_3DEN_MARKER_TEXTPLURAL;
    };
    class FilterComments: FilterObjects
    {
      idc = 16;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6 + 6 + 6) * GRID_W;
      TEXTURES("\a3\3den\data\cfg3den\comment\texture_ca.paa")
      tooltip = $STR_3DEN_COMMENT_TEXTPLURAL;
    };
    class FilterLayers: FilterObjects
    {
      idc = 17;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6 + 6 + 6 + 6) * GRID_W;
      TEXTURES("\a3\3den\data\cfg3den\layer\icon_ca.paa")
      tooltip = $STR_3DEN_LAYER_TEXTPLURAL;
    };
    class EditAttribute: ctrlButtonPictureKeepAspect
    {
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 1) * GRID_W;
      text = "\a3\3den\data\displays\display3den\panelright\customcomposition_edit_ca.paa";
      y = DIALOG_TOP + 6 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this spawn ENH_fnc_selectionFilter_editAttributes";
      tooltip = $STR_3DEN_DISPLAY3DEN_MENUBAR_ATTRIBUTES_TEXT;
    };
    class Ok: EditAttribute
    {
      idc = 1;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 1) * GRID_W;
      text = "\a3\modules_f\data\iconsavegame_ca.paa";
      colorBackground[] = {0, 0.4, 0, 1};
      onButtonClick = "";
      tooltip = $STR_ENH_SELECTIONFILTER_CONFIRMSELECTION;
    };
    class Cancel: Ok
    {
      idc = -1;
      x = CENTERED_X(DIALOG_W) + (1 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 6 + 1) * GRID_W;
      text = "\a3\ui_f\data\gui\rsc\rscdisplayarcademap\icon_exit_cross_ca.paa";
      colorBackground[] = {0.7, 0, 0, 1};
      onButtonClick = "_this call ENH_fnc_selectionFilter_cancel";
      tooltip = $STR_ENH_SELECTIONFILTER_RESTORESELECTION;
    };
  };
};