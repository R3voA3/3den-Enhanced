class ENH_SPR: Title
{
  attributeLoad = "[_this,_value] call ENH_fnc_SPR_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_SPR_onAttributeSave";
  h = 5 * SIZE_M * GRID_H + 25 * pixelH;
  class Controls: Controls
  {
    class RulesetTitle: Title
    {
      text = $STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNTEMPLATES_DISPLAYNAME;
    };
    class Ruleset: ctrlCombo
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class RespawnTimeTitle: Title
    {
      y = SIZE_M * GRID_H + 5 * pixelH;
      text = $STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_DISPLAYNAME;
      tooltip = $STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_TOOLTIP;
    };
    class RespawnTimeValue: ctrlXSliderH
    {
      idc = 101;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = SIZE_M * GRID_H + 5 * pixelH;
      w = (ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
      h = SIZE_M * GRID_H;
       sliderPosition = 20;
      sliderRange[] = {2,360};
      sliderStep = 1;
      lineSize = 1;
    };
    class RespawnTimeEdit: ctrlEdit
    {
      idc = 102;
      x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
      y = SIZE_M * GRID_H + 5 * pixelH;
      w = EDIT_W * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class CanDieTitle: Title
    {
      text = $STR_ENH_SPR_CANDIE_DISPLAYNAME;
      tooltip = $STR_ENH_SPR_CANDIE_TOOLTIP;
      y = 2 * SIZE_M * GRID_H + 10 * pixelH;
    };
    class CanDie: ctrlCheckbox
    {
      idc = 103;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = 2* SIZE_M * GRID_H + 10 * pixelH;
      w = 5 * GRID_W;
      h = SIZE_M * GRID_H;
    };
    class RestoreLoadoutTitle: Title
    {
      text = $STR_ENH_SAVELOADOUT_DISPLAYNAME;
      tooltip = $STR_ENH_SAVELOADOUT_TOOLTIP;
      y = 3 * SIZE_M * GRID_H + 15 * pixelH;
    };
    class RestoreLoadout: CanDie
    {
      idc = 104;
      y = 3 * SIZE_M * GRID_H + 15 * pixelH;
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 4 * SIZE_M * GRID_H + 20 * pixelH;
      onButtonDown  = "_this call ENH_fnc_SPR_onButtonDown";
    };
  };
};