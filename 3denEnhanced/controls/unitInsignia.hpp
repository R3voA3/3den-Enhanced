class UnitInsignia: Title
{
  attributeLoad = "['attributeLoad', _this, _value] call ENH_fnc_unitInsignia";
  attributeSave = "['attributeSave', _this] call ENH_fnc_unitInsignia";
  h = 11 * CTRL_DEFAULT_H + 4 * pixelH;
  class Controls: Controls
  {
    class Title: Title {};
    class Search: ctrlEdit
    {
      idc = 300;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = (ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      h = CTRL_DEFAULT_H;
      onEditChanged = "['onEditChanged', nil, _this] call ENH_fnc_unitInsignia";
    };
    class CancelSearchButton: ctrlButtonSearch
    {
      idc = 301;
      x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "['onButtonClick', nil, _this] call ENH_fnc_unitInsignia";
    };
    class Value: ctrlTree
    {
      idc = 302;
      idcSearch = 300;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = CTRL_DEFAULT_H;
      w = (ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      h = 10 * CTRL_DEFAULT_H;
      onLoad = "['attributeLoad', ctrlParentControlsGroup (_this#0)] call ENH_fnc_unitInsignia";
      sizeEx = SIZEEX_PURISTA(SIZEEX_M);
    };
  };
};