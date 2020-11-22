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

#include "\a3\3DEN\UI\macros.inc"
#define CTRL(IDC) (_displayOrControl displayCtrl IDC)
#define SIDEBAR_W 70 * GRID_W
#define LEFT (safezoneX + GRID_W)
#define Y (safezoneY + 24 * GRID_H)

disableSerialization;
params ["_displayOrControl"];

if (_displayOrControl isEqualType controlNull) then
{
  _displayOrControl = ctrlParent (_this # 0);
};

if (ctrlText CTRL(1406) == "«") then
{
  {
    CTRL(_x) ctrlSetFade 1;
    CTRL(_x) ctrlCommit 0;
  } forEach [2200,1500];

  CTRL(5000) ctrlSetPosition [LEFT,Y,safezoneW - 73 * GRID_W + SIDEBAR_W + GRID_W,safeZoneH - 31 * GRID_H];
  CTRL(5000) ctrlCommit 0;
  CTRL(1406) ctrlSetText "»";
}
else
{
  CTRL(5000) ctrlSetPosition [LEFT + SIDEBAR_W + GRID_W,Y,safezoneW - 73 * GRID_W,safeZoneH - 31 * GRID_H];
  CTRL(5000) ctrlCommit 0;

  {
    CTRL(_x) ctrlSetFade 0;
    CTRL(_x) ctrlCommit 0;
  } forEach [2200,1500];
  CTRL(1406) ctrlSetText "«";
};