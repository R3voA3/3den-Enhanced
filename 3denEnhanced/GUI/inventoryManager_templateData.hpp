#include "\3denEnhanced\defineCommon.hpp"

class ENH_InventoryManager_TemplateData
{
  idd = IDD_INVENTORYMANAGER_TEMPLATEDATA;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 51 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP + 50 * GRID_H;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Title: ctrlStatic
    {
      text = $STR_ENH_SCENARIOATTRIBUTESMANAGERTEMPLATEDATA_TITLE;
      x = CENTERED_X(60);
      y = DIALOG_TOP + 56 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TitleValue: ctrlEdit
    {
      idc = IDC_INVENTORYMANAGER_TEMPLATEDATA_TITLE;
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 62 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Description: ctrlStatic
    {
      text = $STR_ENH_SCENARIOATTRIBUTESMANAGERTEMPLATEDATA_DESCRIPTION;
      x = CENTERED_X(60);
      y = DIALOG_TOP + 68 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class DescriptionValue: ctrlEditMulti
    {
      idc = IDD_INVENTORYMANAGER_TEMPLATEDATA_DESCRIPTION;
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 74 * GRID_H;
      w = 58 * GRID_W;
      h = 25 * GRID_H;
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(60) + 34 * GRID_W;
      y = DIALOG_TOP + 100 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class OK: ctrlButtonOk
    {
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 100 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_IM_createTemplate";
    };
  };
};