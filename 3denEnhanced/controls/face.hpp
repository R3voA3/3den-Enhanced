class Face: Title
{
  attributeLoad = "['attributeLoad', _this, _value] call ENH_fnc_face";
  attributeSave = "['attributeSave', _this] call ENH_fnc_face";
  h = (ATTRIBUTE_TITLE_W + 3) * GRID_H + 4 * pixelH;
  class Controls: Controls
  {
    class Title: Title {};
    class BackgroundPreview: ctrlStaticFooter
    {
      idc = 304;
      x = 1 * GRID_W;
      y = CTRL_DEFAULT_H;
      w = (ATTRIBUTE_TITLE_W - 2) * GRID_W;
      h = (ATTRIBUTE_TITLE_W - 2) * GRID_H;
    };
    class Preview: ctrlStaticPictureKeepAspect
    {
      idc = 303;
      text = "\A3\Characters_F\Heads\Data\m_Miller_co.paa";
      x = 2 * GRID_W;
      y = CTRL_DEFAULT_H + GRID_H;
      w = (ATTRIBUTE_TITLE_W - 4) * GRID_W;
      h = (ATTRIBUTE_TITLE_W - 4) * GRID_H;
    };
    class Search: ctrlEdit
    {
      idc = 300;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      w = (ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      h = CTRL_DEFAULT_H;
      onEditChanged = "['onEditChanged', nil, _this] call ENH_fnc_face";
    };
    class CancelSearchButton: ctrlButtonSearch
    {
      idc = 301;
      x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "['onButtonClick', nil, _this] call ENH_fnc_face";
    };
    class Value: ctrlTree
    {
      idc = 302;
      idcSearch = 300;
      x = ATTRIBUTE_TITLE_W * GRID_W;
      y = CTRL_DEFAULT_H;
      w = (ATTRIBUTE_CONTENT_W - 5) * GRID_W;
      h = (ATTRIBUTE_TITLE_W - 2) * GRID_H;
      onLoad = "['attributeLoad', ctrlParentControlsGroup (_this#0)] call ENH_fnc_face";
      onTreeSelChanged = "['onTreeSelChanged', ctrlParentControlsGroup (_this#0), _this] call ENH_fnc_face";
      sizeEx = SIZEEX_PURISTA(SIZEEX_M);
    };
  };
};