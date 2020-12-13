/*
  Author: R3vo

  Date: 2020-11-15

  Description:
  Toggles the side panel of the ENH_FunctionsViewer GUI.

  Parameter(s):
  0: CONTROL: Collapse Button

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"
#define SIDEBAR_W 70 * GRID_W
#define LEFT (safezoneX + GRID_W)
#define Y (safezoneY + 24 * GRID_H)

disableSerialization;
params ["_display"];

if (_display isEqualType controlNull) then
{
  _display = ctrlParent (_this # 0);
};

if (ctrlText CTRL(IDC_FUNCTIONSVIEWER_PANNEL) == "«") then
{
  {
    CTRL(_x) ctrlSetFade 1;
    CTRL(_x) ctrlCommit 0;
  } forEach [IDC_FUNCTIONSVIEWER_LOADMODE,IDC_FUNCTIONSVIEWER_LIST];

  CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlSetPosition [LEFT,Y,safezoneW - 73 * GRID_W + SIDEBAR_W + GRID_W,safeZoneH - 31 * GRID_H];
  CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlCommit 0;
  CTRL(IDC_FUNCTIONSVIEWER_PANNEL) ctrlSetText "»";
}
else
{
  CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlSetPosition [LEFT + SIDEBAR_W + GRID_W,Y,safezoneW - 73 * GRID_W,safeZoneH - 31 * GRID_H];
  CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlCommit 0;

  {
    CTRL(_x) ctrlSetFade 0;
    CTRL(_x) ctrlCommit 0;
  } forEach [IDC_FUNCTIONSVIEWER_LOADMODE,IDC_FUNCTIONSVIEWER_LIST];
  CTRL(IDC_FUNCTIONSVIEWER_PANNEL) ctrlSetText "«";
};