/*
  Author: R3vo

  Date: 2021-10-11

  Description:
  Makes sure menu strip entries are properly checked.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"
disableSerialization;

private _display = uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull];

for "_i" from 0 to 13 do
{
  CTRL(IDC_FUNCTIONSVIEWER_MENU) menuSetCheck [[0, _i], false];
};

CTRL(IDC_FUNCTIONSVIEWER_MENU) menuSetCheck [[0, profileNamespace getVariable ["ENH_FunctionsViewer_ConfigIndex", 0]], true];
CTRL(IDC_FUNCTIONSVIEWER_MENU) menuSetCheck [[0, (profileNamespace getVariable ["ENH_FunctionsViewer_ModeIndex", 0]) + 4], true];
CTRL(IDC_FUNCTIONSVIEWER_MENU) menuSetCheck [[0, (profileNamespace getVariable ["ENH_FunctionsViewer_LoadFileIndex", 0]) + 9], true];

CTRL(IDC_FUNCTIONSVIEWER_MENU) menuEnable [[1, 3], getNumber (missionConfigfile >> "allowFunctionsRecompile") > 0];
CTRL(IDC_FUNCTIONSVIEWER_MENU) menuEnable [[1, 5], getNumber (missionConfigfile >> "allowFunctionsRecompile") > 0];