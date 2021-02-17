class ENH_MapIndicators: Title
{
  attributeLoad = "[_this, _value] call ENH_fnc_mapIndicators_onAttributeLoad";
  attributeSave = "_this call ENH_fnc_mapIndicators_onAttributeSave";
  h = 4 * CTRL_DEFAULT_H + 20 * pixelH;
  class Controls: Controls
  {
    class FriendlyText: title
    {
      text = "$STR_ENH_MAPINDICATORS_FRIENDLY";
      tooltip = "$STR_ENH_MAPINDICATORS_FRIENDLY_TOOLTIP";
    };
    class FriendlyValue: ctrlCheckbox
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = SIZE_M * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class EnemyText: FriendlyText
    {
      text = "$STR_ENH_MAPINDICATORS_ENEMY";
      tooltip = "$STR_ENH_MAPINDICATORS_ENEMY_TOOLTIP";
      y = CTRL_DEFAULT_H + 5 * pixelH;
    };
    class EnemyValue: FriendlyValue
    {
      idc = 101;
      y = CTRL_DEFAULT_H + 5 * pixelH;
    };
    class MinesText: FriendlyText
    {
      text = "$STR_ENH_MAPINDICATORS_MINES";
      tooltip = "$STR_ENH_MAPINDICATORS_MINES_TOOLTIP";
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
    };
    class MinesValue: FriendlyValue
    {
      idc = 102;
      y = 2 * CTRL_DEFAULT_H + 10 * pixelH;
    };
    class PingText: FriendlyText
    {
      text = "$STR_ENH_MAPINDICATORS_PING";
      tooltip = "$STR_ENH_MAPINDICATORS_PING_TOOLTIP";
      y = 3 * CTRL_DEFAULT_H + 15 * pixelH;
    };
    class PingValue: FriendlyValue
    {
      idc = 103;
      y = 3 * CTRL_DEFAULT_H + 15 * pixelH;
    };
  };
};