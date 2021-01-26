class ENH_GroupMarker: Title
{
  attributeLoad = "[_this, _value] call ENH_fnc_groupMarker_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_groupMarker_onAttributeSave";
  h = 5 * SIZE_M * GRID_H + 25 * pixelH;
  class Controls: Controls
  {
    class TypeTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_TYPE";
    };
    class Type: ctrlCombo
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class ColourTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_COLOUR";
      y = 1 * SIZE_M * GRID_H + 5 * pixelH;
    };
    class Colour: ctrlCombo
    {
      idc = 101;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 1 * SIZE_M * GRID_H + 5 * pixelH;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class TextTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_TEXT";
      y = 2 * SIZE_M * GRID_H + 10 * pixelH;
    };
    class Text: ctrlEdit
    {
      idc = 102;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 2 * SIZE_M * GRID_H + 10 * pixelH;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class ShowGroupSizeTitle: Title
    {
      text = "$STR_ENH_GROUPMARKER_SHOWGROUPSIZE";
      y = 3 * SIZE_M * GRID_H + 15 * pixelH;
    };
    class ShowGroupSize: ctrlCheckbox
    {
      idc = 103;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 3 * SIZE_M * GRID_H + 15 * pixelH;
      w = 5 * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 4 * SIZE_M * GRID_H + 20 * pixelH;
    };
  };
};