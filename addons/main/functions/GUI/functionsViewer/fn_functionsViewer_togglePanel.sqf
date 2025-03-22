#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-11-15

    Description:
    Toggles the side panel of the ENH_FunctionsViewer GUI.

    Parameter(s):
    -

    Returns:
    -
*/

#define SIDEBAR_W 70 * GRID_W
#define LEFT (safeZoneX + GRID_W)
#define Y (safeZoneY + 3 * CTRL_DEFAULT_H + 2 * GRID_H)
#define H (safeZoneH - 4 * CTRL_DEFAULT_H - 4 * GRID_H)

disableSerialization;
private _display = uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull];
private _state = _display getVariable ["SideBarCollapsed", false];

if !_state then
{
    CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlSetPosition [LEFT, Y, safeZoneW - 73 * GRID_W + SIDEBAR_W + GRID_W, H];
}
else
{
    CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlSetPosition [LEFT + SIDEBAR_W + GRID_W, Y, safeZoneW - 73 * GRID_W, H];
};

CTRL(IDC_FUNCTIONSVIEWER_LIST) ctrlShow _state;
CTRL(IDC_FUNCTIONSVIEWER_LIST) ctrlCommit 0;
CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlCommit 0;

_display setVariable ["SideBarCollapsed", !_state];
