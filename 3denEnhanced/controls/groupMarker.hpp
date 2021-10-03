class ENH_GroupMarker: Title
{
  attributeLoad = "[_this, _value] call ENH_fnc_groupMarker_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_groupMarker_onAttributeSave";
  h = 6 * CTRL_DEFAULT_H + 25 * pixelH;
  class Controls: Controls
  {
    class TypeTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_TYPE";
      tooltip = "$STR_3DEN_MARKER_ATTRIBUTE_TYPE_TOOLTIP";
    };
    class Type: ctrlCombo
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {COLOR_TAB_RGBA};
      onLoad = "_this spawn ENH_fnc_groupMarker_onLoad";
    };
    class ColourTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_COLOUR";
      tooltip = "$STR_3DEN_MARKER_ATTRIBUTE_COLOR_TOOLTIP";
      y = CTRL_DEFAULT_H + 5 * pixelH;
    };
    class Colour: Type
    {
      idc = 101;
      y = CTRL_DEFAULT_H + 5 * pixelH;
      onload = "";
    };
    class TextTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_TEXT";
      tooltip = "$STR_3DEN_MARKER_ATTRIBUTE_TEXT_TOOLTIP";
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
    };
    class Text: ctrlEdit
    {
      idc = 102;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ShowGroupSizeTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_SHOWGROUPSIZE";
      y = 3 * CTRL_DEFAULT_H + 15 * pixelH;
    };
    class ShowGroupSize: ctrlCheckbox
    {
      idc = 103;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 3 * CTRL_DEFAULT_H + 15 * pixelH;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ShowGroupVehicleTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_SHOWGROUPVEHICLE";
      y = 4 * CTRL_DEFAULT_H + 15 * pixelH;
    };
    class ShowGroupVehicle: ctrlCheckbox
    {
      idc = 104;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 4 * CTRL_DEFAULT_H + 15 * pixelH;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 5 * CTRL_DEFAULT_H + 20 * pixelH;
    };
  };
};
