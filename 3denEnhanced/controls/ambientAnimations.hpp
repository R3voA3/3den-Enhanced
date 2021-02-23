class ENH_AmbientAnimations: Title
{
  attributeLoad = "[_this, _value] call ENH_fnc_ambientAnimations_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_ambientAnimations_onAttributeSave";
  h = 4 * CTRL_DEFAULT_H + 20 * pixelH;
  class Controls: Controls
  {
    class AnimTitle: Title
    {
      text = "$STR_ENH_AMBIENTANIMATIONS_ANIMATION_DISPLAYNAME";
    };
    class Animation: ctrlCombo
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class CanExitTitle: Title
    {
      text = "$STR_ENH_AMBIENTANIMATIONS_CANEXIT_DISPLAYNAME";
      tooltip = "$STR_ENH_AMBIENTANIMATIONS_CANEXIT_TOOLTIP";
      y = CTRL_DEFAULT_H + 5 * pixelH;
    };
    class CanExit: ctrlCheckbox
    {
      idc = 101;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = CTRL_DEFAULT_H + 5 * pixelH;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class AttachTitle: Title
    {
      text = "$STR_ENH_AMBIENTANIMATIONS_ATTACH_DISPLAYNAME";
      tooltip = "$STR_ENH_AMBIENTANIMATIONS_ATTACH_TOOLTIP";
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
    };
    class Attach: CanExit
    {
      idc = 102;
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 3 * CTRL_DEFAULT_H + 15 * pixelH;
    };
  };
};