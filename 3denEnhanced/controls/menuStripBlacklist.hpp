class ENH_MenuStripBlacklist: Title
{
  attributeLoad = "[_this] call ENH_fnc_menuStripBlacklist_onAttributeLoad";
  attributeSave = "";
  h = 11 * SIZE_M * GRID_H + 10 * pixelH;
  class Controls: Controls
  {
    class Title: Title {};
    class Value: ctrlListBox
    {
      idc = 100;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = ATTRIBUTE_CONTENT_W * GRID_W;
      h = 10 * SIZE_M * GRID_H;
    };
    class Reset: ENH_ResetButton_Base
    {
      y = 10 * SIZE_M * GRID_H + 5 * pixelH;
    };
  };
};