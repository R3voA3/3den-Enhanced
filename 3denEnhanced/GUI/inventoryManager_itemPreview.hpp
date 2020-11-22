#include "\3denEnhanced\defineCommon.hpp"

class ENH_InventoryManager_ItemPreview
{
  idd = IDD_INVENTORYMANAGER_ITEMPREVIEW;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 60 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      idc = IDC_INVENTORYMANAGER_ITEMPREVIEW_HEADER;
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Image: ctrlStaticPictureKeepAspect
    {
      idc = IDC_INVENTORYMANAGER_ITEMPREVIEW_IMAGE;
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 60 * GRID_H;
    };
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(60) + 35 * GRID_W;
      y = DIALOG_TOP + 110 * GRID_H + CTRL_DEFAULT_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};