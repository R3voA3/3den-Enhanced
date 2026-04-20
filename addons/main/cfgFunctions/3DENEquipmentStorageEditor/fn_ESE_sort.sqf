#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;

params [["_mode", "name"]];

private _display = uiNamespace getVariable "ENH_Display_ESE";

switch _mode do
{
    case "name":
    {
        [CTRL(IDC_ESE_INVENTORYLIST), 1] lnbSortBy ["TEXT", false, false];
    };
    case "class":
    {
        [CTRL(IDC_ESE_INVENTORYLIST), 0] lnbSortBy ["DATA", false, false];
    };
    case "count":
    {
        [CTRL(IDC_ESE_INVENTORYLIST), 2] lnbSortBy ["VALUE", false, false];
    };
    case "mod":
    {
        [CTRL(IDC_ESE_INVENTORYLIST), 3] lnbSortBy ["DATA", false, false];
    };
    case "type":
    {
        [CTRL(IDC_ESE_INVENTORYLIST), 1] lnbSortBy ["DATA", false, false];
    };
};
