class ENH_Airdrop: Title
{
  attributeLoad = "[_this, _value] call ENH_fnc_airdrop_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_airdrop_onAttributeSave";
  h = 11 * CTRL_DEFAULT_H + 35 * pixelH;//We make it 5 * pixelH larger to prevent scrolling issues
  class Controls: Controls
  {
    class ClassesTitle: Title
    {
      text = "$STR_ENH_AIRDROP_CLASSES_DISPLAYNAME";
      tooltip = "$STR_ENH_AIRDROP_CLASSES_TOOLTIP";
    };
    class ClassesValue: ctrlEditMulti
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = 4 * CTRL_DEFAULT_H;
    };
    class CenterTitle: Title
    {
      text = "$STR_ENH_AIRDROP_CENTER_DISPLAYNAME";
      tooltip = "$STR_ENH_AIRDROP_CENTER_TOOLTIP";
      y = 4 * CTRL_DEFAULT_H + 5 * pixelH;
    };
    class CenterValue: ctrlEdit
    {
      idc = 101;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 4* CTRL_DEFAULT_H + 5 * pixelH;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ConditionTitle: Title
    {
      y = 5 * CTRL_DEFAULT_H + 10 * pixelH;
      text = "$STR_ENH_AIRDROP_CONDITION_DISPLAYNAME";
      tooltip = "$STR_ENH_AIRDROP_CONDITION_TOOLTIP";
    };
    class ConditionValue: CenterValue
    {
      idc = 102;
      y = 5 * CTRL_DEFAULT_H + 10 * pixelH;
    };
    class AltitudeTitle: Title
    {
      y = 6 * CTRL_DEFAULT_H + 15 * pixelH;
      text = "$STR_ENH_ALTITUDE_DISPLAYNAME";
    };
    class AltitudeValue: ctrlXSliderH
    {
      idc = 103;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 6 * CTRL_DEFAULT_H + 15 * pixelH;
      w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
      h = CTRL_DEFAULT_H;
      sliderPosition = 500;
      sliderRange[] = {200, 5000};
      sliderStep = 50;
      lineSize = 50;
    };
    class AltitudeEdit: ctrlEdit
    {
      idc = 104;
      x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
      y = 6 * CTRL_DEFAULT_H + 15 * pixelH;
      w = EDIT_W_WIDE * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class RadiusTitle: Title
    {
      y = 7 * CTRL_DEFAULT_H + 20 * pixelH;
      text = "$STR_ENH_AIRDROP_RADIUS_DISPLAYNAME";
      tooltip = "$STR_ENH_AIRDROP_RADIUS_TOOLTIP";
    };
    class RadiusValue: AltitudeValue
    {
      idc = 105;
      y = 7 * CTRL_DEFAULT_H + 20 * pixelH;
      sliderPosition = 200;
      sliderRange[] = {50, 2000};
    };
    class RadiusEdit: AltitudeEdit
    {
      idc = 106;
      y = 7 * CTRL_DEFAULT_H + 20 * pixelH;
    };
    class SideTitle: Title
    {
      y = 8 * CTRL_DEFAULT_H + 25 * pixelH;
      text = "$STR_ENH_SIDE_DISPLAYNAME";
    };
    class SideValue: ENH_SideToolbox_Base
    {
      idc = 107;
      y = 8 * CTRL_DEFAULT_H + 25 * pixelH;
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 10 * CTRL_DEFAULT_H + 30 * pixelH;
    };
  };
};