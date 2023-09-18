class UnitInsignia: Title
{
  attributeLoad = "['attributeLoad', _this, _value] call ENH_fnc_unitInsignia";
  attributeSave = "['attributeSave', _this] call ENH_fnc_unitInsignia";
  h = (ATTRIBUTE_TITLE_W + 3) * GRID_H + 4 * pixelH;
  class Controls: Controls
  {
    class Title: Title {};
    class BackgroundPreview: ctrlStaticFooter
    {
      idc = 404;
      x = 1 * GRID_W;
      y = CTRL_DEFAULT_H;
      w = (ATTRIBUTE_TITLE_W - 2) * GRID_W;
      h = (ATTRIBUTE_TITLE_W - 2) * GRID_H;
    };
    class Preview: ctrlStaticPictureKeepAspect
    {
      idc = 403;
      x = 2 * GRID_W;
      y = CTRL_DEFAULT_H + GRID_H;
      w = (ATTRIBUTE_TITLE_W - 4) * GRID_W;
      h = (ATTRIBUTE_TITLE_W - 4) * GRID_H;
    };
    class Search: ctrlEdit
    {
      idc = 400;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = (ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      h = CTRL_DEFAULT_H;
      onEditChanged = "['onEditChanged', nil, _this] call ENH_fnc_unitInsignia";
    };
    class CancelSearchButton: ctrlButtonSearch
    {
      idc = 401;
      x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "['onButtonClick', nil, _this] call ENH_fnc_unitInsignia";
    };
    class Value: ctrlTree
    {
      idc = 402;
      idcSearch = 400;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = CTRL_DEFAULT_H;
      w = (ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      h = (ATTRIBUTE_TITLE_W - 2) * GRID_H;
      onLoad = "['attributeLoad', ctrlParentControlsGroup (_this#0)] call ENH_fnc_unitInsignia";
      onTreeSelChanged = "['onTreeSelChanged', ctrlParentControlsGroup (_this#0), _this] call ENH_fnc_unitInsignia";
      sizeEx = SIZEEX_PURISTA(SIZEEX_M);
    };
  };
};