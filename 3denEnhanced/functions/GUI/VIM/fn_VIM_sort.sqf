#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
params [["_mode", "name"]];

private _display = uiNamespace getVariable "ENH_Display_VIM";

switch (_mode) do
{
  case "name":
  {
    [CTRL(IDC_VIM_INVENTORYLIST), 1] lnbSortBy ["TEXT", false, false];
  };
  case "class":
  {
    [CTRL(IDC_VIM_INVENTORYLIST), 0] lnbSortBy ["DATA", false, false];
  };
  case "count":
  {
    [CTRL(IDC_VIM_INVENTORYLIST), 2] lnbSortBy ["VALUE", false, false];
  };
  case "mod":
  {
    [CTRL(IDC_VIM_INVENTORYLIST), 3] lnbSortBy ["DATA", false, false];
  };
  case "type":
  {
    [CTRL(IDC_VIM_INVENTORYLIST), 1] lnbSortBy ["DATA", false, false];
  };
};