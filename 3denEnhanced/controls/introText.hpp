class ENH_IntroText: Title
{
  attributeLoad = "[_this, _value] call ENH_fnc_introText_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_introText_onAttributeSave";
  h = 10 * CTRL_DEFAULT_H + 30 * pixelH;
  class Controls: Controls
  {
    class DelayTitle: Title
    {
      text = "$STR_ENH_INTROTEXT_INTRODELAY_DISPLAYNAME";
      tooltip = "$STR_ENH_INTROTEXT_INTRODELAY_TOOLTIP";
    };
    class DelayValue: ctrlXSliderH
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
      h = CTRL_DEFAULT_H;
       sliderPosition = 0;
      sliderRange[] = {0, 360};
      sliderStep = 1;
      lineSize = 1;
    };
    class DelayEdit: ctrlEdit
    {
      idc = 101;
      x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
      w = EDIT_W_WIDE * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Line1Title: Title
    {
      y = CTRL_DEFAULT_H + 5 * pixelH;
      text = "$STR_ENH_INTROTEXT_LINE1_DISPLAYNAME";
    };
    class Line1Value: ctrlEdit
    {
      idc = 102;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = CTRL_DEFAULT_H + 5 * pixelH;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Line2Title: Title
    {
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
      text = "$STR_ENH_INTROTEXT_LINE2_DISPLAYNAME";
      tooltip = "";
    };
    class Line2Value: Line1Value
    {
      idc = 103;
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
    };
    class Line3Title: Title
    {
      y = 3 * CTRL_DEFAULT_H + 15 * pixelH;
      text = "$STR_ENH_INTROTEXT_LINE3_DISPLAYNAME";
    };
    class Line3Value: Line1Value
    {
      idc = 104;
      y = 3 * CTRL_DEFAULT_H + 15 * pixelH;
    };
    class IntroTypeTitle: Title
    {
      y = 4 * CTRL_DEFAULT_H + 20 * pixelH;
      text = "$STR_ENH_INTROTEXT_INTROTYPE_DISPLAYNAME";
    };
    class IntroType: ctrlToolboxPictureKeepAspect
    {
      idc = 105;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 4 * CTRL_DEFAULT_H + 20 * pixelH;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = 5 * CTRL_DEFAULT_H;
      rows = 1;
      columns = 3;
      strings[] =
      {
        "\3denEnhanced\data\BIS_fnc_textTiles_preview_ca.paa",
        "\3denEnhanced\data\BIS_fnc_infoText_preview_ca.paa",
        "\3denEnhanced\data\BIS_fnc_EXP_camp_SITREP_preview_ca.paa"
      };
      values[] = {0, 1, 2};
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 9 * CTRL_DEFAULT_H + 25 * pixelH;
    };
  };
};